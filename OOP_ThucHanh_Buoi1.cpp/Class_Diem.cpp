#include <iostream>
#include <cmath>
#include <algorithm>
#include "Class_Diem.h"
using namespace std;

void Diem::KhoiTao()
{
    x = y = 0;
}

void Diem::KhoiTao(double a)
{
    x = a;
    y = 0;
}

void Diem::KhoiTao(double a, double b)
{
    x = a;
    y = b;
}

void Diem::Nhap()
{
    cout << "Nhap tung do: ";
    cin >> x;
    cout << "Nhap hoanh do: ";
    cin >> y;
}

void Diem::Xuat()
{
    cout << "Toa do cua diem la: (" << x << ", " << y << ")";
}

void Diem::DiChuyen(double a, double b) // Tịnh tiến tọa độ ban đầu
{
    x += a;
    y += b;
}

bool Diem::KiemTra2DiemTrungNhau(Diem b)
{
    if (this->x == b.x && this->y == b.y)
        return 1;
    return 0;
}

double Diem::KhoangCach(Diem b) //Đồng thời cũng là cạnh của tam giác
{
    double hoanh_hoanh = this->x - b.x;
    double tung_tung = this->y - b.y;
    return sqrt(hoanh_hoanh * hoanh_hoanh + tung_tung * tung_tung);
}

Diem Diem::Doi_Xung_Qua_O()
{
    Diem Doi_Xung;
    Doi_Xung.x = -this->x;
    Doi_Xung.y = -this->y;
    return Doi_Xung;
}

double Diem::Chu_Vi_Tam_Giac(Diem a, Diem b, Diem c)
{
    return a.KhoangCach(b) + a.KhoangCach(c) + b.KhoangCach(c);
}

double Diem::Dien_Tich_Tam_Giac(Diem a, Diem b, Diem c)
{
    double ncv = Chu_Vi_Tam_Giac(a, b, c) / 2;                                                      // Nửa chu vi
    return sqrt(ncv * (ncv - a.KhoangCach(b)) * (ncv - a.KhoangCach(c)) * (ncv - c.KhoangCach(b))); // Công thức Herong
}