#ifndef VISTORPATTERN_H_INCLUDED
#define VISTORPATTERN_H_INCLUDED
#include <iostream>
using namespace std;

enum COMPARE_DOWN_ENUM
{
    COMPARE_DOWN_LARGEER = 1,
    COMPARE_DOWN_EQUAL_AND_LARGERR = 2,
    COMPARE_DOWN_BUTT
};

enum COMPARE_UP_ENUM
{
    COMPARE_UP_LITTER = 4,
    COMPARE_UP_EQUAL_AND_LITTER = 5,
    COMPARE_UP_BUTT
};

class IVisitInterface;

class AbstractEmployee
{
private:
    string employname;
    unsigned int salary;
    unsigned int id;
    unsigned int age;
    unsigned int ranklevel;
public:

    AbstractEmployee(string name, unsigned int idvalue, unsigned int agevalue);
    string getemployeename();
    unsigned int getemployeeid();
    unsigned int getemployeesalary();
    unsigned int getemployeerank();
    unsigned int getemployage();

    void setemployeesalary(unsigned int salaryvalue);
    void setemployeerank(unsigned int rankvalue);
    void addemployeeage();


    virtual void accept(IVisitInterface* vistor) = 0;
};

class CommonEmployee:public AbstractEmployee
{

private:
    string jobinfo;
public:

    CommonEmployee(string name, unsigned int idvalue, unsigned int agevalue);

    string getemployeejob();

    void setemployeejob(string jobvalue);

    void accept(IVisitInterface* vistor);


};


class MidManager:public AbstractEmployee
{
private:
    string manageposition;
    string departmentreport;
public:
    MidManager(string name, unsigned int idvalue, unsigned int agevalue);
    string getmanagerposition();
    string getdepartreport();

    void setmanagerposition(string positioninfo);
    void setdepartreport(string report);

    void accept(IVisitInterface* vistor);
};

class IVisitInterface
{
public:

   virtual void visit(CommonEmployee* comemployee) = 0;
   virtual void visit(MidManager* comanager) = 0;
   virtual void resetvistinfo() = 0;

};

class AbstractBasicVisit:public IVisitInterface
{
public:

    virtual string getemployeeinfo() = 0;


};

class CommonVisit:public AbstractBasicVisit
{
protected:
    string commoninfo = "";
    void getCommonInfo(AbstractEmployee* employeeinst);
    void getEmployeeSpecialInfo(CommonEmployee* employeeinst);
    void getManageSpecialInfo(MidManager* employeeinst);
public:
    void visit(CommonEmployee *comemployee);
    void visit(MidManager *comanager);
    string getemployeeinfo();
    void resetvistinfo();
};


class AbstractPaymentVisit:public IVisitInterface
{
public:

    virtual string getPaymentinfo() = 0;
};

class PaymentVisit:public AbstractPaymentVisit
{
private:
    unsigned int totalemployeesalary = 0;
    unsigned int totalmanagersalary = 0;

public:
    void visit(CommonEmployee *comemployee);
    void visit(MidManager *comanager);
    string getPaymentinfo();
    void resetvistinfo();
};

class SearLogic
{
private:
    unsigned int compareUpvalue = 0xffffffff;
    unsigned int compareDownvalue = 0;
    unsigned int compareUplogic = COMPARE_UP_LITTER;
    unsigned int compareDownlogic = COMPARE_DOWN_LARGEER;
public:
    SearLogic();
    bool setcompareUPcondition(unsigned int value, COMPARE_UP_ENUM logic);
    bool setcompareDOWNcondition(unsigned int value, COMPARE_DOWN_ENUM logic);
    bool compareresult(unsigned int inputvalue);
    void resetcodition();
};
class SearchInfoVisit:public CommonVisit
{
private:
    SearLogic searchrank;
    SearLogic searsalary;
    SearLogic searchage;
    bool SetLogicCompareCondition(SearLogic &logicinst, unsigned int uplimit, unsigned int downlimit, COMPARE_UP_ENUM uplogic, COMPARE_DOWN_ENUM dnlogic);
    bool GetCompareResult(SearLogic &logicinst, unsigned int inputvalue);
    void ResetComparecondition(SearLogic &logicinst);
    bool VisitFilter(AbstractEmployee* abstracinst);
    void GetRankSalaryinfo(AbstractEmployee* employeeinst);
public:
    bool SetRankCondition(unsigned int uplimit, unsigned int downlimit, COMPARE_UP_ENUM uplogic, COMPARE_DOWN_ENUM dnlogic);
    bool SetSalaryCondition(unsigned int uplimit, unsigned int downlimit, COMPARE_UP_ENUM uplogic, COMPARE_DOWN_ENUM dnlogic);
    bool SetAgeCondition(unsigned int uplimit, unsigned int downlimit, COMPARE_UP_ENUM uplogic, COMPARE_DOWN_ENUM dnlogic);
    void ResetRankCondition();
    void ResetSalaryCondition();
    void ResetAgeCondition();
    void ResetAllCondition();
    void visit(CommonEmployee *comemployee);
    void visit(MidManager *comanager);
};

#endif // VISTORPATTERN_H_INCLUDED
