// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 6. Cài đặt lớp String để biểu diễn khái niệm chuỗi ký tự với các phương thức thiết
// lập và hủy bỏ, các hàm thành phần xác định chiều dài chuỗi, nối hai chuỗi, đảo
// chuỗi, chuyển chuỗi hoa/thường, nhập và xuất chuỗi. Viết chương trình minh họa
// các chức năng đã cài đặt của lớp String.

#include "6.h"
#include <cstring>

using namespace std;

int main()
{
    cString s1 = cString::InputFromConsole();

    cout << "Chuoi ky tu vua nhap: ";
    s1.OutputToConsole();

    cout << "Chieu dai cuoi ky tu: " << s1.Length() << endl;
    cout << "Chuoi ky tu viet hoa: " << s1.ToUpper().ToString() << endl;
    cout << "Chuoi ky tu viet thuong: " << s1.ToLower().ToString() << endl;
    cout << "Chuoi ky tu dao nguoc: " << s1.Reversed().ToString() << endl;

    cString s2 = cString::InputFromConsole();
    cout << "Chuoi ky tu duoc noi tu hai chuoi vua nhap: " << s1.Concat(s2).ToString() << endl;

    return 0;
}

// Default constructor initializes an empty string.
cString::cString()
{
    this->m_iLength = 0;
    this->m_pData = nullptr;
}

// Parameterized constructor initializes the string from a std::string.
cString::cString(string sString)
{
    this->m_iLength = sString.length();
    this->m_pData = new char[this->m_iLength + 1];
    strcpy(this->m_pData, sString.c_str());
}

// Copy constructor creates a deep copy of another cString.
cString::cString(const cString &sOther)
{
    this->m_iLength = sOther.m_iLength;
    if (sOther.m_pData != nullptr)
    {
        this->m_pData = new char[this->m_iLength + 1];
        strcpy(this->m_pData, sOther.m_pData);
    }
    else
    {
        this->m_pData = nullptr;
    }
}

// Copy assignment operator creates a deep copy of another cString.
cString &cString::operator=(const cString &sOther)
{
    if (this != &sOther)
    {
        delete[] this->m_pData;
        this->m_iLength = sOther.m_iLength;
        if (sOther.m_pData != nullptr)
        {
            this->m_pData = new char[this->m_iLength + 1];
            strcpy(this->m_pData, sOther.m_pData);
        }
        else
        {
            this->m_pData = nullptr;
        }
    }
    return *this;
}

// Destructor frees the allocated memory.
cString::~cString()
{
    delete[] this->m_pData;
}

// InputFromConsole prompts the user to input a string from the console.
cString cString::InputFromConsole()
{
    string sNhap;
    cout << "Nhap chuoi ky tu: ";
    getline(cin, sNhap);
    return cString(sNhap);
}

// OutputToConsole outputs the string to the console.
void cString::OutputToConsole()
{
    cout << this->ToString() << endl;
}

// ToString returns the string as a std::string.
string cString::ToString()
{
    if (this->m_pData == nullptr)
        return "";
    return string(this->m_pData);
}

// Length returns the length of the string.
int cString::Length()
{
    return this->m_iLength;
}

// ToUpper returns a new cString with all characters converted to uppercase.
cString cString::ToUpper()
{
    cString sUpper = cString();
    sUpper.m_iLength = this->m_iLength;
    sUpper.m_pData = new char[this->m_iLength + 1];
    for (int i = 0; i < sUpper.m_iLength; i++) // or we could've used toupper()
    {
        if (this->m_pData[i] >= 'a' && this->m_pData[i] <= 'z')
            sUpper.m_pData[i] = (this->m_pData[i] - 32);
        else
            sUpper.m_pData[i] = this->m_pData[i];
    }
    sUpper.m_pData[sUpper.m_iLength] = '\0';
    return sUpper;
}

// ToLower returns a new cString with all characters converted to lowercase.
cString cString::ToLower()
{
    cString sLower = cString();
    sLower.m_iLength = this->m_iLength;
    sLower.m_pData = new char[this->m_iLength + 1];
    for (int i = 0; i < sLower.m_iLength; i++)
    {
        if (this->m_pData[i] >= 'A' && this->m_pData[i] <= 'Z')
            sLower.m_pData[i] = (this->m_pData[i] + 32);
        else
            sLower.m_pData[i] = this->m_pData[i];
    }
    sLower.m_pData[sLower.m_iLength] = '\0';
    return sLower;
}

// Concat returns a new cString by concatenating another cString to this one.
cString cString::Concat(cString sOther)
{
    cString sCombined = cString();
    sCombined.m_iLength = this->m_iLength + sOther.m_iLength;
    sCombined.m_pData = new char[sCombined.m_iLength + 1];
    strcpy(sCombined.m_pData, this->m_pData);
    strcpy(sCombined.m_pData + m_iLength, sOther.m_pData);
    return sCombined;
}

// Reversed returns a new cString with the characters in reverse order.
cString cString::Reversed()
{
    cString sReversed = cString();
    sReversed.m_iLength = this->m_iLength;
    sReversed.m_pData = new char[sReversed.m_iLength + 1];
    for (int i = 0; i < this->m_iLength; i++)
    {
        sReversed.m_pData[this->m_iLength - 1 - i] = this->m_pData[i];
    }
    sReversed.m_pData[this->m_iLength] = '\0';
    return sReversed;
}