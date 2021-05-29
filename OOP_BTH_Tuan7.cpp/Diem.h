#ifndef DIEM_H
#define DIEM_H
#include <iostream>
using namespace std;

class Diem
{
private:
    double x;
    double y;

public:
    Diem();
    Diem(double);
    Diem(double, double);
    double GetX();
    double GetY();
    void SetX(double);
    void SetY(double);
    void SetXY(double, double);
    void Nhap();
    void Xuat();
    void DiChuyen(double, double);
    bool KiemTra2DiemTrungNhau(Diem);
    double KhoangCach(Diem);                       //Tra ve 1 so thuc la khoang cach cua 2 diem hay do dai 1 canh
    Diem Doi_Xung_Qua_O();                         //Tim diem doi xung voi diem dang xet qua O
    double Chu_Vi_Tam_Giac(Diem, Diem, Diem);      //Tra ve 1 so thuc la chu vi cua tam giac
    double Do_Dai_Canh();                          //Tra ve 1 so thuc la khoang cach cua 2 diem hay do dai 1 canh
    double Dien_Tich_Tam_Giac(Diem, Diem, Diem);   //Tra ve 1 so thuc la dien tich cua tam giac
    friend istream &operator>>(istream &, Diem &); //De chong toan tu >>
    friend ostream &operator<<(ostream &, Diem);   //De chong toan tu <<
};

#endif
