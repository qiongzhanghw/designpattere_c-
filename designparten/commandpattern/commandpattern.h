#ifndef COMMANDPATTERN_H_INCLUDED
#define COMMANDPATTERN_H_INCLUDED
#include <iostream>
#include <typeinfo>
//#include <list>
#include <map>

using namespace std;

enum RECEIVE_ENUM
{
    DEVELOPER_ROLE = 1,
    SYSDESIGN_ROLE,
    TEST_ROLE,
    MODULDESIGN_ROLE,
    OPERATOR_ROLE
};

class AbsReceiver
{
private:
    string receivername;
public:
    virtual void DoJobWork() = 0;
    AbsReceiver(string workname);
    string GetReceiverName();
};
//开发
class DevelpReceiver:public AbsReceiver
{
public:
    DevelpReceiver(string workname);
    void DoJobWork();
};
//测试
class TestReceiver:public AbsReceiver
{
public:
    TestReceiver(string workname);
    void DoJobWork();
};
//SE
class SysDesinReceiver:public AbsReceiver
{
public:
    SysDesinReceiver(string workname);
    void DoJobWork();
};
//MDE
class ModuleDesinReceiver:public AbsReceiver
{
public:
    ModuleDesinReceiver(string workname);
    void DoJobWork();
};

//维护
class OperateorReceiver:public AbsReceiver
{
public:
    OperateorReceiver(string workname);
    void DoJobWork();
};

class AbsCommand
{
protected:
    string commandname;
    multimap<RECEIVE_ENUM, AbsReceiver*> Receiverlist;
    void SEAnalysisRequirement();
    void SWEDevelopRequirement();
    void MDEAnalysisRequirement();
    void TSETestRequirement();
    void OPEOperateRequirement();
public:
    void AddCommandReceiver(AbsReceiver* addreceiver);
    virtual void Execute() = 0;
};
//开发需求
class DevlopRequest:public AbsCommand
{
public:
    DevlopRequest();
    void Execute();
};
//特性beta
class FetrueBetaRequest:public AbsCommand
{
public:
    FetrueBetaRequest();
    void Execute();
};

//处理网上问题
class ProblemRequest:public AbsCommand
{
public:
    ProblemRequest();
    void Execute();
};

class ProjectManager
{
private:
    AbsCommand* DoCommand;
    string ownername;
public:
    ProjectManager(string name);
    void ReceiveCommand(AbsCommand* rececommand);
    void ExecuteCommand();
};

#endif // COMMANDPATTERN_H_INCLUDED
