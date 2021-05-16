//
// Created by JJBla on 4/9/2021.
//

#ifndef MOWERENGINE_TEXTURE_H
#define MOWERENGINE_TEXTURE_H

#include<GL/glu.h>

class Texture {
private:
    int textureWidth, textureHeight;
    GLuint textureID;
    void free();
public:
    Texture(GLuint* pixels, int width, int height);
    ~Texture();
    void bind() const;
    static void unbind() ;
};

#endif //MOWERENGINE_TEXTURE_H
