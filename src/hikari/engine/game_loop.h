#ifndef GAME_LOOP_H
#define GAME_LOOP_H

namespace hikari {

class GameLoop {
private:

public:
    void run();
    void processInput();
    void update();
    void render();
    void getRunningState();
};

}
#endif GAME_LOOP_H