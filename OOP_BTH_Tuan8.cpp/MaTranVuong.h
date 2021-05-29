#ifndef __MATRANVUONG_H__
#define __MATRANVUONG_H__
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class MTV
{
    int n;   // Cấp của ma trận vuông
    int **p; //Con trỏ tới vùng nhớ động chứa các phần tử ma trận
public:
    MTV();
    MTV(int);
    MTV(int, int **); // Thiết lập sao chép
    MTV(MTV &);       // Thiết lập sao chép
    ~MTV();
    int Get_n();
    int **Get_p();         // Trả về mảng 2 chiều chứa các phần tử của ma trận
    void Set(int, int **); // Thiết lập sao chép
    void Set(MTV mtv);
    void Nhap();
    void Xuat();
    void LietKe_PhanTuLeTrenDCC();          // Liệt kê các phần tử lẻ trên ĐCC
    int SoPhanTu_CoHangDonViLa3TrenDCP();   // Trả về số lượng phần tử có hàng đơn vị là 3 trên đường chéo phụ
    bool KiemTra_PhanTuAmNuaMangTrenDCC();  // Kiểm tra có phần tử âm ở nủa mảng trên DCC hay không
    int PhanTuChanDauTien_NuaMangDuoiDCP(); // Trả về giá trị của phần tử chẵn đầu tiên ở mảng dưới DCP, nếu không có trả về 1
    void SapXepGiamDan_TrenDCP();           // Sắp xếp tăng dần trên trên đường chéo phụ
};

#endif