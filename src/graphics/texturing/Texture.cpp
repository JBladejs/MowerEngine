//
// Created by JJBla on 4/9/2021.
//

#include "Texture.h"

#include <iostream>
//TODO: make another class representing visual texture (not a direct representation of loaded image)
//TODO: move "constructor" to another method, returning bool
//TODO: add non-power-of-two textures
Texture::Texture(GLuint *pixels, int texWidth, int texHeight, int imgWidth, int imgHeight): textureWidth(texWidth), textureHeight(texHeight), imageHeight(imgHeight), imageWidth(imgWidth) {
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
    std::cout << width << " " << height << " " << textureWidth << " " << textureHeight << std::endl;
    if (textureID != 0) {
        //TODO: use GL data types
        float texL = 0.f;
        float texR = (float) imageWidth / (float) textureWidth;
        float texT = 0.f;
        float texB = (float) imageHeight / (float) textureHeight;

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
//        glLoadIdentity();
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
