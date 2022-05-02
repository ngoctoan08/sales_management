#include "khachhang.h"
int khachhang::getMaKH() {
	return this->maKH;
}

string khachhang::getHoten() {
	return hoten;
}

khachhang::khachhang() {
}

khachhang::khachhang(int MAKH, string HOTEN, string DIACHI) {
	this->maKH = MAKH;
	this->hoten = HOTEN;
	this->diachi = DIACHI;
}

void khachhang::setMaKH(int MAKH) {
	this->maKH = MAKH;
}

void khachhang::setInfo(int MAKH, string HOTEN, int NGAY, int THANG, int NAM, string GIOITINH, string DIACHI) {
	this->maKH = MAKH;
	this->hoten = HOTEN;
	this->ngaysinh.setDate(NGAY, THANG, NAM);
	this->gioitinh = GIOITINH;
	this->diachi = DIACHI;
}

void khachhang::nhap() {
	while (getchar() != '\n');
	cout << "\n\t\t\tNhap ho ten: ";
	getline(cin, hoten);
	cout << "\n\t\t\tNhap ngay sinh: ";
	ngaysinh.nhap();
	cin.ignore();
	cout << "\n\t\t\tNhap gioi tinh: ";
	getline(cin, gioitinh);
	cout << "\n\t\t\tNhap dia chi: ";
	getline(cin, diachi);
}

void khachhang::xuat() {
	cout << "\n\t\t" << left << setw(10) << maKH << setw(30) << hoten;
	ngaysinh.xuat();
	cout << left << setw(20) << gioitinh << setw(20) << diachi << endl;
	cout << "\n\t\t" << "________________________________________________________________________________________________________\n";
}

void khachhang::ghiKH(ofstream &fileout) {
	//ghi file
	fileout.open("khachhang.txt", ios::app);
	fileout << this->maKH << ",";
	fileout << this->hoten << ",";
	fileout << ngaysinh.getNgay() << "/";
	fileout << ngaysinh.getThang() << "/";
	fileout << ngaysinh.getNam() << ",";
	fileout << this->gioitinh << ",";
	fileout<< this->diachi << endl;
	fileout.close();
}

void khachhang::taoHD() {
	cin >> maKH;
}