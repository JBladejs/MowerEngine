//
// Created by goon on 17.05.2021.
//

#include "TextureManager.h"

Texture* TextureManager::makeCheckTexture(int width, int height) {
    GLuint checkImage[width * height];
    unsigned int i, j, c;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            auto* colors = (GLubyte*)&checkImage[i * width + j];
            c = ((i & 0x8) ^ (j & 0x8)) * 255;
            colors[0] = (GLubyte) c;
            colors[1] = (GLubyte) 0;
            colors[2] = (GLubyte) c;
            colors[3] = (GLubyte) 255;
        }
    }
    return new Texture(checkImage, width, height);
}
