//
// Created by dieter on 24/03/18.
//

#ifndef GAMETEST_TIMER_H
#define GAMETEST_TIMER_H

namespace logic {
    class Timer {
    public:
        //Initializes variables
        Timer() = default;

        //The various clock actions
        virtual void start() = 0;

        virtual void stop() = 0;

        virtual void pause() = 0;

        virtual void unpause() = 0;

        //Gets the timer's time
        virtual int getTicks() = 0;

        //Checks the status of the timer
        virtual bool isStarted() = 0;

        virtual bool isPaused() = 0;
    };
}


#endif //GAMETEST_TIMER_H
