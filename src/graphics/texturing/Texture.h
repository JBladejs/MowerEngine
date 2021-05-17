//
// Created by JJBla on 4/9/2021.
//

#ifndef MOWERENGINE_TEXTURE_H
#define MOWERENGINE_TEXTURE_H

#include<GL/glu.h>

class Texture {
private:
    GLuint textureWidth, textureHeight;
    GLuint textureID;
    void free();
    void bind() const;
    static void unbind();
public:
    Texture(GLuint* pixels, int width, int height);
    ~Texture();
    void render(float x, float y, float width, float height);
    void render(float x, float y, float scale = 1.f) {
        render(x, y, textureWidth * scale, textureHeight * scale);
    }
};

#endif //MOWERENGINE_TEXTURE_H
