#include "DIEMMAU.h"

DIEMMAU::DIEMMAU(double xx, double yy, int rr, int gg, int bb)
{
    SetXY(xx, yy);
    MAU::Set(rr, gg, bb);
}

DIEMMAU DIEMMAU::Get()
{
    return *this;
}

void DIEMMAU::Set(DIEM d, MAU m)
{
    SetXY(d.GetX(), d.GetY());
    MAU::Set(m);
}

bool DIEMMAU::KiemTraHopLe()
{
    return MAU::KiemTraHopLe();
}

bool DIEMMAU::KiemTraTrung(DIEMMAU d)
{
    MAU a(d.Get_R(), d.Get_G(), d.Get_B());
    return KiemTra(d) && MAU::KiemTraTrung(a);
}

void DIEMMAU::Nhap()
{
    DIEM::Nhap();
    MAU::Nhap();
}

void DIEMMAU::Xuat()
{
    DIEM::Xuat();
    cout << ". ";
    MAU::Xuat();
}

istream &operator>>(istream &is, DIEMMAU &d)
{
    cout << "\tNhap toa do diem:\n";
    cout << "Nhap hoanh do: ";
    is >> d.x;
    cout << "Nhap tung do: ";
    is >> d.y;
    do
    {
        cout << "\tNhap vao 3 gia tri mau RGB:\n";
        is >> d.r >> d.gr >> d.bl;
        if (!d.KiemTraHopLe())
            cout << "Moi gia tri mau phai nam trong doan [0, 256]. Vui long nhap lai!!!\n";
    } while (!d.KiemTraHopLe());
    return is;
}

ostream &operator<<(ostream &os, DIEMMAU d)
{
    os << "Toa do cua diem la: (" << d.x << ", " << d.y << ")";
    os << ". ";
    os << "Ma mau RGB tuong ung: " << d.r << ", " << d.gr << ", " << d.bl;
    return os;
}