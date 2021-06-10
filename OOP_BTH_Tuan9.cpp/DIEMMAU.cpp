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
    // Kế thừa các phương thức đã xây dựng ở các lớp cha
    SetXY(d.GetX(), d.GetY());
    MAU::Set(m);
}

void DIEMMAU::Set(DIEM d, int rr, int gg, int bb)
{
    // Kế thừa các phương thức đã xây dựng ở các lớp cha
    SetXY(d.GetX(), d.GetY());
    MAU::Set(rr, gg, bb);
}

void DIEMMAU::Set(double xx, double yy, int rr, int gg, int bb)
{
    // Kế thừa các phương thức thiết lập đã xây dựng ở các lớp cha
    DIEM::SetXY(xx, yy);
    MAU::Set(rr, gg, bb);
}

bool DIEMMAU::KiemTraHopLe() // Chỉ cần kiểm tra mã màu
{
    return MAU::KiemTraHopLe(); // Kế thừa từ lớp cha MAU
}

bool DIEMMAU::KiemTraTrung(DIEMMAU d) // Kiểm tra 2 DIEMMAU có giống nhau không (cả tọa độ và mã màu)
{
    MAU a(d.Get_R(), d.Get_G(), d.Get_B());
    return KiemTra(d) && MAU::KiemTraTrung(a); // Kế thừa 2 phương thức kiểm tra của lớp DIEM và MAU
}

void DIEMMAU::Nhap()
{
    // Kế thừa các phương thức nhập đã xây dựng ở các lớp cha
    DIEM::Nhap();
    MAU::Nhap();
}

void DIEMMAU::Xuat()
{
    // Kế thừa các phương thức xuất đã xây dựng ở các lớp cha
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