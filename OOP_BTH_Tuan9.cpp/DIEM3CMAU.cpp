#include "DIEM3CMAU.h"

DIEM3CMAU::DIEM3CMAU(double xx, double yy, double zz, int rr, int gg, int bb)
{
    // Kế thừa phương thức đã có ở các lớp cha
    SetXYZ(xx, yy, zz);
    MAU::Set(rr, gg, bb);
}

DIEM3CMAU::DIEM3CMAU(DIEM3C d, MAU m)
{
    // Kế thừa phương thức đã có ở các lớp cha
    SetXYZ(d.GetX(), d.GetY(), d.GetZ());
    MAU::Set(m);
}

DIEM3CMAU::~DIEM3CMAU() // Đưa điểm đang xét về lại gốc tọa độ và các mã màu về 0
{
    // Kế thừa phương thức đã có ở các lớp cha
    SetXYZ(0, 0, 0);
    MAU::Set(0, 0, 0);
}

DIEM3CMAU DIEM3CMAU::Get() // Trả về đối tượng điểm 3 chiều đang xét
{
    return *this;
}

void DIEM3CMAU::Set(DIEM3C d, MAU m)
{
    // Kế thừa phương thức đã có ở các lớp cha
    SetXYZ(d.GetX(), d.GetY(), d.GetZ());
    MAU::Set(m);
}

void DIEM3CMAU::Set(double xx, double yy, double zz, int rr, int gg, int bb)
{
    // Kế thừa phương thức đã có ở các lớp cha
    SetXYZ(xx, yy, zz);
    MAU::Set(rr, gg, bb);
}

bool DIEM3CMAU::KiemTraTrung(DIEM3CMAU d)
{
    // Kế thừa các phương thức có sẵn từ lớp cha
    return this->KiemTra(d) && this->MAU::KiemTraTrung(d);
}

bool DIEM3CMAU::KiemTraHopLe()
{
    return MAU::KiemTraHopLe();
}

bool DIEM3CMAU::KiemTraMau(DIEM3CMAU d)
{
    return MAU::KiemTraTrung(d);
}

void DIEM3CMAU::Nhap()
{
    // Kế thừa phương thức đã có ở các lớp cha
    DIEM3C::Nhap();
    MAU::Nhap();
}

void DIEM3CMAU::Xuat()
{
    // Kế thừa phương thức đã có ở các lớp cha
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