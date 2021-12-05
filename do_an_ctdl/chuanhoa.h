#pragma once

int DemChuSo(int n)
{
	int count = 0;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return count;
}

char Chuyen1SoSangKiTu(int n)
{
	switch (n)
	{
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 0:
		return '0';
	}
}

string ChuyenSoSangString(int n)
{
	string str;
	int a;
	while (n > 0)
	{
		a = n % 10;
		Chuyen1SoSangKiTu(a);
		str.insert(str.begin() + 0, Chuyen1SoSangKiTu(a));
		n = n / 10;
	}
	return str;
}

void DinhDangChuoi(string& str)
{
	//Xoa khoang trong
	while (str[0] == ' ')
	{
		str.erase(str.begin() + 0);
	}
	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.begin() + (str.length() - 1));
	}

	for (int i = 1; i < str.length() - 1; i++)
	{
		if (str[i + 1] == ' ' && str[i] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
	//Viet thuong
	for (int i = 0; i < str.length(); i++)
	{
		if ((65 <= str[i] && str[i] <= 90) && str[i] != ' ')
		{
			str[i] = str[i] + 32;
		}
	}
	//Viet hoa chu cai dau
	for (int i = 0; i < str.length(); i++)
	{
		if (i == 0 && (97 <= str[i] && str[i] <= 122))
		{
			str[0] = str[0] - 32;
		}
		if (str[i] == ' ' && (97 <= str[i + 1] && str[i + 1] <= 122))
		{
			str[i + 1] = str[i + 1] - 32;
		}
	}
}

//chuan hoa masach ABCD_1 ABCD_2
string NoiChuoi(string str, int n)
{
	string str2;
	str2 = str;
	string str1 = ChuyenSoSangString(n);
	str2.push_back('_');
	for (int i = 0; i < str1.length(); i++)
	{
		str2.push_back(str1[i]);
	}
	return str2;
}

string TachLayMaDauSach(string str)
{
	string str1 = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '_')
		{
			break;
		}
		str1.push_back(str[i]);
	}
	return str1;
}

int TachLayMaSach(string str)
{
	string str1;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (str[i] == '_')
		{
			break;
		}
		str1.push_back(str[i]);
	}
	return atoi(str1.c_str());
}

void tachLayTenVaHo(string str, string& ten, string& ho)
{
	int k = 0;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (str[i] == ' ')
		{
			k = i;
			break;
		}
	}

	for (int i = 0; i < k; i++)
	{
		ho += str[i];
	}

	for (int i = k + 1; i < str.length(); i++)
	{
		ten += str[i];
	}
}

// Xu Ly Ngay Thang
int ChuyenThang(string str)
{
	if (str == "Jan")
	{
		return 1;
	}
	else if (str == "Feb")
	{
		return 2;
	}
	else if (str == "Mar")
	{
		return 3;
	}
	else if (str == "Apr")
	{
		return 4;
	}
	else if (str == "May")
	{
		return 5;
	}
	else if (str == "Jun")
	{
		return 6;
	}
	else if (str == "Jul")
	{
		return 7;
	}
	else if (str == "Aug")
	{
		return 8;
	}
	else if (str == "Sep")
	{
		return 9;
	}
	else if (str == "Oct")
	{
		return 10;
	}
	else if (str == "Nov")
	{
		return 11;
	}
	else if (str == "Dec")
	{
		return 12;
	}
}

Date LayNgayHienTai()
{
	Date d;
	time_t now = time(0);
	char* dt = ctime(&now);
	string str1, str2, str3;
	
	for (int i = 8; i < 10; i++)
	{
		str1.push_back(dt[i]);
	}
	d.ngay = atoi(str1.c_str());
	
	for (int i = 4; i < 7; i++)
	{
		str2.push_back(dt[i]);
	}
	d.thang = ChuyenThang(str2);
	
	for (int i = 20; i < 24; i++)
	{
		str3.push_back(dt[i]);
	}
	d.nam = atoi(str3.c_str());

	return d;
}

bool KTNamNhuan(int nam)
{
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
	{
		return true;
	}
	else
		return false;
}

int SoSanhNgay(Date d1, Date d2)
{
	if (d1.nam == d2.nam)
	{
		if (d1.thang == d2.thang)
		{
			if (d1.ngay > d2.ngay)
			{
				return 1;
			}
			else if (d1.ngay < d2.ngay)
			{
				return -1;
			}
			else
				return 0;
		}
		else if (d1.thang > d2.thang)
		{
			return 1;
		}
		else
			return -1;
	}
	else if (d1.nam > d2.nam)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int SoNgayCuaThang(int thang)
{
	if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
	{
		return 31;
	}
	else if (thang == 2)
	{
		if (KTNamNhuan)
		{
			return 29;
		}
		else
			return 28;
	}
	else
		return 30;
}

Date CongNgay(Date t, int SoNgay)
{
	Date d = t;
	d.ngay = d.ngay + SoNgay;
	if (d.ngay > SoNgayCuaThang(d.thang))
	{
		if (d.thang == 12)
		{
			d.thang = 1;
			d.nam = d.nam + 1;
		}
		else
		{
			d.thang = d.thang + 1;
		}
		d.ngay = d.ngay - SoNgayCuaThang(t.thang);
	}
	return d;
}

// === Xu li trang Thai === 
string layGioiTinh(int n)
{
	if (n == 1)
	{
		return "Nam";
	}
	return "Nu";
}

string layTrangThaiDocGia(int n)
{
	if (n == 1)
		return "Hoat Dong";
	else
		return "Khoa";
}
string TrangThaiSach(int n)
{
	if (n == 1)
	{
		return "Da Muon";
	}
	else
		return "Chua muon";

}
string TrangThaiMuonTra(int n)
{
	if (n == 0)
		return "Dang Muon";
	else if (n == 1)
		return "Da Tra";
	else if (n == 2)
		return "Da Mat";
}
