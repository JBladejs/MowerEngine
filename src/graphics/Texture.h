//
// Created by JJBla on 4/9/2021.
//

#ifndef MOWERENGINE_TEXTURE_H
#define MOWERENGINE_TEXTURE_H

#define textureWidth 64
#define textureHeight 64

#include<GL/glu.h>

class Texture {
private:
    GLuint texName{};
    GLubyte checkImage[textureHeight][textureWidth][4]{};
    void makeCheckImage();
    void freeTexture();
public:
    Texture();
    ~Texture();
    void bind();
};


#endif //MOWERENGINE_TEXTURE_H
