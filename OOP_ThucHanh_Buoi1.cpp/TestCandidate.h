#include "Candidate.h"
#ifndef _TestCandidate
#define _TestCandidate

class TEST
{
    int n;
    CDD *ThiSinh = new CDD[n];

public:
    void Nhap();
    void LietKe(); // liet ke danh sach thi sinh co tong diem lon hon 15
    void Xuat();
    void GiaiPhongBoNho();
};

#endif