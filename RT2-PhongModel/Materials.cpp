//
// Created by Amado Garcia on 9/7/20.
//

#include "Materials.h"

Materials::Materials(vector<double> diffuse, vector<double> albedo, double spect)
{
    this->diffuse = diffuse;
    this->albedo = albedo;
    this->spect = spect;
}

const vector<double> &Materials::getDiffuse() const
{
    return diffuse;
}

const vector<double> &Materials::getAlbedo() const
{
    return albedo;
}

double Materials::getSpect() const
{
    return spect;
}

Materials::Materials() {}

bool Materials::hasImpacted() const
{
    return impacted;
}

void Materials::setImpacted(bool impacted)
{
    Materials::impacted = impacted;
}
