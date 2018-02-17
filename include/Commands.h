#ifndef COMMANDS_H
#define COMMANDS_H
#include "CPU.h"

class Commands
{friend CPU;
    virtual void execute(CPU &p1) = 0;
public:
    virtual void operator()(CPU &p1)
    {
        execute(p1);
    };
};

class MOVI : public Commands                       //����� �������� 0
{
    virtual void execute(CPU &p1);
};

class MOVF : public Commands                       //����� �������� 1
{
    virtual void execute(CPU &p1);
};

class ADDI : public Commands                       //����� �������� 2
{
    virtual void execute(CPU &p1);
};

class ADDF : public Commands                       //����� �������� 3
{
    virtual void execute(CPU &p1);
};

class SUBI : public Commands                       //����� �������� 4
{
   virtual void execute(CPU &p1);
};

class SUBF : public Commands                       //����� �������� 5
{
    virtual void execute(CPU &p1);
};

class MULI : public Commands                       //����� �������� 6
{
    virtual void execute(CPU &p1);
};

class MULF : public Commands                       //����� �������� 7
{
   virtual void execute(CPU &p1);
};

class DIVI : public Commands                       //����� �������� 8
{
    virtual void execute(CPU &p1);
};

class DIVF : public Commands                       //����� �������� 9
{
    virtual void execute(CPU &p1);
};

class CMPI  : public Commands
{
    virtual void execute(CPU &p1);
};

class CMPF  : public Commands
{
    virtual void execute(CPU &p1);
};


class MOVLI : public Commands                      //����� �������� 16
{
   virtual void execute(CPU &p1);
};

class MOVLF : public Commands                      //����� �������� 17
{
    virtual void execute(CPU &p1);
};

class ADDLI : public Commands                       //����� �������� 2
{
    virtual void execute(CPU &p1);
};

class ADDLF : public Commands                       //����� �������� 3
{
    virtual void execute(CPU &p1);
};

class SUBLI : public Commands                       //����� �������� 4
{
   virtual void execute(CPU &p1);
};

class SUBLF : public Commands                       //����� �������� 5
{
    virtual void execute(CPU &p1);
};

class MULLI : public Commands                       //����� �������� 6
{
    virtual void execute(CPU &p1);
};

class MULLF : public Commands                       //����� �������� 7
{
   virtual void execute(CPU &p1);
};

class DIVLI : public Commands                       //����� �������� 8
{
    virtual void execute(CPU &p1);
};

class DIVLF : public Commands                       //����� �������� 9
{
    virtual void execute(CPU &p1);
};

class CMPLI  : public Commands
{
    virtual void execute(CPU &p1);
};

class CMPLF  : public Commands
{
    virtual void execute(CPU &p1);
};

class BEQ : public Commands
{
    virtual void execute(CPU &p1);
};

class BNE : public Commands
{
    virtual void execute(CPU &p1);
};

class BLT : public Commands
{
    virtual void execute(CPU &p1);
};

class BGE : public Commands
{
    virtual void execute(CPU &p1);
};

class BLE : public Commands
{
    virtual void execute(CPU &p1);
};

class BGT : public Commands
{
    virtual void execute(CPU &p1);
};

class BSR : public Commands
{
    virtual void execute(CPU &p1);
};

class RET : public Commands
{
    virtual void execute(CPU &p1);
};

class BR : public Commands                         //�����. ����� �������� 56
{
    virtual void execute(CPU &p1);
};

class STOP : public Commands
{
    virtual void execute(CPU &p1);
};

#endif // COMMANDS_H
