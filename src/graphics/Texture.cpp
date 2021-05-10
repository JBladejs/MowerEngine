//
// Created by JJBla on 4/9/2021.
//

#include "Texture.h"

#include <iostream>

void Texture::makeCheckImage() {
    unsigned int i, j, c;
    for (i = 0; i < textureHeight; i++) {
        for (j = 0; j < textureWidth; j++) {
            c = ((i & 0x8) ^ (j & 0x8)) * 255;
            std::cout << i << "-" << j << ": " << c << std::endl;
            checkImage[i][j][0] = (GLubyte) c;
            checkImage[i][j][1] = (GLubyte) 0;
            checkImage[i][j][2] = (GLubyte) c;
            checkImage[i][j][3] = (GLubyte) 255;
        }
    }
}

Texture::Texture() {
    textureID = 0;

    makeCheckImage();
//    TODO: do some research about this line:
//    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &textureID);
//    TODO: find if this need its own method
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureWidth,
                 textureHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 checkImage);

//    TODO: find out about this
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                    GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_NEAREST);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::free() {

}

Texture::~Texture() {
    //TODO: implement this
}

void Texture::bind() {
    glBindTexture(GL_TEXTURE_2D, textureID);
}