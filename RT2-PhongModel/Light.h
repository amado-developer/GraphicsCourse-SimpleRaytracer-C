//
// Created by Amado Garcia on 9/21/20.
//

#ifndef RT2_PHONGMODEL_LIGHT_H
#define RT2_PHONGMODEL_LIGHT_H
#include <tuple>
using namespace std;

class Light
{
    public:
        Light(tuple<double, double, double> position, double intensity=1);
        Light();
        tuple<double, double, double> position;
        double intensity;

};


#endif //RT2_PHONGMODEL_LIGHT_H
