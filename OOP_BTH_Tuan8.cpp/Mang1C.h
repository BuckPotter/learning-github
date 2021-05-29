#ifndef __MANG1C_H__
#define __MANG1C_H__
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
typedef class MANG1C // Viết tắt MANG1C thành M1C
{
    int n;  // Số phần tử của mảng
    int *a; // Con trỏ tới vùng nhớ động chứa các phần tử mảng
public:
    MANG1C();
    MANG1C(int);
    MANG1C(int, int *); // Thiết lập sao chép
    MANG1C(MANG1C &);
    ~MANG1C();
    int Get_n();          // truy xuất số phần tử của mảng của đối tượng
    int *Get_a();         // truy xuất các phần tử của mảng của đối tượng
    MANG1C Get_M1C();     // Truy xuất đối tượng
    void Set(int, int *); // Thiết lập sao chép
    void Set(MANG1C);
    void Nhap();
    void Xuat();
    friend bool KiemTra_snt(int); // Kiểm tra tham số đang xét có phải số nguyên tố không
    void LietKe_snt();            // Liệt kê số nguyên tố
    friend bool KiemTra_scp(int); // Kiểm tra tham số đang xét có phải số chính phương không
    int Dem_scp();                // Đếm số chính phương
    friend bool KiemTra_sht(int); // // Kiểm tra tham số đang xét có phải số hoàn thiện không
    int Tong_sht();               // Tổng của các số hoàn thiện trong mảng
    friend bool KiemTra_sdx(int); // Kiểm tra tham số đang xét có phải số đối xứng không
    double TBC_sdx();             // Trung bình cộng các số đối xứng
    bool ToanLe();                // Trả về 1 nếu mảng chứa toàn số lẻ, ngược lại trả về 0
    int SoChan_NhoNhat();         // Trả về giá trị của số chẵn nhỏ nhất trong mảng, nếu là mảng toàn lẻ thì thông báo không tìm thấy
    void SapXep_TangDan();
    void SepXep_GiamDan();
    void XoaPhanTu(int);       // Xóa phần tử (vị trí mà tham số truyền vào)
    void ThemPhanTu(int, int); // Tham số đầu tiên là giá trị được thêm vào, tham số thứ 2 là vị trí cần thêm vào
    int TimKiem(int);          // Trả về vị trí xuất hiện của phần tử trong mảng
} M1C;                         // Viết tắt MANG1C thành M1C

#endif