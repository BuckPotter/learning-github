#include "MAU.h"

MAU::MAU(int rr, int gg, int bb)
{
    r = rr;
    gr = gg;
    bl = bb;
    if (!KiemTraHopLe())
    {
        Nhap();
    }
}

MAU::MAU(MAU &m)
{
    r = m.r;
    gr = m.gr;
    bl = m.bl;
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
}

void MAU::Set(MAU m)
{
    r = m.r;
    gr = m.gr;
    bl = m.bl;
}

void MAU::Nhap()
{
    do
    {
        cout << "Nhap vao 3 gia tri mau RGB:\n";
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
    if (r != m.r)
        return 0;
    if (gr != m.gr)
        return 0;
    if (bl != m.bl)
        return 0;
    return 1;
}