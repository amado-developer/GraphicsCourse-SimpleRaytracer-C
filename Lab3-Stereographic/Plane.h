//
// Created by Amado Garcia on 10/12/20.
//

#ifndef LAB3_STEREOGRAPHIC_PLANE_H
#define LAB3_STEREOGRAPHIC_PLANE_H

#include "Materials.h";
#include "Intersect.h";
#include "Lib.h"
class Plane
{
    private:
        tuple<double, double, double> position;
        Materials material;
        tuple<double, double, double> normal;
        Lib lib;
    public:
        Plane(tuple<double, double, double> position,  tuple<double, double, double> normal, Materials material);
        Intersect rayIntersect(tuple<double, double, double> origin, tuple<double, double, double> direction);
        Materials getMaterial();
};


#endif //LAB3_STEREOGRAPHIC_PLANE_H
