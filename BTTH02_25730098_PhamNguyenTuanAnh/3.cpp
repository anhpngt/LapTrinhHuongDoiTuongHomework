// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 3. Cài đặt lớp biểu diễn khái niệm số phức với hai thành phần dữ liệu thực,
// ảo và các hàm thành phần xuất, nhập, định giá trị cho số phức, cộng, trừ,
// nhân, chia hai số phức. Viết chương trình cho phép nhập vào hai số phức, in
// ra kết quả các phép toán cộng, trừ, nhân, chia hai số phức kể trên. Ví dụ:
// Cho hai số phức A(a1, a2), B(b1, b2)  A + B = (a1+b1, a2+b2)  A - B
// = (a1-b1, a2-b2)  A * B = (a1*b1 – a2*b2, a1*b2+a2*b1)  A / B =

#include "3.h"

using namespace std;

int main()
{
    cout << "Nhap so phuc A: " << endl;
    cComplexNumber cA = cComplexNumber::InputFromConsole();
    cout << "Nhap so phuc B: " << endl;
    cComplexNumber cB = cComplexNumber::InputFromConsole();

    cout << "A = ";
    cA.OutputToConsole();
    cout << "B = ";
    cB.OutputToConsole();

    cout << "A + B = ";
    cA.Add(cB).OutputToConsole();
    cout << "A - B = ";
    cA.Subtract(cB).OutputToConsole();
    cout << "A * B = ";
    cA.Multiply(cB).OutputToConsole();
    cout << "A / B = ";
    cA.Divide(cB).OutputToConsole();

    return 0;
}

// Initialize the complex number with default values (0.0 for both real and
// imaginary parts).
cComplexNumber::cComplexNumber() : cComplexNumber(0.0f, 0.0f) {}

// Initialize the complex number with the given real and imaginary parts.
cComplexNumber::cComplexNumber(float fReal, float fImaginary)
{
    this->m_fReal = fReal;
    this->m_fImaginary = fImaginary;
}

// Static method to input a complex number from the console.
cComplexNumber cComplexNumber::InputFromConsole()
{
    float fReal, fImaginary;

    cout << "\tNhap phan thuc: ";
    cin >> fReal;
    cout << "\tNhap phan ao: ";
    cin >> fImaginary;

    return cComplexNumber(fReal, fImaginary);
}

// Method to convert the complex number to a string representation "(real,
// imaginary)".
string cComplexNumber::ToString()
{
    return "(" + to_string(m_fReal) + ", " + to_string(m_fImaginary) + ")";
}

// Output the complex number to the console.
void cComplexNumber::OutputToConsole()
{
    cout << ToString() << endl;
}

// Set the real part of the complex number.
void cComplexNumber::setReal(float fReal)
{
    this->m_fReal = fReal;
}

// Set the imaginary part of the complex number.
void cComplexNumber::setImaginary(float fImaginary)
{
    this->m_fImaginary = fImaginary;
}

// Get the real part of the complex number.
float cComplexNumber::getReal()
{
    return m_fReal;
}

// Get the imaginary part of the complex number.
float cComplexNumber::getImaginary()
{
    return m_fImaginary;
}

// Adds two complex numbers and returns the result as a new complex number.
cComplexNumber cComplexNumber::Add(cComplexNumber cOther)
{
    return cComplexNumber(m_fReal + cOther.m_fReal, m_fImaginary + cOther.m_fImaginary);
}

// Subtracts another complex number from this complex number and returns the
// result as a new complex number.
cComplexNumber cComplexNumber::Subtract(cComplexNumber cOther)
{
    return cComplexNumber(m_fReal - cOther.m_fReal, m_fImaginary - cOther.m_fImaginary);
}

// Multiplies this complex number by another complex number and returns the
// result as a new complex number.
cComplexNumber cComplexNumber::Multiply(cComplexNumber cOther)
{
    float realPart = m_fReal * cOther.m_fReal - m_fImaginary * cOther.m_fImaginary;
    float imaginaryPart = m_fReal * cOther.m_fImaginary + m_fImaginary * cOther.m_fReal;
    return cComplexNumber(realPart, imaginaryPart);
}

// Divides this complex number by another complex number and returns the result
// as a new complex number.
cComplexNumber cComplexNumber::Divide(cComplexNumber cOther)
{
    float denominator = cOther.m_fReal * cOther.m_fReal + cOther.m_fImaginary * cOther.m_fImaginary;
    if (denominator == 0)
    {
        throw std::invalid_argument("Khong the chia cho so phuc bang 0");
    }
    float realPart = (m_fReal * cOther.m_fReal + m_fImaginary * cOther.m_fImaginary) / denominator;
    float imaginaryPart = (m_fImaginary * cOther.m_fReal - m_fReal * cOther.m_fImaginary) / denominator;
    return cComplexNumber(realPart, imaginaryPart);
}
