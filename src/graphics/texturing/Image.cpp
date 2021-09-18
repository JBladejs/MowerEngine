//
// Created by goon on 7/7/21.
//

#include "Image.h"

Image::~Image() {
    //TODO: move ownership of textures to TextureManager
    delete texture;
    texture = nullptr;
}

Texture &Image::getTexture() {
    return *texture;
}
