#ifndef _STRING
#define _STRING

class String
{
    char *str;

public:
    String();
    String(char *);      // Constructor với tham số con trỏ
    ~String();           // Destructor
    int Strlen();        // Trả về chiều dài của chuỗi
    void Strcat(char *); // Nối chuỗi sau vào chuỗi trước với tham số con trỏ
    void Strcat(String); // Nối chuỗi với tham số là String tự định nghĩa
    void Reverse();      // Đảo chuỗi
    void Nhap();
    void Xuat();
};

#endif
