#ifndef HANDLER_H
#define HANDLER_H

namespace hikari {

class EngineHandler {
private:

public:
    void processInput();
    void update();
    void render();
    void getRunningState();
};

}

#endif HANDLER_H