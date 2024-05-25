/*
 * Curso: C++ Construye redes neuronales
 * Plataforma: LinkedIn Learning
 * Instructor: @EliezerLopez
 * */

#include "PerceptronMulticapa.h"

double Perceptron::ejecutar(std::vector<double> datos_de_entrada){
    double suma_ponderada = std::inner_product(datos_de_entrada.begin(),datos_de_entrada.end(),secuencia2.begin(),(double)0.0);
    // Función de activación
    return suma_ponderada; 
}