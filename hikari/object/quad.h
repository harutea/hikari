#ifndef QUAD_H
#define QUAD_H

#include "object.h"

namespace hikari
{
    class Quad : public Object
    {
    private:
    public:
        Quad();
        ~Quad();
        void init();
        void render();
    }
}
#endif