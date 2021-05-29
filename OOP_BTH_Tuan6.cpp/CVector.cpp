#include "CVector.h"

CV::CVECTOR() // Không có tham số truyền vào, mặc định là không gian 1 chiều (là số 0)
{
    n = 1;
    toado.resize(1);
    toado.push_back(0);
}

CV::CVECTOR(int sochieu)
{
    n = sochieu;
    toado.resize(n);
    for (int i = 0; i < n; i++) // Mặc định là vector 0 trong không gian n chiều tương ứng nều không có tham số tượng trưng cho tọa độ được truyền vào
        toado[i] = 0;
}

CV::CVECTOR(int sochieu, vector<double> toado_cv)
{
    n = sochieu;
    toado = toado_cv;
}

int CV::Get_n()
{
    return n;
}

vector<double> CV::Get_toado()
{
    return toado;
}

void CV::Set_n(int sochieu)
{
    n = sochieu;
}

void CV::Set_toado(vector<double> toado_cv)
{
    toado = toado_cv;
}

void CV::Nhap()
{
    do
    {
        cout << "Nhap so chieu: ";
        cin >> n;
        toado.resize(n);
        cout << "Nhap vao " << n << " so, tuong ung voi toa do cua vector:\n";
        for (int i = 0; i < n; i++)
            cin >> toado[i];
        if (n <= 0)
            cout << "Vector vua nhap khong hop le. Vui long nhap lai!!!\n";
    } while (n <= 0);
}

void CV::Xuat()
{
    cout << "Vector dang xet co toa do (";
    for (int i = 0; i < n; i++)
    {
        cout << toado[i];
        if (i < n - 1)
            cout << ", ";
    }
    cout << ") trong khong gian " << n << " chieu";
}

istream &operator>>(istream &is, CV &cv)
{
    do
    {
        cout << "Nhap so chieu: ";
        is >> cv.n;
        cv.toado.resize(cv.n);
        cout << "Nhap vao " << cv.n << " so, tuong ung voi toa do cua vector:\n";
        for (int i = 0; i < cv.n; i++)
            is >> cv.toado[i];
        if (cv.n <= 0)
            cout << "Vector vua nhap khong hop le. Vui long nhap lai!!!\n";
    } while (cv.n <= 0);
    return is;
}

ostream &operator<<(ostream &os, CV cv)
{
    os << "Vector dang xet co toa do (";
    for (int i = 0; i < cv.n; i++)
    {
        os << cv.toado[i];
        if (i < cv.n - 1)
            os << ", ";
    }
    os << ") trong khong gian " << cv.n << " chieu";
    return os;
}

CV CV::operator+(CV cv) // Chỉ có thể cộng 2 vector có cùng số chiều
{
    CV tong(n);
    for (int i = 0; i < n; i++)
        tong.toado[i] = toado[i] + cv.toado[i];
    return tong;
}

CV CV::operator-(CV cv)
{
    CV hieu(n);
    for (int i = 0; i < n; i++)
        hieu.toado[i] = toado[i] - cv.toado[i];
    return hieu;
}

CV CV::operator*(int k)
{
    for (int i = 0; i < n; i++)
        toado[i] *= k;
    return *this;
}

CV CV::operator/(int k)
{
    for (int i = 0; i < n; i++)
        toado[i] /= k;
    return *this;
}

bool CV::operator==(CV cv)
{
    if (n != cv.n)
        return 0;
    for (int i = 0; i < n; i++)
        if (toado[i] != cv.toado[i])
            return 0;
    return 1;
}

bool CV::operator!=(CV cv)
{
    return !(*this == cv);
}

bool CV::operator>(CV cv)
{
}