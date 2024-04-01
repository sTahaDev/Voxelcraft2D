#ifndef COLLIDER_HPP
#define COLLIDER_HPP

#include <raylib.h>
#include <cmath>

class Collider{
public:
    static void addCollider(Rectangle &moveableObject, const Rectangle &staticObject);
};

#endif