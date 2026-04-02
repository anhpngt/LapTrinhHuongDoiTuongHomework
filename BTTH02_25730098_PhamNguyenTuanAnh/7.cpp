// Mã số sinh viên: 25730098
// Họ và tên sinh viên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 7. Sở giao thông cần theo dõi việc đăng ký xe (Vehicle) của người dân, cho biết
// mỗi xe cần lưu các thông tin như sau: chủ xe, loại xe, trị giá xe (>=0), dung tích
// xylanh (>=0). Dựa vào thông tin trị giá xe và dung tích xylanh, sở giao thông
// cũng tính mức thuế phải đóng trước bạ khi mua xe như sau:
//  Dưới 100cc, 1% trị giá xe.
//  Từ 100 đến 200cc, 3% trị giá xe.
//  Trên 200cc, 5% trị giá xe.
// Hãy thiết kế và cài đặt class Vehicle với các attributes và methods phù hợp (có
// kiểm tra ràng buộc dữ liệu). Class phải có các constructor và phải bảo đảm tính
// encapsulation.
// Viết chương trình minh họa thực hiện các chức năng sau:
//  Tạo 3 đối tượng Vehicle xe1, xe2, xe3.
//  Đối tượng xe1 và xe2 được thiết lập dữ liệu sẵn thông qua constructor
//  Đối tượng xe3 cho phép người dùng nhập dữ liệu từ bán phím.
//  Xuất bảng kê khai thông tin chi tiết và tiền thuế trước bạ của các xe trên

#include "7.h"
#include <stdexcept>
#include <string>

int main()
{
    cVehicle v1 = cVehicle("Nguyen Van A", "Xe con", 100000, 1000);
    cVehicle v2 = cVehicle("Nguyen Van B", "Xe tai", 200000, 5000);
    cVehicle v3 = cVehicle::InputFromConsole();

    cout << "=> Bang ke khai thong tin xe 1:\n" << v1.GetAllDetails() << endl;
    cout << "=> Bang ke khai thong tin xe 2:\n" << v2.GetAllDetails() << endl;
    cout << "=> Bang ke khai thong tin xe 3:\n" << v3.GetAllDetails() << endl;
}

// Default constructor initializes all fields to empty/zero values.
cVehicle::cVehicle()
{
    this->m_strOwner = "";
    this->m_strType = "";
    this->m_iPrice = 0;
    this->m_iEngineDisplacement = 0;
}

// Parameterized constructor initializes the vehicle with the given values.
cVehicle::cVehicle(string strOwner, string strType, int iPrice, int iEngineDisplacement)
{
    this->SetOwner(strOwner);
    this->SetType(strType);
    this->SetPrice(iPrice);
    this->SetEngineDisplacement(iEngineDisplacement);
}

// InputFromConsole prompts the user to input vehicle data from the console.
cVehicle cVehicle::InputFromConsole()
{
    string strOwner;
    cout << "Nhap ten chu so huu xe: ";
    getline(cin, strOwner);

    string strType;
    cout << "Nhap loai xe: ";
    getline(cin, strType);

    int iPrice;
    cout << "Nhap gia tri xe: ";
    cin >> iPrice;

    int iEngineDisplacement;
    cout << "Nhap dung tich xylanh: ";
    cin >> iEngineDisplacement;

    return cVehicle(strOwner, strType, iPrice, iEngineDisplacement);
}

// GetOwner returns the owner of the vehicle.
string cVehicle::GetOwner()
{
    return this->m_strOwner;
}

// GetType returns the type of the vehicle.
string cVehicle::GetType()
{
    return this->m_strType;
}

// GetPrice returns the price of the vehicle.
int cVehicle::GetPrice()
{
    return this->m_iPrice;
}

// GetEngineDisplacement returns the engine displacement of the vehicle.
int cVehicle::GetEngineDisplacement()
{
    return this->m_iEngineDisplacement;
}

// SetOwner sets the owner of the vehicle.
void cVehicle::SetOwner(string strOwner)
{
    this->m_strOwner = strOwner;
}

// SetType sets the type of the vehicle.
void cVehicle::SetType(string strType)
{
    this->m_strType = strType;
}

// SetPrice sets the price of the vehicle. Throws if price is negative.
void cVehicle::SetPrice(int iPrice)
{
    if (iPrice < 0)
        throw invalid_argument("Tri gia xe khong duoc nho hon 0.");
    this->m_iPrice = iPrice;
}

// SetEngineDisplacement sets the engine displacement. Throws if negative.
void cVehicle::SetEngineDisplacement(int iEngineDisplacement)
{
    if (iEngineDisplacement < 0)
        throw invalid_argument("Dung tich xylanh khong duoc nho hon 0.");
    this->m_iEngineDisplacement = iEngineDisplacement;
}

// GetRegistrationTax calculates the registration tax based on engine
// displacement: <100cc = 1%, 100-200cc = 3%, >200cc = 5% of the price.
int cVehicle::GetRegistrationTax()
{
    if (this->m_iEngineDisplacement < 100)
    {
        return this->m_iPrice * 0.01;
    }

    if (this->m_iEngineDisplacement <= 200)
    {
        return this->m_iPrice * 0.03;
    }

    return this->m_iPrice * 0.05;
}

// GetAllDetails returns a formatted string with all vehicle details and tax.
string cVehicle::GetAllDetails()
{
    return "\tChu xe: " + this->m_strOwner + "\n" + "\tLoai xe: " + this->m_strType + "\n" +
           "\tTri gia xe: " + to_string(this->m_iPrice) + "\n" +
           "\tDung tich xylanh: " + to_string(this->m_iEngineDisplacement) + "cc\n" +
           "\tThue truoc ba: " + to_string(this->GetRegistrationTax()) + "\n";
}
