#include <iostream>
#include <string>
using namespace std;

class SinhVien {
    private:
        string HoVaTen;
        string msv;
        double gpa;
        string birth;
    public:
        void Input();
        void Output();
        double getGPA();

};

void SinhVien::Input () {
    cout << "Nhap ma so sinh vien: "; cin >> this->msv;
    cin.ignore();
    cout << "Nhap ho va ten sinh vien: "; getline(cin,this->HoVaTen);
    cout << "Nhap ngay thang nam sinh: "; cin >> this->birth;
    cout << "Nhap gpa cua sinh vien: "; cin >> this->gpa; 
}
void SinhVien::Output () {
    cout << "MSV: " <<  this->msv << endl << "Ho va ten: " << this-> HovaTen << endl << "Ngay thang nam sinh: " << this->birth << endl << "GPA: " << this->gpa << endl << endl;
}
double SinhVien::getGPA () {
    return this->gpa;
}
bool GPAcompare (SinhVien a, SinhVien b) {
    return a.getGPA() > b.getGPA();
}

int main () {

}