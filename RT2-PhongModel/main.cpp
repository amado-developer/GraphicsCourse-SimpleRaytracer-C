#include <iostream>
#include "Raytracer.h"
#include "Materials.h"
int main()
{
    Raytracer r;
    r.glCreateWindow(1920, 1080);
    r.glClear();

    Materials redBall({216.0, 44.0, 40.0}, {0.7, 0.2}, 4.0);
    Materials whiteBall({245.0, 245.0, 245.0}, {0.7, 0.3}, 10.0);
    Materials snowBall({255.0, 255.0, 255.0}, {1.0, 0.0}, 1.0);
    Materials lightBrownBall({251, 203, 173}, {1.0, 0.0}, 1.0);
    Materials darkBrownBall({211, 105, 47}, {1.0, 0.0}, 1.0);
    Materials blackBall({10.0, 10.0, 10.0}, {0.3, 0.1}, {1.0});
    r.setLight(Light(make_tuple(0.0, 10.0,  40.0), 1.0));

    //Red Bear
    //Center Ball
    r.setScene(Sphere(make_tuple(5.0, -1.5, -10.0), 2.5, redBall));

    //Head
    r.setScene(Sphere(make_tuple(4.75, 1.60, -9.0), 2.0, lightBrownBall));

    //Nose
    r.setScene(Sphere(make_tuple(4.2, 1.0, -7.5), 0.7, darkBrownBall));
    r.setScene(Sphere(make_tuple(3.65, 0.9, -6.5), 0.1, blackBall));

    //Eyes
    r.setScene(Sphere(make_tuple(4.5, 1.9, -7.0), 0.1, blackBall));
    r.setScene(Sphere(make_tuple(3.5, 1.9, -7.0), 0.1, blackBall));

    //Ears
      r.setScene(Sphere(make_tuple(6.0, 3.0, -8.0), 0.5, darkBrownBall));
      r.setScene(Sphere(make_tuple(3.4, 3.2, -8.5), 0.5, darkBrownBall));

    //Arms
    r.setScene(Sphere(make_tuple(6.9, -0.01, -8.7), 0.8, lightBrownBall));
    r.setScene(Sphere(make_tuple(2.5, -0.1, -9.95), 1.0, lightBrownBall));

    //Feet
    r.setScene(Sphere(make_tuple(6.0, -2.5, -8.0), 0.8, lightBrownBall));
    r.setScene(Sphere(make_tuple(3.0, -2.8, -9.0), 1.0, lightBrownBall));

    //==============================White Bear=============================================
    //Center Ball
    r.setScene(Sphere(make_tuple(-5.0, -1.5, -10), 2.0, whiteBall));
    //Head
    r.setScene(Sphere(make_tuple(-5.0, 1.60, -10.0), 2.0, snowBall));

    //Nose
    r.setScene(Sphere(make_tuple(-4.2, 1.0, -8.0), 0.7, snowBall));
    r.setScene(Sphere(make_tuple(-3.75, 0.9, -7.0), 0.1, blackBall));

    //Eyes
    r.setScene(Sphere(make_tuple(-4.8, 1.9, -8.0), 0.1, blackBall));
    r.setScene(Sphere(make_tuple(-3.8, 1.9, -8.0), 0.1, blackBall));

    //Ears
    r.setScene(Sphere(make_tuple(-6.0, 3.0, -9.0), 0.5, snowBall));
    r.setScene(Sphere(make_tuple(-3.8, 3.2, -9.5), 0.5, snowBall));

    //Arms
    r.setScene(Sphere(make_tuple(-6.4, -0.01, -8.7), 0.8, snowBall));
    r.setScene(Sphere(make_tuple(-3.0, -0.2, -9.8), 1.0, snowBall));

    //Feet
    r.setScene(Sphere(make_tuple(-6.4, -2.5, -8.7), 0.8, snowBall));
    r.setScene(Sphere(make_tuple(-3.0, -2.8, -9.8), 1.0, snowBall));

    r.render();
    r.glFinish("out.bmp");
    return 0;
}
