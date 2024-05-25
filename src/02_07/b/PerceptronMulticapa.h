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
#include <cmath>

class Perceptron{
public:
    Perceptron::Perceptron(size_t numero_de_entradas, double bias=1.0);
    double ejecutar(std::vector<double> datos_de_entrada);
    void establecer_pesos(std::vector<double> pesos_iniciales);
    double sigmoide(double x);
    std::vector<double> pesos;
    double bias;
};

class PerceptronMulticapa{
public:

};