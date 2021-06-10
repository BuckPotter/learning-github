#ifndef __DIEMMAU3C_H__
#define __DIEMMAU3C_H__
#include "DIEM3C.h"

class DIEMMAU3C : public DIEM3C
{
protected:
    int r;
    int gr;
    int bl;

public:
    DIEMMAU3C(double = 0, double = 0, double = 0, int = 0, int = 0, int = 0);
    DIEMMAU3C(DIEM3C, int = 0, int = 0, int = 0);
    ~DIEMMAU3C();    // Đưa tọa độ điểm về lại gốc tọa độ mà đưa các giá trị màu về lại 0
    DIEMMAU3C Get(); // Trả về đối tượng đang xét
    int Get_R();
    int Get_G();
    int Get_B();
    void Set_Mau(int = 0, int = 0, int = 0);
    bool KiemTraMau();               // Kiểm tra các mã màu đã hợp lệ chưa
    bool KiemTraTrungMau(DIEMMAU3C); // Kiểm tra 2 đối tượng có trùng màu với nhau không
    void Nhap();
    void Xuat();
    friend istream &operator>>(istream &, DIEMMAU3C &);
    friend ostream &operator<<(ostream &, DIEMMAU3C);
};

#endif