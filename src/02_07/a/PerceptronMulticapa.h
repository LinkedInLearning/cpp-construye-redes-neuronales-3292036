/*
 * Curso: C++ Construye redes neuronales
 * Plataforma: LinkedIn Learning
 * Instructor: @EliezerLopez
 * */

#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <time.h>

class Perceptron{
public:
    Perceptron::Perceptron(size_t numero_de_entradas, double bias=1.0);
    double ejecutar(std::vector<double> datos_de_entrada);
    void establecer_pesos(std::vector<double> pesos_iniciales);
    double funcion_de_activacion(double x);
    std::vector<double> pesos;
    double bias;
};

class PerceptronMulticapa{
public:

};