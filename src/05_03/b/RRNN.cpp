/*
 * Curso: C++ Construye redes neuronales
 * Plataforma: LinkedIn Learning
 * Instructor: @EliezerLopez
 * */

#include "PerceptronMulticapa.h"
#include <iostream>

int main(){

    srand(time(NULL));

    std::vector<size_t> configuracion;
    configuracion.push_back(2);
    configuracion.push_back(2);
    configuracion.push_back(1);
    PerceptronMulticapa p(configuracion);

    std::vector<std::vector<std::vector<double> > > pesos_iniciales;

    std::vector<std::vector<double> > capa_oculta;
    std::vector<double> neurona1;
    neurona1.push_back(-10);
    neurona1.push_back(-10);
    neurona1.push_back(15);

    std::vector<double> neurona2;
    neurona2.push_back(15);
    neurona2.push_back(15);
    neurona2.push_back(-10);

    capa_oculta.push_back(neurona1);
    capa_oculta.push_back(neurona2);

    std::vector<std::vector<double> > capa_salida;
    std::vector<double> neurona_salida;
    neurona_salida.push_back(10);
    neurona_salida.push_back(10);
    neurona_salida.push_back(-15);
    capa_salida.push_back(neurona_salida);

    pesos_iniciales.push_back(capa_oculta);
    pesos_iniciales.push_back(capa_salida);

    std::vector<double> combinacion1;
    combinacion1.push_back(0);
    combinacion1.push_back(0);
    std::cout << "0 XOR 0 : " << p.ejecutar(combinacion1)[0] << std::endl;

    std::vector<double> combinacion2;
    combinacion2.push_back(0);
    combinacion2.push_back(1);
    std::cout << "0 XOR 1 : " << p.ejecutar(combinacion2)[0] << std::endl;

    std::vector<double> combinacion3;
    combinacion3.push_back(1);
    combinacion3.push_back(0);
    std::cout << "1 XOR 0 : " << p.ejecutar(combinacion3)[0] << std::endl;

    std::vector<double> combinacion4;
    combinacion4.push_back(1);
    combinacion4.push_back(1);
    std::cout << "1 XOR 1 : " << p.ejecutar(combinacion4)[0] << std::endl;
    
    return 0;
}