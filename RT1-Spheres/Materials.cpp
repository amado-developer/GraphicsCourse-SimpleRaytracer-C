//
// Created by Amado Garcia on 9/7/20.
//

#include "Materials.h"

Materials::Materials(vector<double> diffuse)
{
    this->diffuse = diffuse;
}

vector<double> Materials::getMaterial()
{
    return this->diffuse;
}