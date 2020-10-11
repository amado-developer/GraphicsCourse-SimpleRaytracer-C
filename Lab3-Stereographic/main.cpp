#include <iostream>
#include "Raytracer.h"
#include "Materials.h"
int main()
{
    Raytracer r;
    r.glCreateWindow(1000, 1000);
    r.glClear();
    Materials ivory({100.0, 100.0, 80.0}, {0.6, 0.3, 0.1, 0.0}, 50.0);
    Materials rubber({80.0, 0.0, 0.0}, {0.9, 0.1, 0.0, 0.0}, 10.0);
    Materials mirror({255.0, 255.0, 255.0}, {0.0, 0.2, 0.8, 0.0}, 1425);
    Materials glass({150.0, 180.0, 200.0}, {0.0, 0.1, 0.1, 0.8}, 125);

    r.setLight(Light(make_tuple(-20.0, 20.0, 20.0), 1.5));

    r.setScene(Sphere(make_tuple(0.0, -1.5, -10.0), 1.5, ivory), 1.0);
    r.setScene(Sphere(make_tuple(0.0, 0.0, -5.0), 0.5, glass), 1.5);
    r.setScene(Sphere(make_tuple(1.0, 1.0, -8.0), 1.7, rubber), 1.0);
    r.setScene(Sphere(make_tuple(-3.0, 3.0, -10.0), 2.0, mirror), 1.0);
    r.render();
    r.glFinish("out.bmp");
    return 0;
}
