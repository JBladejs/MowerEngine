//
// Created by goon on 7/7/21.
//

#ifndef MOWERENGINE_SPRITE_H
#define MOWERENGINE_SPRITE_H

#include <string>
#include "Image.h"

class Sprite : public Image {
private:
    typedef Image super;
public:
    explicit Sprite(const std::string &path, bool colorKeyed = false, uint32_t color = 0x000000);
    void update() override;
    void render(float x, float y) override;
    void render(float x, float y, float scale) override;
    void render(float x, float y, float width, float height) override;
};

#endif //MOWERENGINE_SPRITE_H
