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

#pragma once

#include <iostream>
#include <string>

using namespace std;

class cVehicle
{
private:
    string m_strOwner;
    string m_strType;
    int m_iPrice;
    int m_iEngineDisplacement;

public:
    cVehicle();
    cVehicle(string strOwner, string strType, int iPrice, int iEngineDisplacement);

    static cVehicle InputFromConsole();

    string GetOwner();
    string GetType();
    int GetPrice();
    int GetEngineDisplacement();
    void SetOwner(string strOwner);
    void SetType(string strType);
    void SetPrice(int iPrice);
    void SetEngineDisplacement(int iEngineDisplacement);

    int GetRegistrationTax();
    string GetAllDetails();
};