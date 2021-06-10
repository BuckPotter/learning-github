#ifndef __DIEM3CMAU_H__
#define __DIEM3CMAU_H__
#include "DIEM3C.h"
#include "MAU.h"
class DIEM3CMAU : public DIEM3C, public MAU
{
public:
    DIEM3CMAU(double = 0, double = 0, double = 0, int = 0, int = 0, int = 0);
    DIEM3CMAU(DIEM3C, MAU);
    ~DIEM3CMAU();
    DIEM3CMAU Get();
    void Set(DIEM3C, MAU);
    void Nhap();
    void Xuat();
    friend istream &operator>>(istream &, DIEM3CMAU &);
    friend ostream &operator<<(ostream &, DIEM3CMAU);
};

#endif