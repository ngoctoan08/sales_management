#include "dsmua.h"
dsmua::dsmua() {
	m = new mathang;
}

dsmua::~dsmua(){
    delete m;
}

int dsmua::getSL() {
	return soluong;
}

float dsmua::getTT() {
	return thanhtien;
}

int dsmua::getIdkh() {
	return idkh;
}

string dsmua::getHoten(){
	return hoten;
}

void dsmua::setHoten(string HOTEN) {
	this->hoten = HOTEN;
}

mathang dsmua::getMH() {
	return *m;
}

void dsmua::setInfo(int IDKH, string HOTEN, mathang* M, int SOLUONG) {
	this->idkh = IDKH;
	this->hoten = HOTEN;
	this->m = M;
	this->soluong = SOLUONG;
}


void dsmua::xuat() {
	this->thanhtien = this->soluong * m->getGia();
	cout << left << "\n\t\t" << setw(10) << m->getMahang() << setw(20) << m->getTenhang();
	cout << left << setw(15) << this->soluong << setw(15) << this->m->getGia() << setw(10) << this->thanhtien;
	cout << "\n\t\t" << "________________________________________________________________________________________________________\n";
}

void dsmua::ghiDsmua(ofstream& fileout) {
	fileout.open("dsmua.txt", ios::app);
	fileout << idkh << "," << hoten << "," << m->getMahang() << "," << m->getTenhang() << "," << soluong << "," << m->getGia() << endl;
	fileout.close();
}
