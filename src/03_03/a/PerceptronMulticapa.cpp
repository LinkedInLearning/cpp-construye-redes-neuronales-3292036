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