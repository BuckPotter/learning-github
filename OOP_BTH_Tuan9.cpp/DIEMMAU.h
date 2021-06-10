#ifndef __DIEMMAU_H__
#define __DIEMMAU_H__
#include "DIEM.cpp"
#include "MAU.h"
class DIEMMAU : public DIEM, public MAU
{
public:
    DIEMMAU(double = 0, double = 0, int = 0, int = 0, int = 0);
    DIEMMAU(DIEM, MAU);
    DIEMMAU Get();
    void Set(DIEM, MAU);
    bool KiemTraHopLe();
    bool KiemTraTrung(DIEMMAU);
    void Nhap();
    void Xuat();
    friend istream &operator>>(istream &, DIEMMAU &);
    friend ostream &operator<<(ostream &, DIEMMAU);
};

#endif