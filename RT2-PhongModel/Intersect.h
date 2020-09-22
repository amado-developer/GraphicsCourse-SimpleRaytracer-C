//
// Created by Amado Garcia on 9/21/20.
//

#ifndef RT2_PHONGMODEL_INTERSECT_H
#define RT2_PHONGMODEL_INTERSECT_H

#include <tuple>
using namespace std;

class Intersect
{
    public:
        Intersect();
        Intersect(double distance, bool impacted, tuple<double, double, double> point= make_tuple(1,1,1), tuple<double, double, double> normal = make_tuple(1,1,1));
        double getDistance();
        bool hasImpacted();
        bool impacted;
        double distance{};
        tuple<double, double, double> point;
        tuple<double, double, double> normal;
};


#endif //RT2_PHONGMODEL_INTERSECT_H
