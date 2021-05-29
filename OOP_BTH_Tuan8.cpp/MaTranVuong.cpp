#include "MaTranVuong.h"

MTV::MTV()
{
    n = 1;
    p = new int *[1];
    p[0] = new int[1];
    p[0][0] = 0;
}

MTV::MTV(int nn)
{
    n = nn;
    p = new int *[n];
    // Cấp phát vùng nhớ
    for (int i = 0; i < n; i++)
        p[i] = new int[n];
    // mặc định các phần tử đều là 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            p[i][j] = 0;
}

MTV::MTV(int nn, int **mt)
{
    n = nn;
    p = new int *[n];
    for (int i = 0; i < n; i++)
        p[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            p[i][j] = mt[i][j];
}

MTV::MTV(MTV &mtv) // Thiết lập sao chép
{
    n = mtv.n;
    p = new int *[n];
    for (int i = 0; i < n; i++)
        p[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            p[i][j] = mtv.p[i][j];
}

MTV::~MTV()
{
    for (int i = 0; i < n; i++)
    {
        delete[] p[i];
        p[i] = nullptr;
    }
    delete[] p;
    p = nullptr;
    n = 0;
}

int MTV::Get_n()
{
    return n;
}

int **MTV::Get_p()
{
    return p;
}

void MTV::Set(int nn, int **mt)
{
    if (n == nn) // Nếu dong và cột từ tham số trùng với dòng và cột của *this thì không cần xóa vùng nhớ
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                p[i][j] = mt[i][j];
    }
    else
    {
        // Xóa vùng nhớ cũ
        for (int i = 0; i < n; i++)
            delete[] p[i];
        delete[] p;
        n = nn;
        // Cấp phát vùng nhớ mới
        p = new int *[n];
        for (int i = 0; i < n; i++)
            p[i] = new int[n];
        // Sao chép
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                p[i][j] = mt[i][j];
    }
}

void MTV::Set(MTV mtv)
{
    if (n == mtv.n) // Nếu dong và cột từ tham số trùng với dòng và cột của *this thì không cần xóa vùng nhớ
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                p[i][j] = mtv.p[i][j];
    }
    else
    {
        // Xóa vùng nhớ cũ
        for (int i = 0; i < n; i++)
            delete[] p[i];
        delete[] p;
        n = mtv.n;
        // Cấp phát vùng nhớ mới
        p = new int *[n];
        for (int i = 0; i < n; i++)
            p[i] = new int[n];
        // Sao chép
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                p[i][j] = mtv.p[i][j];
    }
}

void MTV::Nhap()
{
    do
    {
        cout << "Nhap cap cua ma tran vuong: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "Ma tran nay khong hop le. Vui long nhap lai!!!\n";
            continue;
        }
        // Thiết lập vùng nhớ cho ma trận
        p = new int *[n];
        for (int i = 0; i < n; i++)
            p[i] = new int[n];
        // Nhap lieu
        cout << "Nhap vap cac phan tu cua ma tran:\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> p[i][j];
    } while (n <= 0);
}

void MTV::Xuat()
{
    cout << "Ma tran dang xet la ma tran cap " << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\t";
        for (int j = 0; j < n; j++)
            cout << setw(5) << p[i][j] << " ";
        cout << endl;
    }
}

void MTV::LietKe_PhanTuLeTrenDCC() // Liệt kê các phần tử lẻ trên ĐCC
{
    cout << "Cac phan tu tren duong cheo chinh cua ma tran dang xet la: ";
    for (int i = 0; i < n; i++)
        cout << p[i][i] << " ";
}

int MTV::SoPhanTu_CoHangDonViLa3TrenDCP() // Trả về số lượng phần tử có hàng đơn vị là 3 trên đường chéo phụ
{
    int dem = 0;
    int j = 0;
    for (int i = n - 1; i >= 0; i--)

        if (p[i][j++] % 10 == 3)
            dem++;
    return dem;
}

bool MTV::KiemTra_PhanTuAmNuaMangTrenDCC() // Kiểm tra có phần tử âm ở nủa mảng trên DCC hay không
{
    for (int i = 0; i < n - 1; i++) // Không cần kiểm tra vị trí i = n - 1
        for (int j = i + 1; j < n; j++)
            if (p[i][j] < 0)
                return 1;
    return 0;
}

int MTV::PhanTuChanDauTien_NuaMangDuoiDCP() // Trả về giá trị của phần tử chẵn đầu tiên ở mảng dưới DCP, nếu không có trả về 1
{
    for (int i = 1; i < n; i++)
        for (int j = n - i; j < n; j++)
            if (p[i][j] % 2 == 0)
                return p[i][j];
    return 1; // Return 1 số lẻ nếu như nửa mảng dưới đường chéo phụ không có phần tử nào chẵn
}

void MTV::SapXepGiamDan_TrenDCP() // Sắp xếp giảm dần trên đường chéo phụ
{
    // Chiều giảm dần sẽ là chiều từ góc phải trên xuống góc trái dưới
    int min, tam;
    int i = n - 1, j = 0;
    int k, l;
    int phu1, phu2;             // Biến phu1 và phu2 dùng để lưu lại vị trí của min để thực hiện đổi chỗ
    for (i, j; i > 0; i--, j++) // chọn trực tiếp
    {
        min = p[i][j];
        for (k = i - 1, l = j + 1; k >= 0; k--, l++)
            if (p[k][l] < min)
            {
                min = p[k][l];
                phu1 = k;
                phu2 = l;
            }
        if (min == p[i][j]) // Trường hợp không tìm thấy phần tử nhỏ hơn p[i][j] đang xét thì bỏ qua
            continue;
        // Đổi chỗ
        tam = p[i][j];
        p[i][j] = min;
        p[phu1][phu2] = tam;
    }
}