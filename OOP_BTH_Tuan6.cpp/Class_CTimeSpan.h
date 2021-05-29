#ifndef _CTIMESPAN
#define _CTIMESPAN
#include <iostream>
using namespace std;
class CTimeSpan
{
    int h; // giờ
    int m; // phút
    int s; // giây

public:
    CTimeSpan();
    CTimeSpan(int);
    CTimeSpan(int, int);
    CTimeSpan(int, int, int);
    int Get_h();
    int Get_m();
    int Get_s();
    CTimeSpan Get_CTIMESPAN();
    void Set_h(int);
    void Set_m(int);
    void Set_s(int);
    void Set(int, int, int);
    void Nhap();
    void Xuat();
    void Chuan_Hoa(); // chuẩn hóa khoảng thời gian, giả sử 1 khoảng thời gian 1h 80m 90s sẽ cần chuẩn hóa thành 2h 21m 30s
    friend istream &operator>>(istream &, CTP &time);
    friend ostream &operator<<(ostream &, CTP time);
    CTimeSpan operator+(CTimeSpan);
    CTimeSpan operator-(CTimeSpan);
    bool operator>(CTimeSpan);
    bool operator<(CTimeSpan);
    bool operator>=(CTimeSpan);
    bool operator<=(CTimeSpan);
    bool operator!=(CTimeSpan);
    bool operator==(CTimeSpan);
};

typedef CTimeSpan CTP;

#endif