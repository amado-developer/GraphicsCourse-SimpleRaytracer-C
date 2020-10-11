//
// Created by Amado Garcia on 9/7/20.
//

#ifndef RT1_SPHERES_RAYTRACER_H
#define RT1_SPHERES_RAYTRACER_H

#include <vector>
#include <string>
#include "Sphere.h"
#include "Lib.h"
#include "Light.h"
using namespace std;
class Raytracer
{
    private:
    unsigned char backgroundColor[3];
        unsigned char pointColor[3];
        double width;
        double height;
        vector<vector<vector<unsigned char>>> framebuffer;
        vector<Sphere> scene;
        void glPoint(int x, int y);
        vector<unsigned char> fileHeader();
        vector<unsigned char> infoHeader();
        Lib lib;
        Light light;
        Intersect intersect;

    public:
        const int MAX_RECURSION_DEPTH = 5;
        double refractionIndex;
        vector<double> castRay(tuple<double, double, double> origin, tuple<double, double, double> direction, int recursion);
        void glClear();
        void glClearColor(double r, double g, double b);
        void glColor(double r, double g, double b);
        void glCreateWindow(double width, double height);
        void glFinish(char *filename);
        void render();
        void setScene(Sphere sphere, double refractionIndex);
        void setLight(Light light);
        Materials sceneIntersect(tuple<double, double, double> origin, tuple<double, double, double> direction);
        Raytracer();
};


#endif //RT1_SPHERES_RAYTRACER_H
