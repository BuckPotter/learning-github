#ifndef __CMATRIX_H__
#define __CMATRIX_H__
#include "CVector.cpp"
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

class CMATRIX
{
    int sd;                    // Số dòng của ma trận
    int sc;                    // Số cột của ma trận
    vector<vector<double>> mt; // Mảng động 2 chiều chứa các phần tử của ma trận
public:
    CMATRIX();
    CMATRIX(int, int);
    CMATRIX(int, int, vector<vector<double>>);
    int Get_sd();
    int Get_sc();
    vector<vector<double>> Get_mt();
    void Set_sd(int);
    void Set_sc(int);
    void Set_mt(vector<vector<double>>);
    void Nhap();
    void Xuat();
    friend istream &operator>>(istream &, CMATRIX &cm);
    friend ostream &operator<<(ostream &, CMATRIX cm);
    CMATRIX operator+(CMATRIX);
    CMATRIX operator-(CMATRIX);
    CMATRIX operator*(int);                 // Nhân 1 số vào ma trận
    friend CMATRIX operator*(int, CMATRIX); // Nếu không có hàm này thì viết lệnh k*a sẽ bị báo lỗi
    CMATRIX operator/(int);                 // Chia 1 số cho ma trận
    CMATRIX operator*(CMATRIX);
    CMATRIX operator*(CVECTOR);
};

typedef CMATRIX CM;

#endif