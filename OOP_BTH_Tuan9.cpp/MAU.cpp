#include "MAU.h"

MAU::MAU(int rr, int gg, int bb)
{
    Set(rr, gg, bb);
}

int MAU::Get_R()
{
    return r;
}

int MAU::Get_G()
{
    return gr;
}

int MAU::Get_B()
{
    return bl;
}

MAU MAU::Get()
{
    return *this;
}

void MAU::Set(int rr, int gg, int bb)
{
    r = rr;
    gr = gg;
    bl = bb;
    if (!KiemTraHopLe())
    {
        cout << "Ma mau nay khong hop le. Hay nhap lai\n";
        do
        {
            cin >> r >> gr >> bl;
        } while (KiemTraHopLe() == 0);
    }
}

void MAU::Set(MAU m)
{
    r = m.r;
    gr = m.gr;
    bl = m.bl;
}

void MAU::Set_R(int rr)
{
    while (rr < 0 || rr > 255)
    {
        cout << "Ma mau nay khong hop le. Hay nhap lai\n";
        cin >> rr;
    }
    r = rr;
}

void MAU::Set_G(int gg)
{
    while (gg < 0 || gg > 255)
    {
        cout << "Ma mau nay khong hop le. Hay nhap lai\n";
        cin >> gg;
    }
    gr = gg;
}

void MAU::Set_B(int bb)
{
    while (bb < 0 || bb > 255)
    {
        cout << "Ma mau nay khong hop le. Hay nhap lai\n";
        cin >> bb;
    }
    bl = bb;
}

void MAU::Nhap()
{
    do
    {
        cout << "\tNhap vao 3 gia tri mau RGB:\n";
        cin >> r >> gr >> bl;
        if (!KiemTraHopLe())
            cout << "Moi gia tri mau phai nam trong doan [0, 256]. Vui long nhap lai!!!\n";
    } while (!KiemTraHopLe());
}

void MAU::Xuat()
{
    cout << "Ma mau RGB tuong ung: " << r << ", " << gr << ", " << bl;
}

bool MAU::KiemTraHopLe()
{
    if (r < 0 || r > 255)
        return 0;
    if (gr < 0 || gr > 255)
        return 0;
    if (bl < 0 || bl > 255)
        return 0;
    return 1;
}

bool MAU::KiemTraTrung(MAU m)
{
    if (r != m.r || gr != m.gr || bl != m.bl)
        return 0;
    return 1;
}
