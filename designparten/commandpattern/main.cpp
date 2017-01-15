#include "commandpattern.h"

int main()
{
    ProjectManager* projecowner = new ProjectManager("zhangsansan");

    AbsCommand* pdevelopcommand = new DevlopRequest();
    AbsCommand* pbetacommand = new FetrueBetaRequest();
    AbsCommand* pproblemcommand = new ProblemRequest();

    AbsReceiver* pdeveloper1 = new DevelpReceiver("wang yi");
    AbsReceiver* pdeveloper2 = new DevelpReceiver("wang er");
    AbsReceiver* pdeveloper3 = new DevelpReceiver("wang san");
    AbsReceiver* pdeveloper4 = new DevelpReceiver("wang si");
    AbsReceiver* pdeveloper5 = new DevelpReceiver("wang wu");
    AbsReceiver* pdeveloper6 = new DevelpReceiver("wang liu");

    AbsReceiver* ptester1 = new TestReceiver("li yi");
    AbsReceiver* ptester2 = new TestReceiver("li er");
    AbsReceiver* ptester3 = new TestReceiver("li san");
    AbsReceiver* ptester4 = new TestReceiver("li si");
    AbsReceiver* ptester5 = new TestReceiver("li wu");
    AbsReceiver* ptester6 = new TestReceiver("li liu");

    AbsReceiver* psystemdesigner1 = new SysDesinReceiver("zhao yi");
    AbsReceiver* psystemdesigner2 = new SysDesinReceiver("zhao er");
    AbsReceiver* psystemdesigner3 = new SysDesinReceiver("zhao san");
    AbsReceiver* psystemdesigner4 = new SysDesinReceiver("zhao si");
    AbsReceiver* psystemdesigner5 = new SysDesinReceiver("zhao wu");
    AbsReceiver* psystemdesigner6 = new SysDesinReceiver("zhao liu");

    AbsReceiver* pmoduledesigner1 = new ModuleDesinReceiver("ti yi");
    AbsReceiver* pmoduledesigner2 = new ModuleDesinReceiver("ti er");
    AbsReceiver* pmoduledesigner3 = new ModuleDesinReceiver("ti san");
    AbsReceiver* pmoduledesigner4 = new ModuleDesinReceiver("ti si");
    AbsReceiver* pmoduledesigner5 = new ModuleDesinReceiver("ti wu");
    AbsReceiver* pmoduledesigner6 = new ModuleDesinReceiver("ti liu");

    AbsReceiver* poperatorer1 = new OperateorReceiver("tang yi");
    AbsReceiver* poperatorer2 = new OperateorReceiver("tang er");
    AbsReceiver* poperatorer3 = new OperateorReceiver("tang san");
    AbsReceiver* poperatorer4 = new OperateorReceiver("tang si");
    AbsReceiver* poperatorer5 = new OperateorReceiver("tang wu");
    AbsReceiver* poperatorer6 = new OperateorReceiver("tang liu");

    pdevelopcommand->AddCommandReceiver(poperatorer1);
    pdevelopcommand->AddCommandReceiver(poperatorer2);
    pdevelopcommand->AddCommandReceiver(pmoduledesigner1);
    pdevelopcommand->AddCommandReceiver(pmoduledesigner2);
    pdevelopcommand->AddCommandReceiver(psystemdesigner1);
    pdevelopcommand->AddCommandReceiver(psystemdesigner2);
    pdevelopcommand->AddCommandReceiver(ptester1);
    pdevelopcommand->AddCommandReceiver(ptester2);
    pdevelopcommand->AddCommandReceiver(pdeveloper1);
    pdevelopcommand->AddCommandReceiver(pdeveloper2);

    projecowner->ReceiveCommand(pdevelopcommand);
    projecowner->ExecuteCommand();


    pbetacommand->AddCommandReceiver(poperatorer3);
    pbetacommand->AddCommandReceiver(poperatorer4);
    pbetacommand->AddCommandReceiver(pmoduledesigner3);
    pbetacommand->AddCommandReceiver(pmoduledesigner4);
    pbetacommand->AddCommandReceiver(psystemdesigner3);
    pbetacommand->AddCommandReceiver(psystemdesigner4);
    pbetacommand->AddCommandReceiver(ptester3);
    pbetacommand->AddCommandReceiver(ptester4);
    pbetacommand->AddCommandReceiver(pdeveloper3);
    pbetacommand->AddCommandReceiver(pdeveloper4);

    projecowner->ReceiveCommand(pbetacommand);
    projecowner->ExecuteCommand();


    pproblemcommand->AddCommandReceiver(poperatorer5);
    pproblemcommand->AddCommandReceiver(poperatorer6);
    pproblemcommand->AddCommandReceiver(pmoduledesigner5);
    pproblemcommand->AddCommandReceiver(pmoduledesigner6);
    pproblemcommand->AddCommandReceiver(psystemdesigner5);
    pproblemcommand->AddCommandReceiver(psystemdesigner6);
    pproblemcommand->AddCommandReceiver(ptester5);
    pproblemcommand->AddCommandReceiver(ptester6);
    pproblemcommand->AddCommandReceiver(pdeveloper5);
    pproblemcommand->AddCommandReceiver(pdeveloper6);

    projecowner->ReceiveCommand(pbetacommand);
    projecowner->ExecuteCommand();

    return 0;
}
