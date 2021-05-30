#ifndef __DIEM3C_H__
#define __DIEM3C_H__
#include "DIEM.h"

class DIEM3C : public DIEM
{
    int z;

public:
    DIEM3C(int = 0, int = 0, int = 0);
    ~DIEM3C();
    DIEM3C Get();
    double GetZ();
    void SetZ(double);
    void SetXYZ(double, double, double);
    bool KiemTra(DIEM3C);
    void DiChuyen(double, double, double);
    double KhoangCach(DIEM3C);
    DIEM3C DiemDoiXung();
    void Nhap();
    void Xuat();
    double ChuVi(DIEM3C, DIEM3C, DIEM3C);
    double DienTich(DIEM3C, DIEM3C, DIEM3C);
    friend istream &operator>>(istream &, DIEM3C &);
    friend ostream &operator<<(ostream &, DIEM3C);
};

#endif