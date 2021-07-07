//
// Created by goon on 24.05.2021.
//

#ifndef MOWERENGINE_CAMERA_H
#define MOWERENGINE_CAMERA_H


class Camera {
private:
    float x;
    float y;
    //TODO: check if z will be needed
    float z;
public:
    Camera();
    ~Camera() = default;
    float getX() const;
    void setX(float value);
    float getY() const;
    void setY(float value);
    float getZ() const;
    void setZ(float value);
};


#endif //MOWERENGINE_CAMERA_H
