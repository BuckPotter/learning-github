#ifndef __DIEM_H__
#define ___DIEM_H__
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class DIEM
{
protected:
    double x;
    double y;

public:
    DIEM(double = 0, double = 0);
    double GetX();
    double GetY();
    DIEM GetXY();
    void SetX(double);
    void SetY(double);
    void SetXY(double, double);
    void Nhap();
    void Xuat();
    void DiChuyen(double = 0, double = 0);
    bool KiemTra(DIEM);                            // Kiểm tra 2 điểm có trùng nhau hay không
    double KhoangCach(DIEM);                       // Trả về 1 số thực là khoảng cách của 2 điểm
    DIEM DiemDoiXung();                            // Tìm điểm đối xứng của điểm đang xét qua O
    bool KiemTraTamGiac(DIEM, DIEM);               // Kiểm tra 3 đỉnh có thể tạo thành tam giac hay không
    double Chu_Vi_Tam_Giac(DIEM &, DIEM &);        // Tham chiếu để thay đổi điểm khi nhập lại trong trường hợp tam giác không hợp lệ
    double Dien_Tich_Tam_Giac(DIEM &, DIEM &);     // Tham chiếu để thay đổi điểm khi nhập lại trong trường hợp tam giác không hợp lệ
    friend istream &operator>>(istream &, DIEM &); // Đè chồng toán tử >>
    friend ostream &operator<<(ostream &, DIEM);   // Đè chồng toán tử <<
};

#endif
