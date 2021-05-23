//
// Created by goon on 18.05.2021.
//

#ifndef MOWERENGINE_ANIMATION_H
#define MOWERENGINE_ANIMATION_H


#include "../texturing/Texture.h"

class Animation: public Texture {
private:
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
    Animation(GLuint* pixels, int width, int height, int columns, int rows, int fps = 60);
    ~Animation() = default;
    void nextFrame();
    void render(float x, float y, float width, float height);
    void render(float x, float y, float scale = 1.f) {
        render(x, y, (float) textureWidth * scale, (float) textureHeight * scale);
    }
};


#endif //MOWERENGINE_ANIMATION_H
