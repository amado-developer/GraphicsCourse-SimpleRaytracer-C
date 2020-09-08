//
// Created by Amado Garcia on 9/7/20.
//

#ifndef RT1_SPHERES_MATERIALS_H
#define RT1_SPHERES_MATERIALS_H

#include <vector>
using namespace std;
class Materials
{
    private:
        vector<double> diffuse;
    public:
        Materials(vector<double> diffuse);
        vector<double> getMaterial();
};


#endif //RT1_SPHERES_MATERIALS_H
