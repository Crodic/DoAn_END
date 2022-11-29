#include"Header.h"
int trongso[MAX][MAX]; //trọng số từ routerNguon đến RouterDich trong khoảng MAX
int soRouter; //Số router
#pragma region Hàm Khởi Tạo
void init()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
			trongso[i][j] = vocung;
	}
}
#pragma endregion

#pragma region Nhập, Xuất Ma Trận
void nhapMaTran() {
	int x, y, time;
	cout << "Mang May Tinh Co Bao Nhieu Router ?: ";
	cin >> soRouter;
	x = y = 0;
	cout << "------ Nhap Router x va Router y >= " << soRouter << " de STOP !!!!!--------"<< endl;
	while (x < soRouter && y < soRouter)
	{
		cout << "Nhap Router x: "; cin >> x;
		cout << "Nhap Router y: "; cin >> y;
		if (x < soRouter && y < soRouter)
		{
			cout << "thoi gian truyen du lieu giua Router " << x << " va Router " << y <<" la: ";
			cin >> time;
			trongso[x][y] = time;
			trongso[y][x] = time;
			cout << "___________________________________________________________________" << endl;
		}
	}
}
void xemMaTran() {
	for (int i = 0; i < soRouter; i++)
	{
		for (int j = 0; j < soRouter; j++)
			cout << trongso[i][j] << "\t";
		cout << endl;
	}
}
#pragma endregion

#pragma region Đọc, Ghi File Ma Trận
void ghimatran()
{
	FILE* f;
	fopen_s(&f, "router.txt", "wt"); //Mở file router.txt chế độ ghi văn bản
	if (f == NULL)
	{
		return;
	}
	fprintf_s(f, "%d", soRouter);
	for (int i = 0; i < soRouter; i++)
	{
		fprintf_s(f, "\n");
		for (int j = 0; j < soRouter; j++)
		{
			fprintf_s(f, "%d\t", trongso[i][j]);
		}
	}
	fclose(f);
}
void docmatran()
{
	FILE* f;
	fopen_s(&f, "router.txt", "rt"); //Mở file router.txt chế độ đọc văn bản.
	if (f == NULL)
	{
		return;
	}
	fscanf_s(f, "%d", &soRouter); //Đọc từng dòng file
	for (int i = 0; i < soRouter; i++)
	{
		for (int j = 0; j < soRouter; j++)
			fscanf_s(f, "%d", &trongso[i][j]);
	}
	fclose(f);
}
#pragma endregion

#pragma region Xem Mạng Máy Tính
void xemmatran()
{
	for (int i = 0; i < soRouter; i++)
	{
		for (int j = 0; j < soRouter; j++)
			cout << trongso[i][j] << "\t";
		cout << endl;
	}
	cout << "____________________________________________ \n";
}
#pragma endregion

#pragma region Tìm Đường Đi Ngắn Nhất
void router(int routerNguon, int routerDich, int* ngan, int lotrinh[]) {
	int danhdau[MAX];
	int kcbandau[MAX];
	int routerTram;
	int min;

	for (int i = 0; i < soRouter; i++) {
		danhdau[i] = FALSE;
		kcbandau[i] = vocung;
		lotrinh[i] = routerNguon;
	}

	danhdau[routerNguon] = TRUE;
	kcbandau[routerNguon] = 0;
	routerTram = routerNguon;

	while (danhdau[routerDich]==FALSE)
	{
		min = vocung;

		for (int i = 0; i < soRouter; i++) 
		{

			if (min > kcbandau[i] && danhdau[i] == FALSE)
			{
				min = kcbandau[i];
				routerTram = i;				
			}
			danhdau[routerTram] = TRUE; 

	
			if (trongso[routerTram][i] > 0 && kcbandau[i] > trongso[routerTram][i] + kcbandau[routerTram] && danhdau[routerDich]==FALSE) 
			{
				kcbandau[i] = trongso[routerTram][i] + kcbandau[routerTram]; 
				lotrinh[i] = routerTram;
			}
		}
	}
	*ngan = kcbandau[routerDich]; //Lưu giá trị khoảng cách giữa 2 router vào biến *ngan
}
#pragma endregion
