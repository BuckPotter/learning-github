#include "DIEM.h"

DIEM::DIEM(double a, double b) // Truyền vào 2 tham số, gán lần lượt cho hoành độ x và tung độ y
{
    x = a;
    y = b;
}

double DIEM::GetX() // Trả về 1 số kiểu double là hoành độ x của điểm đang xét
{
    return x;
}

double DIEM::GetY() // Trả về 1 số kiểu double là tung độ y của điểm đang xét
{
    return y;
}

void DIEM::SetX(double a) // Thiết lập hoành độ x
{
    x = a;
}

void DIEM::SetY(double a) // Thiết lập tung độ y
{
    y = a;
}

void DIEM::SetXY(double a, double b) // Thiết lập hoành độ và tung độ
{
    x = a;
    y = b;
}

void DIEM::Nhap()
{
    cout << "\tNhap hoanh do: ";
    cin >> x;
    cout << "\tNhap tung do: ";
    cin >> y;
}

void DIEM::Xuat()
{
    cout << "Toa do cua diem la: (" << x << ", " << y << ")";
}

void DIEM::DiChuyen(double a, double b) // Tịnh tiến tọa độ ban đầu
{
    x += a;
    y += b;
}

bool DIEM::KiemTra(DIEM b)
{
    if (this->x == b.x && this->y == b.y)
        return 1;
    return 0;
}

double DIEM::KhoangCach(DIEM b) //Đồng thời cũng là cạnh của tam giác
{
    double hoanh_hoanh = this->x - b.x;
    double tung_tung = this->y - b.y;
    return sqrt(hoanh_hoanh * hoanh_hoanh + tung_tung * tung_tung);
}

istream &operator>>(istream &is, DIEM &d)
{
    cout << "\tNhap hoanh do: ";
    is >> d.x;
    cout << "\tNhap tung do: ";
    is >> d.y;
    return is;
}

ostream &operator<<(ostream &os, DIEM d)
{
    os << "Toa do cua diem la: (" << d.x << ", " << d.y << ")";
    return os;
}