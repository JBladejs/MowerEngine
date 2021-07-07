//
// Created by goon on 18.05.2021.
//

#ifndef MOWERENGINE_ANIMATION_H
#define MOWERENGINE_ANIMATION_H


#include "memory/Texture.h"
#include "Image.h"

//TODO: Make this use Texture as a class member, not as a parent
class Animation: public Image {
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
    Animation(GLuint *pixels, int texWidth, int texHeight, int imgWidth, int imgHeight, int columns, int rows, int speed);
    void update() override;
    void render(float x, float y) override;
    void render(float x, float y, float scale) override;
    void render(float x, float y, float width, float height) override;
};


#endif //MOWERENGINE_ANIMATION_H
