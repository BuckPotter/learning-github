#ifndef Sinh_Vien_H
#define Sinh_Vien_H

typedef struct SinhVien
{
    char id[15];
    char ten[20];
    short toan;
    short van;
    float DTB;
    short hocbong;
} SV;

void NhapSV(SV &);
void XuatSV(SV);
void XepLoaiSV(float);
void NhapLop(SV[], int &);
void XuatLop(SV[], int);
void DS_HocSinhYeu(SV[], int);        // in ra man hinh dnah sach cac hoc sinh yeu trong lop
int TongSoHSTB(SV[], int);            // tra ve so luong hoc sinh trung binh trong lop
int TongHocBong_HSXuatSac(SV[], int); // tra ve so tien hoc bong da trao cho cac hoc sinh xuat sac
float DTBChung_HSG(SV[], int);        // tra ve diem trung binh chung trong cac hoc sinh gioi
bool KiemTraHSY(SV[], int);           // kiem tra co hoc sinh yeu khong
void SapXepGiamDan(SV[], int);        // Sap xep giam dan theo hoc bong
void TimSV(SV[], int);                // Tim hoc sinh trong lop
void LietKeSV_ten(SV[], int);
#endif