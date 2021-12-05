#pragma once
//Them doc gia vao BNT

void xoaDanhMucSach(DanhMucSach& dms) {
	if (dms.phead == NULL)
		return;
	else
	{
		while (dms.phead != NULL) {
			NodeSach* k = dms.phead;
			dms.phead = dms.phead->pNext;
			delete k;
		}
	}
}

void ThemDocGia(TreeNodeDG*& tree, DocGia dg) 
{
	if (tree == NULL) 
	{
		TreeNodeDG* p = new TreeNodeDG;

		p->data = dg;

		p->pleft = NULL;
		p->pright = NULL;

		tree = p;
	}
	else 
	{
		if (dg.maDG < tree->data.maDG) 
		{
			ThemDocGia(tree->pleft, dg);
		}
		else if (dg.maDG > tree->data.maDG) 
		{
			ThemDocGia(tree->pright, dg);
		}
	}
}


void xoaDSMuonTra(DSMuonTra& dsMt) {
	if (dsMt.phead == NULL)
		return;
	else
	{
		while (dsMt.phead != NULL) {
			NodeMuonTra* k = dsMt.phead;
			dsMt.phead = dsMt.phead->pNext;
			delete k;
		}
	}
}
void xuLiXoaDSDG(TreeNodeDG* t)
{
	if (t == NULL)
		return;
	else
	{
		xuLiXoaDSDG(t->pleft);
		xuLiXoaDSDG(t->pright);

		xoaDSMuonTra(t->data.mt);
		delete t;
	}
}

void xoaDSDocGia(DSDocGia& dsDg)
{
	xuLiXoaDSDG(dsDg.tree);
}

void xoaDSDSach(DSDauSach& dsDs)
{
	for (int i = 0; i < dsDs.sl; i++)
	{
		xoaDanhMucSach(dsDs.data[i]->dms);
		delete dsDs.data[i];
	}
}



//tim doc gia tren BNT
TreeNodeDG* timMaDG(TreeNodeDG* tree, int maDg)
{
	if (tree != NULL)
	{
		if (tree->data.maDG > maDg)
			return timMaDG(tree->pleft, maDg);
		else if (tree->data.maDG < maDg)
			return timMaDG(tree->pright, maDg);
		else
			return tree;
	}
	return NULL;
}
	
void XoaNode2Con(TreeNodeDG*& temp, TreeNodeDG*& Y)
{
	//Y la node the mang can tim
	//node* Y=tree->pright
	if (Y->pleft != NULL)
	{
		XoaNode2Con(temp, Y->pleft);//node trai nhat
	}
	else
	{
		temp->data = Y->data;//cap nhat
		temp = Y;
		Y = Y->pright;
	}
}
//xem
void XoaDocGiaTheoMaDG(TreeNodeDG*& tree, int maDg)
{
	if (tree == NULL)
	{
		return;
	}
	else 
	{
		if (maDg > tree->data.maDG)
		{
			XoaDocGiaTheoMaDG(tree->pright, maDg);
		}
		else if (maDg < tree->data.maDG) 
		{
			XoaDocGiaTheoMaDG(tree->pleft, maDg);
		}
		else 
		{
			TreeNodeDG* temp = tree;

			if (tree->pleft == NULL)
			{
				tree = tree->pright;
			}
			else if (tree->pright == NULL) 
			{
				tree = tree->pleft;
			}
			else
			{
				//tim node trai nhat cua cay con phai
				TreeNodeDG* Y = tree->pright;
				XoaNode2Con(temp, Y);
			}
			delete temp;
		}
	}
}
//xem lai phan nay
void chuyenCaySangMang(TreeNodeDG* t, DocGia dg[], int& n) 
{
	if (t != NULL) 
	{
		chuyenCaySangMang(t->pleft, dg, n);
		chuyenCaySangMang(t->pright, dg, n);

		dg[n++] = t->data;
	}

}


//sap xep doc gia theo ho ten dung mang 
void sapXepDGTheoHoTenBangMang(DocGia dg[], int n)
{	//bubbleSort
	for (int i = 0; i < n - 1; i++) 
	{
		bool flag = false;
		for (int j = 0; j < n - 1 - i; j++) 
		{
			if (dg[i].ten + dg[i].ho > dg[j].ten + dg[j].ho) 
			{
				DocGia temp = dg[i];
				dg[i] = dg[j];
				dg[j] = temp;
			}
		}
		if (flag == false)
			break;
	}
}

//thêm một cuốn sách vào danh sách 
void themSach(DanhMucSach& dsSach, Sach sach) 
{
	NodeSach* nodeSach = new NodeSach;
	nodeSach->data = sach;
	if (dsSach.phead == NULL)
	{
		dsSach.phead = nodeSach;
	}
	else 
	{
		NodeSach* pTail = dsSach.phead;

		while (pTail->pNext != NULL) 
		{
			pTail = pTail->pNext;
		}

		pTail->pNext = nodeSach;
	}
}
//tim kiem dau sach
DauSach* timDauSach(DSDauSach dsDauSach, string maDauSach)
{
	for (int i = 0; i < dsDauSach.sl; i++)
	{ //linear search
		if (dsDauSach.data[i]->MSSach == maDauSach)
			return dsDauSach.data[i];
	}
	return NULL;
}

//thêm đầu sách theo danh mục
void themDauSach(DSDauSach& dsDauSach, DauSach dauSach) 
{
	DauSach* nodeDauSach = new DauSach();
	*nodeDauSach = dauSach;

	dsDauSach.data[dsDauSach.sl] = nodeDauSach;
	dsDauSach.sl++;
}


DSDauSach layDSDauSachTheoTheLoai(DSDauSach dsDauSach, string theLoai)
{
	DSDauSach dsDauSachTemp;

	for (int i = 0; i < dsDauSach.sl; i++) {
		if (theLoai == dsDauSach.data[i]->theloai) {
			dsDauSachTemp.data[dsDauSachTemp.sl++] = dsDauSach.data[i];
		}
	}

	return dsDauSachTemp;
}

//lay cac the loai cua danh sach dau sach
string* layDanhSachTheLoai(DSDauSach dsDauSach, int& n) {
	string* dsTheLoai = new string[dsDauSach.sl];

	for (int i = 0; i < dsDauSach.sl; i++) {
		bool kt = true;
		for (int j = 0; j < n; j++) {
			if (dsTheLoai[j] == dsDauSach.data[i]->theloai) {
				kt = false;
				break;
			}
		}
		if (kt)
			dsTheLoai[n++] = dsDauSach.data[i]->theloai;
	}

	return dsTheLoai;
}

void merge(DSDauSach& dsDauSach, int l, int m, int r)
{
	int i, j, k;
	int n1 = 0;
	int n2 = 0;
	n1 = m - l + 1;
	n2 = r - m;

	DSDauSach L;
	DSDauSach R;


	for (i = 0; i < n1; i++)
		L.data[i] = dsDauSach.data[l + i];
	for (j = 0; j < n2; j++)
		R.data[j] = dsDauSach.data[m + 1 + j];

	i = 0, j = 0, k = l;
	while (i < n1 && j < n2)
	{
		if (L.data[i]->tensach < R.data[j]->tensach)
		{
			dsDauSach.data[k] = L.data[i];
			i++;
		}
		else
		{
			dsDauSach.data[k] = R.data[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		dsDauSach.data[k] = L.data[i];
		k++; i++;
	}
	while (j < n2)
	{
		dsDauSach.data[k] = R.data[j];
		k++; j++;
	}
	xoaDSDSach(L);
	xoaDSDSach(R);

}

void mergeSort(DSDauSach & dsDauSach, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(dsDauSach, l, m);
		mergeSort(dsDauSach, m + 1, r);
		merge(dsDauSach, l, m, r);
	}
}

void sapXepDSDauSachTheoTen(DSDauSach& dsDauSach)
{  
	mergeSort(dsDauSach, 0, dsDauSach.sl-1);
}

// tim ten sach
DSDauSach timTenSach(DSDauSach dsDs, string tenSach)
{
	DSDauSach dsDSTemp;
	for (int i = 0; i < dsDs.sl; i++) 
	{
		if (strstr(dsDs.data[i]->tensach.c_str(), tenSach.c_str()) != NULL) //so sanh hai con tro (neu ton tai thi tra ve ko null
		{
			dsDSTemp.data[dsDSTemp.sl++] = dsDs.data[i];
		}
	}
	return dsDSTemp;
}


void themMuonTra(DSMuonTra& dsmt, MUONTRA mt) {
	NodeMuonTra* nodemt = new NodeMuonTra;

	nodemt->data = mt;

	if (dsmt.phead == NULL) {
		dsmt.phead = nodemt;
	}
	else
	{
		NodeMuonTra* ptail = dsmt.phead;
		while (ptail->pNext != NULL) {
			ptail = ptail->pNext;
		}
		ptail->pNext = nodemt;
	}
}

NodeSach* laySachMuon(DauSach* dauS) 
{
	for (NodeSach* k = dauS->dms.phead; k != NULL; k = k->pNext) {
		if (k->data.trangthai == 0) {
			return k;
		}
	}
	return NULL;
}

bool KiemTraQuaHan(Date ngayMuon)
{
	ngayMuon = CongNgay(ngayMuon, 7);
	Date ngayHienTai = LayNgayHienTai();
	if (SoSanhNgay(ngayHienTai, ngayMuon) == 1)
	{
		return true;
	}
	return false;
}
bool dieuKienMuonSach(TreeNodeDG*& t, DauSach* nodeDauSach) {
	for (NodeMuonTra* k = t->data.mt.phead; k != NULL; k = k->pNext) {
		string maDauSach = TachLayMaDauSach(k->data.masach);
		if (nodeDauSach->MSSach == maDauSach) {
			if (k->data.trangthai == 0) {
				return false;
			}
		}
	}
	return true;
}
void xuLiMuonSach(TreeNodeDG*& TreeNodeDG, DauSach*& nodeDauSach, NodeSach*& nodeSach) {

	TreeNodeDG->data.soSachDangmuon++;

	TreeNodeDG->data.mt.sl++;

	nodeDauSach->soLanMuon++;

	nodeSach->data.trangthai = 1;

	MUONTRA mt;

	mt.masach = nodeSach->data.masach;
	mt.trangthai = 0;
	Date ngayTra;
	ngayTra.ngay = 0;
	ngayTra.thang = 0;
	ngayTra.nam = 0;
	mt.ngaymuon = LayNgayHienTai();
	mt.ngaytra = ngayTra;

	themMuonTra(TreeNodeDG->data.mt, mt);
}

NodeMuonTra* timSachTra(TreeNodeDG* TreeNodeDG, string maSach) {
	for (NodeMuonTra* k = TreeNodeDG->data.mt.phead; k != NULL; k = k->pNext)
	{
		if (k->data.masach == maSach && k->data.trangthai == 0)
			return k;
	}
	return NULL;
}
NodeSach* laySachTra(DauSach* dauS, string maSach) {
	for (NodeSach* k = dauS->dms.phead; k != NULL; k = k->pNext) {
		if (k->data.masach == maSach && k->data.trangthai == 1)
		{
			return k;
		}
	}
	return NULL;
}
void xuliTraSach(DSDauSach& dsDs, TreeNodeDG*& TreeNodeDG, string layDSMaSachMuon[], int vt) {

	NodeMuonTra* nodeMt = timSachTra(TreeNodeDG, layDSMaSachMuon[vt]);
	DauSach* dauS = timDauSach(dsDs, TachLayMaDauSach(layDSMaSachMuon[vt]));

	if (TreeNodeDG->data.trangthai == 0)
		TreeNodeDG->data.trangthai = 1;

	TreeNodeDG->data.soSachDangmuon--;

	nodeMt->data.trangthai = 1;
	nodeMt->data.ngaytra = LayNgayHienTai();

	NodeSach* nodeSach = laySachTra(dauS, layDSMaSachMuon[vt]);

	nodeSach->data.trangthai = 0;

}

void sapXepTheoSoLuotMuon(DSDauSach& dsTemp) {
	for (int i = 0; i < dsTemp.sl - 1; i++) 
	{
		for (int j = i + 1; j < dsTemp.sl; j++) 
		{
			if (dsTemp.data[i]->soLanMuon < dsTemp.data[j]->soLanMuon) 
			{
				DauSach tmp = *dsTemp.data[i];
				*dsTemp.data[i] = *dsTemp.data[j];
				*dsTemp.data[j] = tmp;
			}
		}
	}
}

//Xoa Sach
NodeSach* laySachXoa(DauSach* ds, string maS) {
	for (NodeSach* k = ds->dms.phead; k != NULL; k = k->pNext)
	{
		if (k->data.masach == maS)
			return k;
	}
	return NULL;
}

void Xoa1Sach(DanhMucSach& dms, string masach) {
	if (dms.phead == NULL)
		return;
	if (dms.phead->data.masach == masach)
	{
		NodeSach* tmp = dms.phead;
		dms.phead = dms.phead->pNext;
		delete tmp;
	}
	else
	{
		for (NodeSach* k = dms.phead; k->pNext != NULL; k = k->pNext) //duyệt qua tất cả sách
		{
			if (k->pNext->data.masach == masach)
			{
				NodeSach* g = k->pNext;
				if (g->pNext == NULL)//nếu node next = null thi xoa
				{
					delete g;
					k->pNext = NULL;
					return;
				}
				k->pNext = g->pNext;
				delete g;
			}
		}
	}
}


//Xu li load file
void loadFileDSVaDanhMucSach(DSDauSach& dsDauSach) {
	ifstream filein;
	ifstream filein1;

	filein.open("dsDauSach.txt", ios_base::in);
	filein1.open("dsDMS.txt", ios_base::in);

	if (filein.fail() || filein1.fail())
		return;

	int n = 0;
	filein >> n;
	filein.ignore();

	for (int i = 1; i <= n; i++) {
		DauSach DauSach;

		getline(filein, DauSach.MSSach, ',');
		getline(filein, DauSach.tensach, ',');
		filein >> DauSach.sotrang;
		filein.ignore();

		getline(filein, DauSach.tacgia, ',');
		filein >> DauSach.nxb;
		filein.ignore();

		getline(filein, DauSach.theloai, ',');
		filein >> DauSach.dms.sl;
		filein.ignore();

		for (int j = 0; j < DauSach.dms.sl; j++) {
			Sach sach;
			getline(filein1, sach.masach, ',');
			getline(filein1, sach.vitri, ',');
			filein1 >> sach.trangthai;

			filein1.ignore();

			themSach(DauSach.dms, sach);//them mot quyen sach vao danh muc sach
		}
		themDauSach(dsDauSach, DauSach);//them danh muc sach vao dau sach
	}

	filein.close();
	filein1.close();
}
void loadFileDGVaMT(DSDocGia& dsDg, DSDauSach& dsDs) {
	ifstream Filein;
	ifstream Filein1;

	Filein.open("dsDocGia.txt", ios_base::in);
	Filein1.open("dsMuonTra.txt", ios_base::in);

	if (Filein.fail() || Filein1.fail())
		return;

	Filein >> dsDg.sl;
	Filein.ignore();

	for (int i = 0; i < dsDg.sl; i++) {
		DocGia dg;
		string tam;

		Filein >> dg.maDG;
		Filein.ignore();

		getline(Filein, tam, ',');
		tachLayTenVaHo(tam, dg.ten, dg.ho);

		Filein >> dg.phai;
		Filein.ignore();

		Filein >> dg.trangthai;
		Filein.ignore();

		Filein >> dg.mt.sl;
		Filein.ignore();

		for (int j = 0; j < dg.mt.sl; j++) {
			MUONTRA temp;

			getline(Filein1, temp.masach, ',');

			string maMSSach = TachLayMaDauSach(temp.masach);

			for (int k = 0; k < dsDs.sl; k++) {
				if (dsDs.data[k]->MSSach == maMSSach) {
					dsDs.data[k]->soLanMuon++;
					break;
				}
			}

			Date temp1;

			Filein1 >> temp1.ngay;
			Filein1.ignore();

			Filein1 >> temp1.thang;
			Filein1.ignore();

			Filein1 >> temp1.nam;
			Filein1.ignore();

			temp.ngaymuon = temp1;
			Date temp2;

			Filein1 >> temp2.ngay;
			Filein1.ignore();

			Filein1 >> temp2.thang;
			Filein1.ignore();

			Filein1 >> temp2.nam;
			Filein1.ignore();

			temp.ngaytra = temp2;

			Filein1 >> temp.trangthai;
			Filein1.ignore();

			if (temp.trangthai == 0) {
				dg.soSachDangmuon++;
			}
			if (KiemTraQuaHan(temp.ngaymuon) && temp.trangthai == 0)
				dg.trangthai = 0;

			themMuonTra(dg.mt, temp);
		}
		ThemDocGia(dsDg.tree, dg);
	}

	Filein.close();
	Filein1.close();
}


//Xu li luu file
void ghiFileDSVaDanhMucSach(DSDauSach dsDauSach) {
	ofstream fileout;
	ofstream fileout1;

	fileout.open("dsDauSach.txt", ios_base::out);
	fileout1.open("dsDMS.txt", ios_base::out);

	fileout << dsDauSach.sl << endl;

	for (int i = 0; i < dsDauSach.sl; i++) {
		fileout << dsDauSach.data[i]->MSSach << "," << dsDauSach.data[i]->tensach << "," << dsDauSach.data[i]->sotrang << "," << dsDauSach.data[i]->tacgia << "," <<
			dsDauSach.data[i]->nxb << "," << dsDauSach.data[i]->theloai << "," << dsDauSach.data[i]->dms.sl << endl;

		for (NodeSach* k = dsDauSach.data[i]->dms.phead; k != NULL; k = k->pNext) {
			fileout1 << k->data.masach << "," << k->data.vitri << "," << k->data.trangthai << endl;
		}
	}

	fileout.close();
	fileout1.close();
}
void XuLiGhiDSDGVaMT(TreeNodeDG* t, ofstream& fileout, ofstream& fileout2) {
	if (t == NULL) {
		return;
	}
	else
	{
		XuLiGhiDSDGVaMT(t->pleft, fileout, fileout2);
		fileout << t->data.maDG << "," << t->data.ho << " "
			<< t->data.ten << "," << t->data.phai << ","
			<< t->data.trangthai << "," << t->data.mt.sl << endl;

		for (NodeMuonTra* k = t->data.mt.phead; k != NULL; k = k->pNext) {
			fileout2 << k->data.masach << ","
				<< k->data.ngaymuon.ngay << "/" << k->data.ngaymuon.thang << "/" << k->data.ngaymuon.nam << ","
				<< k->data.ngaytra.ngay << "/" << k->data.ngaytra.thang << "/" << k->data.ngaytra.nam << ","
				<< k->data.trangthai << endl;
		}

		XuLiGhiDSDGVaMT(t->pright, fileout, fileout2);
	}
}
void ghiFileDGVaMT(DSDocGia dsDg) 
{
	ofstream fileout;
	ofstream fileout2;

	fileout.open("dsDocGia.txt", ios_base::out);
	fileout2.open("dsMuonTra.txt", ios_base::out);

	fileout << dsDg.sl << endl;

	XuLiGhiDSDGVaMT(dsDg.tree, fileout, fileout2);

	fileout.close();
	fileout2.close();
}



