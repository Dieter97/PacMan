//
// Created by dieter on 24/03/18.
//

#ifndef GAMETEST_SDLTIMER_H
#define GAMETEST_SDLTIMER_H


#include "Timer.h"

class SDLTimer : public Timer{
private:
    //The clock time when the timer started
    int startTicks;

    //The ticks stored when the timer was paused
    int pausedTicks;

    //The timer status
    bool paused;
    bool started;
public:

    SDLTimer();
    //The various clock actions
    void start() override ;
    void stop() override ;
    void pause() override;
    void unpause() override;

    //Gets the timer's time
    int getTicks() override;

    //Checks the status of the timer
    bool isStarted() override;
    bool isPaused() override;
};


#endif //GAMETEST_SDLTIMER_H
