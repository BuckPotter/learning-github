#ifndef _Candidate
#define _Candidate

class CANDIDATE
{
    char id[10];
    char ten[30];
    int ng; // Ngay sinh
    int th; // Thang sinh
    int n;  // Nam sinh
    int toan;
    int van;
    int anh;
    double DTB;

public:
    void Nhap();
    void Xuat();
    int TongDiem();
    void XepLoaiSV(); // Xep loai hoc luc cua thi sinh
};

typedef CANDIDATE CDD;

#endif