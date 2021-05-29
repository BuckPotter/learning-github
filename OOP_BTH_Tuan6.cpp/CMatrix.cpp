#include "CMatrix.h"
CM::CMATRIX()
{
    sd = 1;
    sc = 1;
    mt.resize(1);
    mt[0].resize(1);
    mt[0][0] = 0;
}

CM::CMATRIX(int dong, int cot)
{
    sd = dong;
    sc = cot;
    mt.resize(dong);
    for (int i = 0; i < dong; i++) // Nếu chỉ truyền tham số cho dòng và cột, mặc định các phần tử trong ma trận đều là 0
    {
        for (int j = 0; j < cot; j++)
            mt[i].push_back(0);
    }
}

CM::CMATRIX(int d, int c, vector<vector<double>> matran)
{
    sd = d;
    sc = c;
    mt = matran;
}

int CM::Get_sd()
{
    return sd;
}

int CM::Get_sc()
{
    return sc;
}

vector<vector<double>> CM::Get_mt()
{
    return mt;
}

void CM::Set_sd(int d)
{
    sd = d;
}

void CM::Set_sc(int c)
{
    sc = c;
}

void CM::Set_mt(vector<vector<double>> matran)
{
    mt = matran;
}

void CM::Nhap()
{
    do
    {
        cout << "Nhap so dong: ";
        cin >> sd;
        cout << "Nhap so cot: ";
        cin >> sc;
        if (sd <= 0 || sc <= 0)
            cout << "Ma tran nay khong hop le. Vui long nhap lai!!!\n";
        // Thiết lập vùng nhớ cho ma trận
        mt.resize(sd);
        for (int i = 0; i < sd; i++)
        {
            mt[i].resize(sc);
        }
        // Nhap lieu
        cout << "Nhap vap cac phan tu cua ma tran:\n";
        for (int i = 0; i < sd; i++)
            for (int j = 0; j < sc; j++)
                cin >> mt[i][j];
    } while (sd <= 0 || sc <= 0);
}

void CM::Xuat()
{
    cout << "Ma tran dang xet la ma tran co " << sd << "x" << sc << ":\n";
    for (int i = 0; i < sd; i++)
    {
        cout << "\t";
        for (int j = 0; j < sc; j++)
            cout << setw(5) << mt[i][j] << " ";
        cout << endl;
    }
}

istream &operator>>(istream &is, CM &cm)
{
    do
    {
        cout << "Nhap so dong: ";
        is >> cm.sd;
        cout << "Nhap so cot: ";
        is >> cm.sc;
        if (cm.sd <= 0 || cm.sc <= 0)
            cout << "Ma tran nay khong hop le. Vui long nhap lai!!!\n";
        // Thiết lập vùng nhớ cho ma trận
        cm.mt.resize(cm.sd);
        for (int i = 0; i < cm.sd; i++)
        {
            cm.mt[i].resize(cm.sc);
        }
        // Nhap lieu
        cout << "Nhap vap cac phan tu cua ma tran:\n";
        for (int i = 0; i < cm.sd; i++)
            for (int j = 0; j < cm.sc; j++)
                is >> cm.mt[i][j];
    } while (cm.sd <= 0 || cm.sc <= 0);
    return is;
}

ostream &operator<<(ostream &os, CM cm)
{
    os << "Ma tran dang xet la ma tran co " << cm.sd << "x" << cm.sc << ":\n";
    for (int i = 0; i < cm.sd; i++)
    {
        os << "\t";
        for (int j = 0; j < cm.sc; j++)
            os << setw(5) << cm.mt[i][j] << " ";
        os << endl;
    }
    return os;
}

CM CM::operator+(CM cm) // Chỉ có thể cộng 2 ma trận nếu 2 ma trận đó có cùng cỡ
{
    CM tong(sd, sc);
    for (int i = 0; i < sd; i++)
        for (int j = 0; j < sc; j++)
            tong.mt[i][j] = mt[i][j] + cm.mt[i][j];
    return tong;
}

CM CM::operator-(CM cm) // Chỉ có thể trừ 2 ma trận nếu 2 ma trận đó có cùng cỡ
{
    CM hieu(sd, sc);
    for (int i = 0; i < sd; i++)
        for (int j = 0; j < sc; j++)
            hieu.mt[i][j] = mt[i][j] - cm.mt[i][j];
    return hieu;
}

CM CM::operator*(int k)
{
    CM phu(sd, sc, mt); // Dùng biến phụ để không làm thay đổi giá trị của ma trận
    for (int i = 0; i < sd; i++)
        for (int j = 0; j < sc; j++)
            phu.mt[i][j] *= k;
    return phu;
}

CM operator*(int k, CM cm) // overloading cho định dạng số*(ma trận). Nếu không có hàm này thì viết lệnh k*a sẽ bị báo lỗi
{
    for (int i = 0; i < cm.sd; i++)
        for (int j = 0; j < cm.sc; j++)
            cm.mt[i][j] *= k;
    return cm;
}

CM CM::operator/(int k)
{
    CM phu(sd, sc, mt); // Dùng biến phụ để không làm thay đổi giá trị của ma trận
    for (int i = 0; i < sd; i++)
        for (int j = 0; j < sc; j++)
            phu.mt[i][j] /= k;
    return phu;
}

CM CM::operator*(CM cm) // Nhân 2 ma trận với nhau
{
    // Điều kiện có thể nhân được là số cột của ma trận trước phải = số dòng của ma trận sau
    CM tich(sd, cm.sc); // Ma trận tích của 2 ma trận sẽ có số dòng của ma trận trước và số cột của ma trận sau
    for (int i = 0; i < sd; i++)
        for (int j = 0; j < cm.sc; j++)
        {
            for (int k = 0; k < sc; k++)
                tich.mt[i][j] += mt[i][k] * cm.mt[k][j];
        }
    return tich;
}

CMATRIX CMATRIX::operator*(CVECTOR cv) // Nhân ma trận với vector CVECTOR
{
    // Điều kiện có thể nhân được là số cột của ma trận phải = số phần tử trong tọa độ vector
    CM tich(sc, 1);                     // Xem vector trong không gian n chiều là ma trận n dòng và 1 cột
    vector<double> vt = cv.Get_toado(); // Sao chép tọa độ của vector sang mảng vt
    for (int i = 0; i < sd; i++)
        for (int j = 0; j < sd; j++)
            tich.mt[i][0] += mt[i][j] * vt[j]; // Ma trận tích của 1 ma trận và 1 vector sẽ chỉ có 1 cột
    return tich;
}
