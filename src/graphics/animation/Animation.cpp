//
// Created by goon on 18.05.2021.
//

#include <iostream>
#include "Animation.h"

Animation::Animation(GLuint *pixels, int width, int height, int columns, int rows) : Texture(pixels, width, height), columns(columns), rows(rows) {
    frame = 0;
    frames = columns * rows;
    frameWidth = 1.f / (float) columns;
    frameHeight = 1.f / (float) rows;
}

void Animation::nextFrame() {
    frame = (frame + 1) % frames;
}

void Animation::render(float x, float y, float width, float height) {
    int row = frame / columns;
    int column = frame % columns;

    FRect clip = FRect();
    clip.x = (float) column * frameWidth;
    clip.y = (float) row * frameHeight;
    clip.w = frameWidth;
    clip.h = frameHeight;

    Texture::render(x, y, width, height, &clip);
//    std::cout << frame << std::endl;
}
