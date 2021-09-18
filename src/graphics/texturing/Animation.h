//
// Created by goon on 18.05.2021.
//

#ifndef MOWERENGINE_ANIMATION_H
#define MOWERENGINE_ANIMATION_H


#include "memory/Texture.h"
#include "Image.h"
#include <string>

class Animation : public Image {
private:
    typedef Image super;
    int columns;
    int rows;
    int frame;
    int real_frame;
    int frames;
    float skip;
    float frame_width;
    float frame_height;
public:
//    TODO: add skipped sprite spaces
//    TODO: consider making fps a float
    Animation(const std::string &path, int columns, int rows, int speed);

    void update() override;

    void render(float x, float y) override;

    void render(float x, float y, float scale) override;

    void render(float x, float y, float width, float height) override;
};


#endif //MOWERENGINE_ANIMATION_H
