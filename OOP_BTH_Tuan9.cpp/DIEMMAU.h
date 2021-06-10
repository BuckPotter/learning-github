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
    void Set(DIEM, int = 0, int = 0, int = 0);
    void Set(double = 0, double = 0, int = 0, int = 0, int = 0); // Phương thức Set, thiết lập giá tọa độ và mã màu
    bool KiemTraHopLe();                                         // Chỉ cần kiểm tra mã màu
    bool KiemTraTrung(DIEMMAU);                                  // Kiểm tra 2 DIEMMAU có giống nhau không (cả tọa độ và mã màu)
    void Nhap();
    void Xuat();
    friend istream &operator>>(istream &, DIEMMAU &);
    friend ostream &operator<<(ostream &, DIEMMAU);
};

#endif