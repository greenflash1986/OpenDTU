#include "Clock_Impl_Atmega.h"

int Clock_Impl_Atmega::getTimezoneOffset() 
{
    return 0;
}

bool Clock_Impl_Atmega::getNow(time_t* nowPtr) 
{
    *nowPtr = 0;
    return false;
}