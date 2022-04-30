#include "hoadon.h"
hoadon::hoadon() {
	k = new khachhang;
	m = new mathang;
}

hoadon::~hoadon(){
	delete k;
    delete m;
}

int hoadon::getSL() {
	return soluong;
}

khachhang hoadon::getKH() {
	return *k;
}

mathang hoadon::getMH() {
	return *m;
}

void hoadon::setInfo(khachhang* K, mathang* M, int SOLUONG) {
	this->k = K;
	this->m = M;
	this->soluong = SOLUONG;
}

void hoadon::xuat() {
	cout << left << "\n\t\t" << setw(10) << "Ma KH" << setw(20) << "Ten KH" << setw(10) << "Ma MH" << setw(20) << "Ten MH";
	cout << left << setw(10) << "So luong";
	cout << left << "\n\t\t" << setw(10) << k->getMaKH() << setw(20) << k->getHoten() << setw(10) << m->getMahang() << setw(20) << m->getTenhang();
	cout << left << setw(10) << this->soluong;
	cout << "\n\t\t" << "___________________________________________________\n";
}

void hoadon::ghiHD(ofstream& fileout) {
	fileout.open("hoadon.txt", ios::app);
	fileout << k->getMaKH() << "," << k->getHoten() << "," << m->getMahang() << "," << m->getTenhang() << "," << soluong << endl;
	fileout.close();
}
