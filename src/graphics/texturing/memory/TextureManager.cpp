//
// Created by goon on 17.05.2021.
//

#include "TextureManager.h"
#include "../../../util/misc_functions.h"
#include <IL/il.h>
#include <IL/ilu.h>

//TODO: fit new textures in free spaces
GLuint TextureManager::power_of_two(GLuint num) {
    if (num != 0) {
        num--;
        num |= (num >> 1);
        num |= (num >> 2);
        num |= (num >> 4);
        num |= (num >> 8);
        num |= (num >> 16);
        num++;
    }
    return num;
}

Texture *TextureManager::makeCheckTexture(int width, int height) {
    GLuint checkImage[width * height];
    unsigned int i, j, c;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            auto *colors = (GLubyte *) &checkImage[i * width + j];
            c = ((i & 0x8) ^ (j & 0x8)) * 255;
            colors[0] = (GLubyte) c;
            colors[1] = (GLubyte) 0;
            colors[2] = (GLubyte) c;
            colors[3] = (GLubyte) 255;
        }
    }
    auto *texture = new Texture();
    texture->loadPixels(checkImage, width, height, width, height);
    return texture;
}

//TODO: store textures and return them instead of loading again
Texture *TextureManager::loadTextureFromFile(const std::string &path) {
    Texture *texture = nullptr;
    bool loaded = false;
    ILuint imgID = 0;
    ilGenImages(1, &imgID);
    ilBindImage(imgID);
    ILboolean success = ilLoadImage(path.c_str());
    if (success == IL_TRUE) {
        //Convert image to RGBA format
        success = ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
        if (success == IL_TRUE) {
            loaded = true;
            auto imgWidth = (GLuint) ilGetInteger(IL_IMAGE_WIDTH);
            auto imgHeight = (GLuint) ilGetInteger(IL_IMAGE_HEIGHT);

            auto texWidth = power_of_two(imgWidth);
            auto texHeight = power_of_two(imgHeight);

            //If image is the wrong size
            if (imgWidth != texWidth || imgHeight != texHeight) {
                //Place image on the top left of a texture
                iluImageParameter(ILU_PLACEMENT, ILU_UPPER_LEFT);
                //Resize texture
                iluEnlargeCanvas((int) texWidth, (int) texHeight, 1);
            }
            texture = new Texture();
            texture->loadPixels((GLuint *) ilGetData(), ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT),
                                (int) imgWidth,
                                (int) imgHeight);
        }
        //Delete file from memory
        ilDeleteImages(1, &imgID);
    }

    if (!loaded) {
        texture = makeCheckTexture(64, 64);
    }
    return texture;
}


