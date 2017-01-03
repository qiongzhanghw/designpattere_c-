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
    CommonEmployee* employinst1 = new CommonEmployee("张三", idcounter++, 30);
    employinst1->setemployeerank(15);
    employinst1->setemployeesalary(10000);
    employinst1->setemployeejob("软件开发");
    this->employeelist.push_back(employinst1);

    CommonEmployee* employinst2 = new CommonEmployee("李四", idcounter++, 25);
    employinst2->setemployeerank(14);
    employinst2->setemployeesalary(9000);
    employinst2->setemployeejob("软件测试");
    this->employeelist.push_back(employinst2);

    CommonEmployee* employinst3 = new CommonEmployee("王五", idcounter++, 34);
    employinst3->setemployeerank(16);
    employinst3->setemployeesalary(16000);
    employinst3->setemployeejob("软件设计");
    this->employeelist.push_back(employinst3);

    CommonEmployee* employinst4 = new CommonEmployee("赵七", idcounter++, 40);
    employinst4->setemployeerank(17);
    employinst4->setemployeesalary(21000);
    employinst4->setemployeejob("架构设计");
    this->employeelist.push_back(employinst4);

    MidManager* managerinst1 = new MidManager("郭老", idcounter++, 45);
    managerinst1->setemployeerank(20);
    managerinst1->setemployeesalary(45000);
    managerinst1->setmanagerposition("控制器PDU部长");
    managerinst1->setdepartreport("开发效率提升30%");
    this->employeelist.push_back(managerinst1);

    MidManager* managerinst2 = new MidManager("老纪", idcounter++, 38);
    managerinst2->setemployeerank(18);
    managerinst2->setemployeesalary(35000);
    managerinst2->setmanagerposition("RNC协议开发部LM");
    managerinst2->setdepartreport("RPM问题下降30%");
    this->employeelist.push_back(managerinst2);

    MidManager* managerinst3 = new MidManager("郑总", idcounter++, 37);
    managerinst3->setemployeerank(18);
    managerinst3->setemployeesalary(38000);
    managerinst3->setmanagerposition("RRM算法开发部LM");
    managerinst3->setdepartreport("RRM问题下降30%");
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

    /* 设置要显示的视图30000<工资<100000*/
    searvisitSalary->SetSalaryCondition(100000, 30000, COMPARE_UP_LITTER, COMPARE_DOWN_LARGEER);

    SearchInfoVisit* searvisitRank = new SearchInfoVisit();

    /* 设置要显示的视图16<=职级<20*/
    searvisitRank->SetRankCondition(20, 16, COMPARE_UP_LITTER, COMPARE_DOWN_EQUAL_AND_LARGERR);

    SearchInfoVisit* searvisitAge = new SearchInfoVisit();

    /* 设置要显示的视图35<年龄<=40*/
    searvisitAge->SetAgeCondition(40, 35, COMPARE_UP_EQUAL_AND_LITTER, COMPARE_DOWN_LARGEER);

    SearchInfoVisit* searvisitcomplex = new SearchInfoVisit();

    /* 设置要显示的视图(35<=年龄<=40),(17<=职级<=20), (30000<工资<100000) */
    searvisitcomplex->SetAgeCondition(40, 35, COMPARE_UP_EQUAL_AND_LITTER, COMPARE_DOWN_EQUAL_AND_LARGERR);
    searvisitcomplex->SetRankCondition(20, 17, COMPARE_UP_EQUAL_AND_LITTER, COMPARE_DOWN_EQUAL_AND_LARGERR);
    searvisitcomplex->SetSalaryCondition(100000, 30000, COMPARE_UP_EQUAL_AND_LITTER, COMPARE_DOWN_EQUAL_AND_LARGERR);


    /* 基本访问*/
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

    cout<<"获取员工基本信息："  << endl;
    cout<< basicvisit->getemployeeinfo();

    cout<<"获取员工整体薪资情况："  << endl;
    cout<< payvisit->getPaymentinfo();

    cout<<"薪资大于30000元小于100000元的员工信息："  << endl;
    cout<< searvisitSalary->getemployeeinfo();

    cout<<"职级大于等于16级小于20级的员工信息："  << endl;
    cout<< searvisitRank->getemployeeinfo();

    cout<<"年龄大于35岁小于等于40岁的员工信息："  << endl;
    cout<< searvisitAge->getemployeeinfo();

    cout<<"35<=年龄<=40,17<=职级<=20,30000<工资<100000满足条件的员工信息："  << endl;
    cout<< searvisitcomplex->getemployeeinfo();




    return 0;
}
