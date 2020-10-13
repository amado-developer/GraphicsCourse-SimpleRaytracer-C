//
// Created by Amado Garcia on 10/12/20.
//

#include "Plane.h"
#include "Lib.h"

Plane::Plane(tuple<double, double, double> position, tuple<double, double, double> normal, Materials material)
{
    this->position = position;
    this->normal = normal;
    this->material = material;
}

Materials Plane::getMaterial()
{
    return this->material;
}
Intersect Plane::rayIntersect(tuple<double, double, double> origin, tuple<double, double, double> direction)
{
    auto orig = make_tuple(get<0>(origin), get<1>(origin) + 1, get<2>(origin));
    auto d = - (get<1>(orig) + get<1>(position)) / get<1>(direction);
    auto pt = lib.sum(orig, lib.mult(direction, d));
    if(d <= 0 || abs(get<0>(pt) > 2.0 || get<2>(pt) > -5 || get<2>(pt) < -10.0))
    {
        return Intersect(-1, false, make_tuple(0, 0, 0), make_tuple(0,0,0));
    }
    auto normal = make_tuple(0.0, 1.0, 0.0);
    return Intersect(d, true, pt, normal);
}
