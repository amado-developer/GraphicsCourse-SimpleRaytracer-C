//
// Created by Amado Garcia on 9/21/20.
//

#include "Intersect.h"

Intersect::Intersect(double distance, bool impacted,  tuple<double, double, double> point,  tuple<double, double, double> normal)
{
    this->distance = distance;
    this->impacted = impacted;
    this->point = point;
    this->normal = normal;
}

double Intersect::getDistance()
{
    return this->distance;
}

bool Intersect::hasImpacted()
{
    return this->impacted;
}

Intersect::Intersect() {}