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

#pragma region Nhập, Xuất, Xem Ma Trận
void nhapMaTran() {
	int x, y, time;
	cout << "Mang May Tinh Co Bao Nhieu Router ?: ";
	cin >> soRouter;
	x = y = 0;
	cout << "------ Nhap vao Router 1 va Router 2 >= " << soRouter << " de STOP !!!!!--------"<< endl;
	while (x < soRouter && y < soRouter)
	{
		cout << "Nhap Router 1: "; cin >> x;
		cout << "Nhap Router 2: "; cin >> y;
		if (x < soRouter && y < soRouter)
		{
			cout << "thoi gian truyen du lieu giua Router " << x << " va Router " << y <<" la: ";
			cin >> time;
			trongso[x][y] = time;
			trongso[y][x] = time;
			cout << "_________________________________________________________________________________" << endl;
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
	cout << "Ma Tran Mang May Tinh La: \n";
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
	int capnut[MAX]; //Đánh dấu điểm chưa xét
	int kcbandau[MAX]; //Đánh dấu khoảng cách ban đầu
	int routerTram;
	int min;

	//Khởi tạo các nhãn tạm thời cho các đỉnh.
	for (int i = 0; i < soRouter; i++) {
		capnut[i] = FALSE; //Với toàn bộ đỉnh sẽ được đánh dấu là False
		kcbandau[i] = vocung; //Và khởi cách lúc đầu của tất cả các đỉnh = vocung
		lotrinh[i] = routerNguon;
	}

	capnut[routerNguon] = TRUE; //Khi người dùng nhập liệu vào thì Router nguồn sẽ được đánh dấu
	kcbandau[routerNguon] = 0; //Cho khoảng cách từ router nguồn đến chính nó = 0
	routerTram = routerNguon; //Gán router nguồn vào biến router Tram để tiến hành tìm đường đi ngắn nhất

	while (capnut[routerDich]==FALSE) // Bước lặp sẽ dừng khi router đích đã được đánh dấu = TRUE
	{
		min = vocung;
		//Duyệt các đỉnh trong đồ thị
		for (int i = 0; i < soRouter; i++) 
		{
			// Tìm đỉnh i sau cho kcbandau[i] là nhỏ nhât
			if (min > kcbandau[i] && capnut[i] == FALSE)
			{
				min = kcbandau[i]; //Gán kcbandau[i] vào biến min
				routerTram = i;				
			}
			capnut[routerTram] = TRUE; //Router trạm là đỉnh có kcbandau là nhỏ nhất

			//Kiểm tra các điều kiện về đường đi, khoảng cách, và đỉnh đó đã được đánh dấu hay chưa
			if (trongso[routerTram][i] > 0 && kcbandau[i] > trongso[routerTram][i] + kcbandau[routerTram] && capnut[routerDich]==FALSE) 
			{
				kcbandau[i] = trongso[routerTram][i] + kcbandau[routerTram]; 
				lotrinh[i] = routerTram;
			}
		}
	}
	*ngan = kcbandau[routerDich]; //Lưu giá trị khoảng cách giữa 2 router vào biến *ngan
}
#pragma endregion
