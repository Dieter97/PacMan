//
// Created by dieter on 24/03/18.
//

#include <SDL_timer.h>
#include "../../include/SDL/SDLTimer.h"
using namespace SDL;

SDLTimer::SDLTimer() {
    //Initialize the variables
    startTicks = 0;
    pausedTicks = 0;

    paused = false;
    started = false;

}

void SDLTimer::stop() {
    //Stop the timer
    started = false;

    //Unpause the timer
    paused = false;

    //Clear tick variables
    startTicks = 0;
    pausedTicks = 0;
}

void SDLTimer::start() {
    //Start the timer
    started = true;

    //Unpause the timer
    paused = false;

    //Get the current clock time
    startTicks = SDL_GetTicks();
    pausedTicks = 0;
}

void SDLTimer::pause() {
    //If the timer is running and isn't already paused
    if( started && !paused )
    {
        //Pause the timer
        paused = true;

        //Calculate the paused ticks
        pausedTicks = SDL_GetTicks() - startTicks;
        startTicks = 0;
    }
}

void SDLTimer::unpause() {
    //If the timer is running and paused
    if( started && paused )
    {
        //Unpause the timer
        paused = false;

        //Reset the starting ticks
        startTicks = SDL_GetTicks() - pausedTicks;

        //Reset the paused ticks
        pausedTicks = 0;
    }
}

int SDLTimer::getTicks() {
    //The actual timer time
    Uint32 time = 0;

    //If the timer is running
    if( started )
    {
        //If the timer is paused
        if( paused )
        {
            //Return the number of ticks when the timer was paused
            time = pausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            time = SDL_GetTicks() - startTicks;
        }
    }

    return time;
}

bool SDLTimer::isStarted() {
    return started;
}

bool SDLTimer::isPaused() {
    return paused && started;
}

