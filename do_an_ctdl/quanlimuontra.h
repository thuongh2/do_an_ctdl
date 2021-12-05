#pragma once
#include "ctdl.h"
#include "dohoa.h"
#include "chuanhoa.h"
#include "thuattoan.h"
#include "menuchinh.h"
#include "xulinhap.h"
#include "quanlisach.h"
#include "quanlidocgia.h"

void XuatDSSachDangMuon(TreeNodeDG* TreeNodeDG, int toadoX, int toadoY) {
	int j = 0;
	textcolor(112);
	for (NodeMuonTra* k = TreeNodeDG->data.mt.phead; k != NULL; k = k->pNext) {
		if (k->data.trangthai == 0) {
			gotoXY(toadoX + 1, toadoY + 4 + j);
			cout << k->data.masach;
			gotoXY(toadoX + 16 + 1, toadoY + 4 + j);
			cout << k->data.ngaymuon.ngay << "/" << k->data.ngaymuon.thang << "/" << k->data.ngaymuon.nam;
			gotoXY(toadoX + 27 + 1, toadoY + 4 + j);
			cout << TrangThaiMuonTra(k->data.trangthai);
			j = j + 2;
		}
	}
	GiaoDienXuatDanhSachMuon(toadoX, toadoY, TreeNodeDG->data.soSachDangmuon);
}
void xuatGiaoDienMuonSach(DSDauSach dsDs, TreeNodeDG* TreeNodeDG, int toadoX, int toadoY) {
	if (dsDs.sl > 18) {
		VeKhung(5, 1, 200, 10 + (2 * dsDs.sl + 3) + 3, 7);
		ToMauHCN(5, 7, 200, 4 + (2 * dsDs.sl + 3) + 3, 112);
	}
	else {
		ToMauHCN(5, 7, 200, 44, 112);
	}

	if (TreeNodeDG->data.soSachDangmuon > 0)
	{
		gotoXY(toadoX - 15, toadoY - 8);
		textcolor(50);
		cout << "DANH SACH SACH DOC GIA DANG MUON";
		XuatDSSachDangMuon(TreeNodeDG, toadoX - 18, toadoY - 7);
	}

	gotoXY(toadoX + 80, toadoY - 8);
	textcolor(50);
	cout << "DANH SACH CAC DAU SACH";
	xuLiXuatDSDS(dsDs, toadoX + 25, toadoY - 7);
}
void nhapMaDauSach(DSDauSach dsDs, DauSach*& nodeDauSach, NodeSach*& nodeSach, TreeNodeDG* TreeNodeDG, int toadoX, int toadoY, bool& kt1) {
	int k = toadoY - 7 + 3 + TreeNodeDG->data.soSachDangmuon * 2;
	string maDauSach;
	do
	{
		if (nodeDauSach == NULL || dieuKienMuonSach(TreeNodeDG, nodeDauSach) == false || nodeSach == NULL) {
			gotoXY(100, k + 2);
			ToMauHCN(toadoX - 18, k + 10, 40, 10, 112);
			textcolor(112);
		}

		gotoXY(toadoX - 48, k + 2);
		cout << "NHAP MA DAU SACH(ESC:De Thoat): ";

		maDauSach = XuLyNhapMa(10);
		if (maDauSach.empty())
		{
			kt1 = false;
			return;
		}

		nodeDauSach = timDauSach(dsDs, maDauSach);
		if (nodeDauSach == NULL)
		{
			GiaoDienTam(toadoX - 18, k + 10, 95, 7, "MA DAU SACH KHONG TON TAI");
			textcolor(112);
			gotoXY(toadoX - 48, k + 2);
			cout << "                                                              ";
		}
		else if (dieuKienMuonSach(TreeNodeDG, nodeDauSach) == false)
		{
			GiaoDienTam(toadoX - 18, k + 10, 95, 7, "BAN KHONG THE MUON SACH NAY");
			textcolor(112);
			gotoXY(toadoX - 48, k + 2);
			cout << "                                                                 ";
		}
		else if (nodeDauSach != NULL)
		{
			nodeSach = laySachMuon(nodeDauSach);
			if (nodeSach == NULL) {
				GiaoDienTam(toadoX - 18, k + 10, 95, 7, "SACH NAY DA HET");
				textcolor(112);
				gotoXY(toadoX - 48, k + 2);
				cout << "                                                                 ";
			}
		}
	} while (nodeDauSach == NULL || dieuKienMuonSach(TreeNodeDG, nodeDauSach) == false || nodeSach == NULL);
}
void RunNhapMaDauSach(DSDauSach& dsDs, DSDocGia& dsDG, TreeNodeDG* TreeNodeDG, int toadoX, int toadoY) {
	if (dsDG.sl > 15) {
		ToMauHCN(5, 7, 200, 13 + (2 * dsDG.sl + 3), 112);
	}
	else {
		ToMauHCN(5, 7, 200, 44, 112);
	}
	XuatThongTinDG(TreeNodeDG->data, 55, 17);
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

	if (TreeNodeDG->data.trangthai == 0)
	{
		GiaoDienTam(toadoX + 23, 29, 95, 7, "THE DA BI KHOA");
		ToMauHCN(5, 7, 200, 44, 112);
		return;
	}
	if (TreeNodeDG->data.soSachDangmuon >= 3)
	{
		GiaoDienThongBao("MOI DOC GIA CHI DUOC MUON TOI DA 3 QUYEN");
		ToMauHCN(5, 7, 200, 44, 112);
		return;
	}

	DauSach* nodeDauSach = NULL;
	NodeSach* nodeSach = NULL;
	bool kt1 = true;
	while (kt1) {
		xuatGiaoDienMuonSach(dsDs, TreeNodeDG, toadoX, toadoY);
		if (TreeNodeDG->data.soSachDangmuon >= 3)
		{
			GiaoDienThongBao("MOI DOC GIA CHI DUOC MUON TOI DA 3 QUYEN");
			ToMauHCN(5, 7, 200, 44, 112);
			return;
		}
		nhapMaDauSach(dsDs, nodeDauSach, nodeSach, TreeNodeDG, toadoX, toadoY, kt1);
		if (nodeDauSach != NULL && nodeSach != NULL && kt1 != false) {
			xuLiMuonSach(TreeNodeDG, nodeDauSach, nodeSach);
			GiaoDienThongBao("MUON SACH THANH CONG");
		}
	}
}
void MuonSach(DSDocGia& dsDG, DSDauSach& dsDs, int toadoX, int toadoY) {
	ToMauHCN(5, 1, 200, 6, 50);
	gotoXY(97, 4);
	cout << "MUON SACH";
	ToMauHCN(5, 7, 200, 44, 112);

	int x = 55, y = 13;

	TreeNodeDG* TreeNodeDG = NULL;
	textcolor(112);
	int maDG = 0;

	do
	{
		XuatDSDG(dsDG, x, y);
		VeHCN(x + 35, y - 4, 50, 2);
		gotoXY(x, y - 3);
		cout << "NHAP MA DOC GIA(ESC:De Thoat): ";

		gotoXY(x + 37, y - 3);
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
			gotoXY(x + 37, y - 3);
			cout << "                                        ";
		}
		else
		{
			RunNhapMaDauSach(dsDs, dsDG, TreeNodeDG, toadoX, toadoY);
			if (dsDG.sl > 15) {
				ToMauHCN(5, 7, 200, y + (2 * dsDG.sl + 3), 112);
			}
			else {
				ToMauHCN(5, 7, 200, 44, 112);
			}

			if (dsDs.sl > 18) {
				ToMauHCN(5, 7, 200, 4 + (2 * dsDs.sl + 3) + 3, 112);
				ToMauHCN(3, 51, 204, 4 + (2 * dsDs.sl + 3) + 3 - 43, 240);
			}
			else if (dsDG.sl > 15) {
				ToMauHCN(3, 51, 204, 13 + (2 * dsDG.sl + 3) - 43, 240);
			}
			textcolor(112);
			TreeNodeDG = NULL;
			maDG = 0;
		}
	} while (TreeNodeDG == NULL);
}

void menuMaSachDangMuon(TreeNodeDG* t, string layDSMaSachMuon[], int n, int toadoX, int toadoY) {
	int j = 0;
	textcolor(112);
	for (int i = 0; i < n; i++) {
		ToMauHCN(toadoX, toadoY + j - 1, 15, 2, 112);
		gotoXY(toadoX + 1, toadoY + j);
		cout << layDSMaSachMuon[i];
		j += 2;
	}
}
void RunMenuTraSach(TreeNodeDG* t, string* layDSMaSachMuon, int n, int toadoX, int toadoY, int& pointer1, int& vt, bool& kt) {
	if (kbhit())
	{
		char c = getch();
		if (c == -32)
		{
			c = getch();
			if (c == 72)
			{
				if (pointer1 == 23)
				{
					menuMaSachDangMuon(t, layDSMaSachMuon, n, toadoX, toadoY);
					pointer1 = 23 + (n - 1) * 2;
				}
				else
				{
					menuMaSachDangMuon(t, layDSMaSachMuon, n, toadoX, toadoY);
					pointer1 -= 2;
				}
			}
			else if (c == 80)
			{
				if (pointer1 == 23 + (n - 1) * 2)
				{
					menuMaSachDangMuon(t, layDSMaSachMuon, n, toadoX, toadoY);
					pointer1 = 23;
				}
				else
				{
					menuMaSachDangMuon(t, layDSMaSachMuon, n, toadoX, toadoY);
					pointer1 += 2;
				}
			}
		}
		else if (c == 13)
		{
			for (int i = 0; i < n; i++) {
				if (pointer1 - 23 - i * 2 == 0) {
					vt = i;
					kt = false;
					break;
				}
			}
		}
		else if (c == 27) {
			vt = -1;
			kt = false;
			return;
		}

		ToMauHCN(toadoX, pointer1 - 1, 15, 2, 50);
		gotoXY(toadoX + 1, pointer1);
		textcolor(50);
		cout << layDSMaSachMuon[(pointer1 - 23) / 2];
	}
}
void XuatGiaoDienTraSach(DSDauSach& dsDs, TreeNodeDG* TreeNodeDG, int toadoX, int toadoY, bool& kt1) {
	string* layDSMaSachMuon = new string[3];
	int n = 0;
	for (NodeMuonTra* k = TreeNodeDG->data.mt.phead; k != NULL; k = k->pNext) {
		if (k->data.trangthai == 0)
			layDSMaSachMuon[n++] = k->data.masach;
	}
	ToMauHCN(5, 7, 200, 44, 112);

	GiaoDienXuatDSDocGia(toadoX, toadoY - 7, 1);
	textcolor(112);
	gotoXY(toadoX, toadoY - 6 - 2);
	cout << "THONG TIN DOC GIA";
	gotoXY(toadoX + 1, toadoY - 6 + 3);
	cout << "1";
	gotoXY(toadoX + 7 + 1, toadoY - 6 + 3);
	cout << TreeNodeDG->data.maDG;
	gotoXY(toadoX + 17 + 1, toadoY - 6 + 3);
	cout << TreeNodeDG->data.ho + " " + TreeNodeDG->data.ten;
	gotoXY(toadoX + 57 + 1, toadoY - 6 + 3);
	cout << layGioiTinh(TreeNodeDG->data.phai);
	gotoXY(toadoX + 67 + 1, toadoY - 6 + 3);
	cout << layTrangThaiDocGia(TreeNodeDG->data.trangthai);
	gotoXY(toadoX + 80 + 1, toadoY - 6 + 3);
	cout << TreeNodeDG->data.soSachDangmuon;

	if (TreeNodeDG->data.soSachDangmuon > 0)
	{
		gotoXY(toadoX + 30, toadoY);
		textcolor(50);
		cout << "DANH SACH SACH DOC GIA DANG MUON";
		XuatDSSachDangMuon(TreeNodeDG, toadoX + 25, toadoY + 2);
		textcolor(112);
		gotoXY(toadoX + 25, toadoY + 2 + TreeNodeDG->data.soSachDangmuon * 2 + 5);
		cout << "Nhan: ENTER De Tra Sach";
		gotoXY(toadoX + 25, toadoY + 2 + TreeNodeDG->data.soSachDangmuon * 2 + 6);
		cout << "Nhan: ESC De Thoat";
	}

	int y = toadoY + 5 + 2 * TreeNodeDG->data.soSachDangmuon;
	string maSach;

	menuMaSachDangMuon(TreeNodeDG, layDSMaSachMuon, n, toadoX + 25, 23);
	ToMauHCN(toadoX + 25, 22, 15, 2, 50);
	gotoXY(toadoX + 26, 23);
	cout << layDSMaSachMuon[0];

	textcolor(112);
	bool kt = true;
	int pointer1 = 23;
	int vt = 0;
	while (kt) {
		RunMenuTraSach(TreeNodeDG, layDSMaSachMuon, n, toadoX + 25, 23, pointer1, vt, kt);
	}
	if (vt != -1)
	{
		xuliTraSach(dsDs, TreeNodeDG, layDSMaSachMuon, vt);
		GiaoDienThongBao("TRA SACH THANH CONG");
	}
	else
		kt1 = false;
	delete[] layDSMaSachMuon;
}
void TraSach(DSDocGia& dsDG, DSDauSach& dsDs, int toadoX, int toadoY)
{
	ToMauHCN(5, 1, 200, 6, 50);
	gotoXY(97, 4);
	cout << "TRA SACH";

	int maDG = 0;
	TreeNodeDG* TreeNodeDG = NULL;
	do
	{
		ToMauHCN(5, 7, 200, 44, 112);
		gotoXY(toadoX - 48, toadoY);
		cout << "NHAP MA DOC GIA ( ESC:De Thoat ): ";
		maDG = XuLyNhapSo();
		if (maDG == -1)
		{
			return;
		}

		TreeNodeDG = timMaDG(dsDG.tree, maDG);
		if (TreeNodeDG == NULL)
		{
			GiaoDienThongBao("MA DOC GIA KHONG TON TAI");
			ToMauHCN(5, 7, 200, 44, 112);
		}
		else
		{
			bool kt1 = true;
			while (kt1) {
				if (TreeNodeDG->data.soSachDangmuon == 0)
				{
					GiaoDienThongBao("DOC GIA KHONG CO SACH DANG MUON");
					kt1 = false;
				}
				else
				{
					XuatGiaoDienTraSach(dsDs, TreeNodeDG, toadoX, toadoY, kt1);
				}
			}
			textcolor(112);
			TreeNodeDG = NULL;
			maDG = 0;
		}
	} while (TreeNodeDG == NULL);
}

void lietKeCacSachDGDangMuon(DSDocGia dsDG, int toadoX, int toadoY) {
	ToMauHCN(5, 1, 200, 6, 50);
	gotoXY(90, 4);
	cout << "LIET KE SACH DOC GIA DANG MUON";
	ToMauHCN(5, 7, 200, 44, 112);

	int maDG = 0;
	TreeNodeDG* TreeNodeDG = NULL;
	do
	{
		gotoXY(toadoX - 48, toadoY);
		cout << "NHAP MA DOC GIA( ESC:De Thoat ): ";
		maDG = XuLyNhapSo();
		if (maDG == -1)
		{
			return;
		}

		TreeNodeDG = timMaDG(dsDG.tree, maDG);
		if (TreeNodeDG == NULL)
		{
			GiaoDienThongBao("MA DOC GIA KHONG TON TAI");
			ToMauHCN(5, 7, 200, 44, 112);
		}
	} while (TreeNodeDG == NULL);

	ToMauHCN(5, 7, 200, 44, 112);
	//XuatThongTinDG(TreeNodeDG->data, toadoX +10, toadoY);
	GiaoDienXuatDSDocGia(toadoX + 10, toadoY, 1);
	textcolor(112);
	gotoXY(toadoX + 10, toadoY - 2);
	cout << "THONG TIN DOC GIA";

	gotoXY(toadoX + 11, toadoY + 4);
	cout << "1";
	gotoXY(toadoX + 7 + 11, toadoY + 4);
	cout << TreeNodeDG->data.maDG;
	gotoXY(toadoX + 17 + 11, toadoY + 4);
	cout << TreeNodeDG->data.ho + " " + TreeNodeDG->data.ten;
	gotoXY(toadoX + 57 + 11, toadoY + 4);
	cout << layGioiTinh(TreeNodeDG->data.phai);
	gotoXY(toadoX + 67 + 11, toadoY + 4);
	cout << layTrangThaiDocGia(TreeNodeDG->data.trangthai);
	gotoXY(toadoX + 80 + 11, toadoY + 4);
	cout << TreeNodeDG->data.soSachDangmuon;

	if (TreeNodeDG->data.soSachDangmuon > 0)
	{
		gotoXY(toadoX + 10, toadoY + 8);
		textcolor(50);
		cout << "DANH SACH SACH DOC GIA DANG MUON";
		XuatDSSachDangMuon(TreeNodeDG, toadoX + 10, toadoY + 10);
	}
	else
	{
		GiaoDienThongBao("DOC GIA KHONG CO SACH DANG MUON");
		return;
	}
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
}

void XuLiXoaSach(DauSach*& ds, int toadoX, int toadoY, bool& kt1) {
	string masach = "";
	NodeSach* nodeSach = NULL;
	do
	{
		if (ds->dms.sl <= 0)//không có sách nào thì return
		{
			kt1 = false;
			return;
		}
		XuatThongTinSach(ds, toadoX - 7, toadoY); // xuất thông tin sách để lựa chọn
		textcolor(112);
		gotoXY(toadoX - 7, 10);
		cout << "Nhap Ma Sach Can Xoa (Nhan ESC: De Thoat) : ";
		gotoXY(92, 10);
		masach = XuLyNhapMa(15);// nhập mã sách
		if (masach.empty())
		{
			kt1 = false;
			return;
		}
		else
			nodeSach = laySachXoa(ds, masach);
		if (nodeSach == NULL)
		{
			GiaoDienTam(85, toadoY, 95, 7, "MA SACH KHONG TON TAI");
			textcolor(112);
			gotoXY(92, 10);
			cout << "                                ";
		}
		else if (nodeSach != NULL && nodeSach->data.trangthai != 0)
		{
			GiaoDienTam(85, toadoY, 95, 7, "BAN KHONG THE XOA SACH NAY");
			textcolor(112);
			gotoXY(92, 10);
			cout << "                                ";
		}
		else if (nodeSach != NULL && nodeSach->data.trangthai == 0)
		{
			string s = "Ban Co Chac Chan Xoa " + nodeSach->data.masach + " ?";
			char c;
			while (1) {
				if (kbhit()) {
					GiaoDienThongBao(s);
					c = getch();
					if (c == 27) {//esc
						return;
					}
					else if (c == 13) {
						Xoa1Sach(ds->dms, masach);
						ds->dms.sl--;
						GiaoDienThongBao("XOA SACH THANH CONG");
						return;
					}
				}
			}
		}
	} while (nodeSach == NULL);
}
void RunMenuXoaSach(DSDauSach& dsDs, int toadoX, int toadoY, int& pointer1, bool& kt) {
	if (kbhit())
	{
		char c = getch();
		if (c == -32)
		{
			c = getch();
			if (c == 72)
			{
				if (pointer1 == toadoY)
				{
					menuMaDauSach(dsDs, toadoX, toadoY);
					pointer1 = toadoY + (dsDs.sl - 1) * 2;
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
				if (pointer1 - toadoY - i * 2 == 0) {
					bool kt1 = true;
					while (kt1) {
						if (dsDs.data[i]->dms.sl <= 0)
						{
							delete dsDs.data[i];
							dsDs.sl--;
							GiaoDienThongBao("DAU SACH RONG");
							kt = false;
							return;
						}
						else
							XuLiXoaSach(dsDs.data[i], toadoX, toadoY, kt1);
					}
					if (dsDs.data[i]->dms.sl > 0) {
						if (dsDs.data[i]->dms.sl > 12)
						{
							ToMauHCN(5, 7, 200, (dsDs.data[i]->dms.sl * 2 + 3) + 16, 112);
							ToMauHCN(3, 51, 204, (dsDs.data[i]->dms.sl * 2 + 3) + 16 - 43, 240);
						}
						else
						{
							ToMauHCN(5, 7, 200, 44, 112);
						}
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
void XoaSach(DSDauSach& Dsds, int toadoX, int toadoY) {
	int pointer1 = toadoY + 4;
	bool kt = true;
	ToMauHCN(5, 7, 200, 44, 112);
	GiaoDienMaDauSach(Dsds, toadoX, toadoY);// in ra các đầu sách để lựa chọn
	ToMauHCN(toadoX + 7, toadoY + 3, 10, 2, 50);
	gotoXY(toadoX + 7, toadoY + 4);
	cout << Dsds.data[0]->MSSach;
	textcolor(112);

	while (kt) {
		RunMenuXoaSach(Dsds, toadoX, toadoY + 4, pointer1, kt);
	}
}
