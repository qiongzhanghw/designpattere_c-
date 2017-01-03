#include "vistorpattern.h"
#include <list>

class Client
{
public:

    list<AbstractEmployee* > employeelist;
    Client();
    list<AbstractEmployee* >& GetEmployeeList();

};

Client::Client()
{
    unsigned int idcounter =  0;

    this->employeelist.clear();
    CommonEmployee* employinst1 = new CommonEmployee("����", idcounter++, 30);
    employinst1->setemployeerank(15);
    employinst1->setemployeesalary(10000);
    employinst1->setemployeejob("�������");
    this->employeelist.push_back(employinst1);

    CommonEmployee* employinst2 = new CommonEmployee("����", idcounter++, 25);
    employinst2->setemployeerank(14);
    employinst2->setemployeesalary(9000);
    employinst2->setemployeejob("�������");
    this->employeelist.push_back(employinst2);

    CommonEmployee* employinst3 = new CommonEmployee("����", idcounter++, 34);
    employinst3->setemployeerank(16);
    employinst3->setemployeesalary(16000);
    employinst3->setemployeejob("������");
    this->employeelist.push_back(employinst3);

    CommonEmployee* employinst4 = new CommonEmployee("����", idcounter++, 40);
    employinst4->setemployeerank(17);
    employinst4->setemployeesalary(21000);
    employinst4->setemployeejob("�ܹ����");
    this->employeelist.push_back(employinst4);

    MidManager* managerinst1 = new MidManager("����", idcounter++, 45);
    managerinst1->setemployeerank(20);
    managerinst1->setemployeesalary(45000);
    managerinst1->setmanagerposition("������PDU����");
    managerinst1->setdepartreport("����Ч������30%");
    this->employeelist.push_back(managerinst1);

    MidManager* managerinst2 = new MidManager("�ϼ�", idcounter++, 38);
    managerinst2->setemployeerank(18);
    managerinst2->setemployeesalary(35000);
    managerinst2->setmanagerposition("RNCЭ�鿪����LM");
    managerinst2->setdepartreport("RPM�����½�30%");
    this->employeelist.push_back(managerinst2);

    MidManager* managerinst3 = new MidManager("֣��", idcounter++, 37);
    managerinst3->setemployeerank(18);
    managerinst3->setemployeesalary(38000);
    managerinst3->setmanagerposition("RRM�㷨������LM");
    managerinst3->setdepartreport("RRM�����½�30%");
    this->employeelist.push_back(managerinst3);

}
list<AbstractEmployee* >& Client::GetEmployeeList()
{
     return this->employeelist;
}
int main()
{
    Client TestClient;
    list<AbstractEmployee* >& EmploylistReference = TestClient.GetEmployeeList();
    list<AbstractEmployee* >::iterator EmployeeIt;

    AbstractBasicVisit* basicvisit = new CommonVisit();
    AbstractPaymentVisit* payvisit = new PaymentVisit();
    SearchInfoVisit* searvisitSalary = new SearchInfoVisit();

    /* ����Ҫ��ʾ����ͼ30000<����<100000*/
    searvisitSalary->SetSalaryCondition(100000, 30000, COMPARE_UP_LITTER, COMPARE_DOWN_LARGEER);

    SearchInfoVisit* searvisitRank = new SearchInfoVisit();

    /* ����Ҫ��ʾ����ͼ16<=ְ��<20*/
    searvisitRank->SetRankCondition(20, 16, COMPARE_UP_LITTER, COMPARE_DOWN_EQUAL_AND_LARGERR);

    SearchInfoVisit* searvisitAge = new SearchInfoVisit();

    /* ����Ҫ��ʾ����ͼ35<����<=40*/
    searvisitAge->SetAgeCondition(40, 35, COMPARE_UP_EQUAL_AND_LITTER, COMPARE_DOWN_LARGEER);

    SearchInfoVisit* searvisitcomplex = new SearchInfoVisit();

    /* ����Ҫ��ʾ����ͼ(35<=����<=40),(17<=ְ��<=20), (30000<����<100000) */
    searvisitcomplex->SetAgeCondition(40, 35, COMPARE_UP_EQUAL_AND_LITTER, COMPARE_DOWN_EQUAL_AND_LARGERR);
    searvisitcomplex->SetRankCondition(20, 17, COMPARE_UP_EQUAL_AND_LITTER, COMPARE_DOWN_EQUAL_AND_LARGERR);
    searvisitcomplex->SetSalaryCondition(100000, 30000, COMPARE_UP_EQUAL_AND_LITTER, COMPARE_DOWN_EQUAL_AND_LARGERR);


    /* ��������*/
    EmployeeIt = EmploylistReference.begin();
    while(EmployeeIt != TestClient.GetEmployeeList().end())
    {
        (*EmployeeIt)->accept(basicvisit);
        (*EmployeeIt)->accept(payvisit);
        (*EmployeeIt)->accept(searvisitSalary);
        (*EmployeeIt)->accept(searvisitRank);
        (*EmployeeIt)->accept(searvisitAge);
        (*EmployeeIt)->accept(searvisitcomplex);
        EmployeeIt++;
    }

    cout<<"��ȡԱ��������Ϣ��"  << endl;
    cout<< basicvisit->getemployeeinfo();

    cout<<"��ȡԱ������н�������"  << endl;
    cout<< payvisit->getPaymentinfo();

    cout<<"н�ʴ���30000ԪС��100000Ԫ��Ա����Ϣ��"  << endl;
    cout<< searvisitSalary->getemployeeinfo();

    cout<<"ְ�����ڵ���16��С��20����Ա����Ϣ��"  << endl;
    cout<< searvisitRank->getemployeeinfo();

    cout<<"�������35��С�ڵ���40���Ա����Ϣ��"  << endl;
    cout<< searvisitAge->getemployeeinfo();

    cout<<"35<=����<=40,17<=ְ��<=20,30000<����<100000����������Ա����Ϣ��"  << endl;
    cout<< searvisitcomplex->getemployeeinfo();




    return 0;
}
