#include <iostream>
#include "Raytracer.h"
#include "Materials.h"
int main()
{
    Raytracer r;
    r.glCreateWindow(800, 600);
    r.glClear();


    Materials snow({240, 240,  240});
    Materials button({0, 0, 0});
    Materials nose({255, 102, 0});
    Materials eye({255, 255, 255});
    Materials iris({0, 0, 0});

    //===========================================BODY==========================================================
    r.setScene(Sphere(make_tuple(0, -1.5, -12), 0.3, button.getMaterial()));
    r.setScene(Sphere(make_tuple(0, 0.8, -12), 0.3, button.getMaterial()));
    r.setScene(Sphere(make_tuple(0, -0.5, -10), 3.5, snow.getMaterial()));
    //==========================================================================================================
    //===========================================HEAD===========================================================
    r.setScene(Sphere(make_tuple(0.5, -4.8, -12.3), 0.02, iris.getMaterial()));
    r.setScene(Sphere(make_tuple(0.5, -4.8, -12), 0.1, eye.getMaterial()));
    r.setScene(Sphere(make_tuple(-0.5, -4.8, -12.3), 0.02, iris.getMaterial()));
    r.setScene(Sphere(make_tuple(-0.5, -4.8, -12), 0.1, eye.getMaterial()));
    r.setScene(Sphere(make_tuple(0, -4.0, -12), 0.1, nose.getMaterial()));
    r.setScene(Sphere(make_tuple(-0.6, -3.0, -11), 0.01, button.getMaterial()));
    r.setScene(Sphere(make_tuple(-0.2, -2.8, -11), 0.01, button.getMaterial()));
    r.setScene(Sphere(make_tuple(0.2, -2.8, -11), 0.01, button.getMaterial()));
    r.setScene(Sphere(make_tuple(0.6, -3.0, -11), 0.01, button.getMaterial()));
    r.setScene(Sphere(make_tuple(0, -4, -12), 2.5, snow.getMaterial()));

    //===========================================Feet===========================================================
    r.setScene(Sphere(make_tuple(0, 3, -12), 0.5, button.getMaterial()));
    r.setScene(Sphere(make_tuple(0, 2.5, -10), 5, snow.getMaterial()));
    //==========================================================================================================
    r.render();
    r.glFinish("out.bmp");
    return 0;
}
