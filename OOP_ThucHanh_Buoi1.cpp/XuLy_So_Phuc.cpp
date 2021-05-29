#include <iostream>
#include <cmath>
#include "So_Phuc.h"
using namespace std;

void SP::Nhap()
{
    cout << "Nhap phan thuc: ";
    cin >> thuc;
    cout << "Nhap phan ao: ";
    cin >> ao;
}

void SP::GiaTri()
{
    if (ao > 0)
        cout << "Gia tri cua so phuc la: " << thuc << " + " << ao << "i\n";
    else if (ao < 0)
        cout << "Gia tri cua so phuc la: " << thuc << " - " << fabs(ao) << "i\n";
    else
        cout << "Gia tri cua so phuc la: " << thuc << endl;
}

SP SP::Cong2SP(SP a)
{
    SP tong;
    tong.thuc = thuc + a.thuc;
    tong.ao = ao + a.ao;
    return tong;
}

SP SP::Tru2SP(SP a)
{
    SP hieu;
    hieu.thuc = thuc - a.thuc;
    hieu.ao = ao - a.ao;
    return hieu;
}

SP SP::Nhan2SP(SP a)
{
    SP tich;
    tich.thuc = thuc * a.thuc - ao * a.ao;
    tich.ao = thuc * a.ao + ao * a.thuc;
    return tich;
}

SP SP::Chia2SP(SP a)
{
    SP thuong;
    thuong.thuc = (thuc + a.thuc + ao * a.ao) / (a.thuc * a.thuc + a.ao * a.ao);
    thuong.ao = (ao * a.thuc - thuc * a.ao) / (a.thuc * a.thuc + a.ao * a.ao);
    return thuong;
}

void SP::Xuat()
{
    cout << "(" << thuc << ", " << ao << ")";
}

void SP::Tinh_Toan_So_Phuc(SP b)
{
    this->Xuat();
    cout << " + ";
    b.Xuat();
    cout << " = ";
    (this->Cong2SP(b)).Xuat();
    cout << endl;

    this->Xuat();
    cout << " - ";
    b.Xuat();
    cout << " = ";
    (this->Tru2SP(b)).Xuat();
    cout << endl;

    this->Xuat();
    cout << " * ";
    b.Xuat();
    cout << " = ";
    (this->Nhan2SP(b)).Xuat();
    cout << endl;

    this->Xuat();
    cout << " / ";
    b.Xuat();
    cout << " = ";
    (this->Chia2SP(b)).Xuat();
    cout << endl;
}