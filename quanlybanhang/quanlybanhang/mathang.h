#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>

using namespace std;
class mathang
{
private:
	int mahang;
	float gia;
	string tenhang;
public:
	mathang();
	~mathang();
	int getMahang();
	void setMahang(int MAHANG);
	string getTenhang();
	float getGia();
	void setInfo(int MAHANG, string TENHANG, float GIA);
	void nhap();
	void xuat();
	void ghiMH(ofstream& fileout);
	void taoHD();
};

