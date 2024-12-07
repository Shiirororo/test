#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
struct Truong {                                     //Struct của 1 trường
    string truong;
    string khoa;
};

class SinhVien {                                    //Định nghĩa Class Sinh Viên
    private:
        string HoVaTen;                             
        string msv;
        double gpa;
        string birth;
        Truong School;
        static int total_sv;                        //Hàm đếm tổng số sinh viên
    public:
        void Input();                               //Các Function của Class Sinh Viên
        void Output();
        double getGPA();
        void Write(fstream &fs);
};
class GiangVien {                                    //Định nghĩa của Class Giảng Viên
    private: 
        string HoVaTen;
        string msv;
        string birth;
        static int total_gv;
        Truong School;
    public: 
        void Input ();                              //Các Function thuộc Class Giảng Viên
        void Output ();
        void Write(fstream &fs);
};

//Từ đoạn này là hàm thuộc Class Giảng Viên
void GiangVien::Input () {                          //Hàm nhập thông tin của giảng viên vào chương trình
    cout << "Nhập mã của giảng viên: "; cin >> this->msv;   
    cin.ignore();
    cout << "Nhập họ và tên giảng viên: "; cin >> this->HoVaTen;
    cout << "Nhập ngày tháng năm sinh: "; cin >> this->birth;
    cout << "Nhập khoa, trường giảng viên trực thuộc: "; cin >> this->School.khoa >> this->School.truong;
}
void GiangVien::Output() {                         //Hàm xuất thông tin của giảng viên ra màn hình
    cout << "MSV: " <<  this->msv << endl << "Họ và tên: " << this->HoVaTen << endl << "Ngày tháng năm sinh: " << this->birth << endl << "Khoa: " << this->School.khoa << endl << "Trường: " <<this->School.truong << endl << endl;
}       

void GiangVien::Write() {                          //Hàm ghi thông tin của giảng viên vào file text

}



//Từ đoạn này là hàm thuộc Class Sinh Viên

void SinhVien::Input () {                           //Hàm nhập thông tin sinh viên vào chương trình
    cout << "Nhập mã số sinh viên: "; cin >> this->msv;
    cin.ignore();
    cout << "Nhập họ và tên sinh viên: "; getline(cin,this->HoVaTen);
    cout << "Nhập ngày tháng năm sinh: "; cin >> this->birth;
    cout << "Nhập gpa của sinh viên: "; cin >> this->gpa; 
}
void SinhVien::Write (fstream &fs) {                //Hàm ghi thông tin sinh viên vào file text
    fs.open("data_log.txt", ios::app);
    if (fs.is_open()) {
    fs << this->msv;
    fs << ";";
    fs << this->HoVaTen << ";";
    fs << this->birth << ";";
    fs << this->gpa << ";"; 
    fs << endl;
    fs.close();
    }
}
void SinhVien::Output () {                          //Hàm xuất thông tin sinh viên ra màn hình
    cout << "MSV: " <<  this->msv << endl << "Ho va ten: " << this->HoVaTen << endl << "Ngay thang nam sinh: " << this->birth << endl << "GPA: " << this->gpa << endl << endl;
}

double SinhVien::getGPA () {                        //Hàm lấy GPA khỏi vùng private của Class Sinh Viên
    return this->gpa;
}

bool GPAcompare (SinhVien a, SinhVien b) {
    return a.getGPA() > b.getGPA();
}
void Read (fstream fs) {                            //Hàm đọc thông tin sinh viên từ file text
    fs.open("data_log.txt", ios::in);
    if (fs.is_open()) {
        string line;
        while (getline(fs, line)) {
            cout << line << endl;
        }
        fs.close();
    }
}

int main () {
    cout << "Nhap N: ";
    int n; cin >> n;
    SinhVien a[n];
    fstream fs;
    for (int i = 0; i < n; i++) {
        a[i].Input();
        a[i].Write(fs);
    }
    // Read(fs);

    // sort(a, a+ n, GPAcompare);
    // for (int i = 0; i < n; i++) {
    //     a[i].Output();
    // }
}