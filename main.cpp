#include "thuvien.h"

int main() {

	nodeptr list;
	khoiTao(list);

	ifstream filein;
	filein.open("DANHSACHLOP.TXT", ios::in);
	docDSLop(filein, list);
	filein.close();
	xuatDSLop(list);

	chucNang(list);





	system("pause");
	return 0;
}