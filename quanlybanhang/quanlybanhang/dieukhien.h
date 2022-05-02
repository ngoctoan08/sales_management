#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "mathang.h"
#include "khachhang.h"
#include "dsmua.h"
#include <fstream>
using namespace std;
class dieukhien
{
private:
	vector <mathang*> listMH;
	vector <khachhang*> listKH;
	vector <dsmua*> listDS;
	ofstream fileout;
	ifstream filein;
public:
	void themMH(mathang* m);
	void docMH();
	void themKH(khachhang* k);
	void docKH();
	void themDS(dsmua* ds);
	void xuatDS();
	void lapHD();
	void docDL();
	void menu();
	void start();
};

