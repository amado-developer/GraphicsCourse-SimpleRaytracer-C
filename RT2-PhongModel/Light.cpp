//
// Created by Amado Garcia on 9/21/20.
//

#include "Light.h"
Light::Light(tuple<double, double, double> position, double intensity)
{
    this->position = position;
    this->intensity = intensity;
}

Light::Light(){}

