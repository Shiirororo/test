#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class SinhVien {
    private:
        string HoVaTen;                             //Class sinh vien
        string msv;
        double gpa;
        string birth;
        static int total_sv;                        //Ham dem tong so sinh vien
    public:
        void Input();                               //Function cua class
        void Output();
        double getGPA();
        void Write(fstream &fs);
};

void SinhVien::Input () {                           //Ham de nhap thong tin sinh vien
    cout << "Nhap ma so sinh vien: "; cin >> this->msv;
    cin.ignore();
    cout << "Nhap ho va ten sinh vien: "; getline(cin,this->HoVaTen);
    cout << "Nhap ngay thang nam sinh: "; cin >> this->birth;
    cout << "Nhap gpa cua sinh vien: "; cin >> this->gpa; 
}
void SinhVien::Write (fstream &fs) {                //Ham de ghi thong tin sinh vien vao text
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
void SinhVien::Output () {                          //Ham de xuat thong tin sinh vien ra man hinh
    cout << "MSV: " <<  this->msv << endl << "Ho va ten: " << this->HoVaTen << endl << "Ngay thang nam sinh: " << this->birth << endl << "GPA: " << this->gpa << endl << endl;
}
double SinhVien::getGPA () {
    return this->gpa;
}
bool GPAcompare (SinhVien a, SinhVien b) {
    return a.getGPA() > b.getGPA();
}
void Read (fstream fs) {                  //Ham de doc thong tin sinh vien tu text va hien thi ra man hinh
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