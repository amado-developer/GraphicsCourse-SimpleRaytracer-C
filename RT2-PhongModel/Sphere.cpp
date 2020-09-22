//
// Created by Amado Garcia on 9/7/20.
//

#include "Sphere.h"
#include <tuple>
#include <cmath>
#include "Intersect.h"

using namespace std;

Sphere::Sphere(tuple<double, double, double> center, double radius, vector<double> material)
{
    this->center = center;
    this->radius = radius;
    this->material = material;
}

Intersect Sphere::rayIntersect(tuple<double, double, double> origin, tuple<double, double, double> direction)
{
    tuple<double, double, double> L{lib.sub(this->center, origin)};
    double tca{lib.dot(L, direction)};
    double l{lib.length(L)};
    double d2{pow(l, 2) - pow(tca, 2)};
    if(d2 > this->radius)
    {
        return Intersect(0, false);
    }
    double thc{pow(pow(this->radius, 2) - 2, 0.5)};
    double t0{tca - thc};
    double t1{tca + thc};

    if(t0 < 0)
        t0 = t1;
    if(t0 < 0)
        return Intersect(0, false);

    auto hit{lib.sum(origin, lib.mult(direction, t0))};
    auto normal{lib.norm(lib.sub(hit, this->center))};
    return Intersect(t0, true, hit, normal);
}

vector<double> Sphere::getMaterial()
{
    return this->material;
}