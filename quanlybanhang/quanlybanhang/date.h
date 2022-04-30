#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
class date
{
private:
	int ngay, thang, nam;
public:
	date();
	~date();
	int getNgay();
	int getThang();
	int getNam();
	void setNgay(int NGAY);
	void setThang(int THANG);
	void setNam(int NAM);
	void setDate(int NGAY, int THANG, int NAM);
	void nhap();
	void xuat();
};

