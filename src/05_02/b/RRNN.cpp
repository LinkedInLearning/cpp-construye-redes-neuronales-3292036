/*
 * Curso: C++ Construye redes neuronales
 * Plataforma: LinkedIn Learning
 * Instructor: @EliezerLopez
 * */

#include "PerceptronMulticapa.h"
#include <iostream>

int main(){

    srand(time(NULL));
    rand();

    Perceptron p(2);

    std::vector<double> pesos_iniciales;
    pesos_iniciales.push_back(10);
    pesos_iniciales.push_back(10);
    pesos_iniciales.push_back(-5);
    
    p.establecer_pesos(pesos_iniciales);

    std::vector<double> combinacion1;
    combinacion1.push_back(0);
    combinacion1.push_back(0);
    std::cout << "0 || 0 : " << p.ejecutar(combinacion1) << std::endl;

    std::vector<double> combinacion2;
    combinacion2.push_back(0);
    combinacion2.push_back(1);
    std::cout << "0 || 1 : " << p.ejecutar(combinacion2) << std::endl;

    std::vector<double> combinacion3;
    combinacion3.push_back(1);
    combinacion3.push_back(0);
    std::cout << "1 || 0 : " << p.ejecutar(combinacion3) << std::endl;

    std::vector<double> combinacion4;
    combinacion4.push_back(1);
    combinacion4.push_back(1);
    std::cout << "1 || 1 : " << p.ejecutar(combinacion4) << std::endl;
    
    return 0;
}