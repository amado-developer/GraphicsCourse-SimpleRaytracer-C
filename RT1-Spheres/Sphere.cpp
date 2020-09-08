//
// Created by Amado Garcia on 9/7/20.
//

#include "Sphere.h"
#include <tuple>
#include <cmath>

using namespace std;

Sphere::Sphere(tuple<double, double, double> center, double radius, vector<double> material)
{
    this->center = center;
    this->radius = radius;
    this->material = material;
}

bool Sphere::rayIntersect(tuple<double, double, double> origin, tuple<double, double, double> direction)
{
    tuple<double, double, double> L{lib.sub(this->center, origin)};
    double tca{lib.dot(L, direction)};
    double l{lib.length(L)};
    double d2{pow(l, 2) - pow(tca, 2)};
    if(d2 > this->radius)
    {
        return false;
    }
    double thc{pow(pow(this->radius, 2) - 2, 0.5)};
    double t0{tca - thc};
    double t1{tca + thc};

    if(t0 < 0)
        t0 = t1;
    if(t0 < 0)
        return false;
    return true;
}

vector<double> Sphere::getMaterial()
{
    return this->material;
}