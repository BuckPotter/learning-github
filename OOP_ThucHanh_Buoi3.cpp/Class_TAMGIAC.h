#ifndef TAMGIAC_H
#define TAMGIAC_H
#include "Diem.h"

class TAMGIAC
{
    Diem A, B, C;

public:
    TAMGIAC();
    TAMGIAC(double, double, double, double, double, double);
    TAMGIAC(Diem, Diem, Diem);
    Diem GetA();
    Diem GetB();
    Diem GetC();
    void SetA(double, double);
    void SetB(double, double);
    void SetC(double, double);
    void SetABC(Diem, Diem, Diem);
    void Nhap();
    void Xuat();
    void Di_Chuyen(double, double); //tọa độ của cả 3 đỉnh đều di chuyển một đoạn tương ứng với tham số đầu vào
    bool Kiem_Tra();                //Kiem tra xem tam giác có hợp lệ không
    void Phan_Loai();
    double Chu_Vi();
    double Dien_Tich();
    friend istream &operator>>(istream &, TAMGIAC &);
    friend ostream &operator>>(ostream &, TAMGIAC);
};

#endif