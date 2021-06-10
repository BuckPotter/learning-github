#include "DIEM3CMAU.h"

DIEM3CMAU::DIEM3CMAU(double xx, double yy, double zz, int rr, int gg, int bb)
{
    SetXYZ(xx, yy, zz);
    MAU::Set(rr, gg, bb);
}

DIEM3CMAU::DIEM3CMAU(DIEM3C d, MAU m)
{
    SetXYZ(d.GetX(), d.GetY(), d.GetZ());
    MAU::Set(m);
}

DIEM3CMAU::~DIEM3CMAU()
{
    SetXYZ(0, 0, 0);
    MAU::Set(0, 0, 0);
}

DIEM3CMAU DIEM3CMAU::Get()
{
    return *this;
}

void DIEM3CMAU::Set(DIEM3C d, MAU m)
{
    SetXYZ(d.GetX(), d.GetY(), d.GetZ());
    MAU::Set(m);
}

void DIEM3CMAU::Nhap()
{
    DIEM3C::Nhap();
    MAU::Nhap();
}

void DIEM3CMAU::Xuat()
{
    DIEM3C::Xuat();
    cout << ". ";
    MAU::Xuat();
}

istream &operator>>(istream &is, DIEM3CMAU &d)
{
    cout << "\tNhap toa do diem:\n";
    cout << "Nhap hoanh do: ";
    is >> d.x;
    cout << "Nhap tung do: ";
    is >> d.y;
    cout << "Nhap cao do: ";
    cin >> d.z;
    do
    {
        cout << "\tNhap vao 3 gia tri mau RGB:\n";
        cin >> d.r >> d.gr >> d.bl;
        if (!d.KiemTraHopLe())
            cout << "Moi gia tri mau phai nam trong doan [0, 256]. Vui long nhap lai!!!\n";
    } while (!d.KiemTraHopLe());
    return is;
}

ostream &operator<<(ostream &os, DIEM3CMAU d)
{
    os << "Toa do cua diem la: (" << d.x << ", " << d.y << ", " << d.z << ")";
    os << ". ";
    os << "Ma mau RGB tuong ung: " << d.r << ", " << d.gr << ", " << d.bl;
    return os;
}