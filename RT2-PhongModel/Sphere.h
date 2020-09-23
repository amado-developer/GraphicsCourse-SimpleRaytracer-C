//
// Created by Amado Garcia on 9/7/20.
//

#ifndef RT1_SPHERES_SPHERE_H
#define RT1_SPHERES_SPHERE_H
#include <vector>
#include <tuple>
#include <vector>
#include "Lib.h"
#include "Intersect.h"
#include "Materials.h"

using namespace std;


class Sphere
{
    public:
        Sphere(tuple<double, double, double> center, double radius,  Materials material);
        Intersect rayIntersect(tuple<double, double, double> origin, tuple<double, double, double> direction);
        Materials getMaterial();
    private:
        tuple<double, double, double> center;
        Materials material;
        double radius;
        Lib lib;
};


#endif //RT1_SPHERES_SPHERE_H
