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
    //TODO: use these in texture and animation constructors (so you can just use a constructor instead of calling these functions)
    static Texture* loadTextureFromFile(const std::string& path);
    static Animation* loadSpriteSheetFromFile(const std::string& path, int columns, int rows, int speed = 60);
};

#endif //MOWERENGINE_TEXTUREMANAGER_H
