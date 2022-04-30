#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include "date.h"
using namespace std;
class khachhang
{
private:
	int maKH;
	string hoten;
	date ngaysinh;
	string gioitinh;
	string diachi;
public:
	khachhang();
	khachhang(int MAKH, string HOTEN, string DIACHI);
	int getMaKH();
	string getHoten();
	void setMaKH(int MAKH);
	void setInfo(int MAKH, string HOTEN, int NGAY, int THANG, int NAM, string GIOITINH, string DIACHI);
	void nhap();
	void xuat();
	void ghiKH(ofstream &fileout);
	void taoHD();
};

