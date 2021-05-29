#ifndef __MATRAN_H__
#define __MATRAN_H__
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

typedef class MATRAN // Viết tắt MATRAN thành MT
{
    int sd;  // Số dòng của ma trận
    int sc;  // Số cột của ma trận
    int **p; // Con trỏ tới vùng nhớ động chứa các phần tử ma trận
public:
    MATRAN();
    MATRAN(int, int);
    MATRAN(int, int, int **);
    MATRAN(MATRAN &); // Thiết lập sao chép
    ~MATRAN();
    int Get_sd();
    int Get_sc();
    int **Get_p(); // Trả về mảng 2 chiều chứa các phần tử của ma trận
    void Set(int, int, int **);
    void Set(MATRAN);
    void Nhap();
    void Xuat();
    friend bool KiemTra_snt(int); // Kiểm tra tham số đang xét có phải số nguyên tố không
    void LietKe_snt();            // Liệt kê số nguyên tố
    friend bool KiemTra_scp(int); // Kiểm tra tham số đang xét có phải số chính phương không
    int Dem_scp();                // Đếm số chính phương
    friend bool KiemTra_sht(int); // // Kiểm tra tham số đang xét có phải số hoàn thiện không
    int Tong_sht();               // Tổng của các số hoàn thiện trong mảng
    bool KiemTra_sdx(int);        // Kiểm tra tham số đang xét có phải số đối xứng không
    double TBC_sdx();             // Trung bình cộng các số đối xứng
    void SapXep_TrenDong(int);    // Sắp xếp tăng dần trên dòng (tham số truyền vào)
} MT;                             // Viết tắt MATRAN thành MT

#endif