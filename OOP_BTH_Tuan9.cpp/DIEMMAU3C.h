#ifndef __DIEMMAU3C_H__
#define __DIEMMAU3C_H__
#include "DIEM3C.h"

class DIEMMAU3C : public DIEM3C
{
    int r;
    int gr;
    int bl;

public:
    DIEMMAU3C(double = 0, double = 0, double = 0, int = 0, int = 0, int = 0);
    DIEMMAU3C(DIEM3C, int = 0, int = 0, int = 0);
    ~DIEMMAU3C();
    DIEMMAU3C Get();
    int Get_R();
    int Get_G();
    int Get_B();
    void Set_Mau(int = 0, int = 0, int = 0);
    bool KiemTraTrungMau(DIEMMAU3C);
    bool KiemTraMau();
    void Nhap();
    void Xuat();
    friend istream &operator>>(istream &, DIEMMAU3C &);
    friend ostream &operator<<(ostream &, DIEMMAU3C);
};

#endif