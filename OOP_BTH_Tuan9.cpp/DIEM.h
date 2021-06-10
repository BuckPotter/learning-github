#ifndef __DIEM_H__
#define ___DIEM_H__
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class DIEM
{
protected:
    double x;
    double y;

public:
    DIEM(double = 0, double = 0);
    double GetX();
    double GetY();
    DIEM GetXY();
    void SetX(double);
    void SetY(double);
    void SetXY(double, double);
    void Nhap();
    void Xuat();
    void DiChuyen(double, double);
    bool KiemTra(DIEM);
    double KhoangCach(DIEM);                       //Tra ve 1 so thuc la khoang cach cua 2 diem hay do dai 1 canh
    DIEM Doi_Xung_Qua_O();                         //Tim diem doi xung voi diem dang xet qua O
    double Chu_Vi_Tam_Giac(DIEM, DIEM);            //Tra ve 1 so thuc la chu vi cua tam giac
    double Do_Dai_Canh();                          //Tra ve 1 so thuc la khoang cach cua 2 diem hay do dai 1 canh
    double Dien_Tich_Tam_Giac(DIEM, DIEM);         //Tra ve 1 so thuc la dien tich cua tam giac
    friend istream &operator>>(istream &, DIEM &); //De chong toan tu >>
    friend ostream &operator<<(ostream &, DIEM);   //De chong toan tu <<
};

#endif
