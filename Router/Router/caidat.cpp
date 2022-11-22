#include"Header.h"
int trongso[MAX][MAX]; //trọng số từ routerNguon đến RouterDich trong khoảng MAX
int soRouter; //Số router
#pragma region Đọc Ma Trận Mạng Router
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

	//Khởi tạo các giá trị tạm thời cho các đỉnh.
	for (int i = 0; i < soRouter; i++) {
		capnut[i] = FALSE;
		kcbandau[i] = vocung;
		lotrinh[i] = routerNguon;
	}

	capnut[routerNguon] = TRUE;
	kcbandau[routerNguon] = 0;
	routerTram = routerNguon;

	while (routerTram != routerDich) 
	{
		min = vocung;
		//Duyệt các đỉnh trong đồ thị
		for (int i = 0; i < soRouter; i++) 
		{
			//Kiểm tra các điều kiện về đường đi, khoảng cách, và đỉnh đó đã được đánh dấu hay chưa
			if (trongso[routerTram][i] > 0 && kcbandau[i] > trongso[routerTram][i] + kcbandau[routerTram] && capnut[i]==FALSE) 
			{
				kcbandau[i] = trongso[routerTram][i] + kcbandau[routerTram];
				lotrinh[i] = routerTram;
			}
			//Duyệt lại các đỉnh để trả về giá trị sau khi cập nhật và đánh dấu đỉnh đó đã được xét
			for (int i = 0; i < soRouter; i++) 
			{
				if (min > kcbandau[i] && capnut[i] == FALSE)
				{
					min = kcbandau[i];
					routerTram = i;
				}
				capnut[routerTram] = TRUE;
			}
		}
	}
	*ngan = kcbandau[routerDich]; //Lưu giá trị khoảng cách giữa 2 router vào biến *ngan
}
#pragma endregion
