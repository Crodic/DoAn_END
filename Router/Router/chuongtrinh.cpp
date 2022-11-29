#include"Header.h"
int main()
{
	int trongso[MAX][MAX];
	int chon;
	int routerNguon, routerDich;
	int ngan;
	int lotrinh[MAX];
	int i;
	int soRouter;
	do
	{
		cout << "\n1. Nhap va ghi Ma Tran Mang May Tinh Vao File.";
		cout << "\n2. Doc va Xuat File Ma Tran.";
		cout << "\n3. Kiem Tra Duong Truyen Ngan Nhat Giua 2 Router.";
		cout << "\n0. Thoat";
		cout << "\n Chon chuc nang ban can: ";
		cin >> chon;
		switch (chon)
		{
			case 1:
			{
				nhapMaTran();
				ghimatran();
				break;
			}
			case 2: 
			{
				cout << "\nMa Tran Mang May Tinh la: "<< endl;
				docmatran();
				xemMaTran();
				break;
			}
			case 3: 
			{
				docmatran();
				cout << "\nNhap vao 1 Router bat ky: "; cin >> routerNguon;
				cout << "\nNhap vao Router can di den: "; cin >> routerDich;
				router(routerNguon, routerDich, &ngan, lotrinh);
				cout << "\nDuong truyen ngan nhat giua Router (" << routerNguon << ") den Router (" << routerDich << ") la: " << ngan;
				cout << "\nLo trinh duy chuyen giua Router (" << routerNguon << ") den Router (" << routerDich << ") la: ";
				i = routerDich;
				while (i != routerNguon) 
				{
					cout << i << " -> ";
					i = lotrinh[i];
				}
				cout << routerNguon;
				cout << "\n____________________________________________________________________________";
				break;
			}

		}
	} while (chon != 0);
}