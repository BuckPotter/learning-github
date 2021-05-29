#ifndef Phan_So_H
#define Phan_So_H

typedef struct PhanSo
{
    int ts;
    int ms;
} PS;

void NhapPS(PS &);
int UCLN(int, int);
PS ToiGianPS(PS);
void XuatPS(PS);
PS Tong2PS(PS, PS);
PS Hieu2PS(PS, PS);
PS Tich2PS(PS, PS);
PS Thuong2PS(PS, PS);
float GiaTriThuc(PS);

#endif