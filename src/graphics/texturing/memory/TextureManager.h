//
// Created by goon on 17.05.2021.
//

#ifndef MOWERENGINE_TEXTUREMANAGER_H
#define MOWERENGINE_TEXTUREMANAGER_H

#include "../Animation.h"
#include <string>

class TextureManager {
private:
    //TODO: move to a different file
    static GLuint power_of_two(GLuint num);

public:
    static Texture *makeCheckTexture(int width, int height);
    static Texture *loadTextureFromFile(const std::string &path, bool colorKeyed = false, uint32_t color = 0x000000);
};

#endif //MOWERENGINE_TEXTUREMANAGER_H
