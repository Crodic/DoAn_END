#include"Header.h"
int main()
{
	int chon;
	int routerNguon, routerDich;
	int ngan;
	int lotrinh[MAX];
	int i;
	do
	{
		cout << "\n1. Xem Ma Tran Mang";
		cout << "\n2. Kiem Tra Duong Truyen Ngan Nhat Giua 2 Router";
		cout << "\n0. Thoat";
		cout << "\n Chon chuc nang ban can: ";
		cin >> chon;
		switch (chon)
		{
			case 1:
			{
				docmatran();
				xemmatran();
				break;
			}
			case 2: 
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