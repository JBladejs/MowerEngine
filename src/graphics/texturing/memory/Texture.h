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
private:
    GLuint textureWidth, textureHeight;
    GLuint imageWidth, imageHeight;

    void bind() const;

    static void unbind();

public:
    Texture();

    ~Texture();

    void free();

    //TODO: change singed int to unsigned
    bool load(GLuint *pixels, int texWidth, int texHeight, int imgWidth, int imgHeight);

    void render(float x, float y, float width, float height, FRect *clip = nullptr);

    void render(float x, float y, float scale = 1.f, FRect *clip = nullptr);

    GLuint getTextureId() const;

    GLuint getTextureWidth() const;

    GLuint getTextureHeight() const;

    GLuint getImageWidth() const;

    GLuint getImageHeight() const;
};

#endif //MOWERENGINE_TEXTURE_H
