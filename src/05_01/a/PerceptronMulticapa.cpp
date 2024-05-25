/*
 * Curso: C++ Construye redes neuronales
 * Plataforma: LinkedIn Learning
 * Instructor: @EliezerLopez
 * */

#include "PerceptronMulticapa.h"

double frand(){
    return (2.0*(double)rand() / RAND_MAX) - 1.0;
}

Perceptron::Perceptron(size_t numero_de_entradas, double bias){
    this->bias = bias;
    pesos.resize(numero_de_entradas+1);
    generate(pesos.begin(), pesos.end(), frand);
}

void Perceptron::establecer_pesos(std::vector<double> pesos_iniciales){
    pesos = pesos_iniciales;
}

double Perceptron::ejecutar(std::vector<double> datos_de_entrada){
    datos_de_entrada.push_back(bias);
    double suma_ponderada = std::inner_product(datos_de_entrada.begin(),datos_de_entrada.end(),pesos.begin(),(double)0.0);
    return sigmoide(suma_ponderada);
}

double Perceptron::sigmoide(double x){
    return 1.0/(1.0 + exp(-x));
}

PerceptronMulticapa::PerceptronMulticapa(std::vector<size_t> capas, double bias){
    this->capas = capas;
    this->bias = bias;

    for(size_t i=0; i < capas.size(); i++){
        valores.push_back(std::vector<double>(capas[i],0.0));
        red.push_back(std::vector<Perceptron>());

        if(i>0){
            for(size_t j = 0; j<capas[i]; j++){
                red[i].push_back(Perceptron(capas[i-1], bias));
            }
        }
    }    
}

void PerceptronMulticapa::establecer_pesos(std::vector<std::vector<std::vector<double> > > pesos_iniciales){
    for(size_t i=0; i<pesos_iniciales.size();i++){
        for(size_t j =0; j<pesos_iniciales[i].size();j++){
            red[i+1][j].establecer_pesos(pesos_iniciales[i][j]);
        }
    }
}

std::vector<double> PerceptronMulticapa::ejecutar(std::vector<double> datos_de_entrada){

    valores[0] = datos_de_entrada;

    for(size_t i=1; i<red.size(); i++){
        for(size_t j=0; j<capas[i]; j++){
            valores[i][j] = red[i][j].ejecutar(valores[i-1]);
        }
    }
    return valores.back();
}

double PerceptronMulticapa::retro(std::vector<double> x, std::vector<double> y){

    // Paso 1: alimentar la red
    std::vector<double> salidas = ejecutar(x);

    // Paso 2: calcular el error cuadrático medio
    double error_cuadratico_medio = 0.0;
    std::vector<double> error;

    for(size_t i=0; i<y.size();i++){
        error.push_back(y[i] - salidas[i]);
        error_cuadratico_medio += error[i] * error[i];
    }

    error_cuadratico_medio /= capas.back();

    // Paso 3: calcular los términos de error de salida
    for(size_t i = 0; i < salidas.size(); i++){
        d.back()[i] = salidas[i] * (1-salidas[i]) * (error[i]);
    }
    // Paso 4: calcular el término de error de cada unidad en cada capa
    for(size_t i= red.size()-2; i>0;i--){
        for(size_t h=0;h<red[i].size();h++){
            double retro_error = 0.0;
            for(size_t k=0; k<capas[i+1];k++){
                retro_error += red[i+1][k].pesos[h]*valores[i+1][k];
            }
            d[i][h] = valores[i][h]*(1-valores[i][h])*retro_error;
        }
    }
    
    // Pasos 5 y 6: calcular las deltas y actualizar los pesos
    for (size_t i = 1; i < red.size(); i++)
        for (size_t j = 0; j < capas[i]; j++)
            for (size_t k = 0; k < capas[i-1]+1; k++){
                double delta;
                if (k == capas[i-1]) delta = eta * d[i][j] * bias;
                else delta = eta * d[i][j] * valores[i-1][k];
                
                red[i][j].pesos[k] += delta;
            }
}