#pragma once

//Thu vien co sang
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}

//ke khung (truyen vao toa do x,y chieu dai chieu cao cua hinh chu nhat)
void VeHCN(int toadoX, int toadoY, int chieudai, int chieucao)
{
	textcolor(112);
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}
}


void VeKhung(int toadoX, int toadoY, int chieudai, int chieucao,int gachngang)
{
	textcolor(250);
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)201;
		else if (i == chieudai + toadoX)
			cout << (char)187;
		else
			cout << (char)205;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)200;
		else if (i == chieudai + toadoX)
			cout << (char)188;
		else
			cout << (char)205;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)186;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)186;
	}
	int j = gachngang;
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, j);
		if (i == toadoX)
			cout << (char)204;
		else if (i == chieudai + toadoX)
			cout << (char)185;
		else
			cout << (char)205;
	}
}

void ToMauHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mauText)
{
	textcolor(mauText);
	for (int i = toadoY + 1; i < toadoY + chieucao; i++)
	{
		for (int j = toadoX + 1; j < chieudai + toadoX; j++)
		{
			gotoXY(j, i);
			cout << " ";
		}
	}
}

void Logo(int toadoX, int toadoY)
{
	string str;
	ifstream FileIn;
	FileIn.open("TieuDeQLTV.txt", ios::in);
	int h = toadoY;
	textcolor(250);
	while (true)
	{
		getline(FileIn, str);
		gotoXY(toadoX, h++);
		cout << str << endl;
		if (FileIn.eof())
		{
			break;
		}
	}
	FileIn.close();
}



void GiaoDienMain()
{
	VeKhung(5, 1, 200, 50, 7);
	ToMauHCN(5, 1, 200, 6, 50);
	ToMauHCN(5, 7, 200, 44, 112);
	Logo(50, 3);
}

void GiaoDienThongBao(string x)
{
	ToMauHCN(80, 17, 50, 10, 95);
	textcolor(95);
	gotoXY(81, 22);
	cout << string((49 - x.length()) / 2, ' ') + x;
	getch();
}
void GiaoDienTam(int toadoX,int toadoY,int mau,int mauchu,string x)
{
	ToMauHCN(toadoX, toadoY, 40, 10, mau);
	textcolor(mau);
	gotoXY(toadoX+1, toadoY+4);
	cout << string((39 - x.length()) / 2, ' ') + x;
	getch();
	textcolor(mauchu);
}

//doc gia
void GiaoDienThemDocGia(int toadoX, int toadoY)
{
	textcolor(112);
	gotoXY(toadoX - 20, 15);
	cout << "MA THE";
	gotoXY(toadoX - 20, 18);
	cout << "NHAP HO VA TEN LOT";
	gotoXY(toadoX - 20, 21);
	cout << "NHAP TEN";
	gotoXY(toadoX - 20, 24);
	cout << "PHAI(1:Nam,2:Nu)";

	gotoXY(toadoX + 15, toadoY + 10);
	cout << "XAC NHAN";
	gotoXY(toadoX + 30, toadoY + 10);
	cout << "HUY";

	VeHCN(toadoX, toadoY - 3, 50, 2);
	VeHCN(toadoX, toadoY, 50, 2);
	VeHCN(toadoX, toadoY + 3, 50, 2);
	VeHCN(toadoX, toadoY + 6, 50, 2);

}
void GiaoDienXuatDSDocGia(int toadoX, int toadoY, int n)
{
	int chieucao = 3 + 2 * n;
	int chieudai = 92;

	textcolor(112);

	gotoXY(toadoX + 1, toadoY + 1);
	cout << "STT";
	gotoXY(toadoX + 10, toadoY + 1);//1
	cout << "MA THE";
	gotoXY(toadoX + 25, toadoY + 1);//11
	cout << "HO VA TEN";
	gotoXY(toadoX + 60, toadoY + 1);//51
	cout << "PHAI";
	gotoXY(toadoX + 69, toadoY + 1);//61
	cout << "TRANG THAI";
	gotoXY(toadoX + 81, toadoY + 1);//73
	cout << "SO SACH";
	gotoXY(toadoX + 81, toadoY + 2);//73
	cout << "DANG MUON";
	

	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)150;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}


	// gach xuong
	for (int i = toadoX + 1; i < chieudai + toadoX; i++)
	{
		if (i == toadoX + 7 || i==toadoX+ 17 || i == toadoX + 57 || i == toadoX + 67 || i == toadoX + 80)
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j == toadoY)
					cout << char(194);
				else if (j == chieucao + toadoY)
					cout << char(193);
				else
					cout << (char)179;
			}
		}
	}


	// gach ngang
	for (int j = 3; j < chieucao; j = j + 2)
	{
		for (int i = toadoX; i <= chieudai + toadoX; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX)
				cout << (char)195;
			else if (i == chieudai + toadoX)
				cout << (char)180;
			else if (i==toadoX+7 || i == toadoX + 17 || i == toadoX + 57 || i == toadoX + 67 || i == toadoX + 80)
				cout << (char)197;
			else
				cout << (char)196;
		}
	}
	
}

//dau sach
void GiaoDienNhapDauSach(int toadoX, int toadoY)
{
	ToMauHCN(5, 1, 200, 6, 50);
	ToMauHCN(5, 7, 200, 44, 112);
	VeKhung(5, 1, 200, 50, 7);
	gotoXY(95, 4);
	textcolor(50);
	cout << "THEM DAU SACH";
	textcolor(112);
	gotoXY(toadoX - 35, toadoY + 1);
	cout << "NHAP MA Ma So Sach";
	gotoXY(toadoX - 35, toadoY + 4);
	cout << "NHAP TEN SACH";
	gotoXY(toadoX - 35, toadoY + 7);
	cout << "NHAP SO TRANG";
	gotoXY(toadoX - 35, toadoY + 10);
	cout << "NHAP TAC GIA";
	gotoXY(toadoX - 35, toadoY + 13);
	cout << "NHAP NAM XUAT BAN";
	gotoXY(toadoX - 35, toadoY + 16);
	cout << "NHAP THE LOAI";
	gotoXY(toadoX - 35, toadoY + 19);
	cout << "NHAP VI TRI DAU SACH";
	gotoXY(toadoX - 35, toadoY + 22);
	cout << "NHAP SO LUONG SACH CUA DAU SACH";
	gotoXY(toadoX + 15, toadoY + 25);
	cout << "XAC NHAN";
	gotoXY(toadoX + 30, toadoY + 25);
	cout << "HUY";

	VeHCN(toadoX, toadoY, 50, 2);
	VeHCN(toadoX, toadoY + 3, 50, 2);
	VeHCN(toadoX, toadoY + 6, 50, 2);
	VeHCN(toadoX, toadoY + 9, 50, 2);
	VeHCN(toadoX, toadoY + 12, 50, 2);
	VeHCN(toadoX, toadoY + 15, 50, 2);
	VeHCN(toadoX, toadoY + 18, 50, 2);
	VeHCN(toadoX, toadoY + 21, 50, 2);
}
void GiaoDenXuatDauSachTheoTheLoai(int toadoX, int toadoY, int n)
{
	textcolor(112);
	int chieucao = 3 + 2 * n;
	int chieudai = 130;

	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}


	// gach xuong
	for (int i = toadoX + 1; i < chieudai + toadoX; i++)
	{
		if (i == toadoX + 11 || i == toadoX + 52 || i == toadoX + 59 || i == toadoX + 85
			|| i == toadoX + 94 || i == toadoX + 120)
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j == toadoY)
					cout << char(194);
				else if (j == chieucao + toadoY)
					cout << char(193);
				else
					cout << (char)179;
			}
		}
	}


	// gach ngang
	for (int j = 3; j < chieucao; j = j + 2)
	{
		for (int i = toadoX; i <= chieudai + toadoX; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX)
				cout << (char)195;
			else if (i == chieudai + toadoX)
				cout << (char)180;
			else if (i == toadoX + 11 || i == toadoX + 52 || i == toadoX + 59 || i == toadoX + 85
				|| i == toadoX + 94 || i == toadoX + 120)
				cout << (char)197;
			else
				cout << (char)196;
		}
	}

	gotoXY(toadoX + 2, toadoY + 1);
	cout << "MA";
	gotoXY(toadoX + 2, toadoY + 2);
	cout << "DAU SACH";
	gotoXY(toadoX + 26, toadoY + 1);//12
	cout << "TEN SACH";
	gotoXY(toadoX + 53, toadoY + 1);///53
	cout << "SO";
	gotoXY(toadoX + 53, toadoY + 2);
	cout << "TRANG";
	gotoXY(toadoX + 68, toadoY + 1);//60
	cout << "TAC GIA";
	gotoXY(toadoX + 86, toadoY + 1);//86
	cout << "NAM";
	gotoXY(toadoX + 86, toadoY + 2);
	cout << "XUAT BAN";
	gotoXY(toadoX + 102, toadoY + 1);//95
	cout << "VI TRI";
	gotoXY(toadoX + 122, toadoY + 1);//116
	cout << "SO LUONG";
}
void GiaoDienXuat1DauSach(int toadoX, int toadoY)
{
	int chieucao = 5;
	int chieudai = 110;
	textcolor(112);
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}

	// gach xuong
	for (int i = toadoX + 1; i < chieudai + toadoX; i++)
	{
		if (i == toadoX + 11 || i == toadoX + 52 || i == toadoX + 78 || i == toadoX + 88)
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j == toadoY)
					cout << char(194);
				else if (j == chieucao + toadoY)
					cout << char(193);
				else
					cout << (char)179;
			}
		}
	}


	// gach ngang
	for (int j = 3; j < chieucao; j = j + 2)
	{
		for (int i = toadoX; i <= chieudai + toadoX; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX)
				cout << (char)195;
			else if (i == chieudai + toadoX)
				cout << (char)180;
			else if (i == toadoX + 11|| i == toadoX + 52 || i == toadoX + 78 || i == toadoX + 88)
				cout << (char)197;
			else
				cout << (char)196;
		}
	}

	gotoXY(toadoX + 2, toadoY + 1);
	cout << "MA";
	gotoXY(toadoX + 2, toadoY + 2);
	cout << "DAU SACH";
	gotoXY(toadoX + 28, toadoY + 1);
	cout << "TEN SACH";
	gotoXY(toadoX + 63, toadoY + 1);
	cout << "TAC GIA";
	gotoXY(toadoX + 80, toadoY + 1);
	cout << "NAM";
	gotoXY(toadoX + 80, toadoY + 2);
	cout << "XUAT BAN";
	gotoXY(toadoX + 96, toadoY + 1);
	cout << "THE LOAI";
}
void GiaoDienXuatDSDauSach(int toadoX, int toadoY, int n)
{
	int chieucao = 3 + 2 * n;
	int chieudai = 124;
	textcolor(112);
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}


	// gach xuong
	for (int i = toadoX + 1; i < chieudai + toadoX; i++)
	{
		if (i == toadoX + 6 ||i==toadoX+17|| i == toadoX + 54 || i == toadoX + 61 || i == toadoX + 87 || i == toadoX + 96
			|| i == toadoX + 118)
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j == toadoY)
					cout << char(194);
				else if (j == chieucao + toadoY)
					cout << char(193);
				else
					cout << (char)179;
			}
		}
	}

	// gach ngang
	for (int j = 3; j < chieucao; j = j + 2)
	{
		for (int i = toadoX; i <= chieudai + toadoX; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX)
				cout << (char)195;
			else if (i == chieudai + toadoX)
				cout << (char)180;
			else if (i == toadoX + 6 || i == toadoX + 17 || i == toadoX + 54 || i == toadoX + 61 || i == toadoX + 87
				|| i == toadoX + 96 || i==toadoX +118 )
				cout << (char)197;
			else
				cout << (char)196;
		}
	}
	//Thu vien co sang 
	gotoXY(toadoX + 2, toadoY + 1);
	cout << "STT";
	gotoXY(toadoX + 8, toadoY + 1);
	cout << "MA";
	gotoXY(toadoX + 8, toadoY + 2);
	cout << "DAU SACH";
	gotoXY(toadoX + 33, toadoY + 1);
	cout << "TEN SACH";
	gotoXY(toadoX + 56, toadoY + 1);
	cout << "SO";
	gotoXY(toadoX + 56, toadoY + 2);
	cout << "TRANG";
	gotoXY(toadoX + 70, toadoY + 1);
	cout << "TAC GIA";
	gotoXY(toadoX + 88, toadoY + 1);
	cout << "NAM";
	gotoXY(toadoX + 88, toadoY + 2);
	cout << "XUAT BAN";
	gotoXY(toadoX + 102, toadoY + 1);
	cout << "THE LOAI";
	gotoXY(toadoX + 119, toadoY + 1);
	cout << "SO";
	gotoXY(toadoX + 119, toadoY + 2);
	cout << "LUONG";
}
void GiaoDienXuat10DauSachMuonMax(int toadoX, int toadoY,int n)
{
	int chieucao = 3 + n * 2;
	int chieudai = 110;

	textcolor(112);

	gotoXY(toadoX + 2, toadoY + 1);
	cout << "MA DAU SACH";
	gotoXY(toadoX + 32, toadoY + 1);
	cout << "TEN SACH";
	gotoXY(toadoX + 57, toadoY + 1);
	cout << "SO TRANG";
	gotoXY(toadoX + 75, toadoY + 1);
	cout << "TAC GIA";
	gotoXY(toadoX + 96, toadoY + 1);
	cout << "SO LAN MUON";

	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}
	// gach xuong
	for (int i = toadoX + 1; i < chieudai + toadoX; i++)
	{
		if (i == toadoX + 15 || i == toadoX + 56 || i == toadoX + 66 || i == toadoX + 95)
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j == toadoY)
					cout << char(194);
				else if (j == chieucao + toadoY)
					cout << char(193);
				else
					cout << (char)179;
			}
		}
	}

	// gach ngang
	for (int j = 3; j < chieucao; j = j + 2)
	{
		for (int i = toadoX; i <= chieudai + toadoX; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX)
				cout << (char)195;
			else if (i == chieudai + toadoX)
				cout << (char)180;
			else if (i == toadoX + 15 || i == toadoX + 56 || i == toadoX + 66 || i == toadoX + 95)
				cout << (char)197;
			else
				cout << (char)196;
		}
	}
}

//danh muc sach
void GiaoDienXuatDSDMS(int toadoX, int toadoY, int n)
{
	int chieucao = 3 + 2 * n;
	int chieudai = 80;
	textcolor(112);
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}


	// gach xuong
	for (int i = toadoX + 1; i < chieudai + toadoX; i++)
	{
		if (i == toadoX + 25 || i == toadoX + 50)
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j == toadoY)
					cout << char(194);
				else if (j == chieucao + toadoY)
					cout << char(193);
				else
					cout << (char)179;
			}
		}
	}


	// gach ngang
	for (int j = 3; j < chieucao; j = j + 2)
	{
		for (int i = toadoX; i <= chieudai + toadoX; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX)
				cout << (char)195;
			else if (i == chieudai + toadoX)
				cout << (char)180;
			else if (i == toadoX + 25 || i == toadoX + 50)
				cout << (char)197;
			else
				cout << (char)196;
		}
	}

	gotoXY(toadoX + 10, toadoY + 1);
	cout << "MA SACH";
	gotoXY(toadoX + 34, toadoY + 1);
	cout << "TRANG THAI";
	gotoXY(toadoX + 60, toadoY + 1);
	cout << "VI TRI";
}
void GiaoDienXuatDanhSachMuon(int toadoX, int toadoY, int n)
{
	int chieucao = 3 + 2 * n;
	int chieudai = 38;

	textcolor(112);
	gotoXY(toadoX + 2, toadoY + 1);
	cout << "MA SACH";
	gotoXY(toadoX + 18, toadoY + 1);
	cout << "NGAY MUON";
	gotoXY(toadoX + 28, toadoY + 1);
	cout << "TRANG THAI";

	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}



	// gach xuong
	for (int i = toadoX + 1; i < chieudai + toadoX; i++)
	{
		if (i == toadoX + 16 || i == toadoX + 27)
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j == toadoY)
					cout << char(194);
				else if (j == chieucao + toadoY)
					cout << char(193);
				else
					cout << (char)179;
			}
		}
	}


	// gach ngang
	for (int j = 3; j < chieucao; j = j + 2)
	{
		for (int i = toadoX; i <= chieudai + toadoX; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX)
				cout << (char)195;
			else if (i == chieudai + toadoX)
				cout << (char)180;
			else if (i == toadoX + 16 || i == toadoX + 27)
				cout << (char)197;
			else
				cout << (char)196;
		}
	}
}

//MENU
void GiaoDienMenu(int toadoX, int toadoY, int n,string menu[],int chieucao) {
	textcolor(112);
	int j = toadoY;
	for (int i = 0; i < n; i++) {
		ToMauHCN(80, j, 50, chieucao, 240);
		gotoXY(80 + (50 - menu[i].length()) / 2, j + chieucao/2);
		cout << menu[i];
		j = j + chieucao + chieucao / 2 -1;
	}
}



