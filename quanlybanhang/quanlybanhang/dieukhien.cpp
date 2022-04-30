#include "dieukhien.h"
void dieukhien::themMH(mathang *m) {
	m->nhap();
	m->ghiMH(fileout);
}

void dieukhien::docMH() {
	int MAHANG;
	string TENHANG;
	float GIA;
	filein.open("mathang.txt", ios::in);
	if (filein.fail())
	{
		cout << "\nKhong tim thay file!\n";
		return;
	}
	else
	{
		while (!filein.eof()) {
			mathang* m = new mathang;
			if (filein >> MAHANG) //fix loi vong lap vo han
			{
				filein.seekg(1, 1);
			}
			else {
				return;
			}
			if (getline(filein, TENHANG, ','))
			{
				//filein.seekg(1, 1);
			}
			else {
				return;
			}
			if (filein >> GIA)
			{
				filein.seekg(1, 1);
			}
			else {
				return;
			}
			m->setInfo(MAHANG, TENHANG, GIA);
			listMH.push_back(m);
		}
	}
	
	filein.close();
}

void dieukhien::themKH(khachhang* k) {
	k->nhap();
	k->ghiKH(fileout);
}

void dieukhien::docKH(){
	int MAKH;
	string HOTEN;
	int NGAY, THANG, NAM;
	string GIOITINH;
	string DIACHI;
	filein.open("khachhang.txt", ios::in);
	if (filein.fail())
	{
		cout << "\nKhong tim thay file!\n";
		return;
	}
	else
	{
		while (!filein.eof()) {
			khachhang* k = new khachhang;
			if (filein >> MAKH) //fix loi vong lap vo han
			{
				filein.seekg(1, 1);
			}
			else {
				return;
			}
			if (getline(filein, HOTEN, ','))
			{
				//filein.seekg(1, 1);
			}
			else {
				return;
			}
			if (filein>>NGAY)
			{
				filein.seekg(1, 1);
			}
			else
			{
				return;
			}
			if (filein >> THANG)
			{
				filein.seekg(1, 1);
			}
			else
			{
				return;
			}
			if (filein >> NAM)
			{
				filein.seekg(1, 1);
			}
			else
			{
				return;
			}
			if (getline(filein,GIOITINH,','))
			{

			}
			else
			{
				return;
			}
			if (getline(filein, DIACHI))
			{
				//filein.seekg(1, 1);
			}
			else {
				return;
			}
			k->setInfo(MAKH, HOTEN, NGAY, THANG, NAM, GIOITINH, DIACHI);
			listKH.push_back(k);
		}
	}
	filein.close();
}

void dieukhien::themHD(hoadon* h) {
	bool x = false;
	int idkh, idmh;
	khachhang *k = new khachhang;
	mathang *m = new mathang;
	cout << "\n\t\t Tao hoa don cho khach hang: ";
	k->taoHD();
	for (int i = 0; i < listKH.size(); i++)
	{
		if (k->getMaKH() == listKH[i]->getMaKH())
			k = listKH[i];
			x = true;
	}
	if (x==true)
	{
		bool y = false;
		cout << "\n\t\t Nhap ma hang can mua: ";
		m->taoHD();
		for (int j = 0; j < listMH.size(); j++)
		{
			if (m->getMahang()==listMH[j]->getMahang())
			{
				m = listMH[j];
				y = true;
			}
		}
		if (y==true)
		{
			hoadon* h = new hoadon;
			int sl;
			cout << "\n\t\t Nhap so luong: ";
			cin >> sl;
			//hoadon hd(k, m, sl); //tao ra 1 hoa don
			h->setInfo(k, m, sl);
			lishHD.push_back(h);//them vao ds hoa don
			h->ghiHD(fileout);
		}
		else
		{
			cout << "\n\t\tMa hang khong ton tai";
		}
	}
	else
	{
		cout << "\n\t\tKhach hang khong ton tai!";
	}
}

void dieukhien::menu() {

	while (true) {
		system("cls");
		cout << "\n\t\t===============MENU===============" << endl;
		cout << "\n\t\t1. Them mat hang." << endl;
		cout << "\n\t\t2. Xuat DS mat hang." << endl;
		cout << "\n\t\t3. Them khach hang." << endl;
		cout << "\n\t\t4. Xuat DS khach hang." << endl;
		cout << "\n\t\t5. Them hoa don." << endl;
		cout << "\n\t\t6. Xuat hoa don." << endl;
		cout << "\n\t\t8. Doc du lieu." << endl;
		cout << "\n\t\t0. Thoat" << endl;
		cout << "\n\t\t==================================" << endl;
		cout << "\n\t\tNhap lua chon cua ban: ";
		int luachon;
		cin >> luachon;
		switch (luachon)
		{
		case 1: {
			mathang* m = new mathang;
			m->nhap();
			listMH.push_back(m);
			m->ghiMH(fileout);
			system("pause");
			break;
		}
		case 2: {
			this->docMH();
			cout << "\n\t\t" << left << setw(10) << "Ma hang" << setw(20) << "Ten hang" << setw(20) << "Gia" << endl;
			for (int i = 0; i < listMH.size(); i++)
			{
				listMH[i]->xuat();
			}
			system("pause");
			break;
		}
		case 3: {
			khachhang* k = new khachhang;
			k->nhap();
			k->setMaKH(100 + listKH.size());
			listKH.push_back(k);
			k->ghiKH(fileout);
			system("pause");
			break;
		}
		case 4: {
		
			cout << "\n\t\t" << left << setw(10) << "Ma KH" << setw(30) << "Ho va ten" << setw(20);
			cout << "Ngay sinh";
			cout << left << setw(20) << "Gioi tinh" << setw(20) << "Dia chi" << endl;
			cout << "\n\t\t" << "______________________________________________________________________________________\n";
			for (int i = 0; i < listKH.size(); i++)
			{
				listKH[i]->xuat();
			}
			system("pause");
			break;
		}
		case 5: {
			hoadon* h = new hoadon;
			this->themHD(h);
			system("pause");
			break;
		}
		case 6: {
			for (int i = 0; i < lishHD.size(); i++)
			{
				lishHD[i]->xuat();
			}
			system("pause");
			break;
		}
		case 8: {
			this->docKH();
			system("pause");
			break;
		}
		case 0: {
			cout << "\n\t\tThoat";
			return;
			break;
		}

		default:
			cout << "\n\t\tNhap sai!";
			break;
		}
	}
}

void dieukhien::start() {
	menu();
}