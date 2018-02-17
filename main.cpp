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
    p.memory[cell].f1.type = i;                             //считали 6-ти битный код операции
    switch(p.memory[cell].f1.type)
    {
        case 0:                                 //регистр = регистр @ регистр
            file >> i; p.memory[cell].f5.copr = i;                             //считали 6-ти битный код операции
            file >> i; p.memory[cell].f1.a = i;             //считали регистр, в котором будет результат
            file >> i; p.memory[cell].f1.b = i;             //считали первый регистр операции
            file >> i; p.memory[cell].f1.c = i;             //считали второй регистр операции
        break;
        case 1:                                 //регистр = регистр @ число
            file >> i; p.memory[cell].f5.copr = i;                             //считали 6-ти битный код операции
            file >> i; p.memory[cell].f2.a = i;             //считали регистр, в котором будет результат
            file >> i; p.memory[cell].f2.b = i;             //считали первый регистр операции
            file >> i; p.memory[cell].f2.im = i;            //считали число операции
        break;
        case 2:                                 //регистр регистр смещение
            file >> i; p.memory[cell].f5.copr = i;                             //считали 6-ти битный код операции
            file >> i; p.memory[cell].f3.a = i;             //считали регистр, в котором будет результат
            file >> i; p.memory[cell].f3.b = i;             //считали первый регистр операции
            file >> i; p.memory[cell].f3.disp = i;          //считали смещение
        break;
        case 3:                                 // смещение
            file >> i; p.memory[cell].f5.copr = i;                             //считали 6-ти битный код операции
            file >> i; p.memory[cell].f4.disp = i;          //считали смещение
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
	cout<<"Введите имя файла: ";
	cin>>Name;
	fstream file(Name);
    if(!file.is_open())
    {
        "Не удалось открыть файл\n";
        return 0;
    }
    loader(file);
    p.interpreter();
    p.reset();
    system("pause");
    return 0;
}
