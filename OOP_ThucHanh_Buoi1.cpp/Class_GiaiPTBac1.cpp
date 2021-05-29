#include <iostream>
#include <cmath>
#include "Class_GiaiPTBac1.h"
using namespace std;

typedef PTB1 PT; //Gọi tắt là phương trình

void PT::KhoiTao()
{
    a = b = 0;
}

void PT::KhoiTao(double x)
{
    a = 0;
    b = x;
}

void PT::KhoiTao(double x, double y)
{
    a = x;
    b = y;
}

void PT::Nhap()
{
    cout << "Nhap he so a: ";
    cin >> this->a;
    cout << "Nhap mau so: ";
    cin >> this->b;
}

bool PT::KiemTraCoNghiem()
{
    if (a == 0)
        if (b == 0)
            return 0; // Vô số nghiệm
        else
            return -1; // Vô nghiệm
    return 1;
}

void PT::GiaiPT()
{
    if (this->KiemTraCoNghiem() == 1)
    {
        cout << "Phuong trinh co nghiem: ";
        cout << -b / a << endl;
        return;
    }
    else if (this->KiemTraCoNghiem() == -1)
    {
        cout << "Phuong vo nghiem\n";
        return;
    }
    cout << "Phuong trinh co vo so nghiem\n";
}

void PTB1::Xuat()
{
    cout << a << "x ";
    cout << (b >= 0 ? "+ " : "- ") << fabs(b) << " = 0\n";
}