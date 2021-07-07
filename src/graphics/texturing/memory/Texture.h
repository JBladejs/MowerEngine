//
// Created by JJBla on 4/9/2021.
//

#ifndef MOWERENGINE_TEXTURE_H
#define MOWERENGINE_TEXTURE_H

#include<GL/glu.h>
#include "../../util/FRect.h"

class Texture {
private:
    GLuint textureID;
    void free();
    void bind() const;
    static void unbind();
public:
    //TODO: replace this with getters and setters
    //TODO: make dimensions private
    GLuint imageWidth, imageHeight;
    GLuint textureWidth, textureHeight;
    Texture(GLuint *pixels, int texWidth, int texHeight, int imgWidth, int imgHeight);
    ~Texture();
    void render(float x, float y, float width, float height, FRect* clip = nullptr);
    void render(float x, float y, float scale = 1.f, FRect* clip = nullptr) {
        render(x, y, (float) imageWidth * scale, (float) imageHeight * scale, clip);
    }
};

#endif //MOWERENGINE_TEXTURE_H
