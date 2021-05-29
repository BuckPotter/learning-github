#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string Read(string duongdan) // Đọc 1 đoạn văn từ file văn bản, trả về những gì đọc được từ file
{
    string output;
    string line;
    fstream inFile;
    inFile.open(duongdan, ios::in); // mở file với mục đích đọc
    while (!inFile.eof())           // đọc
    {
        getline(inFile, line);
        //hoặc char kt[100]; inFile.getline(kt,100);
        output += line;
    }
    inFile.close(); // đóng file
    return output;
}

vector<string> Cau_Trong_Van_Ban(string duongdan) // Trả về 1 mảng mà trong đó mỗi phần tử là 1 câu của văn bản
{
    fstream inFile;
    vector<string> vt; // 1 mảng với mỗi phần tử là kiểu string lưu mỗi câu của văn bản
    inFile.open(duongdan, ios::in);
    char kt;
    string cau = ""; // Biến string cau dùng để lưu trữ tất các kí tự của 1 câu, trừ dấu . ! ?
    while (!inFile.eof())
    {
        inFile.get(kt);
        if (kt == '!' || kt == '.' || kt == '?') // Nếu gặp dấu chấm câu thì đưa biến câu vào mảng, sau đó làm mới biến này
        {
            vt.push_back(cau);
            cau = "";
            inFile.get(kt); // Gọi lại lệnh 1 lần nữa để dịch chuyển con trỏ chỉ vị ra sau khoảng trắng (xóa khoảng trắng) trước dấu . ? !
            continue;
        }
        cau += kt;
    }
    inFile.close();
    return vt;
}

int Dem_Cau(string duongdan)
{
    int dem = 0;
    char kt;
    fstream inFile;
    inFile.open(duongdan, ios::in);
    while (!inFile.eof())
    {
        inFile.get(kt);
        if (kt == '.' || kt == '!' || kt == '?')
            dem++;
    }
    return dem - 1; // ??? phuong thức get bị duplicate kí tự ở cuối văn bản(1 dấu chấm câu ở cuối biến thành 2 nên trừ 1 lại)
}

int Dem_Tu(string cau) // Đếm số từ trong 1 câu
{
    int dem = 1; // Do từ đầu tiên trong câu không đứng sau khoảng trắng nên đặt biến dem = 1 coi như đã đếm từ đầu tiên
    int i = 0;
    while (cau[i] != '\0')
    {
        if (cau[i] == ' ')
            dem++;
        i++;
    }
    return dem;
}

string Sap_Xep(string cau) // Sắp xếp các từ trong câu theo tứ tự từ điển, có phân biệt chữ hoa - thường, trả về câu đã được sắp xếp
{
    vector<string> TuTrongCau; // 1 mảng phụ chứa tất cả các từ của câu
    string tu;
    int n = cau.length();
    for (int i = 0; i < n + 1; i++) // Điều kiện i < n+1 để có thể xét cả kí tự NULL và đưa từ cuối cùng vào mảng
    {
        if (cau[i] == ' ' || cau[i] == '\0')
        {
            TuTrongCau.push_back(tu);
            tu = "";
            continue;
        }
        else if (cau[i] == ',')
            continue;
        tu += cau[i];
    }

    n = TuTrongCau.size();
    string output; // Chuỗi đã được sắp xếp và sẽ trả về chuỗi này
    string tam;    // Biến tạm để đổi chỗ
    int i, j, min;
    for (i = 0; i < n - 1; i++) // Chọn trực tiếp
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (TuTrongCau[min] > TuTrongCau[j]) // Tìm vị trí từ có thứ tự từ điển nhỏ nhất trong câu
                min = j;
        }
        // Đổi chỗ
        tam = TuTrongCau[i];
        TuTrongCau[i] = TuTrongCau[min];
        TuTrongCau[min] = tam;
        output += TuTrongCau[i] + ' ';
    }
    // Sẽ bị thiếu phần tử lớn nhất ở cuối mảng
    output += TuTrongCau[n - 1]; // Thêm vào phần tử cuối mảng, đây cũng chính là phần tử lớn nhất
    return output;
}

void Tu_Xuat_Hien_Nhieu_Nhat(string duongdan)
{

    string vanban = Read(duongdan); // B1: Đọc văn bản từ file vào 1 biến string có tên vanban

    vector<string> TuTrongVanBan; // B2: Cắt từ đưa vào mảng
    string tu;
    int n = vanban.length();
    for (int i = 0; i < n + 1; i++)
    {
        if (vanban[i] == ' ' || vanban[i] == '\0')
        {
            TuTrongVanBan.push_back(tu);
            tu = "";
            continue;
        }
        else if (vanban[i] == ',' || vanban[i] == '.' || vanban[i] == '?' || vanban[i] == '!')
            continue;
        tu += vanban[i];
    }

    // B3: Sắp xếp lại các từ trong văn bản theo thứ tự từ điển
    n = TuTrongVanBan.size();
    int i, j, min;
    string tam;
    for (int i = 0; i < n - 1; i++) // Chọn trực tiếp
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (TuTrongVanBan[min] > TuTrongVanBan[j]) // Tìm vị trí từ có thứ tự từ điển nhỏ nhất trong câu
                min = j;
        }
        tam = TuTrongVanBan[i];
        TuTrongVanBan[i] = TuTrongVanBan[min];
        TuTrongVanBan[min] = tam;
    }

    //Bước 4: Duyệt mảng đã sắp để đưa vào mảng từ và số lần xuất hiện của từ đó
    struct PAIR // Một cấu trúc PAIR bao gồm string từ và số lần xuất hiện của từ đó
    {
        string tu; // Từ
        int freq;  //Tần số hay số lần xuất hiện
    };

    vector<PAIR> vt; // mảng vt chứa từ và số lần xuất hiện trong văn bản, có phân biệt chữ hoa thường
    int dem = 1, max = 1;
    i = 0;
    while (i < n - 1)
    {
        if (TuTrongVanBan[i] == TuTrongVanBan[i + 1])
            dem++;
        else // Khi nào TuTrongVanBan[i] != TuTrongVanBan[i+1] thì lệnh vt.push_back mới được gọi và khi i == n+1 sẽ dừng vòng lặp, như vậy sẽ bỏ sót từ ở cuối mảng
        {
            if (max < dem)
                max = dem;
            PAIR a;
            a.tu = TuTrongVanBan[i];
            a.freq = dem;
            dem = 1; // Làm mới biến dem cho các từ khác
            vt.push_back(a);
        }

        i++; //Tăng biến i. Vì khi i == n+1 sẽ dừng vòng lặp nên cần để lệnh đưa phần tử cuối cùng vào mảng xuống dưới lệnh i++

        if (i == n - 1) // Thêm từ cuối mảng vào
        {
            if (max < dem)
                max = dem;
            PAIR a;
            a.tu = TuTrongVanBan[i];
            a.freq = dem;
            vt.push_back(a);
        }
    }

    //Bước 5, duyệt lại mảng vt và in ra từ xuất hiện nhiều nhất (có thể có nhiều từ), có phân biệt hoa thường
    cout << "Tu xuat hien nhieu nhat trong van ban la: ";
    n = vt.size();
    for (i = 0; i < n; i++)
        if (max == vt[i].freq)
            cout << vt[i].tu << "";
}

void XuatFile(string duongdan)
{
    cout << Dem_Cau(duongdan) << endl; // số lượng câu trong văn bản
    vector<string> cau = Cau_Trong_Van_Ban(duongdan);
    int n = cau.size();
    for (int i = 0; i < n; i++)
        cout << Dem_Tu(cau[i]) << endl;
    Tu_Xuat_Hien_Nhieu_Nhat(duongdan);
    cout << endl;
    for (int i = 0; i < n; i++) // mỗi dòng là 1 câu đã được sắp xếp lại theo thứ tự từ điển(không tính dấu phẩy), có phân biệt hoa thường
        cout << Sap_Xep(cau[i]) << endl;
}

int main()
{
    XuatFile("doanvan.txt"); // file txt đính kèm khi nộp
    system("pause");
    return 0;
}