// Mã số sinh viên: 25730098
// Họ và tên sinh viên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 4. Cài đặt lớp biểu diễn khái niệm thời gian với các thành phần dữ liệu giờ,
// phút, giây và các thao tác thích hợp (nhập, xuất, thiết lập, thay đổi
// giờ/phút/giây, lấy giờ/phút/giây, tăng/giảm giờ/phút/giây,…). Viết chương
// trình minh họa các chức năng đã cài đặt của lớp Thời gian.

#include "4.h"

using namespace std;

int main()
{
    cout << "Nhap thoi gian:" << endl;
    cTimestamp ts = cTimestamp::InputFromConsole();
    cout << "Thoi gian da nhap: ";
    ts.OutputToConsole();

    cout << "Nhap lai so gio: ";
    int iHours;
    cin >> iHours;
    ts.SetHour(iHours);
    cout << "=> Thoi gian sau khi nhap lai: " << ts.ToString() << " (so gio moi: " << iHours << ")" << endl;

    cout << "Nhap lai so phut: ";
    int iMinutes;
    cin >> iMinutes;
    ts.SetMinute(iMinutes);
    cout << "=> Thoi gian sau khi nhap lai: " << ts.ToString() << " (so phut moi: " << iMinutes << ")" << endl;

    cout << "Nhap lai so giay: ";
    int iSeconds;
    cin >> iSeconds;
    ts.SetSecond(iSeconds);
    cout << "=> Thoi gian sau khi nhap lai: " << ts.ToString() << " (so giay moi: " << iSeconds << ")" << endl;

    cout << "=> Them so giay: ";
    int iSecondsToAdd;
    cin >> iSecondsToAdd;
    ts.AddSeconds(iSecondsToAdd).OutputToConsole();

    cout << "=> Them so phut: ";
    int iMinutesToAdd;
    cin >> iMinutesToAdd;
    ts.AddMinutes(iMinutesToAdd).OutputToConsole();

    cout << "=> Them so gio: ";
    int iHoursToAdd;
    cin >> iHoursToAdd;
    ts.AddHours(iHoursToAdd).OutputToConsole();

    return 0;
}

// Initialize the timestamp with default values (0 for hour, minute, and
// second).
cTimestamp::cTimestamp()
{
    this->m_iHour = 0;
    this->m_iMinute = 0;
    this->m_iSecond = 0;
}

// Initialize the timestamp with the given hour, minute, and second.
cTimestamp::cTimestamp(int iHour, int iMinute, int iSecond)
{
    this->m_iHour = iHour;
    this->m_iMinute = iMinute;
    this->m_iSecond = iSecond;
    if (!this->IsValid())
    {
        throw invalid_argument("Thoi gian khong hop le: " + this->ToString());
    }
}

// Static method to input a timestamp from the console.
cTimestamp cTimestamp::InputFromConsole()
{
    int iHour, iMinute, iSecond;

    cout << "\tNhap gio: ";
    cin >> iHour;
    cout << "\tNhap phut: ";
    cin >> iMinute;
    cout << "\tNhap giay: ";
    cin >> iSecond;

    return cTimestamp(iHour, iMinute, iSecond);
}

// IsValid checks if the timestamp is valid.
bool cTimestamp::IsValid()
{
    if (this->m_iHour < 0 || this->m_iHour > 23)
        return false;
    if (this->m_iMinute < 0 || this->m_iMinute > 59)
        return false;
    if (this->m_iSecond < 0 || this->m_iSecond > 59)
        return false;
    return true;
}

// ToString converts the timestamp to a string in the format of hh:mm:ss.
string cTimestamp::ToString()
{
    return to_string(this->m_iHour) + ":" + to_string(this->m_iMinute) + ":" + to_string(this->m_iSecond);
}

// OutputToConsole outputs the timestamp to the console.
void cTimestamp::OutputToConsole()
{
    cout << this->ToString() << endl;
}

// SetHour sets the hour of the timestamp.
void cTimestamp::SetHour(int iHour)
{
    if (iHour < 0 || iHour > 23)
    {
        throw invalid_argument("So gio khong hop le: " + to_string(iHour));
    }
    this->m_iHour = iHour;
}

// SetMinute sets the minute of the timestamp.
void cTimestamp::SetMinute(int iMinute)
{
    if (iMinute < 0 || iMinute > 59)
    {
        throw invalid_argument("So phut khong hop le: " + to_string(iMinute));
    }
    this->m_iMinute = iMinute;
}

// SetSecond sets the second of the timestamp.
void cTimestamp::SetSecond(int iSecond)
{
    if (iSecond < 0 || iSecond > 59)
    {
        throw invalid_argument("So giay khong hop le: " + to_string(iSecond));
    }
    this->m_iSecond = iSecond;
}

// GetHour gets the hour of the timestamp.
int cTimestamp::GetHour()
{
    return this->m_iHour;
}

// GetMinute gets the minute of the timestamp.
int cTimestamp::GetMinute()
{
    return this->m_iMinute;
}

// GetSecond gets the second of the timestamp.
int cTimestamp::GetSecond()
{
    return this->m_iSecond;
}

// AddSeconds adds (or subtracts) the given seconds to the timestamp.
// Seconds overflow into minutes and hours. Throws if the result exceeds 23:59:59
// or goes below 00:00:00.
cTimestamp cTimestamp::AddSeconds(int iSeconds)
{
    int iTotalSeconds = this->m_iHour * 3600 + this->m_iMinute * 60 + this->m_iSecond + iSeconds;

    int iNewHour = iTotalSeconds / 3600;
    int iNewMinute = (iTotalSeconds % 3600) / 60;
    int iNewSecond = iTotalSeconds % 60;

    return cTimestamp(iNewHour, iNewMinute, iNewSecond);
}

// AddMinutes adds the given minutes to the timestamp.
// Minutes overflow into hours. Throws if the result exceeds 23:59:59 or goes
// below 00:00:00.
cTimestamp cTimestamp::AddMinutes(int iMinutes)
{
    int iTotalMinutes = this->m_iHour * 60 + this->m_iMinute + iMinutes;

    int iNewHour = iTotalMinutes / 60;
    int iNewMinute = iTotalMinutes % 60;
    int iNewSecond = this->m_iSecond;

    return cTimestamp(iNewHour, iNewMinute, iNewSecond);
}

// AddHours adds the given hours to the timestamp.
cTimestamp cTimestamp::AddHours(int iHours)
{
    int iNewHour = this->m_iHour + iHours;
    int iNewMinute = this->m_iMinute;
    int iNewSecond = this->m_iSecond;

    return cTimestamp(iNewHour, iNewMinute, iNewSecond);
}

// AddTime adds the given timestamp to the current timestamp.
cTimestamp cTimestamp::AddTime(cTimestamp ts)
{
    int iTotalSeconds =
        this->m_iHour * 3600 + this->m_iMinute * 60 + this->m_iSecond + ts.m_iHour * 3600 + ts.m_iMinute * 60 + ts.m_iSecond;
    int iSecondsInDay = 24 * 3600;
    iTotalSeconds = ((iTotalSeconds % iSecondsInDay) + iSecondsInDay) % iSecondsInDay;

    int iNewHour = iTotalSeconds / 3600;
    int iNewMinute = (iTotalSeconds % 3600) / 60;
    int iNewSecond = iTotalSeconds % 60;

    return cTimestamp(iNewHour, iNewMinute, iNewSecond);
}