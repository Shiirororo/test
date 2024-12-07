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
        void UpdateField();                         //update thông tin sv      
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
        void UpdateField();
        string getMSGV() const;
        string getName() const;
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

string GiangVien::getMSGV() const {              //Lấy tên và mssv khỏi private
     return msv;
}

string GiangVien::getName() const {
    return HoVaTen;
}


}

void xoaGiangVien(vector<GiangVien> &danhSach, const string &key) {
    bool found = false;

    // Duyệt danh sách để tìm sinh viên cần xóa
    for (int i = 0; i < danhSach.size(); ++i) {
        if (danhSach[i].getMSGV() == key || danhSach[i].getName() == key) {
            cout << "Đã xóa giảng viên: ";
            danhSach[i].Output();
            danhSach.erase(danhSach.begin() + i); // Xóa sinh viên tại chỉ số i
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Không tìm thấy giảng viên có MSGV hoặc tên: " << key << endl;
    }
}

void GiangVien::UpdateField() {
        int choice;
        /*cout << "Chọn thông tin cần thay đổi:" << endl;
        cout << "1. Họ và tên" << endl;
        cout << "2. MSV (Mã số giảng viên)" << endl;
        cout << "3. Ngày sinh" << endl;
        cout << "4. Tên trường" << endl;
        cout << "5. Khoa" << endl;
        cout << "Lựa chọn: ";*/
        cin >> choice;

        cin.ignore(); // Loại bỏ ký tự thừa sau khi nhập số

        switch (choice) {
            case 1: {
                cout << "Nhập họ và tên mới: ";
                getline(cin, HoVaTen);
                break;
            }
            case 2: {
                cout << "Nhập MSV mới: ";
                cin >> msv;
                break;
            }
            case 3: {
                cout << "Nhập ngày sinh mới (dd/mm/yyyy): ";
                cin.ignore();
                getline(cin, birth);
                break;
            }
            case 4: {
                cout << "Nhập tên trường mới: ";
                getline(cin, School.truong);
                break;
            }
            case 5: {
                cout << "Nhập khoa mới: ";
                getline(cin, School.khoa);
                break;
            }
            default:
                cout << "Lựa chọn không hợp lệ!" << endl;
                break;
        }
}

void UpdateGiangVienInVector(vector<GiangVien> &danhSachGiangVien) {
    if (danhSachGiangVien.empty()) {
        cout << "Danh sách giảng viên trống!" << endl;
        return;
    }

    string mssv;
    cout << "Nhập MSSV giảng viên cần chỉnh sửa: ";
    cin >> mssv;

    bool found = false;
    for (auto &gv : danhSachGiangVien) {
        if (gv.getMSSV() == mssv) {
            cout << "Giảng viên tìm thấy:\n";
            gv.Output();
            
            // Cập nhật thông tin giảng viên
            cout << "\nChỉnh sửa thông tin giảng viên:\n";
            gv.UpdateField();
            
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Không tìm thấy giảng viên có MSSV: " << mssv << endl;
    }
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
string SinhVien::getMSSV() const {              //Lấy tên và mssv khỏi private
     return msv;
}

string SinhVien::getName() const {
    return HoVaTen;
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

void xoaSinhVien(vector<SinhVien> &danhSach, const string &key) {
    bool found = false;

    // Duyệt danh sách để tìm sinh viên cần xóa
    for (int i = 0; i < danhSach.size(); ++i) {
        if (danhSach[i].getMSSV() == key || danhSach[i].getName() == key) {
            cout << "Đã xóa sinh viên: ";
            danhSach[i].Output();
            danhSach.erase(danhSach.begin() + i); // Xóa sinh viên tại chỉ số i
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Không tìm thấy sinh viên có MSSV hoặc tên: " << key << endl;
    }
}

void SinhVien::UpdateField() {
        int choice;
        /*cout << "Chọn thông tin cần thay đổi:" << endl;
        cout << "1. Họ và tên" << endl;
        cout << "2. MSSV" << endl;
        cout << "3. GPA" << endl;
        cout << "4. Ngày sinh" << endl;
        cout << "Lựa chọn: ";*/
        cin >> choice;

        cin.ignore(); // Loại bỏ ký tự thừa sau khi nhập số

        switch (choice) {
            case 1: {
                cout << "Nhập họ và tên mới: ";
                getline(cin, HoVaTen);
                break;
            }
            case 2: {
                cout << "Nhập MSSV mới: ";
                cin >> msv;
                break;
            }
            case 3: {
                cout << "Nhập GPA mới: ";
                cin >> gpa;
                break;
            }
            case 4: {
                cout << "Nhập ngày sinh mới (dd/mm/yyyy): ";
                cin.ignore();
                getline(cin, birth);
                break;
            }
            default:
                cout << "Lựa chọn không hợp lệ!" << endl;
                break;
        }
}


void chinhSuaSinhVien(vector<SinhVien> &danhSach) {
    if (danhSach.empty()) {
        cout << "Danh sách sinh viên trống!" << endl;
        return;
    }

    // Hiển thị danh sách sinh viên
    cout << "Danh sách sinh viên hiện có:\n";
    for (size_t i = 0; i < danhSach.size(); ++i) {
        cout << i + 1 << ". ";
        danhSach[i].Output();
    }

    // Chọn sinh viên để chỉnh sửa
    string key;
    cout << "\nNhập MSSV hoặc tên sinh viên cần chỉnh sửa: ";
    cin.ignore();
    getline(cin, key);

    bool found = false;
    for (auto &sv : danhSach) {
        if (sv.getMSSV() == key || sv.getName() == key) {
            cout << "\nSinh viên được chọn:\n";
            sv.Output();

            // Gọi hàm cập nhật thông tin của sinh viên
            cout << "\nCập nhật thông tin sinh viên:\n";
            sv.UpdateField();

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Không tìm thấy sinh viên có MSSV hoặc tên: " << key << endl;
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