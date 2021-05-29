#include "String.h"
#include <string.h>
#include <iostream>
using namespace std;

String::String() // constructor không có tham số thì giá trị của biến char mà con trỏ trỏ tới sẽ là NULL
{
    char *p = new char;
    *p = '\0';
    str = p;
}

String::String(char *string)
{
    int i = 0, n = strlen(string);
    char *tam = new char[n + 1];                   // +1 cho '\0'
    while (string[i] != '\0' && string[i] != '\n') // chép chuỗi string vào mảng động mới nhằm tạo vùng nhớ riêng biệt
    {
        tam[i] = string[i];
        i++;
    }
    tam[i] = '\0'; // vòng lâp đến kí tự NULL thì dừng nên tự thêm kí tự NULL
    str = tam;
}

String::~String()
{
    delete str;
    str = nullptr;
}

int String::Strlen() // Trả về chiều dài của chuỗi
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void String::Strcat(char *string) // Nối chuỗi sau vào chuỗi trước với tham số con trỏ
{
    if (str[0] == '\0') // Nếu chuỗi trước rỗng thì gán cho chuỗi sau
    {
        str = string;
        return;
    }
    int n = this->Strlen(), i = 0;
    while (str[i] != '\0')
    {
        str[n + i] = string[i];
        i++;
    }
    str[n + i] = '\0'; // Gán kí tự NULL vào cuối chuỗi
}

void String::Strcat(String string) // Nối chuỗi với tham số là String tự định nghĩa
{
    this->Strcat(string.str);
}

void String::Reverse() // Đảo chuỗi
{
    int n = this->Strlen(), i = 0;
    int tam; // Bien tam de dao cho gia tri
    while (i <= n / 2)
    {
        tam = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = tam;
        i++;
    }
}

void String::Nhap()
{
    cout << "Nhap chuoi: ";
    char *nhap = new char; // Cấp phát vùng nhớ mới
    fflush(stdin);
    gets(nhap); // Nhập liệu cho vùng nhớ mới
    str = nhap; // trỏ str tới vùng nhớ mới
}

void String::Xuat()
{
    if (str[0] == '\0')
        return;
    cout << "Chuoi dang xet la: " << str;
}