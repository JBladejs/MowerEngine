//
// Created by goon on 18.05.2021.
//

#include <iostream>
#include "Animation.h"
#include "memory/TextureManager.h"

Animation::Animation(const std::string& path, int columns, int rows, int speed)
    : super(TextureManager::loadTextureFromFile(path)), columns(columns), rows(rows) {
    frame = 0;
    real_frame = 0;
    frames = columns * rows;
    frame_width = 1.f / (float) columns;
    frame_height = 1.f / (float) rows;
    //TODO: get that value from the engine instead of using 60
    //TODO: make that calculation every frame (based on delta time) for framerate independence
    skip = (float) speed * 0.0166666f;
}

//TODO: move this to render after adding delta time
void Animation::update() {
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
}

void Animation::render(float x, float y, float scale) {
    render(x, y, (float) texture->getImageWidth() * scale, (float) texture->getImageHeight() * scale);
}

void Animation::render(float x, float y) {
    render(x, y, 1.f);
}
