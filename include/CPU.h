#ifndef CPU_H
#define CPU_H

struct rr                           //������� = ������� @ �������
{
    unsigned type  : 2;             //��� �������
    unsigned op    : 4;
    unsigned a     : 4;             //������ �������
    unsigned b     : 4;             //������ �������
    unsigned       : 10;            //������ ������������
    unsigned c     : 4;             //������ �������
};

struct rn                           //������� = ������� @ �����
{
    unsigned type  : 2;             //��� �������
    unsigned op    : 4;
    unsigned a     : 4;             //������ �������
    unsigned b     : 4;             //������ �������
    unsigned im    : 18;            //�����, ������� �����
};

struct rd                           //
{
    unsigned type  : 2;             //��� �������
    unsigned op    : 4;
    unsigned a     : 4;
    unsigned b     : 4;
    unsigned disp  : 18;
};

struct d                            //��������(�����������) ��������
{
    unsigned type  : 2;             //��� �������
    unsigned op    : 4;
    unsigned disp  : 26;
};

struct gen_type                     //����������� ���� �������
{
    unsigned copr  : 6;
    unsigned arg   : 26;
};

union type_com                      //�������� ������������ ������ ������
{
    rr f1;
    rn f2;
    rd f3;
    d  f4;
    gen_type f5;
    float f;
    int i;
};

union ROM                           //������ ���������
{
    float f;
    int i;
};

class Commands;

class CPU
{
        int IP;

    public:
        bool Z, N;                  //����� ���������(Z - ���� ��. N - ������������ ��)
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
