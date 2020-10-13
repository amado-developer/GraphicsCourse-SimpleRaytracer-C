//
// Created by Amado Garcia on 9/9/20.
//

#ifndef TRANSFORMATIONS_TEXTURE_H
#define TRANSFORMATIONS_TEXTURE_H

#include <string>
#include <vector>
#include "Lib.h"
using namespace std;
class Texture
{
    private:
        char *path;
        vector<vector<vector<double>>> pixels{};
        Lib lib;
        int widht;
        int height;

    public:
        vector<vector<vector<double>>> backgroundPixels{};
        Texture(char* path);

    Texture();

    void read();
        vector<double> getColor(double tx, double ty);
        void readBackground();
        vector<double> getBackgroundColor(tuple<double, double, double> direction);
};


#endif
