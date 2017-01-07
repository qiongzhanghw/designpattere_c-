#include "statepattern.h"

void LiftState::setliftcontext(Lift* currentcontext)
{
   this->LiftStateContext =  currentcontext;
}

void LiftOpenState::open()
{
    cout<<"open the lift......"<<endl;
}
void LiftOpenState::close()
{
    cout<<"lift actor close the door"<<endl;
    //切换状态到close状态
    this->LiftStateContext->setliftstate(&(this->LiftStateContext->liftclose));
    this->LiftStateContext->getliftstate()->close();

}
void LiftOpenState::run()
{
    cout<<"lift is open state now"<<endl;
}
void LiftOpenState::stop()
{
    cout<<"lift is open state now"<<endl;
}
void LiftOpenState::maintain()
{
    cout<<"lift actor maintain the door"<<endl;
    //切换状态到maintain状态
    this->LiftStateContext->setliftstate(&(this->LiftStateContext->liftmaintain));
    this->LiftStateContext->getliftstate()->maintain();

}

void LiftCloseState::open()
{
    cout<<"lift actor open the door"<<endl;
    //切换状态到open状态
    this->LiftStateContext->setliftstate(&(this->LiftStateContext->liftopen));
    /*执行动作*/
    this->LiftStateContext->getliftstate()->open();
}
void LiftCloseState::close()
{
    cout<<"close the lift......"<<endl;

}
void LiftCloseState::run()
{
    cout<<"lift actor run the lift"<<endl;
    //切换状态到open状态
    this->LiftStateContext->setliftstate(&(this->LiftStateContext->liftrun));
    /*执行动作*/
    this->LiftStateContext->getliftstate()->run();
}
void LiftCloseState::stop()
{
    cout<<"lift is close state now"<<endl;
}
void LiftCloseState::maintain()
{
    cout<<"lift actor maintain the door"<<endl;
    //切换状态到maintain状态
    this->LiftStateContext->setliftstate(&(this->LiftStateContext->liftmaintain));
    /*执行动作*/
    this->LiftStateContext->getliftstate()->maintain();

}

void LiftRunState::open()
{
    cout<<"lift is run state now"<<endl;
}
void LiftRunState::close()
{
    cout<<"lift is run state now"<<endl;

}
void LiftRunState::run()
{
    cout<<"run the lift......"<<endl;
}
void LiftRunState::stop()
{
    cout<<"lift actor stop the lift"<<endl;
    //切换状态到stop状态
    this->LiftStateContext->setliftstate(&(this->LiftStateContext->liftstop));
    /*执行动作*/
    this->LiftStateContext->getliftstate()->stop();
}
void LiftRunState::maintain()
{
    cout<<"lift actor maintain the door"<<endl;
    //切换状态到maintain状态
    this->LiftStateContext->setliftstate(&(this->LiftStateContext->liftmaintain));
    /*执行动作*/
    this->LiftStateContext->getliftstate()->maintain();

}

void LiftStopState::open()
{
    cout<<"lift actor open the door"<<endl;
    //切换状态到open状态
    this->LiftStateContext->setliftstate(&(this->LiftStateContext->liftopen));
    /*执行动作*/
    this->LiftStateContext->getliftstate()->open();
}
void LiftStopState::close()
{
    cout<<"lift is stop state now"<<endl;
}
void LiftStopState::run()
{
    cout<<"lift is stop state now"<<endl;
}
void LiftStopState::stop()
{
    cout<<"stop the lift......"<<endl;
}
void LiftStopState::maintain()
{
    cout<<"lift actor maintain the door"<<endl;
    //切换状态到maintain状态
    this->LiftStateContext->setliftstate(&(this->LiftStateContext->liftmaintain));
    /*执行动作*/
    this->LiftStateContext->getliftstate()->maintain();
}


void LiftMaintainState::open()
{
    cout<<"lift actor maintain and open the door"<<endl;
    //切换状态到open状态
    this->LiftStateContext->setliftstate(&(this->LiftStateContext->liftopen));
    /*执行动作*/
    this->LiftStateContext->getliftstate()->open();
}
void LiftMaintainState::close()
{
    cout<<"lift actor maintain and close the door"<<endl;
    //切换状态到open状态
    this->LiftStateContext->setliftstate(&(this->LiftStateContext->liftclose));
    /*执行动作*/
    this->LiftStateContext->getliftstate()->close();
}
void LiftMaintainState::run()
{
    cout<<"lift actor maintain and run the lift"<<endl;
    //切换状态到open状态
    this->LiftStateContext->setliftstate(&(this->LiftStateContext->liftrun));
    /*执行动作*/
    this->LiftStateContext->getliftstate()->run();
}
void LiftMaintainState::stop()
{
    cout<<"lift actor maintain and stop the lift"<<endl;
    //切换状态到open状态
    this->LiftStateContext->setliftstate(&(this->LiftStateContext->liftstop));
    /*执行动作*/
    this->LiftStateContext->getliftstate()->stop();
}
void LiftMaintainState::maintain()
{
    cout<<"maintain the lift......"<<endl;
}

Lift::Lift()
{
    this->setliftstate(&(this->liftstop));
}
void Lift::open()
{
    this->liftcurrentstae->open();
}
void Lift::close()
{
    this->liftcurrentstae->close();
}
void Lift::run()
{
    this->liftcurrentstae->run();
}
void Lift::stop()
{
    this->liftcurrentstae->stop();
}
void Lift::maintain()
{
    this->liftcurrentstae->maintain();
}

void Lift::setliftstate(LiftState* currentliftstae)
{
    //更新当前状态
    this->liftcurrentstae = currentliftstae;
    //同时保存上下文
    this->liftcurrentstae->setliftcontext(this);
}
LiftState* Lift::getliftstate()
{
    return this->liftcurrentstae;
}
