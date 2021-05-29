#ifndef _HCN
#define _HCN
#include "Diem.h"

class HCN
{
private:
    Diem A; //Điểm chéo trên
    Diem B; //Điểm chéo dưới
public:
    HCN();                                      // Constructor
    HCN(double, double, double, double);        // Constructor
    HCN(Diem, Diem);                            // Constructor
    Diem GetA();                                // phương thức truy xuất, trả về điểm chéo trên
    Diem GetB();                                // phương thức truy xuất, trả về điểm chéo dưới
    void SetA(double, double);                  // phương thức thiết lập tọa độ cho điểm chéo trên với 1 cặp tham số double
    void SetB(double, double);                  // phương thức thiết lập tọa độ cho điểm chéo dưới với 1 cặp tham số double
    void SetA(Diem);                            // phương thức thiết lập tọa độ cho điểm chéo trên với tham số Diem
    void SetB(Diem);                            // phương thức thiết lập tọa độ cho điểm chéo dưới với tham số Diem
    void SetAB(double, double, double, double); // thiết lập tọa độ cho điểm chéo trên và dưới với 2 cặp tham số double tương ứng
    void SetAB(Diem, Diem);                     // thiết lập tọa độ cho điểm chéo trên và dưới với tham số Diem tương ứng
    void Nhap();
    void Xuat();
    void Di_Chuyen(double, double); // tịnh tiến điểm chéo trên và điểm chéo dưới 1 khoảng tương ứng với tham số đầu vào
    double Chu_Vi();
    double Dien_Tich();
    bool Kiem_Tra(); // Kiểm tra HCN có hợp lệ không
    friend istream &operator>>(istream &, HCN &);
    friend ostream &operator<<(ostream &, HCN);
};

#endif