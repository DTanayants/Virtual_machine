#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "CPU.h"
using namespace std;
CPU p;
void com(int cell, fstream &file)
{
    unsigned  i;
    file >> i;
    p.memory[cell].f1.type = i;                             //������� 6-�� ������ ��� ��������
    switch(p.memory[cell].f1.type)
    {
        case 0:                                 //������� = ������� @ �������
            file >> i; p.memory[cell].f5.copr = i;                             //������� 6-�� ������ ��� ��������
            file >> i; p.memory[cell].f1.a = i;             //������� �������, � ������� ����� ���������
            file >> i; p.memory[cell].f1.b = i;             //������� ������ ������� ��������
            file >> i; p.memory[cell].f1.c = i;             //������� ������ ������� ��������
        break;
        case 1:                                 //������� = ������� @ �����
            file >> i; p.memory[cell].f5.copr = i;                             //������� 6-�� ������ ��� ��������
            file >> i; p.memory[cell].f2.a = i;             //������� �������, � ������� ����� ���������
            file >> i; p.memory[cell].f2.b = i;             //������� ������ ������� ��������
            file >> i; p.memory[cell].f2.im = i;            //������� ����� ��������
        break;
        case 2:                                 //������� ������� ��������
            file >> i; p.memory[cell].f5.copr = i;                             //������� 6-�� ������ ��� ��������
            file >> i; p.memory[cell].f3.a = i;             //������� �������, � ������� ����� ���������
            file >> i; p.memory[cell].f3.b = i;             //������� ������ ������� ��������
            file >> i; p.memory[cell].f3.disp = i;          //������� ��������
        break;
        case 3:                                 // ��������
            file >> i; p.memory[cell].f5.copr = i;                             //������� 6-�� ������ ��� ��������
            file >> i; p.memory[cell].f4.disp = i;          //������� ��������
        break;
    }
}

void loader(fstream &file)
{

    int ip, cell = 0;
    char elem;
    while(!file.eof())
    {
        file >> cell;
        file >> elem;
        switch(elem)
        {
            case 'i':
                file >> p.memory[cell].i;
            break;
            case 'f':
                file >> p.memory[cell].f;
            break;
            case 'c':
                com(cell, file);
            break;
            case 'e':
                file >> ip;
                p.set_IP(ip);
            break;
        }
    }
    file.close();
}

int main()
{
    setlocale(0, "rus");
    string Name;
	cout<<"������� ��� �����: ";
	cin>>Name;
	fstream file(Name);
    if(!file.is_open())
    {
        "�� ������� ������� ����\n";
        return 0;
    }
    loader(file);
    p.interpreter();
    p.reset();
    system("pause");
    return 0;
}
