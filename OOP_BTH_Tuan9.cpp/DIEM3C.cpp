#include "DIEM3C.h"

DIEM3C::DIEM3C(double xx, double yy, double zz)
{
    SetXY(xx, yy);
    z = zz;
}

DIEM3C::~DIEM3C()
{
    x = y = z = 0;
}

DIEM3C DIEM3C::Get()
{
    return *this;
}

double DIEM3C::GetZ()
{
    return z;
}

void DIEM3C::SetZ(double zz)
{
    z = zz;
}

void DIEM3C::SetXYZ(double xx, double yy, double zz)
{
    x = xx;
    y = yy;
    z = zz;
}

bool DIEM3C::KiemTra(DIEM3C d)
{
    if (x == d.x || y == d.y || z == d.z)
        return 1;
    return 0;
}

void DIEM3C::DiChuyen(double xx, double yy, double zz)
{
    x += xx;
    y += yy;
    z += zz;
}

double DIEM3C::KhoangCach(DIEM3C d)
{
    return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2) + pow((z - d.z), 2));
}

DIEM3C DIEM3C::DiemDoiXung()
{
    int a = 0, b = 0, c = 0;
    if (x != 0)
        a = -x;
    if (y != 0)
        b = -y;
    if (z != 0)
        c = -z;
    return DIEM3C(a, b, c);
}

void DIEM3C::Nhap()
{
    DIEM::Nhap();
    cout << "Nhap cao do: ";
    cin >> z;
}

void DIEM3C::Xuat()
{
    cout << "Toa do cua diem la: (" << x << ", " << y << ", " << z << ")";
}

bool DIEM3C::KiemTraTamGiac(DIEM3C b, DIEM3C c)
{
    double i = KhoangCach(b);
    double j = KhoangCach(c);
    double k = b.KhoangCach(c);
    if (i + j <= k || i + k <= j || j + k <= i)
        return 0;
    return 1;
}

double DIEM3C::ChuVi(DIEM3C b, DIEM3C c)
{
    if (KiemTraTamGiac(b, c) == 0) // Trường hợp tam giác không hợp lệ
    {
        cout << "Tam giac nay khong hop le!!!\n";
        do
        {
            cout << "Hay nhap lai toa do (x, y, z) cho 3 dinh cho tam giac\n";
            cin >> *this >> b >> c;
        } while (KiemTraTamGiac(b, c) == 0);
    }
    return KhoangCach(b) + KhoangCach(c) + b.KhoangCach(c);
}

double DIEM3C::DienTich(DIEM3C b, DIEM3C c)
{
    if (KiemTraTamGiac(b, c) == 0) // Trường hợp tam giác không hợp lệ
    {
        cout << "Tam giac nay khong hop le!!!\n";
        do
        {
            cout << "Hay nhap lai toa do (x, y, z) cho 3 dinh cho tam giac\n";
            cin >> *this >> b >> c;
        } while (KiemTraTamGiac(b, c) == 0);
    }
    double i = KhoangCach(b);
    double j = KhoangCach(c);
    double k = b.KhoangCach(c);
    double p = this->ChuVi(b, c) / 2;
    return sqrt(p * (p - i) * (p - j) * (p - k));
}

istream &operator>>(istream &is, DIEM3C &d)
{
    cout << "\tNhap toa do diem:\n";
    cout << "Nhap hoanh do: ";
    is >> d.x;
    cout << "Nhap tung do: ";
    is >> d.y;
    cout << "Nhap cao do: ";
    is >> d.z;
    return is;
}

ostream &operator<<(ostream &os, DIEM3C d)
{
    os << "Toa do cua diem la: (" << d.x << ", " << d.y << ", " << d.z << ")";
    return os;
}