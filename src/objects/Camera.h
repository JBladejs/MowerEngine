//
// Created by goon on 24.05.2021.
//

#ifndef MOWERENGINE_CAMERA_H
#define MOWERENGINE_CAMERA_H

//TODO: make camera an entity
class Camera {
private:
    float x;
    float y;
    //TODO: check if z will be needed
    float z;
public:
    Camera();
    ~Camera() = default;
    [[nodiscard]] float getX() const;
    void setX(float value);
    [[nodiscard]] float getY() const;
    void setY(float value);
    [[nodiscard]] float getZ() const;
    void setZ(float value);
};


#endif //MOWERENGINE_CAMERA_H
