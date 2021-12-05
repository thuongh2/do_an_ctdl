#pragma once

void NhapDauSach(DSDauSach& dsDs, int toadoX, int toadoY)
{
	DauSach ds;
	ds.soLanMuon = 0;
	string vitri = "";

	int pointer1 = toadoY;
	GiaoDienNhapDauSach(toadoX, toadoY);
	textcolor(112);
	ShowCur(1);

	while (true)
	{
		if (pointer1 == toadoY)
		{
			gotoXY(toadoX + 2 + ds.MSSach.length(), pointer1 + 1);
			XuLyNhapMa(ds.MSSach, toadoX + 2, pointer1, 10);//nhap mã sách
			if (pointer1 < toadoY)
			{
				pointer1 = toadoY + 24;
			}
		}
		else if (pointer1 == toadoY + 3)
		{
			gotoXY(toadoX + 2 + ds.tensach.length(), pointer1 + 1);
			XuLyNhapChu(ds.tensach, toadoX + 2, pointer1, 35);//nhập tên sách
		}
		else if (pointer1 == toadoY + 6)
		{
			gotoXY(toadoX + 2 + DemChuSo(ds.sotrang), pointer1 + 1);
			XuLyNhapSo(ds.sotrang, toadoX + 2, pointer1);//nhập số trang
		}
		else if (pointer1 == toadoY + 9)
		{
			gotoXY(toadoX + 2 + ds.tacgia.length(), pointer1 + 1);
			XuLyNhapChu(ds.tacgia, toadoX + 2, pointer1, 24);//nhap tên tác giả
		}
		else if (pointer1 == toadoY + 12)
		{
			gotoXY(toadoX + 2 + DemChuSo(ds.nxb), pointer1 + 1);
			XuLyNhapSo(ds.nxb, toadoX + 2, pointer1);//nhập năm xuất bản
		}
		else if (pointer1 == toadoY + 15)
		{
			gotoXY(toadoX + 2 + ds.theloai.length(), pointer1 + 1);
			XuLyNhapChu(ds.theloai, toadoX + 2, pointer1, 20);//nhập thể loại
		}
		else if (pointer1 == toadoY + 18)
		{
			gotoXY(toadoX + 2 + vitri.length(), pointer1 + 1);
			XuLyNhapChu(vitri, toadoX + 2, pointer1, 20);//nhập vị trí
		}
		else if (pointer1 == toadoY + 21)
		{
			gotoXY(toadoX + 2 + DemChuSo(ds.dms.sl), pointer1 + 1);
			XuLyNhapSo(ds.dms.sl, toadoX + 2, pointer1);//nhập số lượng
		}
		else if (pointer1 == toadoY + 24)//Xác nhận 
		{
			ShowCur(0);
			int pointer2 = toadoX + 15;
			while (true)
			{
				if (kbhit())
				{
					char c = getch();
					if (c == 13)
					{
						DauSach* temp = timDauSach(dsDs, ds.MSSach);//tìm đã có sách chưa

						if (!ds.MSSach.empty() && temp == NULL && !ds.tensach.empty() && (ds.sotrang > 0) && !ds.tacgia.empty()
							&& ds.nxb > 0 && !ds.theloai.empty() && !vitri.empty()
							&& (ds.dms.sl > 0) && pointer2 == toadoX + 15)//chech tất cả các trường khác null
						{
							DinhDangChuoi(ds.tensach);//Chuẩn hóa chuỗi
							DinhDangChuoi(ds.tacgia);
							DinhDangChuoi(ds.theloai);
							DinhDangChuoi(vitri);

							//Chia thành từng cuốn sách có ms sách = ms+thứ tự
							for (int i = 1; i <= ds.dms.sl; i++) {
								Sach sach;
								sach.masach = NoiChuoi(ds.MSSach, i);
								sach.trangthai = 0;
								sach.vitri = vitri;
								themSach(ds.dms, sach);//them sách vào cùng một danh mục
							}
							themDauSach(dsDs, ds);//thêm vào danh sách sách theo danh mục

							GiaoDienThongBao("THEM THANH CONG");
							return;
						}
						else if (pointer2 == toadoX + 30)
						{
							return;
						}
						else
						{
							if (temp != NULL)
							{
								gotoXY(107, 46);
								cout << "                                 ";
								gotoXY(107, 46);
								cout << "MA DAU SACH DA TON TAI";
							}
							else
							{
								gotoXY(107, 46);
								cout << "VUI LONG DIEN DAY DU THONG TIN";
							}
						}
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)
						{
							gotoXY(toadoX + 30, toadoY + 25);
							cout << "HUY";
							gotoXY(toadoX + 15, toadoY + 25);
							cout << "XAC NHAN";
							ShowCur(1);
							pointer1 = pointer1 - 3;
							break;
						}
						else if (c == 80)
						{

							gotoXY(toadoX + 30, toadoY + 25);
							cout << "HUY";
							gotoXY(toadoX + 15, toadoY + 25);
							cout << "XAC NHAN";
							ShowCur(1);
							pointer1 = toadoY;
							break;
						}
						else if (c == 75)
						{
							if (pointer2 == toadoX + 30)
							{
								pointer2 = toadoX + 15;
							}
							else
								pointer2 = toadoX + 30;
						}
						else if (c == 77)
						{
							if (pointer2 == toadoX + 15)
							{
								pointer2 = toadoX + 30;
							}
							else
								pointer2 = toadoX + 15;
						}
					}
				}

				SetColor(4);
				gotoXY(pointer2, pointer1 + 1);
				if (pointer2 == toadoX + 15)
				{
					cout << "XAC NHAN";
					textcolor(112);
					gotoXY(toadoX + 30, toadoY + 25);
					cout << "HUY";
				}
				else if (pointer2 == toadoX + 30)
				{
					cout << "HUY";
					textcolor(112);
					gotoXY(toadoX + 15, toadoY + 25);
					cout << "XAC NHAN";
				}
			}
		}
	}
}


void XuatDanhSachDMS(DanhMucSach dsSach, int toadoX, int toadoY) {
	int j = 0;
	textcolor(112);
	for (NodeSach* k = dsSach.phead; k != NULL; k = k->pNext)
	{
		gotoXY(toadoX + 1, toadoY + 4 + j);
		cout << k->data.masach;
		gotoXY(toadoX + 26 + 1, toadoY + 4 + j);
		cout << TrangThaiSach(k->data.trangthai);
		gotoXY(toadoX + 51 + 1, toadoY + 4 + j);
		cout << k->data.vitri;

		j = j + 2;
	}
	GiaoDienXuatDSDMS(toadoX, toadoY, dsSach.sl);
}
void XuatThongTinSach(DauSach* nodeDauSach, int toadoX, int toadoY) {
	system("cls");
	VeKhung(5, 1, 200, 50, 7);
	ToMauHCN(5, 1, 200, 6, 50);
	gotoXY(98, 4);
	textcolor(50);
	cout << "THONG TIN SACH";
	if (nodeDauSach->dms.sl > 12)
	{
		ToMauHCN(5, 7, 200, (nodeDauSach->dms.sl * 2 + 3) + 16, 112);
		VeKhung(5, 1, 200, (nodeDauSach->dms.sl * 2 + 3) + 22, 7);
	}
	else
	{
		ToMauHCN(5, 7, 200, 44, 112);
	}

	int toadoYTemp = toadoY - 5;
	gotoXY(toadoX, toadoYTemp++);
	toadoYTemp++;
	textcolor(112);
	cout << "THONG TIN SACH";
	GiaoDienXuat1DauSach(toadoX, toadoYTemp);
	toadoYTemp += 4;

	gotoXY(toadoX + 1, toadoYTemp);
	cout << nodeDauSach->MSSach;
	gotoXY(toadoX + 12 + 1, toadoYTemp);
	cout << nodeDauSach->tensach;
	gotoXY(toadoX + 53 + 1, toadoYTemp);
	cout << nodeDauSach->tacgia;
	gotoXY(toadoX + 79 + 1, toadoYTemp);
	cout << nodeDauSach->nxb;
	gotoXY(toadoX + 89 + 1, toadoYTemp);
	cout << nodeDauSach->theloai;
	toadoYTemp += 3;
	XuatDanhSachDMS(nodeDauSach->dms, toadoX, toadoYTemp++);
}
void xuLiXuatDSDS(DSDauSach dsds, int toadoX, int toadoY) {
	int j = 0;
	textcolor(112);
	for (int i = 0; i < dsds.sl; i++) {
		gotoXY(toadoX + 2, toadoY + j + 4);
		cout << i + 1;
		gotoXY(toadoX + 7, toadoY + j + 4);
		cout << dsds.data[i]->MSSach;
		gotoXY(toadoX + 17 + 1, toadoY + j + 4);
		cout << dsds.data[i]->tensach;
		gotoXY(toadoX + 54 + 2, toadoY + j + 4);
		cout << dsds.data[i]->sotrang;
		gotoXY(toadoX + 61 + 1, toadoY + j + 4);
		cout << dsds.data[i]->tacgia;
		gotoXY(toadoX + 87 + 3, toadoY + j + 4);
		cout << dsds.data[i]->nxb;
		gotoXY(toadoX + 98 + 1, toadoY + j + 4);
		cout << dsds.data[i]->theloai;
		gotoXY(toadoX + 118 + 2, toadoY + j + 4);
		cout << dsds.data[i]->dms.sl;
		j = j + 2;
	}
	GiaoDienXuatDSDauSach(toadoX, toadoY, dsds.sl);
}
void menuMaDauSach(DSDauSach dsDs, int toadoX, int toadoY) {
	int j = 0;
	textcolor(112);
	for (int i = 0; i < dsDs.sl; i++) {
		ToMauHCN(toadoX + 7, toadoY + j - 1, 10, 2, 112);
		gotoXY(toadoX + 7, toadoY + j);
		cout << dsDs.data[i]->MSSach;
		j += 2;
	}
}
void GiaoDienMaDauSach(DSDauSach dsds, int toadoX, int toadoY) {

	textcolor(112);
	VeKhung(5, 1, 200, 50, 7);
	xuLiXuatDSDS(dsds, toadoX, toadoY);

	gotoXY(toadoX + 50, toadoY - 4);
	textcolor(50);
	cout << "DANH SACH CAC DAU SACH";
	textcolor(112);
	gotoXY(toadoX, toadoY - 3);
	cout << "Nhan ENTER De Xem Thong Tin Sach";
	gotoXY(toadoX, toadoY - 2);
	cout << "Nhan ESC De Thoat";
}
void RunMenuMaDauSach(DSDauSach dsDs, int toadoX, int toadoY, int& pointer1, bool& kt) {//12
	if (kbhit())
	{
		char c = getch();
		if (c == -32)
		{
			c = getch();
			if (c == 72)
			{
				if (pointer1 == toadoY)//12
				{
					menuMaDauSach(dsDs, toadoX, toadoY);
					pointer1 = toadoY + (dsDs.sl - 1) * 2;//12+ 8=20;
				}
				else
				{
					menuMaDauSach(dsDs, toadoX, toadoY);
					pointer1 -= 2;
				}
			}
			else if (c == 80)
			{
				if (pointer1 == toadoY + (dsDs.sl - 1) * 2)
				{
					menuMaDauSach(dsDs, toadoX, toadoY);
					pointer1 = toadoY;
				}
				else
				{
					menuMaDauSach(dsDs, toadoX, toadoY);
					pointer1 += 2;
				}
			}
		}
		else if (c == 13)
		{

			for (int i = 0; i < dsDs.sl; i++) {
				if (pointer1 - toadoY - i * 2 == 0) //kiểm tra vi tri con tro tuong duong voi index sach
				{
					XuatThongTinSach(dsDs.data[i], toadoX - 7, toadoY);

					getch();
					if (dsDs.data[i]->dms.sl > 12)
					{
						ToMauHCN(5, 7, 200, (dsDs.data[i]->dms.sl * 2 + 3) + 16, 112);
						ToMauHCN(3, 51, 204, (dsDs.data[i]->dms.sl * 2 + 3) + 16 - 43, 240);
					}
					else
					{
						ToMauHCN(5, 7, 200, 44, 112);
					}
					break;
				}
			}
			GiaoDienMaDauSach(dsDs, toadoX, toadoY - 4);
		}
		else if (c == 27) {
			kt = false;
		}

		// to mau 
		ToMauHCN(toadoX + 7, pointer1 - 1, 10, 2, 50);
		gotoXY(toadoX + 7, pointer1);//17
		textcolor(50);
		cout << dsDs.data[(pointer1 - toadoY) / 2]->MSSach;
	}
}
void xuatThongTinDSDS(DSDauSach dsds, int toadoX, int toadoY)
{
	int pointer1 = toadoY + 4;
	bool kt = true;
	GiaoDienMaDauSach(dsds, toadoX, toadoY);
	ToMauHCN(toadoX + 7, toadoY + 3, 10, 2, 50);
	gotoXY(toadoX + 7, toadoY + 4);
	cout << dsds.data[0]->MSSach;
	textcolor(112);

	while (kt) {
		RunMenuMaDauSach(dsds, toadoX, toadoY + 4, pointer1, kt);
	}
}

void xuLiXuatDSDSTheoTheLoai(DSDauSach dsDauSachTemp, int toadoX, int toadoY)
{
	int j = 0;
	textcolor(112);
	GiaoDenXuatDauSachTheoTheLoai(toadoX + 2, toadoY + 1, dsDauSachTemp.sl);
	for (int k = 0; k < dsDauSachTemp.sl; k++)
	{
		gotoXY(toadoX + 1 + 2, toadoY + 5 + j);
		cout << dsDauSachTemp.data[k]->MSSach;
		gotoXY(toadoX + 12 + 3, toadoY + 5 + j);
		cout << dsDauSachTemp.data[k]->tensach;
		gotoXY(toadoX + 52 + 3, toadoY + 5 + j);
		cout << dsDauSachTemp.data[k]->sotrang;
		gotoXY(toadoX + 59 + 3, toadoY + 5 + j);
		cout << dsDauSachTemp.data[k]->tacgia;
		gotoXY(toadoX + 87 + 3, toadoY + 5 + j);
		cout << dsDauSachTemp.data[k]->nxb;
		gotoXY(toadoX + 95 + 3, toadoY + 5 + j);
		cout << dsDauSachTemp.data[k]->dms.phead->data.vitri;
		gotoXY(toadoX + 122 + 3, toadoY + 5 + j);
		cout << dsDauSachTemp.data[k]->dms.sl;
		j = j + 2;
	}
}
void MenuDSTheLoai(string* dsTheLoai, int n, int toadoX, int toadoY) {//80,10
	GiaoDienMenu(toadoX, toadoY, n, dsTheLoai, 4);
	ToMauHCN(80, toadoY + n * 5, 50, 4, 240);
	gotoXY(toadoX + 22, toadoY + n * 5 + 2);
	cout << "Thoat";
}
void RunDSTheLoai(DSDauSach dsDs, string* dsTheLoai, int n, int toadoX, int toadoY, int& pointer2, bool& kt2) {
	if (kbhit())
	{
		char c = getch();
		if (c == -32)
		{
			c = getch();
			if (c == 72)
			{
				if (pointer2 == 10)
				{
					MenuDSTheLoai(dsTheLoai, n, toadoX, toadoY);
					pointer2 = 10 + n;
				}
				else
				{
					MenuDSTheLoai(dsTheLoai, n, toadoX, toadoY);
					pointer2--;
				}
			}
			else if (c == 80)
			{
				if (pointer2 == 10 + n)
				{
					MenuDSTheLoai(dsTheLoai, n, toadoX, toadoY);
					pointer2 = 10;
				}
				else
				{
					MenuDSTheLoai(dsTheLoai, n, toadoX, toadoY);
					pointer2++;
				}
			}
		}
		else if (c == 13)
		{
			if (pointer2 == 10 + n)//thoát
			{
				delete[] dsTheLoai;
				kt2 = false;
				return;
			}
			else
			{
				for (int i = 0; i < n; i++) {
					if (pointer2 == 10 + i) {
						DSDauSach dsDauSachTemp = layDSDauSachTheoTheLoai(dsDs, dsTheLoai[i]);//lấy các sách có cùng thể loại
						sapXepDSDauSachTheoTen(dsDauSachTemp);

						int x = toadoX - 40;
						ToMauHCN(5, 7, 200, (n + 1) * 5 + 4, 112);
						textcolor(50);
						gotoXY(80 + (50 - dsTheLoai[i].length()) / 2, 11);
						cout << dsTheLoai[i];
						xuLiXuatDSDSTheoTheLoai(dsDauSachTemp, x, toadoY + 2);
						getch();
					}
				}
			}
			ToMauHCN(5, 7, 200, (n + 1) * 5 + 4, 112);
			MenuDSTheLoai(dsTheLoai, n, toadoX, toadoY);
		}

		textcolor(50);
		ToMauHCN(toadoX, 10 + (pointer2 - 10) * 5, 50, 4, 50);
		if (pointer2 == 10 + n) {
			gotoXY(toadoX + 22, 12 + (pointer2 - 10) * 5);
			cout << "Thoat";
		}
		else
		{
			gotoXY(toadoX + (50 - dsTheLoai[pointer2 - 10].length()) / 2, 12 + (pointer2 - 10) * 5);
			textcolor(50);
			cout << dsTheLoai[pointer2 - 10];
		}
	}
}
void XuatDSDauSachTheoTheLoai(DSDauSach dsDs, int toadoX, int toadoY) {
	int n = 0, pointer2 = toadoY;

	string* dsTheLoai = layDanhSachTheLoai(dsDs, n);//láy đanh sách các thể loại

	ShowCur(0);
	ToMauHCN(5, 1, 200, 6, 50);
	gotoXY(85, 4);
	textcolor(50);
	cout << "GIAO DIEN XUAT SACH THEO THE LOAI";
	if (n > 7) {
		ToMauHCN(5, 7, 200, (n + 1) * 5 + 4, 112);
		VeKhung(5, 1, 200, 6 + (n + 1) * 5 + 4, 7);
	}
	else
	{
		ToMauHCN(5, 7, 200, 44, 112);
	}


	MenuDSTheLoai(dsTheLoai, n, toadoX, toadoY);// xuất giao diện các thể loại
	ToMauHCN(toadoX, toadoY, 50, 4, 50);
	textcolor(50);
	gotoXY(toadoX + (50 - dsTheLoai[0].length()) / 2, toadoY + 2);
	cout << dsTheLoai[0];

	bool kt2 = true;

	while (kt2) {
		RunDSTheLoai(dsDs, dsTheLoai, n, toadoX, toadoY, pointer2, kt2);
	}
	if (n > 7) {
		ToMauHCN(3, 51, 204, (n + 1) * 5 + 4 - 44 + 1, 240);
		textcolor(112);
	}
}


void RunXuatDSDS(DSDauSach dsDs, string menuXuatDSDS[], int toadoX, int toadoY, int& pointer1, bool& kt1) {
	if (kbhit())
	{
		char c = getch();
		if (c == -32)
		{
			c = getch();
			if (c == 72)
			{
				if (pointer1 == 13)
				{
					GiaoDienMenu(toadoX, toadoY, 3, menuXuatDSDS, 6);
					pointer1 = 13 - 1 + 3;
				}
				else
				{
					GiaoDienMenu(toadoX, toadoY, 3, menuXuatDSDS, 6);
					pointer1--;
				}
			}
			else if (c == 80)
			{
				if (pointer1 == 13 - 1 + 3)
				{
					GiaoDienMenu(toadoX, toadoY, 3, menuXuatDSDS, 6);
					pointer1 = 13;
				}
				else
				{
					GiaoDienMenu(toadoX, toadoY, 3, menuXuatDSDS, 6);
					pointer1++;
				}
			}
		}
		else if (c == 13)
		{
			sapXepDSDauSachTheoTen(dsDs);
			switch (pointer1)
			{
			case 13: {//xuat theo the loai
				XuatDSDauSachTheoTheLoai(dsDs, toadoX, toadoY - 3);
				break;
			}

			case 14: {//xuat tat ca
				ToMauHCN(5, 7, 200, 44, 112);
				xuatThongTinDSDS(dsDs, toadoX - 40, toadoY);
				if (dsDs.sl > 15) {
					ToMauHCN(3, 51, 204, toadoY + (dsDs.sl * 2 + 3) - 43, 240);
				}
				break;
			}
			case 15: {
				kt1 = false;
				break;
			}
			}
			if (pointer1 != 15) {
				GiaoDienMain();
				GiaoDienMenu(toadoX, toadoY, 3, menuXuatDSDS, 6);
			}
		}

		// to mau 
		ToMauHCN(80, 13 + (pointer1 - 13) * 8, 50, 6, 50);//180//7
		gotoXY(80 + (50 - menuXuatDSDS[pointer1 - 13].length()) / 2, 16 + (pointer1 - 13) * 8);
		textcolor(50);//180
		cout << menuXuatDSDS[pointer1 - 13];
	}
}
void MenuXuatDSDS(DSDauSach dsDs, int toadoX, int toadoY) {
	string menuXuatDSDS[] = {//xem lai
		"XUAT DAU SACH THEO THE LOAI",
		"XUAT TAT CA DAU SACH",
		"THOAT"
	};
	ToMauHCN(5, 7, 200, 44, 112);
	GiaoDienMenu(toadoX, toadoY, 3, menuXuatDSDS, 6);
	ToMauHCN(toadoX, toadoY, 50, 6, 50);
	gotoXY(toadoX + (50 - menuXuatDSDS[0].length()) / 2, toadoY + 3);
	textcolor(50);
	cout << menuXuatDSDS[0];
	textcolor(112);
	int pointer1 = toadoY;
	bool kt1 = true;
	while (kt1) {
		RunXuatDSDS(dsDs, menuXuatDSDS, toadoX, toadoY, pointer1, kt1);// thuc hien cac chuc nang
	}
}

void TimThongTinSachDuaVaoTenSach(DSDauSach dsDs, int toadoX, int toadoY) {
	ToMauHCN(5, 1, 200, 7, 50);
	ToMauHCN(5, 7, 200, 44, 112);
	VeKhung(5, 1, 200, 50, 7);
	gotoXY(92, 4);
	textcolor(50);
	cout << "GIAO DIEN TIM SACH";

	string tenSach;
	DSDauSach dsDSTemp;
	textcolor(112);
	do
	{
		gotoXY(toadoX - 25, toadoY);
		cout << "NHAP TEN SACH CAN TIM( Nhan ESC De Thoat ): ";
		VeHCN(toadoX + 18, toadoY - 1, 51, 2);
		gotoXY(toadoX + 20, toadoY);
		tenSach = XuLyNhapChu();// nhap ten sach can tim
		if (!tenSach.empty())
			DinhDangChuoi(tenSach);//chuẩn hóa chuỗi
		if (tenSach.empty())
		{
			return;
		}

		dsDSTemp = timTenSach(dsDs, tenSach);//thuật toán tìm tên sách
		if (dsDSTemp.sl <= 0)
		{
			GiaoDienThongBao("TEN SACH KHONG TON TAI");
			ToMauHCN(5, 7, 200, 44, 112);
		}
	} while (dsDSTemp.sl <= 0);

	int pointer1 = toadoY + 4;
	bool kt = true;
	ToMauHCN(toadoX - 27, toadoY - 2, 100, 4, 112);
	GiaoDienMaDauSach(dsDSTemp, toadoX, toadoY);//đi đến giao diện hiển thị danh sách tìm được
	ToMauHCN(toadoX + 7, toadoY + 3, 10, 2, 50);
	gotoXY(toadoX + 7, toadoY + 4);
	cout << dsDSTemp.data[0]->MSSach;
	textcolor(112);

	while (kt) {
		RunMenuMaDauSach(dsDSTemp, toadoX, toadoY + 4, pointer1, kt);//hiển thị sách
	}
}

