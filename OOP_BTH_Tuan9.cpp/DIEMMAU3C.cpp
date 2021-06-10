#include "DIEMMAU3C.h"

DIEMMAU3C::DIEMMAU3C(double xx, double yy, double zz, int rr, int gg, int bb)
{
    SetXYZ(xx, yy, zz);
    Set_Mau(rr, gg, bb);
}

DIEMMAU3C::DIEMMAU3C(DIEM3C d, int rr, int gg, int bb)
{
    SetXYZ(d.GetX(), d.GetY(), d.GetZ());
    Set_Mau(rr, gg, bb);
}

DIEMMAU3C::~DIEMMAU3C() // Đưa điểm này về lại gốc tọa độ mà đưa các giá trị màu về lại 0
{
    SetXYZ(0, 0, 0);
    Set_Mau(0, 0, 0);
}

DIEMMAU3C DIEMMAU3C::Get()
{
    return *this;
}

int DIEMMAU3C::Get_R()
{
    return r;
}

int DIEMMAU3C::Get_G()
{
    return gr;
}

int DIEMMAU3C::Get_B()
{
    return bl;
}

bool DIEMMAU3C::KiemTraMau() // Kiểm tra mã màu của đối tượng đang xét có hợp lệ hay không
{
    if (r < 0 || r > 255)
        return 0;
    if (gr < 0 || gr > 255)
        return 0;
    if (bl < 0 || bl > 255)
        return 0;
    return 1;
}

void DIEMMAU3C::Set_Mau(int rr, int gg, int bb)
{
    r = rr;
    gr = gg;
    bl = bb;
    if (KiemTraMau() == 0)
    {
        cout << "Ma mau khong hop le\n";
        do
        {
            cout << "Nhap lai ma mau RGB:\n";
            cin >> r >> gr >> bl;
        } while (KiemTraMau() == 0);
    }
}

bool DIEMMAU3C::KiemTraTrungMau(DIEMMAU3C d)
{
    if (r != d.r || gr != d.gr || bl != d.bl)
        return 0;
    return 1;
}

void DIEMMAU3C::Nhap()
{
    this->DIEM3C::Nhap(); // Phương thức nhập điểm trong lớp DIEM3C
    do
    {
        cout << "\tNhap ma mau RGB:\n";
        cout << "Red: ";
        cin >> r;
        cout << "Green: ";
        cin >> gr;
        cout << "Blue: ";
        cin >> bl;
        if (KiemTraMau() == 0)
            cout << "Ma mau ban vua nhap khong hop le!!!\n";
    } while (KiemTraMau() == 0);
}

void DIEMMAU3C::Xuat()
{
    this->DIEM3C::Xuat();
    cout << ". Ma mau RGB: " << r << " - " << gr << " - " << bl;
}

istream &operator>>(istream &is, DIEMMAU3C &d)
{
    d.DIEM3C::Nhap(); // Phương thức nhập điểm trong lớp DIEM3C
    do
    {
        cout << "\tNhap ma mau RGB:\n";
        cout << "Red: ";
        is >> d.r;
        cout << "Green: ";
        is >> d.gr;
        cout << "Blue: ";
        is >> d.bl;
        if (d.KiemTraMau() == 0)
            cout << "Ma mau ban vua nhap khong hop le!!!\n";
    } while (d.KiemTraMau() == 0);
    return is;
}

ostream &operator<<(ostream &os, DIEMMAU3C d)
{
    d.DIEM3C::Xuat(); // Xuất tọa độ
    os << ". Ma mau RGB: " << d.r << " - " << d.gr << " - " << d.bl;
    return os;
}