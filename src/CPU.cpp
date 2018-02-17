#include <iostream>
#include <iomanip>
#include "CPU.h"
#include "Commands.h"
using namespace std;

CPU::CPU()
{
    memory = new type_com [16384]();

    com[0] = new MOVI();
    com[1] = new MOVF();
    com[2] = new ADDI();
    com[3] = new ADDF();
    com[4] = new SUBI();
    com[5] = new SUBF();
    com[6] = new MULI();
    com[7] = new MULF();
    com[8] = new DIVI();
    com[9] = new DIVF();
    com[10] = new CMPI();
    com[11] = new CMPF();
    com[16] = new MOVLI();
    com[17] = new MOVLF();
    com[18] = new ADDLI();
    com[19] = new ADDLF();
    com[20] = new SUBLI();
    com[21] = new SUBLF();
    com[22] = new MULLI();
    com[23] = new MULLF();
    com[24] = new DIVLI();
    com[25] = new DIVLF();
    com[26] = new CMPLI();
    com[27] = new CMPLF();
    com[48] = new BEQ();
    com[49] = new BNE();
    com[50] = new BLT();
    com[51] = new BGE();
    com[52] = new BLE();
    com[53] = new BGT();
    com[56] = new BR();
    com[57] = new BSR();
    com[58] = new RET();
    com[59] = new STOP();
}

void CPU::set_IP(int ip)
{
    IP = ip;
}

void CPU::output(int copr)
{
    if(copr < 32)
    {
        cout<<R[15].i<<") ";
        if(copr != 11 && copr != 10 && copr != 26 && copr != 27)
        {
            cout<<"R["<<memory[R[15].i].f1.a<<"] = ";
            if(copr % 2 == 0)
                cout<<R[memory[R[15].i].f1.a].i<<"\n";
            else
                cout<<R[memory[R[15].i].f1.a].f<<"\n";
        }
        else
            cout<<"N = "<<N<<"  "<<"Z = "<<Z<<"\n";
    }
}

void CPU::interpreter()
{
    R[15].i = IP;
    int copr;
    do
    {
        copr = memory[R[15].i].f5.copr;
        com[copr]->operator()(*this);
        output(copr);
        R[15].i ++;
    }while(copr != 59);
}

void CPU::reset()
{
    delete[] memory;
    memory = new type_com [16384];
}

CPU::~CPU()
{}
