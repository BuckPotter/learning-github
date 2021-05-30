#ifndef __DIEMMAU3C_H__
#define __DIEMMAU3C_H__
#include "DIEM3C.h"

class DIEMMAU3C : public DIEM3C
{
    int r;
    int gr;
    int bl;

public:
    DIEMMAU3C(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);
    DIEMMAU3C(DIEM3C, int = 0, int = 0, int = 0);
    DIEMMAU3C Get();
    ~DIEMMAU3C();
    void Set_Mau(int, int, int);
    bool KiemTraTrungMau(DIEM3C);
    void Nhap();
    void Xuat();
    friend istream &operator>>(istream &, DIEMMAU3C &);
    friend ostream &operator<<(ostream &, DIEMMAU3C);
};

#endif