#include <iostream>
#include "Class_PS.h"
using namespace std;

typedef PHANSO PS;

PHANSO::PHANSO(int tu, int mau) : ts(tu), ms(mau) {}

void PHANSO::Nhap()
{
    cout << "Nhap tu so: ";
    cin >> this->ts;
    cout << "Nhap mau so: ";
    do
    {
        cin >> this->ms;
        if (this->ms == 0)
            cout << "Vui long nhap mau so khac 0!!!\n";
    } while (this->ms == 0);
}

void PS::Nhap2PS(PS &b)
{
    cout << "\tNhap vao 2 phan so \n";
    cout << "Nhap phan so thu nhat:\n";
    this->Nhap();
    cout << "Nhap phan so thu hai:\n";
    b.Nhap();
    cout << "\n\n";
}

void PHANSO::Xuat()
{
    if (this->ms < 0)
    {
        this->ts = -this->ts;
        this->ms = -this->ms;
    }
    if (this->ts == 0)
    {
        cout << 0;
        return;
    }
    if (this->ms == 1)
    {
        cout << this->ts;
        return;
    }
    cout << this->ts << "/" << this->ms;
}

int PHANSO::UCLN(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if (a == 0 || b == 0)
        return a + b;
    if (a == 1 || b == 1)
        return 1;
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

PHANSO PHANSO::RutGon() //Toi gian PS va tra ve phan so toi gian
{
    PHANSO rg;
    int ucln = UCLN(this->ts, this->ms);
    rg.ts = this->ts / ucln;
    rg.ms = this->ms / ucln;
    return rg;
}

float PHANSO::GiaTriThuc()
{
    return (float)this->ts / this->ms;
}

PHANSO PHANSO::PSLonHon(PHANSO b)
{
    if (this->GiaTriThuc() > b.GiaTriThuc())
        return *this;
    else
        return b;
}

void PHANSO::format(PS b, int oper)
{
    cout << this->ts << "/" << this->ms;
    switch (oper)
    {
    case 6:
        cout << " + ";
        break;
    case 7:
        cout << " - ";
        break;
    case 8:
        cout << " * ";
        break;
    case 9:
        cout << " : ";
        break;
    }
    cout << b.ts << "/" << b.ms << " = ";
}

PHANSO PHANSO::Cong2PS(PHANSO b)
{
    PHANSO tong;
    tong.ts = this->ts * b.ms + this->ms * b.ts;
    tong.ms = this->ms * b.ms;
    return tong;
}

PHANSO PHANSO::Tru2PS(PHANSO b)
{
    PHANSO hieu;
    hieu.ts = this->ts * b.ms - this->ms * b.ts;
    hieu.ms = this->ms * b.ms;
    return hieu;
}

PHANSO PHANSO::Nhan2PS(PHANSO b)
{
    PHANSO tich;
    tich.ts = this->ts * b.ts;
    tich.ms = this->ms * b.ms;
    return tich;
}

PHANSO PHANSO::Chia2PS(PHANSO b)
{
    PHANSO thuong;
    thuong.ts = this->ts * b.ms;
    thuong.ms = this->ms * b.ts;
    return thuong;
}

bool PS::KiemTra()
{
    if (this->ts == 0)
        return 1;
    return 0;
}