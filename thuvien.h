#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>;
using namespace std;
struct sinhVien
{
	char MSSV[10];
	char ho[30];
	char ten[10];
	int gioitinh;
	float diemTB;
};
struct Lop
{
	int siSo;
	char tenLop[10];
	sinhVien ds[100];
};
struct Node
{
	Lop data;
	Node* link;
};
typedef Node* nodeptr;
void khoiTao(nodeptr& list);
int empty(nodeptr l);
nodeptr taoNode(Lop x);
void themCuoi(nodeptr& l, Lop a);
void nhapSinhVien(sinhVien& a);
void nhapLop(Lop& a);
void xuatSinhVien(sinhVien a);
void menu();
void chucNang(nodeptr list);
void xuatDSSinhVien(Lop a);
void xuatDSLop(nodeptr list);
void timSV(char* mssv, nodeptr list);
void sapXepTenSVTuADenZ(Lop& a);
void capNhatDSLop(nodeptr& list);
void xuatLopSSChan(nodeptr list);
void thayTheX(nodeptr& list, char* x, char* y);
bool kiemTraLopX(nodeptr list, char* x);
void sapXepSSLopGiam(nodeptr& list);
void deleteFirst(nodeptr& list);
void xoaLopX(nodeptr& list, char* x);
void tachLopHon50SV(nodeptr& list,nodeptr &list2);
void themSV(Lop &x, sinhVien a, int pos);
void xoaSV(Lop& x, int pos);
void xuatSV(sinhVien a);
void ghiFile1Sv(ofstream& fileout, sinhVien sv);
void ghiFileDSSV(ofstream& fileout, Lop lop);
int ghiFileDSLop(nodeptr list);
void doc1SV(ifstream& filein, sinhVien& sv);
void docDSSV(ifstream& filein, Lop& lop);
void docDSLop(ifstream& filein, nodeptr& list);
