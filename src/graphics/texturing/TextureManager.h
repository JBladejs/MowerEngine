//
// Created by goon on 17.05.2021.
//

#ifndef MOWERENGINE_TEXTUREMANAGER_H
#define MOWERENGINE_TEXTUREMANAGER_H

//TODO: clean up imports
#include "../animation/Animation.h"
#include <string>

class TextureManager {
public:
    static Texture* makeCheckTexture(int width, int height);
    static Texture* loadTextureFromFile(const std::string& path);
    static Animation* loadSpriteSheetFromFile(const std::string& path, int columns, int rows);
};

#endif //MOWERENGINE_TEXTUREMANAGER_H
