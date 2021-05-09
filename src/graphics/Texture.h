//
// Created by JJBla on 4/9/2021.
//

#ifndef MOWERENGINE_TEXTURE_H
#define MOWERENGINE_TEXTURE_H

#define checkImageWidth 64
#define checkImageHeight 64

#include<GL/glu.h>

class Texture {
private:
    GLuint texName{};
    GLubyte checkImage[checkImageHeight][checkImageWidth][4]{};
    void makeCheckImage();

public:
    Texture();
    ~Texture();
    void bind();
};


#endif //MOWERENGINE_TEXTURE_H
