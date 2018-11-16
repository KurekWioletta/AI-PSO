#include "mathUtils.hpp"
#include <iostream>

double func(double x, double y){
    return x*x + y*y - 20*(cos(PI*x)+cos(PI*y)-2);
}

double randomDouble(double min, double max){
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(min, max);
    return dist(mt);
}