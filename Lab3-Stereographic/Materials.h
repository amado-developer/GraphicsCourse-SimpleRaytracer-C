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
        vector<double> albedo;
        double spect;
        bool impacted;

    public:
        Materials(vector<double> diffuse, vector<double> albedo, double spect);
        Materials();
        bool hasImpacted() const;
        const vector<double> &getDiffuse() const;
        const vector<double> &getAlbedo() const;
        double getSpect() const;
        void setImpacted(bool impacted);
};


#endif //RT1_SPHERES_MATERIALS_H
