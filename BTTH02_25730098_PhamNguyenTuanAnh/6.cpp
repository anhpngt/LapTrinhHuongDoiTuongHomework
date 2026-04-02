// Mã số sinh viên: 25730098
// Họ và tên sinh viên: Phạm Nguyễn Tuấn Anh
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

    cout << "=> Chuoi ky tu vua nhap: ";
    s1.OutputToConsole();

    cout << "=> Chieu dai chuoi ky tu: " << s1.Length() << endl;
    cout << "=> Chuoi ky tu viet hoa: ";
    s1.ToUpper().OutputToConsole();
    cout << "=> Chuoi ky tu viet thuong: ";
    s1.ToLower().OutputToConsole();
    cout << "=> Chuoi ky tu dao nguoc: ";
    s1.Reversed().OutputToConsole();

    cString s2 = cString::InputFromConsole();
    cout << "=> Chuoi ky tu duoc noi tu hai chuoi vua nhap: ";
    s1.Concat(s2).OutputToConsole();

    return 0;
}

// Default constructor initializes an empty string.
cString::cString()
{
    this->m_iLength = 0;
    this->m_pData = nullptr;
}

// Parameterized constructor initializes the string from a std::string.
cString::cString(string strString)
{
    this->m_iLength = strString.length();
    this->m_pData = new char[this->m_iLength + 1];
    strcpy(this->m_pData, strString.c_str());
}

// Copy constructor creates a deep copy of another cString.
cString::cString(const cString &strOther)
{
    this->m_iLength = strOther.m_iLength;
    if (strOther.m_pData != nullptr)
    {
        this->m_pData = new char[this->m_iLength + 1];
        strcpy(this->m_pData, strOther.m_pData);
    }
    else
    {
        this->m_pData = nullptr;
    }
}

// Copy assignment operator creates a deep copy of another cString.
cString &cString::operator=(const cString &strOther)
{
    if (this != &strOther)
    {
        delete[] this->m_pData;
        this->m_iLength = strOther.m_iLength;
        if (strOther.m_pData != nullptr)
        {
            this->m_pData = new char[this->m_iLength + 1];
            strcpy(this->m_pData, strOther.m_pData);
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
    string strNhap;
    cout << "Nhap chuoi ky tu: ";
    getline(cin, strNhap);
    return cString(strNhap);
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
    cString strUpper = cString();
    strUpper.m_iLength = this->m_iLength;
    strUpper.m_pData = new char[this->m_iLength + 1];
    for (int i = 0; i < strUpper.m_iLength; i++) // or we could've used toupper()
    {
        if (this->m_pData[i] >= 'a' && this->m_pData[i] <= 'z')
            strUpper.m_pData[i] = (this->m_pData[i] - 32);
        else
            strUpper.m_pData[i] = this->m_pData[i];
    }
    strUpper.m_pData[strUpper.m_iLength] = '\0';
    return strUpper;
}

// ToLower returns a new cString with all characters converted to lowercase.
cString cString::ToLower()
{
    cString strLower = cString();
    strLower.m_iLength = this->m_iLength;
    strLower.m_pData = new char[this->m_iLength + 1];
    for (int i = 0; i < strLower.m_iLength; i++)
    {
        if (this->m_pData[i] >= 'A' && this->m_pData[i] <= 'Z')
            strLower.m_pData[i] = (this->m_pData[i] + 32);
        else
            strLower.m_pData[i] = this->m_pData[i];
    }
    strLower.m_pData[strLower.m_iLength] = '\0';
    return strLower;
}

// Concat returns a new cString by concatenating another cString to this one.
cString cString::Concat(cString strOther)
{
    cString strCombined = cString();
    strCombined.m_iLength = this->m_iLength + strOther.m_iLength;
    strCombined.m_pData = new char[strCombined.m_iLength + 1];
    strcpy(strCombined.m_pData, this->m_pData);
    strcpy(strCombined.m_pData + m_iLength, strOther.m_pData);
    return strCombined;
}

// Reversed returns a new cString with the characters in reverse order.
cString cString::Reversed()
{
    cString strReversed = cString();
    strReversed.m_iLength = this->m_iLength;
    strReversed.m_pData = new char[strReversed.m_iLength + 1];
    for (int i = 0; i < this->m_iLength; i++)
    {
        strReversed.m_pData[this->m_iLength - 1 - i] = this->m_pData[i];
    }
    strReversed.m_pData[this->m_iLength] = '\0';
    return strReversed;
}