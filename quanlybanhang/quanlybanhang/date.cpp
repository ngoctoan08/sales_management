#include "date.h"
date::date() {
	ngay = thang = nam = 0;
}

date::~date() {
}

int date::getNgay() {
	return ngay;
}

int date::getThang() {
	return thang;
}

int date::getNam() {
	return nam;
}

void date::setDate(int NGAY, int THANG, int NAM) {
	this->ngay = NGAY;
	this->thang = THANG;
	this->nam = NAM;
}

void date::nhap() {
	cin >> ngay >> thang >> nam;
}

void date::xuat() {
	cout << ngay << "/" << thang << "/" << nam << left << setw(12) << " ";
}

