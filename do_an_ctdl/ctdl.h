#pragma once
#pragma warning(disable:4996)
#include<iostream>
#include<cstdlib>
#include<time.h>
#include<conio.h>
#include <string>
#include<fstream>
#include <dos.h>
#include <Windows.h>
#include <stdio.h>
#define MAX 200

int pointer = 13;

using namespace std;

struct Sach {
	string masach;
	int trangthai;// 0. duoc muon 1. da co nguoi muon
	string vitri;
};

struct NodeSach {
	Sach data;
	NodeSach* pNext = NULL;
};

struct DanhMucSach {
	NodeSach* phead = NULL;//con tro quan li cac cuon sach rieng biet
	int sl = 0;
};

struct DauSach {
	string MSSach;
	string tensach;
	int sotrang;
	string tacgia;
	int nxb;
	string theloai;
	int soLanMuon = 0;
	DanhMucSach dms;

};

struct DSDauSach {
	DauSach *data[MAX];
	int sl = 0;
};

struct Date {
	int ngay;
	int thang;
	int nam;
};

struct MUONTRA {
	string masach;
	Date ngaymuon;
	Date ngaytra; 
	int trangthai; //0:dang muon 1:da tra 2:lam mat sach
};

struct NodeMuonTra
{
	MUONTRA data;
	NodeMuonTra* pNext=NULL;
};

struct DSMuonTra {
	NodeMuonTra* phead = NULL;
	int sl = 0;
};

struct DocGia{
	int maDG;
	string ho;
	string ten;
	int phai;//1:nam 2:nu
	int trangthai;//0:the bi khoa  1:dang hoat dong
	int soSachDangmuon = 0;
	DSMuonTra mt;
};
struct TreeNodeDG{
	DocGia data;
	TreeNodeDG* pleft;
	TreeNodeDG* pright;
};

struct DSDocGia {
	TreeNodeDG *tree = NULL;
	int sl = 0;
};