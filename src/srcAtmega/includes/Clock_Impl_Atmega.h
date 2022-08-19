#pragma once

#include "Clock.h"

class Clock_Impl_Atmega : public Clock {
public:
    int getTimezoneOffset();
    bool getNow(time_t* nowPtr);
};