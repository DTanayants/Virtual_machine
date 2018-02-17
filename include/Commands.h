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

class MOVI : public Commands                       //номер операции 0
{
    virtual void execute(CPU &p1);
};

class MOVF : public Commands                       //номер операции 1
{
    virtual void execute(CPU &p1);
};

class ADDI : public Commands                       //номер операции 2
{
    virtual void execute(CPU &p1);
};

class ADDF : public Commands                       //номер операции 3
{
    virtual void execute(CPU &p1);
};

class SUBI : public Commands                       //номер операции 4
{
   virtual void execute(CPU &p1);
};

class SUBF : public Commands                       //номер операции 5
{
    virtual void execute(CPU &p1);
};

class MULI : public Commands                       //номер операции 6
{
    virtual void execute(CPU &p1);
};

class MULF : public Commands                       //номер операции 7
{
   virtual void execute(CPU &p1);
};

class DIVI : public Commands                       //номер операции 8
{
    virtual void execute(CPU &p1);
};

class DIVF : public Commands                       //номер операции 9
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


class MOVLI : public Commands                      //номер операции 16
{
   virtual void execute(CPU &p1);
};

class MOVLF : public Commands                      //номер операции 17
{
    virtual void execute(CPU &p1);
};

class ADDLI : public Commands                       //номер операции 2
{
    virtual void execute(CPU &p1);
};

class ADDLF : public Commands                       //номер операции 3
{
    virtual void execute(CPU &p1);
};

class SUBLI : public Commands                       //номер операции 4
{
   virtual void execute(CPU &p1);
};

class SUBLF : public Commands                       //номер операции 5
{
    virtual void execute(CPU &p1);
};

class MULLI : public Commands                       //номер операции 6
{
    virtual void execute(CPU &p1);
};

class MULLF : public Commands                       //номер операции 7
{
   virtual void execute(CPU &p1);
};

class DIVLI : public Commands                       //номер операции 8
{
    virtual void execute(CPU &p1);
};

class DIVLF : public Commands                       //номер операции 9
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

class BR : public Commands                         //джамп. номер операции 56
{
    virtual void execute(CPU &p1);
};

class STOP : public Commands
{
    virtual void execute(CPU &p1);
};

#endif // COMMANDS_H
