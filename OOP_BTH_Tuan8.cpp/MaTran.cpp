#include "MaTran.h"

MT::MATRAN() // Xem như là ma trận 1x1 có 1 phần tử là 0
{
    sd = 1;
    sc = 1;
    p = new int *[1];
    p[0] = new int[1];
    p[0][0] = 0;
}

MT::MATRAN(int dong, int cot)
{
    sd = dong;
    sc = cot;
    // Cấp phát vùng nhớ cho ma trận
    p = new int *[sd];
    for (int i = 0; i < sd; i++)
        p[i] = new int[sc];
    // Không có tham số cho các phần tử trong ma trận nên mặc định các phần tử trong ma trận đều là 0
    for (int i = 0; i < sd; i++)
        for (int j = 0; j < sc; j++)
            p[i][j] = 0;
}

MT::MATRAN(int dong, int cot, int **mt)
{
    sd = dong;
    sc = cot;
    // Cấp phát vùng nhớ
    p = new int *[sd];
    for (int i = 0; i < sd; i++)
        p[i] = new int[sc];
    // Sao chép
    for (int i = 0; i < sd; i++)
        for (int j = 0; j < sc; j++)
            p[i][j] = mt[i][j];
}

MT::MATRAN(MT &mt) // Thiết lập sao chép
{
    sd = mt.sd;
    sc = mt.sc;
    p = new int *[sd];
    for (int i = 0; i < sd; i++)
        p[i] = new int[sc];
    for (int i = 0; i < sd; i++)
        for (int j = 0; j < sc; j++)
            p[i][j] = mt.p[i][j];
}

MT::~MATRAN()
{
    for (int i = 0; i < sd; i++)
    {
        delete[] p[i];
        p[i] = nullptr;
    }
    delete[] p;
    p = nullptr;
    sd = 0;
    sc = 0;
}

int MT::Get_sd()
{
    return sd;
}

int MT::Get_sc()
{
    return sc;
}

int **MT::Get_p()
{
    return p;
}

void MT::Set(int dong, int cot, int **mt) // Thiết lập sao chép
{
    if (sd == dong && sc == cot) // Nếu dong và cột từ tham số trùng với dòng và cột của *this thì không cần xóa vùng nhớ
    {
        for (int i = 0; i < sd; i++)
            for (int j = 0; j < sc; j++)
                p[i][j] = mt[i][j];
    }
    else
    {
        // Xóa vùng nhớ cũ
        for (int i = 0; i < sd; i++)
            delete[] p[i];
        delete[] p;
        sd = dong;
        sc = cot;
        // Cấp phát vùng nhớ mới
        p = new int *[sd];
        for (int i = 0; i < sd; i++)
            p[i] = new int[sc];
        // Sao chép
        for (int i = 0; i < sd; i++)
            for (int j = 0; j < sc; j++)
                p[i][j] = mt[i][j];
    }
}

void MT::Set(MT mt) // Thiết lập sao chép
{
    if (sd == mt.sd && sc == mt.sc) // Nếu dòng và cột từ tham số trùng với dòng và cột của *this thì không cần xóa vùng nhớ
    {
        for (int i = 0; i < sd; i++)
            for (int j = 0; j < sc; j++)
                p[i][j] = mt.p[i][j];
    }
    else
    {
        // Xóa vùng nhớ cũ
        for (int i = 0; i < sd; i++)
            delete[] p[i];
        delete[] p;
        sd = mt.sd;
        sc = mt.sc;
        // Cấp phát vùng nhớ mới
        p = new int *[sd];
        for (int i = 0; i < sd; i++)
            p[i] = new int[sc];
        // Sao chép
        for (int i = 0; i < sd; i++)
            for (int j = 0; j < sc; j++)
                p[i][j] = mt.p[i][j];
    }
}

void MT::Nhap()
{
    do
    {
        cout << "Nhap so dong: ";
        cin >> sd;
        cout << "Nhap so cot: ";
        cin >> sc;
        if (sd <= 0 || sc <= 0)
        {
            cout << "Ma tran nay khong hop le. Vui long nhap lai!!!\n";
            continue;
        }
        // Thiết lập vùng nhớ cho ma trận
        p = new int *[sd];
        for (int i = 0; i < sd; i++)
            p[i] = new int[sc];
        // Nhap lieu
        cout << "Nhap vap cac phan tu cua ma tran:\n";
        for (int i = 0; i < sd; i++)
            for (int j = 0; j < sc; j++)
                cin >> p[i][j];
    } while (sd <= 0 || sc <= 0);
}

void MT::Xuat()
{
    cout << "Ma tran dang xet la ma tran co " << sd << "x" << sc << ":\n";
    for (int i = 0; i < sd; i++)
    {
        cout << "\t";
        for (int j = 0; j < sc; j++)
            cout << setw(5) << p[i][j] << " ";
        cout << endl;
    }
}

bool KiemTra_snt(int x) // Kiểm tra tham số đang xét có phải số nguyên tố không
{
    if (x < 2)
        return 0;
    for (int i = 2; i <= x / 2; i++)
        if (x % i == 0)
            return 0;
    return 1;
}

void MT::LietKe_snt() // Liệt kê số nguyên tố
{
    cout << "Cac phan tu la so nguyen to trong ma tran dang xet la: ";
    for (int i = 0; i < sd; i++)
        for (int j = 0; j < sc; j++)
            if (KiemTra_snt(p[i][j]))
                cout << p[i][j] << " ";
}

bool KiemTra_scp(int x) // Kiểm tra tham số đang xét có phải số chính phương không
{
    for (int i = 0; i <= sqrt(x); i++)
        if (i * i == x)
            return 1;
    return 0;
}

int MT::Dem_scp() // Đếm số chính phương
{
    int dem = 0;
    for (int i = 0; i < sd; i++)
        for (int j = 0; j < sc; j++)
            if (KiemTra_scp(p[i][j]))
                dem++;
    return dem;
}

bool KiemTra_sht(int x) // // Kiểm tra tham số đang xét có phải số hoàn thiện không
{
    int sum = 1;
    for (int i = 2; i < x; i++)
        if (x % i == 0)
            sum += i;
    return (x == sum);
}

int MT::Tong_sht() // Tổng của các số hoàn thiện trong mảng
{
    int sum = 0;
    for (int i = 0; i < sd; i++)
        for (int j = 0; j < sc; j++)
            if (KiemTra_sht(p[i][j]))
                sum += p[i][j];
    return sum;
}

bool MT::KiemTra_sdx(int x) // Kiểm tra tham số đang xét có phải số đối xứng không
{
    // Chuyển int sang string
    string input = to_string(x);
    int n = input.length();
    if (n == 1)
        return 1;
    if (n % 2 == 0) // Trường hợp chuỗi có độ dài chẵn
    {
        for (int i = 0; i <= n / 2; i++)
            if (input[i] != input[n - 1 - i])
                return 0;
    }
    else // Trường hợp chuỗi có độ dài lẻ
    {
        for (int i = 0; i < n / 2; i++)
            if (input[i] != input[n - 1 - i])
                return 0;
    }

    return 1;
}

double MT::TBC_sdx() // Trung bình cộng các số đối xứng
{
    int dem = 0, sum = 0;
    for (int i = 0; i < sd; i++)
        for (int j = 0; j < sc; j++)
            if (KiemTra_sdx(p[i][j]))
                dem++;
    if (dem == 0) // Trường hợp không có số đối xứng nào
        return 0;
    return (double)sum / dem;
}

void MT::SapXep_TrenDong(int k) // Sắp xếp tăng dần trên dòng k
{
    if (k < 0 || k > sd - 1) // Nếu dòng cần sắp xếp nằm ngoài phạm vi thì dùng thuật toán
        return;
    int tam;
    for (int i = 0; i < sd - 1; i++) // Bubble sort
        for (int j = sd - 1; j > i; j--)
            if (p[k][j] < p[k][j - 1])
            {
                tam = p[k][j];
                p[k][j] = p[k][j - 1];
                p[k][j - 1] = tam;
            }
}