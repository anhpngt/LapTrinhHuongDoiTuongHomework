// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 6. Cài đặt lớp String để biểu diễn khái niệm chuỗi ký tự với các phương thức thiết
// lập và hủy bỏ, các hàm thành phần xác định chiều dài chuỗi, nối hai chuỗi, đảo
// chuỗi, chuyển chuỗi hoa/thường, nhập và xuất chuỗi. Viết chương trình minh họa
// các chức năng đã cài đặt của lớp String.

#pragma once

#include <iostream>
#include <string>

using namespace std;

class cString
{
private:
    char *m_pData;
    int m_iLength;

public:
    cString();
    cString(string strString);
    cString(const cString& strOther);
    cString& operator=(const cString& strOther);
    ~cString();
    static cString InputFromConsole();
    void OutputToConsole();

    int Length();
    string ToString();
    cString Concat(cString strOther);
    cString Reversed();
    cString ToUpper();
    cString ToLower();
};
