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
		if (filein >> NGAY)
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
		if (getline(filein, GIOITINH, ','))
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
	filein.close();
}

void dieukhien::themDS(dsmua* ds) {
	bool x = false;
	int idkh;
	string hoten;
	mathang *m = new mathang;
	cout << "\n\t\t Tao hoa don cho khach hang: ";
	cin >> idkh;
	for (int i = 0; i < listKH.size(); i++)
	{
		if (idkh == listKH[i]->getMaKH()) {
			hoten = listKH[i]->getHoten();
			x = true;
		}

	}
	if (x==true)
	{
		cout << "\n\t\t\t1. Them ma hang.\n";
		cout << "\n\t\t\t0. Hoan thanh.\n";
		while (true) {
			int choose;
			cout << "\n\t\t\tNhap lua chon: ";
			cin >> choose;
			bool y = false;
			if (choose == 0) {
				cout << "\n\t\t\t Mua hang hoan tat.";
				break;
			}
			else if (choose == 1) {
				ds = new dsmua;
				cout << "\n\t\t\tNhap ma hang: ";
				m->taoHD();
				for (int j = 0; j < listMH.size(); j++)
				{
					if (m->getMahang() == listMH[j]->getMahang())
					{
						m = listMH[j];
						y = true;
					}
				}
				if (y == true)
				{
					int sl;
					cout << "\n\t\t\t Nhap so luong: ";
					cin >> sl;
					ds->setInfo(idkh, hoten, m, sl);
					listDS.push_back(ds);//them vao ds mua hang`
					ds->ghiDsmua(fileout);
				}
				else
				{
					cout << "\n\t\tMa hang khong ton tai";
				}
				//break;
			}
		}
	}
	else
	{
		cout << "\n\t\tKhach hang khong ton tai!";
	}
}

void tieude() {
	cout << left << "\n\t\t" << setw(10) << "Ma MH" << setw(20) << "Ten MH";
	cout << left << setw(15) << "So luong" << setw(15) << "Don gia" << setw(10) << "Thanh tien";
	cout << "\n\t\t" << "________________________________________________________________________________________________________\n";
}


void dieukhien::xuatDS() {
	int idkh;
	string hoten;
	cout << "\n\t\tDS mua hang cua KH: ";
	cin >> idkh;
	tieude();
	for (int i = 0; i < listDS.size(); i++)
	{
		if (idkh == listDS[i]->getIdkh()) {
			hoten = listDS[i]->getHoten();
			listDS[i]->xuat();
		}
	}
	cout << "\n\t\tMa khach hang: " << idkh << endl;
	cout << "\n\t\tHo ten: " << hoten << endl;
}

void dieukhien::lapHD() {
	int idkh;
	string hoten;
	cout << "\n\t\tLap hoa don cho KH: ";
	cin >> idkh;
	int tongtien = 0;
	tieude();
	for (int i = 0; i < listDS.size(); i++)
	{
		if (idkh==listDS[i]->getIdkh())
		{
			hoten = listDS[i]->getHoten();
			listDS[i]->xuat();
			tongtien += listDS[i]->getTT();
		}
	}
	cout << left << "\n\t\t" << "Tong tien: " << tongtien << endl;
	cout << "\n\t\tMa khach hang: " << idkh << endl;
	cout << "\n\t\tHo ten: " << hoten << endl;
}


void dieukhien::docDL() {
	while (true) {
		system("cls");
		cout << "\n\t\t\t1. Doc DL mat hang." << endl;
		cout << "\n\t\t\t2. Doc DL khach hang." << endl;
		cout << "\n\t\t\t3. Thoat" << endl;
		int chon;
		cout << "\n\t\t\t Doc DL: ";
		cin >> chon;
		if (chon==1)
		{
			this->docMH();
			system("pause");
			break;
		}
		else if(chon==2){
			this->docKH();
			system("pause");
			break;
		}
		else if (chon == 0) {
			cout << "\n\t\t\t Thoat";
			break;
		}
	}
}

void dieukhien::menu() {

	while (true) {
		system("cls");
		cout << "\n\t\t\t\t===============MENU===============" << endl;
		cout << "\n\t\t\t\t1. Them mat hang." << endl;
		cout << "\n\t\t\t\t2. Xuat DS mat hang." << endl;
		cout << "\n\t\t\t\t3. Them khach hang." << endl;
		cout << "\n\t\t\t\t4. Xuat DS khach hang." << endl;
		cout << "\n\t\t\t\t5. Them DS mua hang." << endl;
		cout << "\n\t\t\t\t6. Xuat DS mua hang" << endl;
		cout << "\n\t\t\t\t7. Lap hoa don." << endl;
		cout << "\n\t\t\t\t8. Doc du lieu mat hang." << endl;
		cout << "\n\t\t\t\t9. Doc du lieu khach hang." << endl;
		cout << "\n\t\t\t\t0. Thoat\n" << endl;
		cout << "\n\t\t\t\t==================================" << endl;
		cout << "\n\t\t\tNhap lua chon cua ban: ";
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
			//this->docMH();
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
			//this->docKH();
			cout << "\n\t\t" << left << setw(10) << "Ma KH" << setw(30) << "Ho va ten" << setw(20);
			cout << "Ngay sinh";
			cout << left << setw(20) << "Gioi tinh" << setw(20) << "Dia chi" << endl;
			cout << "\n\t\t" << "________________________________________________________________________________________________________\n";
			for (int i = 0; i < listKH.size(); i++)
			{
				listKH[i]->xuat();
			}
			system("pause");
			break;
		}
		case 5: {
			dsmua* ds = new dsmua;
			this->themDS(ds);
			system("pause");
			break;
		}
		case 6: {
			this->xuatDS();
			system("pause");
			break;
		}
		case 7: {
			this->lapHD();
			system("pause");
			break;
		}
		case 8: {
			this->docMH();
			system("pause");
			break;
		}
		case 9: {
			this->docKH();
			system("pause");
			break;
		}
		case 0: {
			cout << "\n\t\t\t\tThoat";
			return;
			break;
		}
		default:
			cout << "\n\t\t\t\tNhap sai!";
			break;
		}
	}
}

void dieukhien::start() {
	menu();
}