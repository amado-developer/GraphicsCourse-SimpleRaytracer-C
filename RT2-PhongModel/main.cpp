#include <iostream>
#include "Raytracer.h"
#include "Materials.h"
int main()
{
    Raytracer r;
    r.glCreateWindow(1000, 1000);
    r.glClear();

    Materials ivory({100.0, 100.0, 80.0}, {0.6, 0.3}, 50.0);
    Materials rubber({80.0, 0.0, 0.0}, {0.9, 0.1}, 10.0);
    r.setLight(Light(make_tuple(-20.0, 20.0,  20.0), 1.5));

    r.setScene(Sphere(make_tuple(0.0, -1.5, -10), 1.5, ivory));
    r.setScene(Sphere(make_tuple(-2.0, -1.0, -12.0), 2.0, rubber));
    r.setScene(Sphere(make_tuple(1.0, 1.0, -8.0), 1.7, rubber));
    r.setScene(Sphere(make_tuple(0.0, 5.0, -20.0), 5.0, ivory));

    r.render();
    r.glFinish("out.bmp");
    return 0;
}
