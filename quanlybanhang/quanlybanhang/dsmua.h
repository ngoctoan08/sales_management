#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include "khachhang.h"
#include "mathang.h"
using namespace std;
class dsmua
{
private:
	int soluong;
	float thanhtien;
	int idkh;
	string hoten;
	mathang *m;
public:
	dsmua();
	~dsmua();
	int getSL();
	float getTT();
	int getIdkh();
	string getHoten();
	void setHoten(string HOTEN);
	mathang getMH();
	void setInfo(int, string, mathang* m, int);
	void xuat();
	void ghiDsmua(ofstream& fileout);
};

