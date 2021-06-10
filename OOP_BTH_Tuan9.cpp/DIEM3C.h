#ifndef __DIEM3C_H__
#define __DIEM3C_H__
#include "DIEM.cpp"

class DIEM3C : public DIEM
{
protected:
    int z; // cao độ

public:
    DIEM3C(double = 0, double = 0, double = 0);
    ~DIEM3C();         // Đặt lại điểm về gốc tọa độ
    DIEM3C Get();      // Trả về điểm có tọa độ của điểm đang xét
    double GetZ();     // Bổ sung thêm GetZ so với lớp cha DIEM
    void SetZ(double); // Bổ sung thêm SetZ so với lớp cha DIEM
    void SetXYZ(DIEM, double = 0);
    void SetXYZ(double, double, double); // Thiết lập tọa độ x y và z
    bool KiemTra(DIEM3C);                // Kiểm tra 2 điểm ba chiều có trùng nhau không
    void DiChuyen(double = 0, double = 0, double = 0);
    double KhoangCach(DIEM3C); // Trả về khoảng cách của 2 điểm trong không gian Oxyz
    DIEM3C DiemDoiXung();      // Trả về 1 điêm là điểm đối xứng của điểm đang xét qua O
    void Nhap();
    void Xuat();
    bool KiemTraTamGiac(DIEM3C, DIEM3C); // Kiểm tra 3 điểm trong Oxyz có tạo thành tam giác được không
    double ChuVi(DIEM3C &, DIEM3C &);    // Tham chiếu để thay đổi điểm khi nhập lại trong trường hợp tam giác không hợp lệ
    double DienTich(DIEM3C &, DIEM3C &); // Tham chiếu để thay đổi điểm khi nhập lại trong trường hợp tam giác không hợp lệ
    friend istream &operator>>(istream &, DIEM3C &);
    friend ostream &operator<<(ostream &, DIEM3C);
};

#endif
