#include <iostream>
#include <iomanip>
#ifndef BANGCUUCHUONG_H
#define BANGCUUCHUONG_H

class BANGCUUCHUONG
{
    int n, m;

public:
    BANGCUUCHUONG();
    BANGCUUCHUONG(int);
    BANGCUUCHUONG(int, int);
    void Nhap();      // Nhập vào giá trị m va 2 n
    void In_BCC();    // In ra màn hình bảng cửu chương n
    void In_BCC_MN(); // In ra màn hình bảng cửu chương từ n đến m
    void In_BCC_TH(); // In ra màn hình bảng cửu chương tổng hợp từ 2 đến 9
};

typedef BANGCUUCHUONG BCC;
#endif