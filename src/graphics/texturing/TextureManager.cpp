//
// Created by goon on 17.05.2021.
//

#include "TextureManager.h"
#include <IL/il.h>

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

//TODO: store textures and return them instead of loading again
Texture *TextureManager::loadTextureFromFile(const std::string& path) {
    Texture* texture = nullptr;
    bool loaded = false;
    ILuint imgID = 0;
    ilGenImages(1, &imgID);
    ilBindImage(imgID);
    ILboolean success = ilLoadImage(path.c_str());
    if (success == IL_TRUE) {
        //Convert image to RGBA format
        success = ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
        if (success == IL_TRUE) {
            //TODO: check if the texture was loaded
            loaded = true;
            texture = new Texture((GLuint*) ilGetData(), ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT));
        }
        //Delete file from memory
        ilDeleteImages(1, &imgID);
    }

    if (!loaded) {
        texture = makeCheckTexture(64, 64);
    }
    return texture;
}

//TODO: remove code duplication
//TODO: ensure encapsulation between texture and animation
Animation *TextureManager::loadSpriteSheetFromFile(const std::string &path, int columns, int rows) {
    Animation* texture = nullptr;
    bool loaded = false;
    ILuint imgID = 0;
    ilGenImages(1, &imgID);
    ilBindImage(imgID);
    ILboolean success = ilLoadImage(path.c_str());
    if (success == IL_TRUE) {
        //Convert image to RGBA format
        success = ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
        if (success == IL_TRUE) {
            //TODO: check if the texture was loaded
            loaded = true;
            texture = new Animation((GLuint*) ilGetData(), ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT), columns, rows);
        }
        //Delete file from memory
        ilDeleteImages(1, &imgID);
    }
    //TODO: add some kind of exception
    return texture;
}


