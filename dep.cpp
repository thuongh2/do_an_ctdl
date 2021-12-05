void TimThongTinSachDuaVaoTenSach(DSDauSach dsDs, int toadoX, int toadoY) {

	string tenSach;
	DSDauSach dsDSTemp;
	do
	{
		tenSach = XuLyNhapChu();// nhap ten sach can tim
		if (!tenSach.empty())
			DinhDangChuoi(tenSach);
		if (tenSach.empty())
		{
			return;
		}

		dsDSTemp = timTenSach(dsDs, tenSach);//tìm sách
		if (dsDSTemp.sl <= 0)
		{
			GiaoDienThongBao("TEN SACH KHONG TON TAI");
		}
	} while (dsDSTemp.sl <= 0);

	bool kt = true;
	
	GiaoDienMaDauSach(dsDSTemp, toadoX, toadoY);//đi đến giao 
	
	cout << dsDSTemp.data[0]->MSSach;

	while (kt) {
		RunMenuMaDauSach(dsDSTemp, toadoX, toadoY + 4, pointer1, kt);
	}
}
