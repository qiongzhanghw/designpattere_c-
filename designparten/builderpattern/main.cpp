#include "builderpattern.h"

int main()
{
    SuvCarDirect* suvdirectacor = new SuvCarDirect();

    /*�ж�ý����Ϣ��SUV*/
    AbstractCarBuilder* suvcarbuilder = new SuvBuilder();

    suvdirectacor->Construct1(suvcarbuilder);

    ProductCar* suvcar1 = suvcarbuilder->getProduct();

    suvcar1->ShowCarConfigure();
    /*û�ж�ý���SUV */
    AbstractCarBuilder* suvcarbuilder1 = new SuvBuilder();

    suvdirectacor->Construct2(suvcarbuilder1);

    ProductCar* suvcar2 = suvcarbuilder1->getProduct();

    suvcar2->ShowCarConfigure();

    MpvCarDirect* mpvdirectacor = new MpvCarDirect();

    /*�ж�ý����Ϣ��MPV*/
    AbstractCarBuilder* mpvcarbuilder = new MpvBuilder();

    mpvdirectacor->Construct1(mpvcarbuilder);

    ProductCar* mpvcar1 = mpvcarbuilder->getProduct();

    mpvcar1->ShowCarConfigure();
    /*û�ж�ý���MPV */
    AbstractCarBuilder* mpvcarbuilder1 = new MpvBuilder();

    mpvdirectacor->Construct2(mpvcarbuilder1);

    ProductCar* mpvcar2 = mpvcarbuilder1->getProduct();

    mpvcar2->ShowCarConfigure();

    return 0;
}
