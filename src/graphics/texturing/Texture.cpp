//
// Created by JJBla on 4/9/2021.
//

#include "Texture.h"

#include <iostream>

//TODO: move it to another method, returning bool
Texture::Texture(GLuint *pixels, int width, int height): textureWidth(width), textureHeight(height) {
    textureID = 0;

//    TODO: do some research about this line:
//    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &textureID);
//    TODO: find if this need its own method
    bind();

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureWidth,
                 textureHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 pixels);

//    TODO: find out about this
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                    GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_NEAREST);

    unbind();

    //TODO: add error checking
}

void Texture::free() {
    unbind();
    if (textureID != 0) {
        glDeleteTextures(1, &textureID);
        textureID = 0;
    }
}

Texture::~Texture() {
    free();
}

void Texture::bind() const {
    glBindTexture(GL_TEXTURE_2D, textureID);
}

void Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::render(float x, float y, float width, float height, FRect* clip) {
    if (textureID != 0) {
        float texL = 0.f;
        float texR = 1.f;
        float texT = 0.f;
        float texB = 1.f;

        if (clip != nullptr) {
//            texL = clip->x / textureWidth;
//            texT = clip->y / textureHeight;
//            texR = (clip->x + clip->w) / textureWidth;
//            texB = (clip->y + clip->h) / textureHeight;
            texL = clip->x;
            texT = clip->y;
            texR = clip->x + clip->w;
            texB = clip->y + clip->h;
        }

        //Remove previous transformations
        glLoadIdentity();
        glTranslatef(x, y, 0.f);
        bind();
        glBegin(GL_QUADS);
            glTexCoord2f(texL, texT); glVertex2f(0.f, 0.f);
            glTexCoord2f(texR, texT); glVertex2f(width, 0.f);
            glTexCoord2f(texR, texB); glVertex2f(width, height);
            glTexCoord2f(texL, texB); glVertex2f(0.f, height);
        glEnd();
        unbind();
    }
}
