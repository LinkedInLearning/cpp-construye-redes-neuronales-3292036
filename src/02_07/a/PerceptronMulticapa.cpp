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
    // Función de activación
    return suma_ponderada; 
}