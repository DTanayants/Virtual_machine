#ifndef CPU_H
#define CPU_H

struct rr                           //регистр = регистр @ регистр
{
    unsigned type  : 2;             //тип команды
    unsigned op    : 4;
    unsigned a     : 4;             //первый регистр
    unsigned b     : 4;             //второй регистр
    unsigned       : 10;            //пустое пространство
    unsigned c     : 4;             //третий регистр
};

struct rn                           //регистр = регистр @ число
{
    unsigned type  : 2;             //тип команды
    unsigned op    : 4;
    unsigned a     : 4;             //первый регистр
    unsigned b     : 4;             //второй регистр
    unsigned im    : 18;            //число, которое помещ
};

struct rd                           //
{
    unsigned type  : 2;             //тип команды
    unsigned op    : 4;
    unsigned a     : 4;
    unsigned b     : 4;
    unsigned disp  : 18;
};

struct d                            //условное(безусловное) смещение
{
    unsigned type  : 2;             //тип команды
    unsigned op    : 4;
    unsigned disp  : 26;
};

struct gen_type                     //определение кода команды
{
    unsigned copr  : 6;
    unsigned arg   : 26;
};

union type_com                      //вариации состовляющих ячейки памяти
{
    rr f1;
    rn f2;
    rd f3;
    d  f4;
    gen_type f5;
    float f;
    int i;
};

union ROM                           //массив регистров
{
    float f;
    int i;
};

class Commands;

class CPU
{
        int IP;

    public:
        bool Z, N;                  //флаги состояния(Z - ноль ли. N - отрицательно ли)
        ROM R[16];
        CPU();
        virtual ~CPU();
        type_com *memory;
        void interpreter();
        void reset();
        void set_IP(int ip);
        void output(int copr);
        Commands *com[59];
};

#endif // CPU_H
