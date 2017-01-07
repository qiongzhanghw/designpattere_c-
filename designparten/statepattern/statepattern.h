#ifndef STATEPATTERN_H_INCLUDED
#define STATEPATTERN_H_INCLUDED
#include <iostream>

using namespace std;

class Lift;

class LiftState
{
protected:
    Lift* LiftStateContext;
public:
    virtual void open() = 0;
    virtual void close() = 0;
    virtual void run() = 0;
    virtual void stop() = 0;
    virtual void maintain() = 0;
    void setliftcontext(Lift* currentcontext);
};

class LiftOpenState:public LiftState
{
public:
    void open();
    void close();
    void run();
    void stop();
    void maintain();
};

class LiftCloseState:public LiftState
{
public:
    void open();
    void close();
    void run();
    void stop();
    void maintain();
};

class LiftRunState:public LiftState
{
public:
    void open();
    void close();
    void run();
    void stop();
    void maintain();
};

class LiftStopState:public LiftState
{
public:
    void open();
    void close();
    void run();
    void stop();
    void maintain();
};

class LiftMaintainState:public LiftState
{
public:
    void open();
    void close();
    void run();
    void stop();
    void maintain();
};

class Lift
{
public:
   LiftOpenState liftopen;
   LiftCloseState liftclose;
   LiftRunState liftrun;
   LiftStopState liftstop;
   LiftMaintainState liftmaintain;
   LiftState* liftcurrentstae;

   Lift();
   void open();
   void close();
   void run();
   void stop();
   void maintain();
   void setliftstate(LiftState* currentliftstae);
   LiftState* getliftstate();
};

#endif // STATEPATTERN_H_INCLUDED
