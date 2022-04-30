#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include "khachhang.h"
#include "mathang.h"
using namespace std;
class hoadon
{
private:
	int soluong;
	khachhang *k;
	mathang *m;
public:
	hoadon();
	~hoadon();
	int getSL();
	khachhang getKH();
	mathang getMH();
	void setInfo(khachhang* k, mathang* m, int);
	void xuat();
	void ghiHD(ofstream& fileout);
};

