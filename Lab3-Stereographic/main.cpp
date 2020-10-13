#include <iostream>
#include "Raytracer.h"
#include "Materials.h"
#include "Plane.h"
#include "Texture.h"
int main()
{
    Raytracer r;
    r.glCreateWindow(2000, 1000);
    r.glClearColor(50.0, 50.0, 200.0);
    Materials leaf({110.0, 150.0, 50.0}, {0.9, 0.1, 0.0, 0.0}, 11.0);
    Materials eye({0.0, 0.0, 0.0}, {0.9, 0.1, 0.0, 0.0}, 11.0);
    Materials nose({255, 50.0, 50.0}, {0.9, 0.1, 0.0, 0.0}, 11.0);
    Materials antennae({50.0, 50.0, 50.0}, {0.9, 0.1, 0.0, 0.0}, 11.0);
    r.setLight(Light(make_tuple(0.5, 2.0, 1.0), 1.0));
    r.type = 1;
    r.setScene(Sphere(make_tuple(0.0, 2.5, -10.0), 1.5, leaf), 0.0);
    r.setScene(Sphere(make_tuple(0.0, 0.0, -10.0), 1.5, leaf), 0.0);
    r.setScene(Sphere(make_tuple(0.0, -2.5, -10.0), 1.5, leaf), 0.0);

    r.setScene(Sphere(make_tuple(0.0, 2.0, -8.75), 0.2, nose), 0.0);

    r.setScene(Sphere(make_tuple(0.45, 2.5, -8.0), 0.1, eye), 0.0);
    r.setScene(Sphere(make_tuple(-0.45, 2.5, -8.0), 0.1, eye), 0.0);

    r.setScene(Sphere(make_tuple(-0.95, 3.4, -9.0), 0.2, antennae), 0.0);
    r.setScene(Sphere(make_tuple(-1.2, 3.7, -9.0), 0.2, antennae), 0.0);
    r.setScene(Sphere(make_tuple(-1.4, 4.0, -9.0), 0.2, antennae), 0.0);

    r.setScene(Sphere(make_tuple(0.95, 3.5, -9.0), 0.2, antennae), 0.0);
    r.setScene(Sphere(make_tuple(1.2, 3.7, -9.0), 0.2, antennae), 0.0);
    r.setScene(Sphere(make_tuple(1.5, 3.9, -9.0), 0.2, antennae), 0.0);
//    r.render();
    r.render3D();

    r.glFinish("3D.bmp");
    return 0;
}
