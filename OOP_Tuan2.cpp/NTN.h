#ifndef NTN_H
#define NTN_h

typedef struct NgayThangNam // Tao struct ngay, thang, nam
{
    int ng;
    int th;
    int n;
} NTN;

bool KiemTraNTN(NTN); // Kiem tra dieu kien nhap
void NhapNTN(NTN &);
int SoNgayTrongThang(int);  // tra ve so nagy cua thang a
void FindTheNextDay(NTN &); // Tim ngay ke tiep va in ra man hinh

#endif
