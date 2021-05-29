#ifndef _SoPhuc
#define _SoPhuc
#include <iostream>
using namespace std;
// Quan điểm số thực như 1 số phức đặc biệt -> phần ảo = 0

class SOPHUC
{
    double thuc, ao;

public:
    SOPHUC();                       // constructor
    SOPHUC(double);                 // constructor
    double GetThuc();               // truy xuất phần thực
    double GetAo();                 // truy xuất phần ảo
    void SetThuc(double);           // thiết lập phần thực
    void SetAo(double);             // thiết lập phần ảo
    void SetThucAo(double, double); // thiết lập thực và ảo
    void Nhap();
    void Xuat();
    friend istream &operator>>(istream &, SOPHUC &); // overload toán tử nhập
    friend ostream &operator<<(ostream &, SOPHUC);   // overload toán tử xuất
    SOPHUC operator+(SOPHUC);                        // Đè chồng toán tử +
    SOPHUC operator-(SOPHUC);                        // Đè chồng toán tử -
    SOPHUC operator*(SOPHUC);                        // Đè chồng toán tử *
    SOPHUC operator/(SOPHUC);                        // Đè chồng toán tử /
    bool operator==(SOPHUC);                         // Đè chồng toán tử ==
    bool operator!=(SOPHUC);                         // Đè chồng toán tử !=
    bool operator>(SOPHUC);                          // Chỉ sử dụng cho số thực (số phức đặc biệt có phần ảo = 0)
    bool operator>=(SOPHUC);                         // Chỉ sử dụng cho số thực (số phức đặc biệt có phần ảo = 0)
    bool operator<(SOPHUC);                          // Chỉ sử dụng cho số thực (số phức đặc biệt có phần ảo = 0)
    bool operator<=(SOPHUC);                         // Chỉ sử dụng cho số thực (số phức đặc biệt có phần ảo = 0)
};

typedef SOPHUC SP; // viết tắt SOPHUC thành SP

#endif