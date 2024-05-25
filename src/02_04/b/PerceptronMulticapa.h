/*
 * Curso: C++ Construye redes neuronales
 * Plataforma: LinkedIn Learning
 * Instructor: @EliezerLopez
 * */

#include <vector>
#include <numeric>

class Perceptron{
public:
    double ejecutar(std::vector<double> datos_de_entrada);
    void establecer_pesos(std::vector<double> pesos_iniciales);
    double funcion_de_activacion(double x);
    double bias;
};

class PerceptronMulticapa{
public:

};