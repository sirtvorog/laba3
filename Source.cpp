#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

using namespace std;



HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

int const N = 6;
int down = -99, up = 99;
bool printFlag = false;



/*int sizeInt(int down, int up) {
	int sizeDown=1, sizeUp=1;
	int bottom = down, top = up;
	while (bottom !=0 ) {
		sizeDown++;
		bottom = bottom/10;
	}

	while (top != 0) {
		sizeUp++;
		top = top / 10;
	}
	return max(sizeDown, sizeUp);
}
*/

int cursorPositionX(){
	CONSOLE_SCREEN_BUFFER_INFO bi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bi);
	return bi.dwCursorPosition.X;
}

int cursorPositionY() {
	CONSOLE_SCREEN_BUFFER_INFO bi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bi);
	return bi.dwCursorPosition.Y;

}

int lox(int vvod) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	cin.clear();
	cin.ignore(1000, '\n');
	SetConsoleTextAttribute(handle, FOREGROUND_RED);
	cout << "������ �����. ����������, ������� ����� �����.\n";
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "��� �����: ";
	cin >> vvod;
	return vvod;
}

void printArr(int arr[][N]) {

	cout << "\n";

	for (int i = 0; i < N; i++) {
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY  | FOREGROUND_BLUE | FOREGROUND_RED);
		
		for (int j = 0; j < N; j++) {
			if (j % 2 != 0) 	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);

			cout.width(
				4);
			cout << *(*(arr+i)+j) << ' ';

			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
		}
		cout << "\n";
	}
	

	

	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE|FOREGROUND_RED);
}

void snakeFill(int arr[][N]) {

	system("cls");

	srand(time(NULL));

	
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	int queue = 0;
	

    for (int i = 0; i <= N-1; i+=2) {


        for (int j = 0; j < N; j++) {
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE );

			destCoord.X = queue * 5;
			destCoord.Y = j * 2;
			SetConsoleCursorPosition(hStdout, destCoord);

			*(*(arr + j)+queue) = down + rand() % (up + up + 1);

			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *(*(arr + j) + queue);
			Sleep(100);
        }
		queue++;

		for (int j = N-1; j >= 0; j--) {
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);

			destCoord.X = queue * 5;
			destCoord.Y = j * 2;
			SetConsoleCursorPosition(hStdout, destCoord);

			*(*(arr + j) + queue) = -99 + rand() % (99 + 99 + 1);

			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *(*(arr + j) + queue);
			Sleep(100);
		}
		queue++;
    }

	
	destCoord.X = 0;
	destCoord.Y = N*2;
	SetConsoleCursorPosition(hStdout, destCoord);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

	printFlag = true;

}

void spiralFill(int arr[][N]) {

	system("cls");

	srand(time(0));

	
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	int up = 0, down = N - 1, left = 0, right = N - 1;

	while  (right>=left && up<=down ) {
		//verhnyaya stroka
		
		for (int j = left; j <= right; j++) {

			destCoord.X = j * 4;
			destCoord.Y =  up * 2;
			SetConsoleCursorPosition(hStdout, destCoord);

			*(*(arr + up) + j) = -99 + rand() % (99 + 99 + 1);

			if (j%2==0) SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);

			cout << *(*(arr + up) + j);

			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);

			cout.flush();
			Sleep(100);
			
		}
		up++;
		
		//praviy stolbec

		for (int j = up; j <=down; j++) {

			destCoord.X = right * 4;
			destCoord.Y =  j * 2;
			SetConsoleCursorPosition(hStdout, destCoord);

			*(*(arr + j) + right) = -99 + rand() % (99 + 99 + 1);
			
			if (right % 2 == 0) SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);

			cout << *(*(arr + j) + right);

			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);

			cout.flush();
			Sleep(100);

		}
		right--;

		//nizhnyaya stroka

		for (int j = right; j >= left; j--) {

			destCoord.X = j * 4;
			destCoord.Y = down * 2;
			SetConsoleCursorPosition(hStdout, destCoord);

			*(*(arr + down) + j) = -99 + rand() % (99 + 99 + 1);
			
			if (j % 2 == 0) SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);

			cout << *(*(arr + down) + j);

			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);

			cout.flush();
			Sleep(100);
		}
		down--;

		//leviy stolbec

		for (int j = down; j >= up; j--) {

			destCoord.X = left * 4;
			destCoord.Y =  j * 2;
			SetConsoleCursorPosition(hStdout, destCoord);
			
			*(*(arr + j) + left) = -99 + rand() % (99 + 99 + 1);

			if (left % 2 == 0) SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);

			cout << *(*(arr + j) + left);

			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);

			cout.flush();
			Sleep(100);
			
		}
		left++;
	}

	

	destCoord.X = 0;
	destCoord.Y =  N *2;
	SetConsoleCursorPosition(hStdout, destCoord);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	
	printFlag = true;

}

void hourlyMix(int arr[][N]) {

	
	for (int i = 0; i < (N / 2); i++) {
		for (int j = 0; j < (N / 2); j++) {
			swap(*(*(arr + i + (N / 2)) + j + (N / 2)), *(*(arr + i) + j));
		}

	}
	for (int i = 0; i < (N / 2); i++) {
		for (int j = 0; j < N; j++) {
			swap(*(*(arr + i + (N / 2)) + j), *(*(arr + i) + j));
		}
	}
}
void diagonalMix(int arr[][N]) {

	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N; j++) {
			swap(*(*(arr + N / 2 + i) + j), *(*(arr + i) + j));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N / 2; j++) {
			swap(*(*(arr + i) + j + N / 2), *(*(arr + i) + j));
				
		}
	}
}

void horizontalMix (int arr[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N / 2; j++) {
			swap(*(*(arr + i) + j + N / 2), *(*(arr + i) + j));
		}
	}
}

void verticalMix(int arr[][N]) {
	for (int i = 0; i < N/2; i++) {
		for (int j = 0; j < N ; j++) {
			swap(*(*(arr +N / 2+ i) + j ), *(*(arr + i) + j));
		}
	}
}

void insertSortPtr(int* arr) {
	int j;
	int *end = arr + N * N - 1;
	for (int* i = arr + 1; i <= end; i++) {
		if (*i < *(i - 1)) {
			for (j = *i; i > arr && *(i - 1) > j; i--) {
				*i = *(i - 1);
			}
			*i = j;
		}

	}
}

void calculate(int arr[][N], char sign, int num) {
	switch (sign) {
		case '+': {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					*(*(arr + i) + j) += num;
				}
			}
		} break;

		case '-': {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					*(*(arr + i) + j) -= num;
				}
			}
		}break;

		case '*': {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					*(*(arr + i) + j) *= num;
				}
			}
		}break;

		case '/': {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					*(*(arr + i) + j) /= num;
				}
			}
		}break;

	}

}

void trans(int arr[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (i != j) {
				swap(*(*(arr + i) + j), *(*(arr + j) + i));
			}
		}
	}

	

	printArr(arr);
}


int main() {

	system("chcp 1251");
	setlocale(0, "");

	int arr[N][N];


	cout << "������� ������� ����� :)\n\n";
	int choose = 0;


	while (choose != -1) {
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);

		cout << "\n\n\n��������, ��� �� ������ �������, � ������� �����, �������������� ������ �������, �� ���� ����: \n"\
			"1. ��������� ������� " << N << '*' << N << " ��������� ��������!\n"\
			"2. ��������� ������� �� ������ ����� � ������������ ��!\n"\
			"3. ������������� �������� ������� �� �����������!\n"\
			"4. ��������� �����-������ ������� �������������� �������� ��� ���������� �������!\n"\
			"5. ��������������� �������\n"\
			"6. ����� �� ��������� :(\n\n\n";


		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN| FOREGROUND_BLUE);

		cout << "\n��� �����: ";
		cin >> choose;
		cout << "\n\n";

		switch (choose) {

			case (!isdigit): {
				lox(choose);
			}break;

			case 6: {
				cout << "����-���� :(\n";
				choose = -1;
			}break;

			case 1: {

				int fillChoose;

				cout << "��� �� ������ ��������� �������?\n 1. �������! \n 2. ����������!\n\n";
				cout << "\n��� �����: ";
				cin >> fillChoose;
				cout << "\n\n";

				switch (fillChoose) {

					case (!isdigit): {
						fillChoose = lox(fillChoose);
					}

					default: {
						if (fillChoose>2 or fillChoose<1)
						fillChoose = lox(fillChoose);
					}

					case 1: {
						snakeFill(arr);
					}break;

					case 2: {
						spiralFill(arr);
					}break;						
				}
				
			}
				  break;
			
			case 2: {
				if (printFlag == false) spiralFill(arr);

				int mixChoose;

				cout << "��� ����� �������-������� �����?\n 1. �� ������� �������.\n 2. �����-������� \n 3. �������� ������� ������� � ������� \n 4. �������� ������� ������ � ������.\n\n ";
				cout << "\n��� �����: ";
				cin >> mixChoose;
				cout << "\n\n";

				switch (mixChoose) {

				case (!isdigit): {
					mixChoose = lox(mixChoose);
				}
				case 1: {
					hourlyMix(arr);
					printArr(arr);
				}break;

				case 2: {
					diagonalMix(arr);
					printArr(arr);
				}break;

				case 3: {
					verticalMix(arr);
					printArr(arr);
				}break;

				case 4: {
					horizontalMix(arr);
					printArr(arr);
				}break;
				}


			} break;

			case 3: {
				if (printFlag == false) spiralFill(arr);
				insertSortPtr(*arr);
				printArr(arr);
			} break;

			case 4: {

				char sign;
				int num;

				cout << "\n\n������� �������������� �������� (+, -, * ��� / )\n\n";
				cout << "\n��� �����: ";
				cin >> sign;
				cout << "\n\n������� �����, � ������� �� ������ ����������� ����������\n\n";
				cout << "\n��� �����: ";
				cin >> num;
				cout << "\n\n";
				calculate(arr, sign, num);
				printArr(arr);
			}break;

			case 5: {
				trans(arr);

			}
		}

	}
	return 0;
}

