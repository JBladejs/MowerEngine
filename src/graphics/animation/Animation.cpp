//
// Created by goon on 18.05.2021.
//

#include <iostream>
#include "Animation.h"

Animation::Animation(GLuint *pixels, int width, int height, int columns, int rows, int speed) : columns(columns), rows(rows) {
    texture = new Texture(pixels, width, height);
    frame = 0;
    real_frame = 0;
    frames = columns * rows;
    frame_width = 1.f / (float) columns;
    frame_height = 1.f / (float) rows;
    //TODO: get that value from the engine instead of using 60
    //TODO: make that calculation every frame (based on delta time) for frame independence
    skip = (float) speed * 0.016666f;
}

//TODO: move this to render after adding delta time
void Animation::nextFrame() {
    real_frame = (real_frame + 1) % 60;
    frame = (int) ((float) real_frame * skip) % frames;
}

void Animation::render(float x, float y, float width, float height) {
    int row = frame / columns;
    int column = frame % columns;

    FRect clip = FRect();
    clip.x = (float) column * frame_width;
    clip.y = (float) row * frame_height;
    clip.w = frame_width;
    clip.h = frame_height;

    texture->render(x, y, width, height, &clip);
//    std::cout << frame << std::endl;
}

Texture *Animation::getTexture() {
    return texture;
}

Animation::~Animation() {
    delete texture;
    texture = nullptr;
}
