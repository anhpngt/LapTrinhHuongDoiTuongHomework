// Mã số sinh viên: 25730098
// Họ và tên sinh viên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 2. Cài đặt lớp biểu diễn khái niệm điểm trong mặt phẳng với hai thành phần dữ
// liệu hoành độ và tung độ với các phương thức thiết lập, các hàm thành phần
// cho phép thay đổi nội dung của điểm, lấy hoành độ, tung độ, thay đổi hoành
// độ, tung độ, tịnh tiến, nhập, xuất một điểm. Viết chương trình minh họa các
// chức năng đã cài đặt được

#pragma once

#include <iostream>
#include <string>

using namespace std;

class cDiem
{
private:
    float m_fHoanhDo;
    float m_fTungDo;

public:
    cDiem();
    cDiem(float fHoanhDo, float fTungDo);

    static cDiem NhapTuConsole();
    void XuatRaConsole();
    string ToString();

    void SetHoanhDo(float fHoanhDo);
    void SetTungDo(float fTungDo);
    float GetHoanhDo();
    float GetTungDo();
    void TinhTien(float fDeltaX, float fDeltaY);
};
