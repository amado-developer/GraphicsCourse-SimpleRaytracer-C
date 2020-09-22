//
// Created by Amado Garcia on 9/7/20.
//
# define M_PI

#include "Raytracer.h"

#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

void Raytracer::glCreateWindow(double width, double height){
    vector<vector<vector<unsigned char>>>framebuffer(width, vector<vector<unsigned char >>(height, vector<unsigned char >(3)));
    this->framebuffer = framebuffer;
    this->width = width;
    this->height = height;
}
void Raytracer::glClear()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                framebuffer[j][i][k] = (unsigned char)backgroundColor[k];
            }
        }
    }
}
void Raytracer::glClearColor(double r, double g, double b)
{
    backgroundColor[2] = (unsigned char) (r * 255.0);
    backgroundColor[1] = (unsigned char) (g * 255.0);
    backgroundColor[0] = (unsigned char) (b * 255.0);
}
void Raytracer::glColor(double r, double g, double b)
{
    pointColor[2] = (unsigned char) (r * 255.0);
    pointColor[1] = (unsigned char) (g * 255.0);
    pointColor[0] = (unsigned char) (b * 255.0);
}
void Raytracer::glPoint(int x, int y)
{
    this->framebuffer[x][y][0] = this->pointColor[0];
    this->framebuffer[x][y][1] = this->pointColor[1];
    this->framebuffer[x][y][2] = this->pointColor[2];
}
vector<double> Raytracer::sceneIntersect(tuple<double, double, double> origin, tuple<double, double, double> direction)
{
    double zbuffer = INFINITY;
    vector<double> material{};

    for(auto obj : this->scene)
    {
        auto hit = obj.rayIntersect(origin, direction);
        if(hit.hasImpacted() && hit.getDistance() < zbuffer)
        {
            zbuffer = hit.getDistance();
            material = obj.getMaterial();
            this->intersect = hit;
        }
    }
    return material;
}
vector<double> Raytracer::castRay(tuple<double, double, double> origin, tuple<double, double, double> direction)
{
    vector<double> impactedMaterial{sceneIntersect(origin, direction)};

    if(impactedMaterial.size() == 0)
    {
        return {50.0, 50.0, 200.0};
    }


    auto lightDirection{lib.norm(lib.sub(this->light.position, this->intersect.point))};
    double intensity{this->light.intensity * lib.dot(lightDirection, intersect.normal)};

    if(intensity < 0.0)
        intensity = 0.0;

    double r{round(impactedMaterial[0] * intensity)};
    double g{round(impactedMaterial[1] * intensity)};
    double b{round(impactedMaterial[2] * intensity)};

    return {r, g, b};
}
void Raytracer::setScene(Sphere sphere)
{
    this->scene.push_back(sphere);
}
void Raytracer::render()
{
    int fov = (M_PI / 2);
    for(auto y{0}; y < height; ++y)
    {
        for(auto x{0}; x < width; ++x)
        {
            double i{(2.0*(x + 0.5)/width - 1.0)*tan(fov/2.0)*width/height};
            double j{-(2.0*(y + 0.5)/height - 1.0)*tan(fov/2.0)};
            tuple<double, double, double> direction{this->lib.norm(make_tuple(i, j, -1))};
            double r = (this->castRay(make_tuple(0, 0, 0), direction).at(0)) / 255.0;
            double g = (this->castRay(make_tuple(0, 0, 0), direction).at(1)) /255.0;
            double b = (this->castRay(make_tuple(0, 0, 0), direction).at(2)) / 255.0;
            this->glColor(r, g, b);
            this->glPoint(x, y);
        }
    }
}
vector<unsigned char> Raytracer::fileHeader()
{
    int fileSize = 14 + 40 + width * height * 3;
    vector<unsigned char> fileHeader
            {
                    'B', 'M',
                    (unsigned char)(fileSize), 0, 0 , 0,
                    0, 0, 0, 0,
                    54, 0, 0, 0
            };
    return fileHeader;
}
vector<unsigned char> Raytracer::infoHeader()
{
    int imageSize = this->width * this->height * 3;
    vector<unsigned char> infoHeader
            {
                    40,0,0,0,
                    (unsigned char)(width),(unsigned char)(int(width) >> 8),(unsigned char)(int(width) >> 16),(unsigned char)(int(width) >> 24),
                    (unsigned char)(height),(unsigned char)(int(height) >> 8),(unsigned char)(int(height) >> 16),(unsigned char)(int(height) >> 24),
                    1,0,
                    24,0,0,0,
                    0,0,
                    (unsigned char)(imageSize),0,0,0,
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0
            };

    return infoHeader;
}
void Raytracer::glFinish(char *filename)
{
    FILE* imageFile = fopen(filename, "wb");

    vector<unsigned char> file = fileHeader();
    for(auto f: file)
    {
        fwrite(&f, 1, 1, imageFile);
    }

    vector<unsigned char> header = infoHeader();
    for(auto h: header)
    {
        fwrite(&h, 1, 1, imageFile);
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                fwrite(&framebuffer[j][i][k], 1, 1, imageFile);
            }
        }
    }
    fclose(imageFile);
}

void Raytracer::setLight(Light light)
{
    this->light = light;
}

Raytracer::Raytracer() {

}
