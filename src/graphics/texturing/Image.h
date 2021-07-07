//
// Created by goon on 7/7/21.
//

#ifndef MOWERENGINE_IMAGE_H
#define MOWERENGINE_IMAGE_H

#include "memory/Texture.h"

class Image {
protected:
    Texture* texture;
public:
    explicit Image(Texture* texture): texture(texture) {};
    virtual ~Image();
    Texture* getTexture();
    virtual void update() = 0;
    virtual void render(float x, float y) = 0;
    virtual void render(float x, float y, float scale) = 0;
    virtual void render(float x, float y, float width, float height) = 0;
};

#endif //MOWERENGINE_IMAGE_H
