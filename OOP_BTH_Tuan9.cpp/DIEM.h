#ifndef __DIEM2D_H__
#define ___DIEM2D_H__
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class DIEM
{
private:
    double x;
    double y;

public:
    DIEM(double = 0, double = 0);
    double GetX();
    double GetY();
    void SetX(double);
    void SetY(double);
    void SetXY(double, double);
    void Nhap();
    void Xuat();
    void DiChuyen(double, double);
    bool KiemTra(DIEM);
    double KhoangCach(DIEM);                       //Tra ve 1 so thuc la khoang cach cua 2 diem hay do dai 1 canh
    friend istream &operator>>(istream &, DIEM &); //De chong toan tu >>
    friend ostream &operator<<(ostream &, DIEM);   //De chong toan tu <<
};

#endif
