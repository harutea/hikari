#ifndef OBJECT_H
#define OBJECT_H

#include <hikari/vector/vector.h>

namespace hikari {

class Object {
private:
    Vector3 position;
    Vector3 velocity;
    Vector3 force;
    double mass;

public:
    Object();
    ~Object();
};

}

#endif