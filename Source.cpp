#include "thuvien.h"


void khoiTao(nodeptr& list) {
	list = NULL;
}
int empty(nodeptr l) {
	return (l == NULL ? 1 : 0);
}
nodeptr taoNode(Lop x) {
	nodeptr p = new Node;
	p->data = x;
	p->link = NULL;
	return p;
}
void themCuoi(nodeptr& l, Lop a) {
	nodeptr p = taoNode(a);
	nodeptr q;
	if (empty(l))
		l = p;
	else {
		q = l;
		while (q->link != NULL) {
			q = q->link;
		}q->link = p;
	}
}
void nhapSinhVien(sinhVien& a) {
	cin.ignore();
	cout << "\nNhap ma so sinh vien : ";
	cin.getline(a.MSSV, 10);
	cout << "\nNhap ho sinh vien : ";
	cin.getline(a.ho, 30);
	cout << "\nNhap ten sinh vien : ";
	cin.getline(a.ten, 10);
	cout << "\nNhap gioi tinh (0:nam - 1:nu) : ";
	cin >> a.gioitinh;
	cout << "\nNhap diem trung binh : ";
	cin >> a.diemTB;
	cout << "\n ---------------------------------";
}
void xuatSinhVien(sinhVien a) {
	cout << "Ma so sinh vien : " << a.MSSV;
	cout << "\nHo sinh vien : " << a.ho;
	cout << "\nTen sinh vien : " << a.ten;
	if (a.gioitinh == 0)
		cout << "\nGioi tinh: Nam" << endl;
	else cout << "\nGioi tinh: Nu" << endl;
	cout << "Diem trung binh : " << a.diemTB << endl;
}
void xuatSV(sinhVien a) {

	cout << a.MSSV << "\t\t\t" << a.ho << "\t\t" << a.ten << "\t\t";
	if (a.gioitinh == 0)
		cout << "Nam\t\t";
	else cout << "Nu\t\t";
	cout << a.diemTB;

}
void nhapLop(Lop& a) {
	cin.ignore();
	cout << "\nNhap ten lop : ";
	cin.getline(a.tenLop, 10);
	cout << "\nNhap si so lop : ";
	cin >> a.siSo;
	for (int i = 0; i < a.siSo; i++) {
		cout << "\nNhap sinh vien thu " << i << endl;
		nhapSinhVien(a.ds[i]);
	}
}
void xuatDSSinhVien(Lop a)
{
	cout << "\n\n*************************************************************************************";
	cout << "\nDanh sach sinh vien cua lop: " << a.tenLop;
	cout << "\nSi so lop: " << a.siSo;
	cout << "\nDanh sach cac sinh vien la: " << endl;
	cout << "Ma so sinh vien \tHo sinh vien \tTen sinh vien \tGioi tinh \tDiem trung binh" << endl;
	for (int i = 0; i < a.siSo; i++)
	{
		/*cout << "\n--------------------------------" << endl;*/
		/*cout << "Sinh vien thu " << i << endl;*/
		xuatSV(a.ds[i]);
		cout << endl;
	}
}
void xuatDSLop(nodeptr list)
{
	int i = 0;
	nodeptr p = list;
	while (p != NULL)
	{
		xuatDSSinhVien(p->data);
		p = p->link;

	}
}
// Câu 3:Tìm sinh viên có MSSV là X, nếu có xuất ra thông tin sinh viên là tên lớp 
void timSV(char* mssv, nodeptr list) {
	if (list != NULL) {
		nodeptr p = list;
		bool flag = false;
		while (p != NULL)
		{
			for (int i = 0; i < p->data.siSo; i++) {
				if (strcmp(p->data.ds[i].MSSV, mssv) == 0) {
					flag = true;
					cout << "\nSinh vien cua lop: " << p->data.tenLop << endl;
					xuatSinhVien(p->data.ds[i]);
					break;
				}
			}
			p = p->link;
		}
		if (flag == false) {
			cout << "\nKhong tim thay\n";
		}
	}
}
// Câu 5: Trả về số lượng lớp hiện có 
int soLuongLop(nodeptr list) {
	if (list == NULL) {
		return 0;
	}
	else {
		nodeptr p = list;
		int dem = 0;
		while (p != NULL) {
			dem++;
			p = p->link;
		}return dem;
	}
}
// Câu 7: Sử dụng giải thuật SelectionSort để sắp xếp danh sách tên sinh viên theo thứ tự từ A->Z theo từng lớp
//selection sort: tìm min trong danh sách chưa sắp xếp, đỏi chổ i với min
void sapXepTenSVTuADenZ(Lop& a) {
	for (int i = 0; i < a.siSo - 1; i++) {
		int min = i;
		for (int j = 0; j < a.siSo; j++) {
			if (strcmp(a.ds[i].ten, a.ds[j].ten) > 0) {
				min = j;
			}
			sinhVien tam = a.ds[i];
			a.ds[i] = a.ds[min];
			a.ds[min] = tam;
		}
	}
}
void capNhatDSLop(nodeptr& list) {
	if (list != NULL) {
		nodeptr p = list;
		while (p != NULL)
		{
			sapXepTenSVTuADenZ(p->data);
			p = p->link;
		}
	}
}
// Câu 2: Xuất lớp sĩ số chẵn
void xuatLopSSChan(nodeptr list) {
	nodeptr p = list;
	while (p != NULL)
	{
		if ((float)(p->data.siSo % 2 == 0))
			xuatDSSinhVien(p->data);
		p = p->link;
	}
}
// Câu 6: Tìm và thay thế tên lớp X thành Y
bool kiemTraLopX(nodeptr list, char* x) { // Tìm lớp tên X nếu có trả về true ngược lại trả về false
	nodeptr p = list;
	if (list != NULL) {
		while (p != NULL)
		{
			if (strcmp(p->data.tenLop, x) == 0)
			{
				return true;
			}
			p = p->link;
		}
	}
	return false;
}
void thayTheX(nodeptr& list, char* x, char* y) {
	nodeptr p = list;
	if (p != NULL) {
		while (p != NULL)
		{
			if (strcmp(p->data.tenLop, x) == 0)
			{
				strcpy(p->data.tenLop, y);
			}
			p = p->link;
		}
	}
}
// Câu 8: Sử dụng giải thuật bất kỳ để sắp xếp tên lớp theo sĩ số giảm dần 
void sapXepSSLopGiam(nodeptr& list) {
	if (list != NULL) {
		nodeptr p = list;
		while (p != NULL) {
			nodeptr q = p->link;
			while (q != NULL)
			{
				if (p->data.siSo <= q->data.siSo) {
					Lop tam = p->data;
					p->data = q->data;
					q->data = tam;
				}
				q = q->link;
			}
			p = p->link;
		}
	}
}
// Câu 4: Xóa lớp tên X ra khỏi danh sách 
void deleteFirst(nodeptr& list) {
	if (list != NULL)
	{
		nodeptr p = list;
		list = p->link;
		p->link = NULL;
		delete(p);
	}
}
void xoaLopX(nodeptr& list, char* x) {
	if (list != NULL)
	{
		nodeptr p = list;
		nodeptr prev = NULL;
		while (p->link != NULL && strcmp(p->data.tenLop, x) != 0)
		{
			prev = p;
			p = p->link;
		}
		if (p != NULL)
		{
			if (prev == NULL)
				deleteFirst(list);
			else
			{
				prev->link = p->link;
				p->link = NULL;
				delete(p);
			}
		}
	}
}
// Câu 9: Tách lớp có sĩ số trên >= 50 ra 1 danh sách khác
void tachLopHon50SV(nodeptr& list,nodeptr& list2) {
	if (list != NULL) {
		khoiTao(list2);
		Lop lop;
		nodeptr p = list;
		nodeptr q;
		while (p != NULL)
		{	
			q = p->link;
			if (q->data.siSo >= 50) {
				lop = q->data;
				themCuoi(list2, lop);
				xoaLopX(list, q->data.tenLop);
			}
			p = p->link;
		}
	}
}

void ghiFile1Sv(ofstream& fileout, sinhVien sv) {
	fileout << sv.MSSV << " ";
	fileout << sv.ho << " ";
	fileout << sv.ten << " ";
	fileout << sv.gioitinh << " ";
	fileout << sv.diemTB;
}
void ghiFileDSSV(ofstream& fileout, Lop lop) {
	fileout << lop.tenLop;
	fileout << endl;
	fileout << lop.siSo;
	fileout << endl;
	for (int i = 0; i < lop.siSo; i++) {
		ghiFile1Sv(fileout, lop.ds[i]);
		fileout << endl;
	}
}
int ghiFileDSLop(nodeptr list) {
	ofstream fileout;
	fileout.open("DANHSACHLOP.TXT", ios::out);
	nodeptr p = list;
	while (p != NULL) {
		ghiFileDSSV(fileout, p->data);

		p = p->link;
	}
	fileout.close();
	return 1;
}
void doc1SV(ifstream& filein, sinhVien& sv) {
	string tam;

	filein >> sv.MSSV;
	filein >> sv.ho;
	filein >> sv.ten;
	filein >> sv.gioitinh;
	getline(filein, tam, ' ');
	filein >> sv.diemTB;
}
void docDSSV(ifstream& filein, Lop& lop) {
	filein >> lop.tenLop;
	filein >> lop.siSo;
	for (int i = 0; i < lop.siSo; i++) {
		doc1SV(filein, lop.ds[i]);
	}
}
void docDSLop(ifstream& filein, nodeptr& list) {
	Lop lop;
	while (!filein.eof()) {
		docDSSV(filein, lop);
		themCuoi(list, lop);
	}
}
void menu() {
	cout << "\n================== MENU =================\n";
	cout << "=  Nhap 1.  Nhap lop                    =\n";
	cout << "=  Nhap 2.  xuat danh sach lop          =\n";
	cout << "=  Nhap 3.  Tim sinh vien               =\n";
	cout << "=  Nhap 4.  So luong lop hien co        =\n";
	cout << "=  Nhap 5.  Sap sep ten sinh vien A->Z  =\n";
	cout << "=  Nhap 6.  Xuat lop si so chan         =\n";
	cout << "=  Nhap 7.  Doi ten lop X thanh Y       =\n";
	cout << "=  Nhap 8.  Sap xep si so giam dan      =\n";
	cout << "=  Nhap 9.  Xoa lop                     =\n";
	cout << "=  Nhap 10. Tach lop tren 50 sinh vien  =\n";
	cout << "=  Nhap 11. Ghi file                    =\n";
	cout << "=  Nhap -99. Thoat                      =\n";
	cout << "=========================================\n";
}
void chucNang(nodeptr list) {
	int so;
	Lop a;
	char mssv[10];
	char nwlop[10];
	char tlop[10];
	nodeptr list2;
	do {
		menu();
		cout << "\nNHAP CHUC NANG : ";
		cin >> so;
		switch (so)
		{
		case 1:
			nhapLop(a);
			themCuoi(list, a);
			break;
		case 2:
			xuatDSLop(list);
			break;
		case 3:
			cout << "\nNhap mssv can tim : ";
			cin.ignore();
			cin.getline(mssv, 10);
			timSV(mssv, list);
			break;
		case 4:
			cout << "\nSo luong lop hien co la : " << soLuongLop(list);
			break;
		case 5:
			capNhatDSLop(list);
			xuatDSLop(list);
			break;
		case 6:
			cout << "\nCac lop co si so chan la ";
			xuatLopSSChan(list);
			break;
		case 7:
			cout << "\nNhap ten lop X can doi ten: ";
			cin.ignore();
			cin.getline(tlop, 10);
			cout << "\nNhap ten moi: ";
			cin.getline(nwlop, 10);
			if (kiemTraLopX(list, tlop) == false) {
				cout << "\nKhong co lop vua nhap!";
				break;
			}
			thayTheX(list, tlop, nwlop);
			xuatDSLop(list);
			break;
		case 8:
			sapXepSSLopGiam(list);
			cout << "\Danh sach lop sau khi sap xep theo si so giam dan la: " << endl;
			xuatDSLop(list);
			break;
		case 9:
			cout << "\nNhap ten lop X can xoa: ";
			cin.ignore();
			cin.getline(tlop, 10);
			if (kiemTraLopX(list, tlop) == false) {
				cout << "\nKhong co lop vua nhap!";
				break;
			}
			xoaLopX(list, tlop);
			cout << "\nDanh sach lop sau khi xoa:";
			xuatDSLop(list);
			break;
		case 10:
			tachLopHon50SV(list,list2);
			cout << "\nDanh sach lop cu sau khi tach:";
			xuatDSLop(list);
			cout << "\nDanh sach lop moi";
			xuatDSLop(list2);
			break;
		case 11:
			if (ghiFileDSLop(list) == 1) {
				cout << "\nGhi thanh cong\n";
			}
			break;
		case -99:
			cout << "THOAT CHING TRINH !!!!!\n";
			break;
		default:
			cout << "VUI LONG NHAP DUNG CHUC NANG !!!";
		}
	} while (so != -99);
}