#ifndef __DIEM3C_H__
#define __DIEM3C_H__
#include "DIEM.cpp"
class DIEM3C : public DIEM
{
protected:
    int z; // cao độ

public:
    DIEM3C(double = 0, double = 0, double = 0);
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
    bool KiemTraTamGiac(DIEM3C, DIEM3C);
    double ChuVi(DIEM3C, DIEM3C);
    double DienTich(DIEM3C, DIEM3C);
    friend istream &operator>>(istream &, DIEM3C &);
    friend ostream &operator<<(ostream &, DIEM3C);
};

#endif