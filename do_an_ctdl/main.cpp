#include<iostream>
#include "ctdl.h"
#include "dohoa.h"
#include "chuanhoa.h"
#include "thuattoan.h"
#include "menuchinh.h"
#include "xulinhap.h"
#include "quanlisach.h"

using namespace std;

int main()
{
	DSDauSach dsds;

	DSDocGia dsdg;

	khoiTaoDanhSach(dsds, dsdg);

	while (true)
	{
		RunQuanLiThuVien(dsdg, dsds);
	}

	getch();
}
