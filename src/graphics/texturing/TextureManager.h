//
// Created by goon on 17.05.2021.
//

#ifndef MOWERENGINE_TEXTUREMANAGER_H
#define MOWERENGINE_TEXTUREMANAGER_H

#include "Texture.h"
#include <string>

class TextureManager {
public:
    static Texture* makeCheckTexture(int width, int height);
    static Texture* loadTextureFromFile(const std::string& path);
};

#endif //MOWERENGINE_TEXTUREMANAGER_H
