//
// Created by JJBla on 4/9/2021.
//

#include "Texture.h"

#include <iostream>
#include <cstring>

Texture::Texture() {
    loadedPixels = nullptr;
    pixelsLoaded = false;
    textureID = 0;
    textureWidth = textureHeight = 0.f;
    imageWidth = imageHeight = 0.f;
}

void Texture::bind() const {
    glBindTexture(GL_TEXTURE_2D, textureID);
}

void Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::free() {
    unbind();
    if (textureID != 0) {
        glDeleteTextures(1, &textureID);
        textureID = 0;
    }
    if (pixelsLoaded) {
        delete[] loadedPixels;
        loadedPixels = nullptr;
        pixelsLoaded = false;
    }
}

//TODO: consider making pixels constant
void Texture::loadPixels(GLuint *pixels, int texWidth, int texHeight, int imgWidth, int imgHeight) {
    free();
    GLuint size = texHeight * texWidth;
    loadedPixels = new GLuint[size];

    textureID = 0;
    textureWidth = texWidth;
    textureHeight = texHeight;
    imageWidth = imgWidth;
    imageHeight = imgHeight;

    memcpy(loadedPixels, pixels, size * 4);
    pixelsLoaded = true;
}

void Texture::generate() {
    glGenTextures(1, &textureID);
    bind();

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei) textureWidth,
                 (GLsizei) textureHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 loadedPixels);

//    TODO: find out about this
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
//                    GL_NEAREST);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
//                    GL_NEAREST);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

    unbind();
    delete[] loadedPixels;
    loadedPixels = nullptr;
    pixelsLoaded = false;
    //TODO: add error checking
}

void Texture::load(GLuint *pixels, int texWidth, int texHeight, int imgWidth, int imgHeight) {
    loadPixels(pixels, texWidth, texHeight, imgWidth, imgHeight);
    generate();
}

//TODO: do color keying while drawing
void Texture::loadColorKeyed(GLuint *pixels, int texWidth, int texHeight, int imgWidth, int imgHeight, Color color, GLuint alpha) {
    loadPixels(pixels, texWidth, texHeight, imgWidth, imgHeight);
    //TODO: make sure that only the part that contains an image is keyed
    GLuint size = imageWidth * imageHeight;
    GLuint y_offset = texWidth - imgWidth;
    for (int i = 0; i < size; i++) {
        auto* colors = (GLubyte*) &loadedPixels[i];
        if (colors[0] == color.iR && colors[1] == color.iB && colors[2] == color.iG && colors[3] == alpha) {
            colors[0] = 255;
            colors[1] = 255;
            colors[2] = 255;
            colors[3] = 0;
        }
    }
    generate();
}

void Texture::render(float x, float y, float width, float height, FRect *clip) {
    if (textureID != 0) {
        //TODO: use GL data types
        //TODO: use constant image to texture proportions
        float texL = 0.f;
        float texR = (float) imageWidth / (float) textureWidth;
        float texT = 0.f;
        float texB = (float) imageHeight / (float) textureHeight;

        if (clip != nullptr) {
            texL = clip->x * (float) imageWidth / (float) textureWidth;
            texT = clip->y * (float) imageHeight / (float) textureHeight;
            texR = (clip->x + clip->w) * (float) imageWidth / (float) textureWidth;
            texB = (clip->y + clip->h) * (float) imageHeight / (float) textureHeight;
        }

        //Remove previous transformations
//        glLoadIdentity();
        glTranslatef(x, y, 0.f);
        bind();
        glBegin(GL_QUADS);
        glTexCoord2f(texL, texT);
        glVertex2f(0.f, 0.f);
        glTexCoord2f(texR, texT);
        glVertex2f(width, 0.f);
        glTexCoord2f(texR, texB);
        glVertex2f(width, height);
        glTexCoord2f(texL, texB);
        glVertex2f(0.f, height);
        glEnd();
        unbind();
        glTranslatef(-x, -y, 0.f);
    }
}

void Texture::render(float x, float y, float scale, FRect *clip) {
    render(x, y, (float) imageWidth * scale, (float) imageHeight * scale, clip);
}

Texture::~Texture() {
    free();
}

GLuint Texture::getTextureId() const {
    return textureID;
}

GLuint Texture::getTextureWidth() const {
    return textureWidth;
}

GLuint Texture::getTextureHeight() const {
    return textureHeight;
}

GLuint Texture::getImageWidth() const {
    return imageWidth;
}

GLuint Texture::getImageHeight() const {
    return imageHeight;
}
