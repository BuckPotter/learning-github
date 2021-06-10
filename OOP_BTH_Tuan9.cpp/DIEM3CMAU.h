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
    DIEM3CMAU Get(); // Trả về đối tượng điểm 3 chiều đang xét
    void Set(DIEM3C, MAU);
    void Set(double, double, double, int, int, int);
    bool KiemTraTrung(DIEM3CMAU); // Kiểm tra xem 2 đối tượng DIEM3CMAU đang xét có giống nhau hay không (cả tọa độ lẫn mã màu)
    bool KiemTraHopLe();          // Kiểm tra hợp lệ, chỉ xét mã màu
    bool KiemTraMau(DIEM3CMAU);   // Kiểm tra xem 2 đối tượng có trùng màu (chỉ xét trùng màu) hay không
    void Nhap();
    void Xuat();
    friend istream &operator>>(istream &, DIEM3CMAU &);
    friend ostream &operator<<(ostream &, DIEM3CMAU);
};

#endif