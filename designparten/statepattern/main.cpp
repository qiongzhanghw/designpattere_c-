#include "statepattern.h"
int main()
{
    Lift* Delift = new Lift();

    Delift->open();
    Delift->close();
    Delift->run();
    Delift->stop();
    Delift->open();
    Delift->run();
    Delift->stop();
    Delift->maintain();
    Delift->run();
    Delift->stop();
    Delift->open();
    Delift->close();
    Delift->run();
    Delift->stop();
    return 0;
}
