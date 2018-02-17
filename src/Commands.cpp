#include <iostream>
#include <math.h>
#include "Commands.h"
#include "CPU.h"

 void MOVI::execute(CPU &p1)    //����� �������� 0
{
    int a = p1.memory[p1.R[15].i].f1.a;
    int c = p1.memory[p1.R[15].i].f1.c;
    p1.R[a].i = p1.R[c].i;
}

 void MOVF::execute(CPU &p1)    //����� �������� 1
{
    int a = p1.memory[p1.R[15].i].f1.a;
    int c = p1.memory[p1.R[15].i].f1.c;
    p1.R[a].f = p1.R[c].f;
}

 void ADDI::execute(CPU &p1)    //����� �������� 2
{
    int a = p1.memory[p1.R[15].i].f1.a;
    int b = p1.memory[p1.R[15].i].f1.b;
    int c = p1.memory[p1.R[15].i].f1.c;
    p1.R[a].i = p1.R[b].i + p1.R[c].i;
}

 void ADDF::execute(CPU &p1)    //����� �������� 3
{
    int a = p1.memory[p1.R[15].i].f1.a;
    int b = p1.memory[p1.R[15].i].f1.b;
    int c = p1.memory[p1.R[15].i].f1.c;
    p1.R[a].f = p1.R[b].f + p1.R[c].f;
}

void SUBI::execute(CPU &p1)     //����� �������� 4
{
    int a = p1.memory[p1.R[15].i].f1.a;
    int b = p1.memory[p1.R[15].i].f1.b;
    int c = p1.memory[p1.R[15].i].f1.c;
    p1.R[a].i = p1.R[b].i - p1.R[c].i;
}

void SUBF::execute(CPU &p1)     //����� �������� 5
{
    int a = p1.memory[p1.R[15].i].f1.a;
    int b = p1.memory[p1.R[15].i].f1.b;
    int c = p1.memory[p1.R[15].i].f1.c;
    p1.R[a].f = p1.R[b].f - p1.R[c].f;
}

void MULI::execute(CPU &p1)     //����� �������� 6
{
    int a = p1.memory[p1.R[15].i].f1.a;
    int b = p1.memory[p1.R[15].i].f1.b;
    int c = p1.memory[p1.R[15].i].f1.c;
    p1.R[a].i = p1.R[b].i * p1.R[c].i;
}

void MULF::execute(CPU &p1)     //����� �������� 7
{
    int a = p1.memory[p1.R[15].i].f1.a;
    int b = p1.memory[p1.R[15].i].f1.b;
    int c = p1.memory[p1.R[15].i].f1.c;
    p1.R[a].f = p1.R[b].f * p1.R[c].f;
}

void DIVI::execute(CPU &p1)     //����� �������� 8
{
    int a = p1.memory[p1.R[15].i].f1.a;
    int b = p1.memory[p1.R[15].i].f1.b;
    int c = p1.memory[p1.R[15].i].f1.c;
    p1.R[a].i = p1.R[b].i / p1.R[c].i;
}

void DIVF::execute(CPU &p1)     //����� �������� 9
{
    int a = p1.memory[p1.R[15].i].f1.a;
    int b = p1.memory[p1.R[15].i].f1.b;
    int c = p1.memory[p1.R[15].i].f1.c;
    p1.R[a].f = p1.R[b].f / p1.R[c].f;
}

void CMPI::execute(CPU &p1)     //����� �������� 10
{
    int b = p1.memory[p1.R[15].i].f1.b;
    int c = p1.memory[p1.R[15].i].f1.c;
    p1.Z = (p1.R[b].i == p1.R[c].i);
    p1.N = (p1.R[b].i < p1.R[c].i);
}

void CMPF::execute(CPU &p1)     //����� �������� 11
{
    int b = p1.memory[p1.R[15].i].f1.b;
    int c = p1.memory[p1.R[15].i].f1.c;
    p1.Z = (fabs(p1.R[b].f - p1.R[c].f) < 0.000000001);
    p1.N = (p1.R[b].f < p1.R[c].f);
}

void MOVLI::execute(CPU &p1)    //����� �������� 16
{
    int a = p1.memory[p1.R[15].i].f2.a;
    int im = p1.memory[p1.R[15].i].f2.im;
    p1.R[a].i = p1.memory[im].i;
}

void MOVLF::execute(CPU &p1)    //����� �������� 17
{
    int a = p1.memory[p1.R[15].i].f2.a;
    int im = p1.memory[p1.R[15].i].f2.im;
    p1.R[a].f = p1.memory[im].f;
}

void ADDLI::execute(CPU &p1)    //����� �������� 18
{
    int a = p1.memory[p1.R[15].i].f2.a;
    int b = p1.memory[p1.R[15].i].f2.b;
    int im = p1.memory[p1.R[15].i].f2.im;
    p1.R[a].i = p1.R[b].i + p1.memory[im].i;
}

void ADDLF::execute(CPU &p1)    //����� �������� 19
{
    int a = p1.memory[p1.R[15].i].f2.a;
    int b = p1.memory[p1.R[15].i].f2.b;
    int im = p1.memory[p1.R[15].i].f2.im;
    p1.R[a].f = p1.R[b].f + p1.memory[im].f;
}

void SUBLI::execute(CPU &p1)    //����� �������� 20
{
    int a = p1.memory[p1.R[15].i].f2.a;
    int b = p1.memory[p1.R[15].i].f2.b;
    int im = p1.memory[p1.R[15].i].f2.im;
    p1.R[a].i = p1.R[b].i - p1.memory[im].i;
}

void SUBLF::execute(CPU &p1)    //����� �������� 21
{
    int a = p1.memory[p1.R[15].i].f2.a;
    int b = p1.memory[p1.R[15].i].f2.b;
    int im = p1.memory[p1.R[15].i].f2.im;
    p1.R[a].f = p1.R[b].f - p1.memory[im].f;
}

void MULLI::execute(CPU &p1)    //����� �������� 22
{
    int a = p1.memory[p1.R[15].i].f2.a;
    int b = p1.memory[p1.R[15].i].f2.b;
    int im = p1.memory[p1.R[15].i].f2.im;
    p1.R[a].i = p1.R[b].i * p1.memory[im].i;
}

void MULLF::execute(CPU &p1)    //����� �������� 23
{
    int a = p1.memory[p1.R[15].i].f2.a;
    int b = p1.memory[p1.R[15].i].f2.b;
    int im = p1.memory[p1.R[15].i].f2.im;
    p1.R[a].f = p1.R[b].f * p1.memory[im].f;
}

void DIVLI::execute(CPU &p1)    //����� �������� 24
{
    int a = p1.memory[p1.R[15].i].f2.a;
    int b = p1.memory[p1.R[15].i].f2.b;
    int im = p1.memory[p1.R[15].i].f2.im;
    p1.R[a].i = p1.R[b].i / p1.memory[im].i;
}

void DIVLF::execute(CPU &p1)    //����� �������� 25
{
    int a = p1.memory[p1.R[15].i].f2.a;
    int b = p1.memory[p1.R[15].i].f2.b;
    int im = p1.memory[p1.R[15].i].f2.im;
    p1.R[a].f = p1.R[b].f / p1.memory[im].f;
}

void CMPLI::execute(CPU &p1)    //����� �������� 26
{
    int b = p1.memory[p1.R[15].i].f2.b;
    int im = p1.memory[p1.R[15].i].f2.im;
    p1.Z = (p1.R[b].i == p1.memory[im].i);
    p1.N = (p1.R[b].i < p1.memory[im].i);
}

void CMPLF::execute(CPU &p1)    //����� �������� 27
{
    int b = p1.memory[p1.R[15].i].f2.b;
    int im = p1.memory[p1.R[15].i].f2.im;
    p1.Z = (fabs(p1.R[b].f - p1.memory[im].f) < 0.000000001);
    p1.N = (p1.R[b].f < p1.memory[im].f);
}

void BEQ::execute(CPU &p1)      //����� �������� 48
{
    if(p1.Z)
        p1.R[15].i = p1.memory[p1.R[15].i].f4.disp-1;
}

void BNE::execute(CPU &p1)      //����� �������� 49
{
    if(!p1.Z)
        p1.R[15].i = p1.memory[p1.R[15].i].f4.disp-1;
}

void BLT::execute(CPU &p1)      //����� �������� 50
{
    if(p1.N)
        p1.R[15].i = p1.memory[p1.R[15].i].f4.disp-1;
}

void BGE::execute(CPU &p1)      //����� �������� 51
{
    if(!p1.N)
        p1.R[15].i = p1.memory[p1.R[15].i].f4.disp-1;
}

void BLE::execute(CPU &p1)      //����� �������� 52
{
    if(p1.Z || p1.N)
        p1.R[15].i = p1.memory[p1.R[15].i].f4.disp-1;
}

void BGT::execute(CPU &p1)      //����� �������� 53
{
    if(!(p1.Z || p1.N))
        p1.R[15].i = p1.memory[p1.R[15].i].f4.disp-1;
}

void BR::execute(CPU &p1)       //����� �������� 56
{
    p1.R[15].i = p1.memory[p1.R[15].i].f4.disp-1;
}

void BSR::execute(CPU &p1)      //��� �������� 57
{
    p1.R[14].i = p1.R[15].i;
    p1.R[15].i = p1.memory[p1.R[15].i].f4.disp-1;
}

void RET::execute(CPU &p1)      //��� �������� 58
{
    p1.R[15].i = p1.R[14].i;
}

void STOP::execute(CPU &p1)     //����� �������� 59
{
   return;
}
