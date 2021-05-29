#include <iostream>
#include <cmath>
#include "Class_TamGiac.h"
using namespace std;

typedef TAMGIAC TG;

void TG::KhoiTao()
{
    a = b = c = 1;
}

void TG::Nhap()
{
    cout << "Lan luot nhap vao 3 canh cua tam giac o day: ";
    cin >> this->a >> this->b >> this->c;
}

void TG::Xuat()
{
    cout << "Tam giac co 3 canh lan luot la: " << this->a << " " << this->b << " " << this->c;
}

bool TG::Kiem_Tra()
{
    if (a + b < c || a + c < b || b + c < a)
        return 0;
    return 1;
}

int TG::Phan_Loai()
{
    if (this->Kiem_Tra() == 0)
        return -1; // Khong phai tam giac

    if (a == b && b == c)
        return 1; // Tam giác đều

    if ((a == b && a == c) || (b == a && b == c) || (c == a && c == b)) // Điều kiện tam giác cân
    {
        // Điều kiện tam giác vuông
        if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a))
            return 2; // Tam giác vuông cân
        else
            return 3; // Tam giác cân
    }

    if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a))
        return 4; // Tam giác vuông

    return 5; // Không phái các trường hợp trên => tam giác thường;
}

double TG::Chu_Vi()
{
    return a + b + c;
}

double TG::Dien_Tich()
{
    double ncv = this->Chu_Vi() / 2; // Nửa chu vi
    return sqrt(ncv * (ncv - a) * (ncv - b) * (ncv - c));
}