#ifndef __CVECTOR_H__
#define __CVECTO_H__
#include <iostream>
#include <vector>
using namespace std;

class CVECTOR
{
    int n;                // Số chiều của vector
    vector<double> toado; // 1 mảng gồm n phần tử là tọa độ trong không gian n chiều
public:
    CVECTOR();    // Không có tham số truyền vào, mặc định là không gian 1 chiều (là số 0)
    CVECTOR(int); // Mặc định là vector 0 trong không gian n chiều tương ứng nều không có tham số tượng trưng cho tọa độ được truyền vào
    CVECTOR(int, vector<double>);
    int Get_n();
    vector<double> Get_toado();
    void Set_n(int);
    void Set_toado(vector<double>);
    void Nhap();
    void Xuat();
    friend istream &operator>>(istream &, CVECTOR &);
    friend ostream &operator<<(ostream &, CVECTOR);
    CVECTOR operator+(CVECTOR);
    CVECTOR operator-(CVECTOR);
    CVECTOR operator*(int); // Nhân tọa độ của vector với 1 số nguyên
    CVECTOR operator/(int); // Chia tọa độ của vector với 1 số nguyên
    bool operator==(CVECTOR);
    bool operator!=(CVECTOR);
    bool operator>(CVECTOR); // Chỉ áp dụng cho
    bool operator>=(CVECTOR);
    bool operator<(CVECTOR);
    bool operator<=(CVECTOR);
};
typedef CVECTOR CV; // Viết tắt CVECTOR -> CV

#endif