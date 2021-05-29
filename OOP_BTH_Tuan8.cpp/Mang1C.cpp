#include "Mang1C.h"

M1C::MANG1C() // Không truyền tham số coi như mảng có 1 phần tử duy nhất là số 0
{
    n = 1;
    a = new int[1];
    a[0] = 0;
}

M1C::MANG1C(int nn) // Nếu chỉ truyền 1 tham số kiểu int cho số lượng phần tử thì mặc định n phần tử này đều là 0
{
    n = nn;
    for (int i = 0; i < n; i++)
        a[i] = 0;
}

M1C::MANG1C(int nn, int *arr) // Thiết lập sao chép
{
    n = nn;
    a = new int[n];             // Tạo vùng nhớ mới để sao chép các phần tử trong mảng arr sang a
    for (int i = 0; i < n; i++) // Sao chép các phần tử trong mảng arr sang a
        a[i] = arr[i];
}

M1C::MANG1C(M1C &arr) // Thiết lập sao chép
{
    n = arr.n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = arr.a[i];
}

M1C::~MANG1C()
{
    n = 0;
    delete[] a;
    a = nullptr;
}

int M1C::Get_n() // truy xuất số phần tử của mảng của đối tượng
{
    return n;
}

int *M1C::Get_a() // truy xuất các phần tử của mảng của đối tượng
{
    return a;
}

M1C M1C::Get_M1C() // Truy xuất đối tượng
{
    return *this;
}

void M1C::Set(int nn, int *arr) // Thiết lập sao chép
{
    n = nn;
    for (int i = 0; i < n; i++)
        a[i] = arr[i];
}

void M1C::Set(M1C arr)
{
    if (n == arr.n)
    {
        for (int i = 0; i < n; i++)
            a[i] = arr.a[i];
    }
    else
    {
        n = arr.n;
        delete[] a;
        a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = arr.a[i];
    }
}

void M1C::Nhap()
{
    do
    {
        cout << "Nhap so luong phan tu: ";
        cin >> n;
        if (n < 0)
            cout << "So luong phan tu cua mang khong the la so am. Vui long nhap lai\n";
    } while (n < 0);
    delete[] a; // Xóa vùng nhớ cũ

    a = nullptr;
    if (n == 0) // Nếu như n = 0 thì không cần thực hiện nữa
        return;

    a = new int[n]; // Thiết lập vùng nhớ mới
    cout << "Nhap vao " << n << " so, ung voi cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void M1C::Xuat()
{
    cout << "Mang dang xet la co " << n << " phan tu.\n";
    cout << "Cac phan tu trong mang la: ";
    for (int i = 0; i < n - 1; i++) // Nếu điều kiện là i < n-1 sẽ bị dư dấu phẩy ở cuối
        cout << a[i] << ", ";
    cout << a[n - 1];
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

void M1C::LietKe_snt() // Liệt kê số nguyên tố
{
    cout << "Cac so nguyen to trong mang dang xet la: ";
    for (int i = 0; i < n; i++)
        if (KiemTra_snt(a[i]))
            cout << a[i] << " ";
}

bool KiemTra_scp(int x) // Kiểm tra tham số đang xét có phải số chính phương không
{
    for (int i = 0; i <= sqrt(x); i++)
        if (i * i == x)
            return 1;
    return 0;
}

int M1C::Dem_scp() // Đếm số chính phương
{
    if (n == 0) // Trường hợp mảng không có phần tử nào
        return 0;
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (KiemTra_scp(a[i]))
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

int M1C::Tong_sht() // Tổng của các số hoàn thiện trong mảng
{
    if (n == 0) // Trường hợp mảng không có phần tử nào
        return 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (KiemTra_sht(a[i]))
            sum += a[i];
    return sum;
}

bool KiemTra_sdx(int x) // Kiểm tra tham số đang xét có phải số đối xứng không
{
    // Chuyển int sang string
    string input = to_string(x);
    int n = input.length();
    if (n == 1)
        return 1;
    if (n % 2 == 0)
    {
        for (int i = 0; i <= n / 2; i++)
            if (input[i] != input[n - 1 - i])
                return 0;
    }
    else
    {
        for (int i = 0; i < n / 2; i++)
            if (input[i] != input[n - 1 - i])
                return 0;
    }
    return 1;
}

double M1C::TBC_sdx() // Trung bình cộng các số đối xứng
{
    if (n == 0) // Trường hợp mảng không có phần tử nào
        return 0;
    int dem = 0, sum = 0;
    for (int i = 0; i < n; i++)

        if (KiemTra_sdx(a[i]))
        {
            sum += a[i];
            dem++;
        }
    if (dem == 0)
        return 0;
    return (double)sum / dem;
}

bool M1C::ToanLe() // Trả về 1 nếu mảng chứa toàn số lẻ, ngược lại trả về 0
{
    if (n == 0) // Trường hợp mảng không có phần tử nào
        return 0;
    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            return 0;
    return 1;
}

int M1C::SoChan_NhoNhat() // Trả về giá trị của số chẵn nhỏ nhất trong mảng, nếu là mảng toàn lẻ thì thông báo không tìm thấy
{
    int min = 1; // Lính canh min = 1
    int i = 0;
    while (i < n)
    {
        if (a[i] % 2 == 0) // Tìm số chẵn đầu tiên trong mảng để gán tạm thời cho min, nếu tìm được thì thoát vòng lặp ngay
        {
            min = a[i];
            break;
        }
        i++;
    }

    if (min == 1) // Ra khỏi vòng lặp trên mà min vẫn là giá trị lính canh 1 thì mảng không có số chẵn nào, dừng tìm kiếm
        return 1; // Trả về 1 số lẻ coi như không có số chẵn nào trong mảng

    for (i; i < n; i++) // Bắt đầu từ vị trí số chẵn đầu tiên tìm được trong vòng lặp while phía trên bắt đầu tìm số chẵn nhỏ nhất trong mảng
        if (a[i] % 2 == 0 && a[i] < min)
            min = a[i];
    return min;
}

void M1C::SapXep_TangDan()
{
    int tam;
    for (int i = 0; i < n - 1; i++) // Bubble sort
        for (int j = n - 1; j > i; j--)
            if (a[j] < a[j - 1])
            {
                tam = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tam;
            }
}

void M1C::SepXep_GiamDan()
{
    int tam;
    for (int i = 0; i < n - 1; i++) // Bubble sort
        for (int j = n - 1; j > i; j--)
            if (a[j] > a[j - 1])
            {
                tam = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tam;
            }
}

void M1C::XoaPhanTu(int pos) // Xóa phần tử (vị trí mà tham số truyền vào)
{
    if (pos < 0 || pos > n - 1) // Trường hợp vị trí cần xóa nằm ngoài mảng
        return;
    if (pos == 0)
        a = a + 1; // Trỏ a sang vùng nhớ kế tiếp phía sau
    else
        for (int i = pos; i < n - 1; i++) // Dời các giá trị
            a[i] = a[i + 1];
    n--; // Giảm số phần tử
}

void M1C::ThemPhanTu(int giatri, int pos) // Tham số đầu tiên là giá trị được thêm vào, tham số thứ 2 là vị trí cần thêm vào
{
    if (pos < 0 || pos > n) // Trường hợp vị trí cần thêm nằm ngoài và không liên tiếp với các phần tử khác của mảng mảng
        return;
    for (int i = n; i > pos; i--) // Dời các giá trị từ vị trí cần thêm ra sau
        a[i] = a[i - 1];
    a[pos] = giatri;
    n++;
}

int M1C::TimKiem(int x) // Trả về vị trí xuất hiện của x trong mảng, nếu không có trả về 1
{
    for (int i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return -1;
}