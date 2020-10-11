//
// Created by Amado Garcia on 9/7/20.
//

#ifndef RT1_SPHERES_LIB_H
#define RT1_SPHERES_LIB_H

#include <tuple>
using namespace std;

class Lib
{
    public:
        tuple<double, double, double> sum(tuple<double, double, double> v0, tuple<double, double, double> v1);
        tuple<double, double, double> sub(tuple<double, double, double> v0, tuple<double, double, double> v1);
        tuple<double, double, double> mult(tuple<double, double, double> v0, double k);
        double dot(tuple<double, double, double> v0, tuple<double, double, double> v1);
        double length(tuple<double, double, double> v0);
        tuple<double, double, double> norm(tuple<double, double, double> v0);
        tuple<double, double, double> cross(tuple<double, double, double> u, tuple<double, double, double> w);
        tuple<double, double, double> reflect(tuple<double, double, double> I, tuple<double, double, double> N);
};
#endif //RT1_SPHERES_LIB_H
