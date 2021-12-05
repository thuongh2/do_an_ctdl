#pragma once

string XuLyNhapMa(int length)
{
	string input;
	ShowCur(1);
	/*gotoXY(whereX(), whereY());*/
	while (true)
	{
		char c = getch();
		if (((c >= 48 && c <= 57) || c == '_' || (c >= 65 && c <= 90)) && input.length() < length)
		{
			input.insert(input.begin() + input.length(), c);
			cout << c;
		}
		else if ((c >= 97 && c <= 122) && input.length() < length)
		{
			c = c - 32;
			input.insert(input.begin() + input.length(), c);
			cout << c;
		}
		else if (c == 8 && input.length() > 0)
		{
			input.erase(input.begin() + input.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 27)
		{
			input.clear();
			ShowCur(0);
			return input;
		}
		else if (c == 13 && input.length() > 0)
		{
			ShowCur(0);
			return input;
		}
	}
}

string XuLyNhapChu()
{
	string input;
	ShowCur(1);

	/*gotoXY(whereX(), whereY());*/
	while (true)
	{
		char c = getch();
		if (((c >= 48 && c <= 57) || (c >= 97 && c <= 122) || c == '_' || (c >= 65 && c <= 90) && input.length() < 6) && input.length() < 48)
		{
			input.insert(input.begin() + input.length(), c);
			cout << c;
		}
		else if (c == 32 && input.length() != 0 && input[input.length() - 1] != ' ')
		{
			input.insert(input.begin() + input.length(), ' ');
			cout << c;
		}
		else if (c == 8 && input.length() > 0)
		{
			input.erase(input.begin() + input.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 27)
		{
			input.clear();
			ShowCur(0);
			return input;
		}
		else if (c == 13 && input.length() > 0)
		{
			ShowCur(0);
			return input;
		}
	}
}

int XuLyNhapSo()
{
	int n;
	ShowCur(1);
	gotoXY(whereX(), whereY());
	string x = "";
	char c;
	while (true)
	{
		c = getch();
		if ((c >= 48 && c <= 57) && x.length() < 5)
		{
			x.insert(x.begin() + x.length(), c);
			cout << c;
		}
		else if (c == 8 && x.length() > 0)
		{
			x.erase(x.begin() + x.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 27)
		{
			ShowCur(0);
			return -1;
		}
		else if (c == 13 && x.length() > 0)
		{

			n = atoi(x.c_str());
			ShowCur(0);
			return n;
		}

	}
}
void XuLyNhapMa(string& input, int toadoX, int& toadoY, int lenghtMax)
{
	char c;
	ShowCur(1);
	while (true)
	{
		c = getch();
		if (((c >= 48 && c <= 57) || (c >= 65 && c <= 90)) && input.length() < lenghtMax) //chữ hoa và số thêm trực tiếp vào input
		{
			input.insert(input.begin() + input.length(), c);
			cout << c;
		}
		else if ((c >= 97 && c <= 122) && input.length() < lenghtMax)// chứ thường thì đổi sang chữ hoa
		{
			c = c - 32;
			input.insert(input.begin() + input.length(), c);
			cout << c;
		}
		else if (c == 8 && input.length() > 0)// XÓA 
		{
			input.erase(input.begin() + input.length() - 1);//GIẢM INPUT ĐI 1
			cout << "\b";//LÙI CÒN TRỎ VỀ TRÁI
			cout << " ";
			cout << "\b";
		}
		else if (c == 13 && input.length() > 0)//nhan enter thi xuong tiep theo
		{
			toadoY = toadoY + 3;
			ShowCur(0);
			return;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 80)
			{
				toadoY = toadoY + 3;
				ShowCur(0);
				return;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				ShowCur(0);
				return;
			}
		}
	}
}
void XuLyNhapSo(int& n, int toadoX, int& toadoY)
{
	string x;
	x = ChuyenSoSangString(n);
	char c;
	ShowCur(1);
	while (true)
	{
		c = getch();
		if (c >= 48 && c <= 57 && x.length() < 4)
		{
			x.insert(x.begin() + x.length(), c);
			cout << c;
		}
		else if (c == 8 && x.length() > 0)
		{
			x.erase(x.begin() + x.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 13 && x.length() > 0)
		{
			toadoY = toadoY + 3;
			n = atoi(x.c_str());
			ShowCur(0);
			return;
		}
		else if (c == -32)
		{
			c = getch();

			if (c == 80)
			{
				if (x.empty())
				{
					n = 0;
				}
				else
				{
					n = atoi(x.c_str());
				}
				toadoY = toadoY + 3;
				ShowCur(0);
				return;
			}
			else if (c == 72)
			{
				if (x.empty())
				{
					n = 0;
				}
				else
				{
					n = atoi(x.c_str());
				}
				toadoY = toadoY - 3;
				ShowCur(0);
				return;
			}
		}
	}
}
void XuLyNhapChu(string& input, int toadoX, int& toadoY, int lenghtMax)
{
	char c;
	ShowCur(1);//show con tro
	while (true)
	{
		char c = _getch();
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57)) && input.length() < lenghtMax)
		{
			input.insert(input.begin() + input.length(), c);
			cout << c;
		}
		else if (c == 8 && input.length() > 0)
		{
			input.erase(input.begin() + input.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 32 && input.length() < lenghtMax && input.length() != 0 && input[input.length() - 1] != ' ')
		{
			input.insert(input.begin() + input.length(), ' ');
			cout << c;
		}
		else if (c == 13 && input.length() > 0)
		{
			toadoY = toadoY + 3;//thay doi tao do y 
			ShowCur(0);//an con tro
			return;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 80)
			{
				toadoY = toadoY + 3;
				ShowCur(0);
				return;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				ShowCur(0);
				return;
			}
		}
	}
}
