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

    // double edad, nivel_de_colesterol, presion_arterial;
    std::vector<size_t> configuracion;
    configuracion.push_back(3);
    configuracion.push_back(5);
    configuracion.push_back(1);

    PerceptronMulticapa red_neuronal(configuracion);
    // Entrenamiento
    std::vector<double> datos_paciente;

    datos_paciente.push_back(0.55);
    datos_paciente.push_back(0.7);
    datos_paciente.push_back(0.65);

    std::vector<double> salida = red_neuronal.ejecutar(datos_paciente);
    
    if(salida[0] > 0.5) std::cout << "Alto riesgo de enfermedad. Realice más pruebas." << std::endl;
    else std::cout << "Bajo riesgo de enfermedad. Continúe manteniendo un estilo de vida saludable." << std::endl;

    return 0;
}