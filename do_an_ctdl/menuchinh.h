#pragma once
#include "quanlidocgia.h"
#include "quanlimuontra.h"
#include "quanlisach.h"


string stringChucNangChinh[] = {
	"QUAN LI SACH",
	"QUAN LI DOC GIA",
	"MUON TRA SACH",
	"THOAT"
};
string stringChucNangSach[] = {
	"THEM DAU SACH",
	"TIM THONG TIN SACH",
	"XOA SACH",
	"XUAT DANH SACH",
	"THOAT"
};
string stringChucNangDocGia[] = {
	"THEM DOC GIA",
	"XOA DOC GIA",
	"CHINH SUA DOC GIA",
	"IN DANH SACH DOC GIA",
	"THOAT"
};
string stringChucNangMuonTra[] = {
	"MUON SACH",
	"TRA SACH",
	"LIET KE SACH DOC GIA DANG MUON",
	"THOAT"
};

int length = 4;

void Menu()
{
	textcolor(240);
	int j = 13;
	for (int i = 0; i < length; i++)
	{
		ToMauHCN(80, j, 50, 6, 250);
		gotoXY(80 + (50 - stringChucNangChinh[i].length()) / 2, j + 3);
		cout << stringChucNangChinh[i];
		j = j + 9;
	}
}


void MenuDauSach() {
	textcolor(240);
	int j = 13;
	for (int i = 0; i < 5; i++)
	{
		ToMauHCN(80, j, 50, 6, 250);
		gotoXY(80 + (50 - stringChucNangSach[i].length()) / 2, j + 3);
		cout << stringChucNangSach[i];
		j = j + 7;
	}
}

void MenuDocGia() {
	textcolor(240);
	int j = 13;
	for (int i = 0; i < 5; i++) {
		ToMauHCN(80, j, 50, 6, 250);
		gotoXY(80 + (50 - stringChucNangDocGia[i].length()) / 2, j + 3);
		cout << stringChucNangDocGia[i];
		j = j + 7;
	}
}

void MenuMuonTra()
{
	textcolor(240);
	int j = 13;
	for (int i = 0; i < 4; i++)
	{
		ToMauHCN(80, j, 50, 6, 250);
		gotoXY(80 + (50 - stringChucNangMuonTra[i].length()) / 2, j + 3);
		cout << stringChucNangMuonTra[i];
		j = j + 9;
	}
}

void QuanLiDauSach(DSDocGia& dsDG, DSDauSach& dsDS, int& pointer1, bool& kt)
{
	if (kbhit())
	{
		//xử lí in menu và các thao tác
		char c = getch();
		if (c == -32)
		{
			c = getch();
			if (c == 72)
			{
				if (pointer1 == 13)
				{
					MenuDauSach();
					pointer1 = 13 - 1 + 5;
				}
				else
				{
					MenuDauSach();
					pointer1--;
				}
			}
			else if (c == 80)
			{
				if (pointer1 == 13 - 1 + 5)
				{
					MenuDauSach();
					pointer1 = 13;
				}
				else
				{
					MenuDauSach();
					pointer1++;
				}
			}
		}
		else if (c == 13)
		{
			switch (pointer1)
			{
				//thêm dầu sách
			case 13: {
				NhapDauSach(dsDS, 95, 17);
				ghiFileDSVaDanhMucSach(dsDS);
				break;
			}
			case 14: {
				TimThongTinSachDuaVaoTenSach(dsDS, 40, 13);
				break;
			}

			case 15: {
				if (dsDS.sl > 0) {
					XoaSach(dsDS, 55, 13);
					ghiFileDSVaDanhMucSach(dsDS);
				}
				else {
					ToMauHCN(5, 7, 200, 44, 112);
					GiaoDienThongBao("THU VIEN CHUA CO SACH");
				}
				break;
			}
			case 16: 
			{
				if (dsDS.sl > 0)
					MenuXuatDSDS(dsDS, 80, 13);
				else 
				{
					ToMauHCN(5, 7, 200, 44, 112);
					GiaoDienThongBao("THU VIEN CHUA CO SACH");
				}
				break;
			}
			case 17: {
				kt = false;
				break;
			}
			}
			if (pointer1 != 17) {
				GiaoDienMain();
				MenuDauSach();
			}
		}

		ToMauHCN(80, 13 + (pointer1 - 13) * 7, 50, 6, 180);
		gotoXY(80 + (50 - stringChucNangSach[pointer1 - 13].length()) / 2, 16 + (pointer1 - 13) * 7);
		textcolor(180);
		cout << stringChucNangSach[pointer1 - 13];
	}
}
void QuanLiDocGia(DSDocGia& dsDG, DSDauSach& dsDS, int& pointer1, bool& kt) {
	if (kbhit()) {
		char c = getch();
		//in menu và thao tác với menu
		if (c == -32) {
			c = getch();
			if (c == 72) {
				if (pointer1 == 13) {
					MenuDocGia();
					pointer1 = 13 - 1 + 5;
				}
				else
				{
					MenuDocGia();
					pointer1--;
				}
			}
			else if (c == 80) {
				if (pointer1 == 13 - 1 + 5) {
					MenuDocGia();
					pointer1 = 13;
				}
				else
				{
					MenuDocGia();
					pointer1++;
				}
			}
		}
		//khi nhấn enter
		else if (c == 13) {

			switch (pointer1) {
			case 13://Them Doc Gia
			{
				NhapDocGia(dsDG, 85, 17);
				ghiFileDGVaMT(dsDG);
				break;
			}
			case 14://Xoa Doc Gia
			{
				XoaDocGia(dsDG, 55, 13);
				if (dsDG.sl > 15) {
					ToMauHCN(3, 51, 204, 13 + (2 * dsDG.sl + 3) - 43, 240);
				}
				ghiFileDGVaMT(dsDG);
				break;
			}
			case 15://Hieu Chinh Doc Gia
			{
				SuaDocGia(dsDG, 85, 17);
				if (dsDG.sl > 15) {
					ToMauHCN(3, 51, 204, 13 + (2 * dsDG.sl + 3) - 43, 240);
				}
				ghiFileDGVaMT(dsDG);
				break;
			}
			case 16://In Danh Sach Doc Gia
			{
				if (dsDG.sl > 0)
					InDanhSachDocGia(dsDG, 80, 13);
				else {
					ToMauHCN(5, 7, 200, 44, 112);
					GiaoDienThongBao("DANH SACH DOC GIA TRONG");
				}
				break;
			}
			case 17:
			{
				kt = false;
				break;
			}
			}
			if (pointer1 != 17) {
				GiaoDienMain();
				MenuDocGia();
			}
		}
		ToMauHCN(80, 13 + (pointer1 - 13) * 7, 50, 6, 180);
		gotoXY(80 + (50 - stringChucNangDocGia[pointer1 - 13].length()) / 2, 16 + (pointer1 - 13) * 7);
		textcolor(180);
		cout << stringChucNangDocGia[pointer1 - 13];
	}
}
void QuanLiMuonTra(DSDocGia& dsDG, DSDauSach& dsDS, int& pointer1, bool& kt)
{
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
					MenuMuonTra();
					pointer1 = 13 - 1 + 4;
				}
				else
				{
					MenuMuonTra();
					pointer1--;
				}
			}
			else if (c == 80)
			{
				if (pointer1 == 13 - 1 + 4)
				{
					MenuMuonTra();
					pointer1 = 13;
				}
				else
				{
					MenuMuonTra();
					pointer1++;
				}
			}
		}
		else if (c == 13)
		{
			switch (pointer1)
			{
			case 13: {//Muon Sach
				MuonSach(dsDG, dsDS, 55, 17);
				ghiFileDGVaMT(dsDG);
				ghiFileDSVaDanhMucSach(dsDS);

				break;
			}
			case 14: {//Tra Sach
				TraSach(dsDG, dsDS, 55, 17);
				ghiFileDGVaMT(dsDG);
				ghiFileDSVaDanhMucSach(dsDS);
				break;
			}
			case 15: {//Liet Ke Cac Sach Doc Gia Dang Muon
				lietKeCacSachDGDangMuon(dsDG, 55, 13);
				break;
			}
			case 16: {
				kt = false;
				break;
			}
			}
			if (pointer1 != 16) {
				GiaoDienMain();
				MenuMuonTra();
			}
		}

		// to mau 
		ToMauHCN(80, 13 + (pointer1 - 13) * 9, 50, 6, 180);//180//7
		gotoXY(80 + (50 - stringChucNangMuonTra[pointer1 - 13].length()) / 2, 16 + (pointer1 - 13) * 9);
		textcolor(180);//180
		cout << stringChucNangMuonTra[pointer1 - 13];
	}
}
//
void RunQuanLiThuVien(DSDocGia& dsDG, DSDauSach& dsDS)
{
	if (kbhit())
	{
		char c = getch();
		//Thoa tác in menu
		if (c == -32)
		{
			c = getch();
			if (c == 72)
			{
				if (pointer == 13)
				{
					Menu();
					pointer = 13 - 1 + length;
				}
				else
				{
					Menu();
					pointer--;
				}
			}
			else if (c == 80)
			{
				if (pointer == 13 - 1 + length)
				{
					Menu();
					pointer = 13;
				}
				else
				{
					Menu();
					pointer++;
				}
			}
		}
		//khi nhân enter chọn chức năng
		else if (c == 13)
		{
			ToMauHCN(5, 7, 200, 44, 114);
			switch (pointer)
			{
				//thuong
			case 13: {
				int pointer1 = 13;
				bool kt = true;

				MenuDauSach();// in ra menu chức năng
				ToMauHCN(80, 13 + (pointer1 - 13) * 9, 50, 6, 180);
				gotoXY(80 + (50 - stringChucNangSach[0].length()) / 2, 16 + (pointer1 - 13) * 9);
				textcolor(180);
				cout << stringChucNangSach[0];

				while (kt) {
					QuanLiDauSach(dsDG, dsDS, pointer1, kt);
				}
				break;
			}
			case 14: {
				int pointer1 = 13;
				bool kt = true;

				MenuDocGia();
				ToMauHCN(80, 13 + (pointer1 - 13) * 7, 50, 6, 180);
				gotoXY(80 + (50 - stringChucNangDocGia[0].length()) / 2, 16 + (pointer1 - 13) * 7);
				textcolor(180);
				cout << stringChucNangDocGia[0];

				while (kt) {
					QuanLiDocGia(dsDG, dsDS, pointer1, kt);// truyền vào danh sách đoc giả và danh sách đâu sách
				}
				break;
			}
			case 15: {
				int pointer1 = 13;
				bool kt = true;

				MenuMuonTra();
				ToMauHCN(80, 13 + (pointer1 - 13) * 9, 50, 6, 180);//180
				gotoXY(80 + (50 - stringChucNangMuonTra[0].length()) / 2, 16 + (pointer1 - 13) * 9);
				textcolor(180);
				cout << stringChucNangMuonTra[0];

				while (kt) {
					QuanLiMuonTra(dsDG, dsDS, pointer1, kt);
				}
				break;
			}
			case 16: 
			{
				xoaDSDSach(dsDS);//giai phong tat ca bo nho
				xoaDSDocGia(dsDG);
				exit(0);
			}
			}
			GiaoDienMain();
			Menu();
		}

		// to mau 
		ToMauHCN(80, 13 + (pointer - 13) * 9, 50, 6, 180);
		gotoXY(80 + (50 - stringChucNangChinh[pointer - 13].length()) / 2, 16 + (pointer - 13) * 9);
		textcolor(180);
		cout << stringChucNangChinh[pointer - 13];
	}
}

void khoiTaoDanhSach(DSDauSach& dsDS, DSDocGia& dsDG)
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	system("color F0");

	loadFileDSVaDanhMucSach(dsDS);

	loadFileDGVaMT(dsDG, dsDS);

	GiaoDienMain();
	Menu();

	ShowCur(0);

	ToMauHCN(80, 13 + (pointer - 13) * 9, 50, 6, 50);
	gotoXY(80 + (50 - stringChucNangChinh[0].length()) / 2, 16 + (pointer - 13) * 9);
	textcolor(50);
	cout << stringChucNangChinh[0];
}


