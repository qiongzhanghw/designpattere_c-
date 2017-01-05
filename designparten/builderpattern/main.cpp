#include "builderpattern.h"

int main()
{
    SuvCarDirect* suvdirectacor = new SuvCarDirect();

    /*有多媒体信息的SUV*/
    AbstractCarBuilder* suvcarbuilder = new SuvBuilder();

    suvdirectacor->Construct1(suvcarbuilder);

    ProductCar* suvcar1 = suvcarbuilder->getProduct();

    suvcar1->ShowCarConfigure();
    /*没有多媒体的SUV */
    AbstractCarBuilder* suvcarbuilder1 = new SuvBuilder();

    suvdirectacor->Construct2(suvcarbuilder1);

    ProductCar* suvcar2 = suvcarbuilder1->getProduct();

    suvcar2->ShowCarConfigure();

    MpvCarDirect* mpvdirectacor = new MpvCarDirect();

    /*有多媒体信息的MPV*/
    AbstractCarBuilder* mpvcarbuilder = new MpvBuilder();

    mpvdirectacor->Construct1(mpvcarbuilder);

    ProductCar* mpvcar1 = mpvcarbuilder->getProduct();

    mpvcar1->ShowCarConfigure();
    /*没有多媒体的MPV */
    AbstractCarBuilder* mpvcarbuilder1 = new MpvBuilder();

    mpvdirectacor->Construct2(mpvcarbuilder1);

    ProductCar* mpvcar2 = mpvcarbuilder1->getProduct();

    mpvcar2->ShowCarConfigure();

    return 0;
}
