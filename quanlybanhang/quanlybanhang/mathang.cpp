#include "mathang.h"
mathang::mathang() {
}

mathang::~mathang() {
}

void mathang::setInfo(int MAHANG, string TENHANG, float GIA) {
	this->mahang = MAHANG;
	this->tenhang = TENHANG;
	this->gia = GIA;
}

int mathang::getMahang() {
	return this->mahang;
}

string mathang::getTenhang() {
	return this->tenhang;
}

float mathang::getGia() {
	return this->gia;
}

void mathang::setMahang(int MAHANG) {
	this->mahang = MAHANG;
}

void mathang::nhap() {
	srand(time(NULL));
	this->mahang = rand();
	while (getchar() != '\n');
	cout << "Nhap ten MH: ";
	getline(cin, tenhang);
	cout << "Nhap gia: ";
	cin >> gia;
}

void mathang::xuat() {
	cout << "\n\t\t" << left << setw(10) << mathang::getMahang() << setw(20) << mathang::getTenhang() << setw(20) << mathang::getGia() << endl;
}

void mathang::ghiMH(ofstream &fileout) {
	fileout.open("mathang.txt", ios::app);
	fileout << this->mahang << "," << this->tenhang << "," << this->gia << endl;
	fileout.close();
}

void mathang::taoHD() {
	cin >> mahang;
}
