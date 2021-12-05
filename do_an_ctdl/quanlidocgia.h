#pragma once
#include "ctdl.h"
#include "dohoa.h"
#include "chuanhoa.h"
#include "thuattoan.h"
#include "menuchinh.h"
#include "xulinhap.h"
#include "quanlisach.h"
const int maxDG = 999999;

//Xu Li Doc Gia
void NhapDocGia(DSDocGia& dsDG, int toadoX, int toadoY)  //toadoX=95, toadoY=17
{
	textcolor(112);
	if (dsDG.sl == maxDG)
	{
		GiaoDienThongBao("Bo Nho Day");
		return;
	}

	DocGia dg;
	bool check = false;
	do
	{
		srand(time(NULL));
		int res = rand() % (100000 - 10000 + 1) + 10000;
		if (timMaDG(dsDG.tree, res) == NULL)
		{
			dg.maDG = res;
			check = true;
		}
	} while (check == false);
	dg.phai = 1;
	dg.trangthai = 1;
	dg.soSachDangmuon = 0;

	int pointer1 = toadoY;

	ToMauHCN(5, 1, 200, 7, 50);
	ToMauHCN(5, 7, 200, 44, 112);
	VeKhung(5, 1, 200, 50, 7);
	gotoXY(95, 4);
	textcolor(50);
	cout << "THEM DOC GIA";

	GiaoDienThemDocGia(toadoX, toadoY);
	textcolor(112);
	gotoXY(toadoX + 2, toadoY - 2);
	cout << dg.maDG;
	gotoXY(toadoX + 2, toadoY + 7);
	cout << dg.phai;

	ShowCur(1);//hien
	while (true)
	{
		if (pointer1 == toadoY) // nhap ho va ten lot
		{
			gotoXY(toadoX + 2 + dg.ho.length(), pointer1 + 1);
			XuLyNhapChu(dg.ho, toadoX + 2, pointer1, 30);
			if (pointer1 < toadoY)
			{
				pointer1 = toadoY + 9;
			}
		}
		else if (pointer1 == toadoY + 3) // nhap ten
		{
			gotoXY(toadoX + 2 + dg.ten.length(), pointer1 + 1);
			XuLyNhapChu(dg.ten, toadoX + 2, pointer1, 8);
		}
		else if (pointer1 == toadoY + 6) // gioi tinh
		{
			gotoXY(toadoX + 2 + DemChuSo(dg.phai), pointer1 + 1);
			XuLyNhapSo(dg.phai, toadoX + 2, pointer1);
		}
		else if (pointer1 == toadoY + 9) // save hoac huy
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
						if (!dg.ho.empty() && !dg.ten.empty() && (dg.phai == 1 || dg.phai == 2) && pointer2 == toadoX + 15)
						{
							DinhDangChuoi(dg.ho);
							DinhDangChuoi(dg.ten);

							ThemDocGia(dsDG.tree, dg);
							dsDG.sl++;
							GiaoDienThongBao("THEM THANH CONG");
							return;
						}
						else if (pointer2 == toadoX + 30)
						{
							return;
						}
						else
						{
							gotoXY(90, 30);
							textcolor(112);
							cout << "VUI LONG DIEN DAY DU THONG TIN";
						}
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)
						{
							textcolor(112);
							gotoXY(toadoX + 30, toadoY + 10);
							cout << "HUY";
							gotoXY(toadoX + 15, toadoY + 10);
							cout << "XAC NHAN";
							ShowCur(1);
							pointer1 = pointer1 - 3;
							break;
						}
						else if (c == 80)
						{
							textcolor(112);
							gotoXY(toadoX + 30, toadoY + 10);
							cout << "HUY";
							gotoXY(toadoX + 15, toadoY + 10);
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
					gotoXY(toadoX + 30, toadoY + 10);
					cout << "HUY";
				}
				else if (pointer2 == toadoX + 30)
				{
					cout << "HUY";
					textcolor(112);
					gotoXY(toadoX + 15, toadoY + 10);
					cout << "XAC NHAN";
				}
			}
		}
	}
}

void XuatThongTinDG(DocGia dg, int toadoX, int toadoY)
{
	ToMauHCN(5, 7, 200, 44, 112);
	GiaoDienXuatDSDocGia(toadoX, toadoY, 1);

	textcolor(112);
	gotoXY(toadoX, toadoY - 2);
	cout << "THONG TIN DOC GIA";

	gotoXY(toadoX + 1, toadoY + 4);
	cout << "1";
	gotoXY(toadoX + 7 + 1, toadoY + 4);
	cout << dg.maDG;
	gotoXY(toadoX + 17 + 1, toadoY + 4);
	cout << dg.ho + " " + dg.ten;
	gotoXY(toadoX + 57 + 1, toadoY + 4);
	cout << layGioiTinh(dg.phai);
	gotoXY(toadoX + 67 + 1, toadoY + 4);
	cout << layTrangThaiDocGia(dg.trangthai);
	gotoXY(toadoX + 80 + 1, toadoY + 4);
	cout << dg.soSachDangmuon;

	ToMauHCN(toadoX + 20, toadoY + 8, 52, 4, 50);
	gotoXY(toadoX + 22, toadoY + 10);
	cout << "VUI LONG KIEM TRA LAI THONG TIN ( ECS: De Thoat )";
}
void XuatDSDG(TreeNodeDG* t, int& n, int toadoX, int toadoY)
{
	if (t == NULL)
	{
		return;
	}

	XuatDSDG(t->pleft, n, toadoX, toadoY);

	gotoXY(toadoX + 1, toadoY + 4 + n * 2);
	cout << n + 1;
	gotoXY(toadoX + 7 + 1, toadoY + 4 + n * 2);
	cout << t->data.maDG;
	gotoXY(toadoX + 17 + 1, toadoY + 4 + n * 2);
	cout << t->data.ho + " " + t->data.ten;
	gotoXY(toadoX + 57 + 1, toadoY + 4 + n * 2);
	cout << layGioiTinh(t->data.phai);
	gotoXY(toadoX + 67 + 1, toadoY + 4 + n * 2);
	cout << layTrangThaiDocGia(t->data.trangthai);
	gotoXY(toadoX + 80 + 1, toadoY + 4 + n * 2);
	cout << t->data.soSachDangmuon;

	n++;
	XuatDSDG(t->pright, n, toadoX, toadoY);
}
void XuatDSDG(DSDocGia dsDG, int x, int y) {
	if (dsDG.sl > 15) {
		VeKhung(5, 1, 200, y + 3 + (2 * dsDG.sl + 3) + 3, 7);
		ToMauHCN(5, 7, 200, y + (2 * dsDG.sl + 3), 112);
	}
	else {
		ToMauHCN(5, 7, 200, 44, 112);
	}
	gotoXY(x + 40, y + 1);
	textcolor(50);
	cout << "DANH SACH DOC GIA";
	int n = 0;
	textcolor(112);
	XuatDSDG(dsDG.tree, n, x, y + 3);
	GiaoDienXuatDSDocGia(x, y + 3, n);
}

void XoaDocGia(DSDocGia& dsDG, int toadoX, int toadoY)//55,13
{
	ToMauHCN(5, 1, 200, 6, 50);
	gotoXY(97, 4);
	textcolor(50);
	cout << "XOA DOC GIA";
	XuatDSDG(dsDG, toadoX, toadoY);

	textcolor(112);
	int maDG = 0;
	TreeNodeDG* TreeNodeDG = NULL;
	do
	{
		VeHCN(toadoX + 35, toadoY - 4, 50, 2);
		gotoXY(toadoX, toadoY - 3);
		cout << "NHAP MA DOC GIA(ESC:De Thoat): ";

		gotoXY(toadoX + 37, toadoY - 3);
		maDG = XuLyNhapSo();
		if (maDG == -1)
		{
			return;
		}

		TreeNodeDG = timMaDG(dsDG.tree, maDG);
		if (TreeNodeDG == NULL)
		{
			GiaoDienThongBao("MA DOC GIA KHONG TON TAI");
			textcolor(112);
			gotoXY(toadoX + 37, toadoY - 3);
			cout << "                                        ";
			XuatDSDG(dsDG, toadoX, toadoY);
		}
	} while (TreeNodeDG == NULL);

	if (TreeNodeDG->data.soSachDangmuon > 0)
	{
		GiaoDienThongBao("DOC GIA CON DANG MUON SACH");
		return;
	}
	if (dsDG.sl > 15) {
		ToMauHCN(5, 7, 200, toadoY + (2 * dsDG.sl + 3), 112);
	}
	else {
		ToMauHCN(5, 7, 200, 44, 112);
	}
	XuatThongTinDG(TreeNodeDG->data, 55, toadoY);
	char c;
	while (true)
	{
		if (kbhit())
		{
			c = getch();
			if (c == 27)
			{
				return;
			}
			else
				break;
		}
	}

	XoaDocGiaTheoMaDG(dsDG.tree, maDG);
	dsDG.sl--;
	GiaoDienThongBao("XOA THANH CONG");
}

void SuaDocGia(DSDocGia& dsDG, int toadoX, int toadoY)
{
	ToMauHCN(5, 1, 200, 6, 50);
	gotoXY(95, 4);
	textcolor(50);
	cout << "HIEU CHINH DOC GIA";
	int x = 55, y = 13;
	XuatDSDG(dsDG, x, y);
	textcolor(112);
	int maDG = 0;
	TreeNodeDG* temp = NULL;
	do
	{
		VeHCN(x + 35, y - 4, 50, 2);
		gotoXY(x, y - 3);
		cout << "NHAP MA DOC GIA(ESC:De Thoat): ";

		gotoXY(x + 37, y - 3);
		maDG = XuLyNhapSo();
		if (maDG == -1)
		{
			return;
		}

		temp = timMaDG(dsDG.tree, maDG);
		if (temp == NULL)
		{
			GiaoDienThongBao("MA DOC GIA KHONG TON TAI");
			textcolor(112);
			gotoXY(x + 37, y - 3);
			cout << "                                        ";
			XuatDSDG(dsDG, x, y);
		}
	} while (temp == NULL);

	if (dsDG.sl > 15) {
		ToMauHCN(5, 7, 200, y + (2 * dsDG.sl + 3), 112);
	}
	else {
		ToMauHCN(5, 7, 200, 44, 112);
	}

	DocGia dg = temp->data;
	ToMauHCN(5, 7, 200, 44, 112);
	int pointer1 = toadoY;
	GiaoDienThemDocGia(toadoX, toadoY);
	gotoXY(toadoX + 2, toadoY - 2);
	cout << dg.maDG;
	gotoXY(toadoX + 2, toadoY + 1);
	cout << dg.ho;
	gotoXY(toadoX + 2, toadoY + 4);
	cout << dg.ten;
	gotoXY(toadoX + 2, toadoY + 7);
	cout << dg.phai;

	while (true)
	{
		if (pointer1 == toadoY)
		{
			gotoXY(toadoX + 2 + dg.ho.length(), pointer1 + 1);
			XuLyNhapChu(dg.ho, toadoX + 2, pointer1, 30);
			if (pointer1 < toadoY)
			{
				pointer1 = toadoY + 9;
			}
		}
		else if (pointer1 == toadoY + 3)
		{
			gotoXY(toadoX + 2 + dg.ten.length(), pointer1 + 1);
			XuLyNhapChu(dg.ten, toadoX + 2, pointer1, 8);
		}
		else if (pointer1 == toadoY + 6)
		{
			gotoXY(toadoX + 3, pointer1 + 1);
			XuLyNhapSo(dg.phai, toadoX + 2, pointer1);
		}
		else if (pointer1 == toadoY + 9)
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
						if (!dg.ho.empty() && !dg.ten.empty() && (dg.phai == 1 || dg.phai == 2) && pointer2 == toadoX + 15)
						{
							DinhDangChuoi(dg.ho);
							DinhDangChuoi(dg.ten);
							temp->data = dg;
							GiaoDienThongBao("HIEU CHINH THANH CONG");
							return;
						}
						else if (pointer2 == toadoX + 30)
						{
							return;
						}
						else
						{
							gotoXY(90, 30);
							textcolor(112);
							cout << "VUI LONG DIEN DAY DU THONG TIN";
						}
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)
						{
							textcolor(112);
							gotoXY(toadoX + 30, toadoY + 10);
							cout << "HUY";
							gotoXY(toadoX + 15, toadoY + 10);
							cout << "XAC NHAN";
							ShowCur(1);
							pointer1 = pointer1 - 3;
							break;
						}
						else if (c == 80)
						{
							textcolor(112);
							gotoXY(toadoX + 30, toadoY + 10);
							cout << "HUY";
							gotoXY(toadoX + 15, toadoY + 10);
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
					gotoXY(toadoX + 30, toadoY + 10);
					cout << "HUY";
				}
				else if (pointer2 == toadoX + 30)
				{
					cout << "HUY";
					textcolor(112);
					gotoXY(toadoX + 15, toadoY + 10);
					cout << "XAC NHAN";
				}
			}
		}
	}
}

void XuatDSDGBangMang(DocGia a[], int n, int toadoX, int toadoY)
{
	int j = 0;
	textcolor(112);
	for (int i = 0; i < n; i++)
	{
		gotoXY(toadoX + 1, toadoY + 4 + j);
		cout << i + 1;
		gotoXY(toadoX + 7 + 1, toadoY + 4 + j);
		cout << a[i].maDG;
		gotoXY(toadoX + 17 + 1, toadoY + 4 + j);
		cout << a[i].ho + " " + a[i].ten;
		gotoXY(toadoX + 57 + 1, toadoY + 4 + j);
		cout << layGioiTinh(a[i].phai);
		gotoXY(toadoX + 67 + 1, toadoY + 4 + j);
		cout << layTrangThaiDocGia(a[i].trangthai);
		gotoXY(toadoX + 80 + 1, toadoY + 4 + j);
		cout << a[i].soSachDangmuon;

		j = j + 2;
	}
	GiaoDienXuatDSDocGia(toadoX, toadoY, n);
	getch();
}

void XuatDSDGTheoHoTen(DSDocGia& dsDG, int toadoX, int toadoY)
{
	int n = 0;
	DocGia* a = new DocGia[dsDG.sl];
	chuyenCaySangMang(dsDG.tree, a, n);
	sapXepDGTheoHoTenBangMang(a, n);

	ToMauHCN(5, 1, 200, 6, 50);
	gotoXY(90, 4);
	cout << "DANH SACH DOC GIA THEO HO + TEN";
	if (n > 18) {
		VeKhung(5, 1, 200, 7 + (2 * n + 3) + 5, 7);
		ToMauHCN(5, 7, 200, (2 * n + 3) + 6, 112);
	}
	else {
		ToMauHCN(5, 7, 200, 44, 112);
	}

	textcolor(112);
	XuatDSDGBangMang(a, n, toadoX - 20, toadoY);
	delete[]a;

	if (n > 18) {
		ToMauHCN(3, 51, 204, (2 * n + 3) + 6 - 43, 240);
	}
}

void XuatDSDGTheoMaDGTangDan(DSDocGia& dsDG, int toadoX, int toadoY)
{
	int n = 0;

	ToMauHCN(5, 1, 200, 6, 50);
	gotoXY(90, 4);
	cout << "DANH SACH DOC GIA THEO MA DOC GIA";
	if (dsDG.sl > 18) {
		VeKhung(5, 1, 200, 7 + (2 * dsDG.sl + 3) + 5, 7);
		ToMauHCN(5, 7, 200, (2 * dsDG.sl + 3) + 6, 112);
	}
	else {
		ToMauHCN(5, 7, 200, 44, 112);
	}

	textcolor(112);
	XuatDSDG(dsDG.tree, n, toadoX - 20, toadoY);
	GiaoDienXuatDSDocGia(toadoX - 20, toadoY, n);
	getch();

	if (dsDG.sl > 18) {
		ToMauHCN(3, 51, 204, (2 * n + 3) + 6 - 43, 240);
	}
}


void MenuXuatDG(string menuXuatDG[], int toadoX, int toadoY) {
	textcolor(112);
	GiaoDienMenu(toadoX, toadoY, 3, menuXuatDG, 6);
}

void RunXuatDSDG(string menuXuatDG[], DSDocGia dsDg, int toadoX, int toadoY, int& pointer1, bool& kt) {
	if (kbhit())
	{
		char c = getch();
		if (c == -32)
		{
			c = getch();
			if (c == 72)
			{
				MenuXuatDG(menuXuatDG, toadoX, toadoY);
				if (pointer1 == 13)
				{
					pointer1 = 15;
				}
				else
				{
					pointer1--;
				}
			}
			else if (c == 80) //xuong
			{
				MenuXuatDG(menuXuatDG, toadoX, toadoY);
				if (pointer1 == 15)
				{
					pointer1 = 13;
				}
				else
				{
					pointer1++;
				}
			}
		}
		else if (c == 13)
		{
			switch (pointer1) {
			case 13: {
				XuatDSDGTheoHoTen(dsDg, 85, 10);
				break;
			}
			case 14: {
				XuatDSDGTheoMaDGTangDan(dsDg, 85, 10);
				break;
			}
			case 15: {
				kt = false;
				break;
			}
			}
			if (pointer1 != 16) {
				VeKhung(5, 1, 200, 50, 7);
				ToMauHCN(5, 1, 200, 6, 50);
				gotoXY(95, 4);
				cout << "XUAT DANH SACH DOC GIA";
				ToMauHCN(5, 7, 200, 44, 112);
				MenuXuatDG(menuXuatDG, toadoX, toadoY);
			}
		}
		ToMauHCN(toadoX, 13 + (pointer1 - 13) * 8, 50, 6, 50);
		gotoXY(toadoX + (50 - menuXuatDG[pointer1 - 13].length()) / 2, 16 + (pointer1 - 13) * 8);
		cout << menuXuatDG[pointer1 - 13];
	}
}

void InDanhSachDocGia(DSDocGia dsDg, int toadoX, int toadoY) {
	string menuXuatDG[] = {
		"XUAT DANH SACH DOC GIA THEO TEN",
		"XUAT DANH SACH DOC GIA THEO MA DOC GIA",
		"THOAT"
	};
	int pointer1 = toadoY;
	bool kt = true;
	ToMauHCN(5, 1, 200, 6, 50);
	gotoXY(95, 4);
	cout << "XUAT DANH SACH DOC GIA";
	ToMauHCN(5, 7, 200, 44, 112);
	MenuXuatDG(menuXuatDG, toadoX, toadoY);
	ToMauHCN(toadoX, toadoY, 50, 6, 50);
	gotoXY(toadoX + (50 - menuXuatDG[0].length()) / 2, toadoY + 3);
	textcolor(50);
	cout << menuXuatDG[0];

	while (kt) {
		RunXuatDSDG(menuXuatDG, dsDg, toadoX, toadoY, pointer1, kt);
	}
}