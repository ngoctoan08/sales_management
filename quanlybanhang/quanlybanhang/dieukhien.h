#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "mathang.h"
#include "khachhang.h"
#include "hoadon.h"
#include <fstream>
using namespace std;
class dieukhien
{
private:
	vector <mathang*> listMH;
	vector <khachhang*> listKH;
	vector <hoadon*> lishHD;
	ofstream fileout;
	ifstream filein;
public:
	void themMH(mathang* m);
	void docMH();
	void themKH(khachhang* k);
	void docKH();
	void themHD(hoadon* h);
	void menu();
	void start();
};

