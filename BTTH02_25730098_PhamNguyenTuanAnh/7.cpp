// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
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

    cout << "Bang ke khai thong tin xe 1:\n" << v1.GetAllDetails() << endl;
    cout << "Bang ke khai thong tin xe 2:\n" << v2.GetAllDetails() << endl;
    cout << "Bang ke khai thong tin xe 3:\n" << v3.GetAllDetails() << endl;
}

cVehicle::cVehicle()
{
    this->sOwner = "";
    this->sType = "";
    this->iPrice = 0;
    this->iEngineDisplacement = 0;
}

cVehicle::cVehicle(string sOwner, string sType, int iPrice, int iEngineDisplacement)
{
    this->SetOwner(sOwner);
    this->SetType(sType);
    this->SetPrice(iPrice);
    this->SetEngineDisplacement(iEngineDisplacement);
}

cVehicle cVehicle::InputFromConsole()
{
    string sOwner;
    cout << "Nhap ten chu so huu xe: ";
    getline(cin, sOwner);

    string sType;
    cout << "Nhap loai xe: ";
    getline(cin, sType);

    int iPrice;
    cout << "Nhap gia tri xe: ";
    cin >> iPrice;

    int iEngineDisplacement;
    cout << "Nhap dung tich xylanh: ";
    cin >> iEngineDisplacement;

    return cVehicle(sOwner, sType, iPrice, iEngineDisplacement);
}

string cVehicle::GetOwner()
{
    return this->sOwner;
}

string cVehicle::GetType()
{
    return this->sType;
}

int cVehicle::GetPrice()
{
    return this->iPrice;
}

int cVehicle::GetEngineDisplacement()
{
    return this->iEngineDisplacement;
}

void cVehicle::SetOwner(string sOwner)
{
    this->sOwner = sOwner;
}

void cVehicle::SetType(string sType)
{
    this->sType = sType;
}

void cVehicle::SetPrice(int iPrice)
{
    if (iPrice < 0)
        throw invalid_argument("Tri gia xe khong duoc nho hon 0.");
    this->iPrice = iPrice;
}

void cVehicle::SetEngineDisplacement(int iEngineDisplacement)
{
    if (iEngineDisplacement < 0)
        throw invalid_argument("Dung tich xylanh khong duoc nho hon 0.");
    this->iEngineDisplacement = iEngineDisplacement;
}

int cVehicle::GetRegistrationTax()
{
    if (this->iEngineDisplacement < 100)
    {
        return this->iPrice * 0.01;
    }

    if (this->iEngineDisplacement <= 200)
    {
        return this->iPrice * 0.03;
    }

    return this->iPrice * 0.05;
}

string cVehicle::GetAllDetails()
{
    return "\tChu xe: " + this->sOwner + "\n" + "\tLoai xe: " + this->sType + "\n" +
           "\tTri gia xe: " + to_string(this->iPrice) + "\n" +
           "\tDung tich xylanh: " + to_string(this->iEngineDisplacement) + "cc\n" +
           "\tThue truoc ba: " + to_string(this->GetRegistrationTax()) + "\n";
}
