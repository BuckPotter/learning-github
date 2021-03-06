#include "CDate.h"

DATE::DATE()
{
    ng = th = 1;
    n = 0;
}

DATE::DATE(int ngay)
{
    ng = ngay;
    th = n = 1;
}

DATE::DATE(int ngay, int thang)
{
    ng = ngay;
    th = thang;
    n = 1;
}

DATE::DATE(int ngay, int thang, int nam)
{
    ng = ngay;
    th = thang;
    n = nam;
}

int DATE::Get_ng()
{
    return ng;
}

int DATE::Get_th()
{
    return th;
}

int DATE::Get_n()
{
    return n;
}

void DATE::Set_ng(int ngay)
{
    ng = ngay;
}
void DATE::Set_th(int thang)
{
    th = thang;
}

void DATE::Set_n(int nam)
{
    n = nam;
}

void DATE::Set_NgThN(int ngay, int thang, int nam)
{
    ng = ngay;
    th = thang;
    n = nam;
}

bool DATE::KiemTraHopLe()
{
    if (th > 12 || th < 1 || ng < 1)
        return 0;
    switch (th)
    {
        // Truong hop cac thang 31 ngay
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (ng > 31)
            return 0;
        break;

        // Truong hop cac thang 30 ngay
    case 4:
    case 6:
    case 9:
    case 11:
        if (ng > 30)
            return 0;
        break;

        // Truong hop thang 2
    case 2:
        if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) // Kiem tra nam nhuan
            if (ng > 29)
                return 0;
            else
                return 1;
        else if (ng > 28)
            return 0;
        break;
    }

    // Neu vuot qua tat ca cac dieu kien ben tren thi dieu kien nhap chac chac dung
    return 1;
}

void DATE::Nhap()
{
    cout << "Nhap vao lan luot ngay - thang - nam:\n";
    do
    {
        cout << "\tNhap ngay: ";
        cin >> ng;
        cout << "\tNhap thang: ";
        cin >> th;
        cout << "\tNhap nam: ";
        cin >> n;
        if (this->KiemTraHopLe() == 0)
            cout << "Ngay ban vua nhap khong hop le. vui long nhap lai!!!\n";
    } while (this->KiemTraHopLe() == 0);
}

void DATE::Xuat()
{
    cout << "Ngay dang xet la: ngay " << ng << " thang " << th << " nam " << n;
}

void DATE::Them_1ng()
{
    switch (th)
    {
    // Truong hop cac thang co 31 ngay
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
        if (ng < 31)
            ng++;
        else //ngay 31 thi tang thang va dat lai ngay
        {
            th++;
            ng = 1;
        }
        break;
    case 12:
        if (ng < 31)
            ng++;
        else //ng??y 31 th??ng 12 th?? n??m sau s??? sang n??m m???i
        {
            th = 1;
            ng = 1;
            n++;
        }
        break;

    // Truong hop thang 2
    case 2:
        if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) //Neu nam nhuan;
        {
            if (ng < 29)
                ng++;
            else
            {
                th++;
                ng = 1;
            }
        }
        else
        {
            if (ng < 28)
                ng++;
            else
            {
                th++;
                ng = 1;
            }
        }
        break;

    //Truong hop cac thang co 30 ngay
    case 4:
    case 6:
    case 9:
    case 11:
        if (ng < 30)
            ng++;
        else
        {
            th++;
            ng = 1;
        }
        break;
    }
}

void DATE::Bot_1ng()
{
    switch (th)
    {
    case 1:
        if (ng == 1) // Ng??y 1 th??ng 1, gi???m ??i 1 ng??y s??? l?? ng??y 31 th??ng 12 c???a n??m tr?????c
        {
            th = 12;
            ng = 31;
            n--;
        }
        else
            ng--;
        break;
    case 3:
        if (ng != 1)
            ng--;
        else
        {
            if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) // n???u n??m nhu???n
            {
                ng = 29;
                th--;
            }
            else
            {
                ng = 28;
                th--;
            }
        }
        break;
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (ng == 1) // Ng??y b???ng 1 th?? gi???m th??ng, v?? ?????t l???i ng??y l?? 30 v?? th??ng tr?????c ???? l?? th??ng 30 ng??y
        {
            th--;
            ng = 30;
        }
        else
            ng--;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        if (ng == 1)
        {
            th--;
            ng = 31; // Ng??y b???ng 1 th?? gi???m th??ng, v?? ?????t l???i ng??y l?? 31 v?? th??ng tr?????c ???? l?? th??ng 31 ng??y
        }
        else
            ng--;
        break;
    case 2:
        if (ng == 1)
        {
            th--;
            ng = 31;
        }
        else
            ng--;
        break;
    }
}

int DATE::KhoangCach(DATE time)
{
    if (this->KiemTraTrung(time))
        return 0;
    int dem = 0;
    DATE tam;
    if (n > time.n)
    {
        tam = time;
        while (this->KiemTraTrung(tam) == 0)
        {
            dem++;
            tam.Them_1ng(); // T??ng ng??y l??n, ?????n khi n??o 2 ng??y tr??ng nhau
        }
    }
    else if (n == time.n)
    {
        if (th > time.th)
        {
            tam = time;
            while (this->KiemTraTrung(tam) == 0)
            {
                dem++;
                tam.Them_1ng(); // T??ng ng??y l??n, ?????n khi n??o 2 ng??y tr??ng nhau
            }
        }
        else if (th < time.th)
        {
            tam = *this;
            while (time.KiemTraTrung(tam) == 0)
            {
                dem++;
                tam.Them_1ng(); // T??ng ng??y l??n, ?????n khi n??o 2 ng??y tr??ng nhau
            }
        }
        else // n??m b???ng nhau v?? th??ng c??ng b???ng nhau
        {
            return abs(ng - time.ng);
        }
    }
    else
    {
        tam = *this;
        while (time.KiemTraTrung(tam) == 0)
        {
            dem++;
            tam.Them_1ng(); // T??ng ng??y l??n, ?????n khi n??o 2 ng??y tr??ng nhau
        }
    }
    return dem;
}

bool DATE::KiemTraTrung(DATE time)
{
    if (ng != time.ng || th != time.th || n != time.n)
        return 0;
    return 1;
}

DATE DATE::Cong(int a) // C???ng v??o ng??y ??ang x??t a ng??y v?? tr??? v??? ng??y m???i
{
    DATE cong = *this;
    for (int i = 0; i < a; i++)
        cong.Them_1ng();
    return cong;
}

DATE DATE::Tru(int a) // C???ng v??o ng??y ??ang x??t a ng??y v?? tr??? v??? ng??y m???i
{
    DATE tru = *this;
    for (int i = 0; i < a; i++)
        tru.Bot_1ng();
    return tru;
}
