// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 2. Cài đặt lớp biểu diễn khái niệm điểm trong mặt phẳng với hai thành phần dữ
// liệu hoành độ và tung độ với các phương thức thiết lập, các hàm thành phần
// cho phép thay đổi nội dung của điểm, lấy hoành độ, tung độ, thay đổi hoành
// độ, tung độ, tịnh tiến, nhập, xuất một điểm. Viết chương trình minh họa các
// chức năng đã cài đặt được

#include "2.h"

int main()
{
    cout << "Nhap diem: " << endl;
    cDiem diem = cDiem::NhapTuConsole();
    cout << "Diem vua nhap: ";
    diem.XuatRaConsole();

    // Thay đổi hoành độ và xuất giá trị sau khi thay đổi
    cout << "Nhap hoanh do moi: ";
    float fHoanhDoMoi;
    cin >> fHoanhDoMoi;
    diem.SetHoanhDo(fHoanhDoMoi);
    cout << "=> Hoanh do sau khi thay doi: " << diem.GetHoanhDo() << endl;

    // Thay đổi tung độ và xuất giá trị sau khi thay đổi
    cout << "Nhap tung do moi: ";
    float fTungDoMoi;
    cin >> fTungDoMoi;
    diem.SetTungDo(fTungDoMoi);
    cout << "=> Tung do sau khi thay doi: " << diem.GetTungDo() << endl;

    // Tịnh tiến điểm và xuất giá trị sau khi tịnh tiến
    cout << "Nhap delta x va delta y de tinh tien: " << endl;
    float fDeltaX, fDeltaY;
    cout << "\tDelta x: ";
    cin >> fDeltaX;
    cout << "\tDelta y: ";
    cin >> fDeltaY;
    diem.TinhTien(fDeltaX, fDeltaY);
    cout << "=> Diem sau khi tinh tien: ";
    diem.XuatRaConsole();

    return 0;
}

// Default constructor initializes the point to the origin (0, 0).
cDiem::cDiem() : cDiem(0.0f, 0.0f) {}

// Parameterized constructor initializes the point with given x and y
// coordinates.
cDiem::cDiem(float fHoanhDo, float fTungDo)
{
    this->m_fHoanhDo = fHoanhDo;
    this->m_fTungDo = fTungDo;
}

// NhapTuConsole prompts the user to input the x and y coordinates, and returns
// a cDiem object.
cDiem cDiem::NhapTuConsole()
{
    float fHoanhDo, fTungDo;

    cout << "\tNhap hoanh do: ";
    cin >> fHoanhDo;

    cout << "\tNhap tung do: ";
    cin >> fTungDo;

    return cDiem(fHoanhDo, fTungDo);
}

// XuatRaConsole outputs the point to the console.
void cDiem::XuatRaConsole()
{
    cout << this->ToString() << endl;
}

// ToString returns a string representation of the point in the format "(x, y)".
string cDiem::ToString()
{
    return "(" + to_string(this->m_fHoanhDo) + ", " + to_string(this->m_fTungDo) + ")";
}

// Sets the x-coordinate of the point.
void cDiem::SetHoanhDo(float fHoanhDo)
{
    this->m_fHoanhDo = fHoanhDo;
}

// Sets the y-coordinate of the point.
void cDiem::SetTungDo(float fTungDo)
{
    this->m_fTungDo = fTungDo;
}

// Returns the x-coordinate of the point.
float cDiem::GetHoanhDo()
{
    return this->m_fHoanhDo;
}

// Returns the y-coordinate of the point.
float cDiem::GetTungDo()
{
    return this->m_fTungDo;
}

// Translates the point by adding the given delta x and delta y to the current
// coordinates.
void cDiem::TinhTien(float fDeltaX, float fDeltaY)
{
    this->m_fHoanhDo += fDeltaX;
    this->m_fTungDo += fDeltaY;
}
