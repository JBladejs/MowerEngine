//
// Created by Alan Ćwiek on 7/7/21.
//

#include "Sprite.h"
#include "memory/TextureManager.h"

Sprite::Sprite(const std::string &path) : super(TextureManager::loadTextureFromFile(path)) {}

void Sprite::update() {}

void Sprite::render(float x, float y, float width, float height) {
    texture->render(x, y, width, height);
}

void Sprite::render(float x, float y, float scale) {
    render(x, y, scale * (float) texture->getImageWidth(), scale * (float) texture->getImageHeight());
}

void Sprite::render(float x, float y) {
    render(x, y, 1.f);
}

