/*1. Дан масив чисел розмірністю 10 елементів. 
Написати функцію, яка сортує масив за зростанням або за спаданням, залежно від третього параметра функції.
Якщо він дорівнює 1, сортування йде за спаданням, якщо 0, то за зростанням. 
Перші 2 параметри функції — це масив і його розмір, третій параметр за замовчуванням дорівнює 1.
2. Дан масив випадкових чисел у діапазоні від -20 до +20. 
Необхідно знайти позиції крайніх від'ємних елементів 
(найлівішого від'ємного елемента і найправішого від'ємного елемента) 
і впорядкувати елементи, що знаходяться між ними.
3. Дан масив із 20 цілих чисел зі значеннями від 1 до 20. Необхідно:
■ написати функцію, що розкидає елементи масиву довільним чином;
■ створити випадкове число з того ж діапазону і знайти позицію цього випадкового числа в масиві;
■ відсортувати елементи масиву, що знаходяться зліва від знайденої позиції за спаданням, 
а елементи масиву, що знаходяться справа від знайденої позиції, за зростанням.*/

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#define Vvod(A)cin>>A;
#define Show(A)cout<<A;
#define Default cout<<"Ne virno obranui variant";
using namespace std;

void Vubir_zadachi();
void Switch(int A);
void Random();
void Masuv_int(int Ar[], int n);
void Masuv_double(double Ar[], int n);
void Vubir_tupy_masuva();
void Sortyvanna_masuva();
template<typename T1, typename T2>void Switch_masuvy(int A, T1 Ar1[], T2 Ar2[], int N);
template<typename T>void Show_masuw(T Ar[], int n);
template<typename T>void Sortyvanna(T Ar[], int n, bool s = 1);
template<typename T>void Za_zrostannam(T Ar[], int n);
template<typename T>void Za_spadannam(T Ar[], int n);

void Vporadkyvanna_v_duapazoni();
int Pravui_videmnui(int Ar[], int N);
int Livui_videmnui(int Ar[], int N);

void Dii_z_masuvom();
void Rozkudyvanna_masuva(int Ar[], int N);
int Randomne_chuslo();
int Indeks_randomnogo_chisla(int Ar[], int N);
void Sortyvanna_vid_pozusii(int Ar[], int N, int z);

int main() {
	int a = 0;
	while (true) {
		if (a == 4) break;
		Vubir_zadachi();
		Show('\n');
		Vvod(a);
		Show('\n');
		Switch(a);
		Show('\n');
	}
}
int Indeks_randomnogo_chisla(int Ar[], int N) {
	int x = Randomne_chuslo();
	for (int i = 0; i < N; i++) {
		if (Ar[i] == x) {
			return i;
			break;
		}
	}
}
int Randomne_chuslo() {
	Random();
	int a = rand() % 19 + 1;
	return a;
}
void Rozkudyvanna_masuva(int Ar[], int N) {
	Random();
	int x, q, n = 0;
	int i, j;
	const int N2 = 20;
	int Ar2[N2];

	for (int i = 1; i < N; i++) {
		q = rand() % 19;
		Sleep(10);
		x = Ar[i];
		Ar[i] = Ar[q];
		Ar[q] = x;
	}
}
void Sortyvanna_vid_pozusii(int Ar[], int N, int z) {
	for (int f = 0; f < N; f++) {
		//Sortyvanna vuborom
		for (int i = 0; i < z; i++) {
			int k = i;
			int x = Ar[i];
			for (int j = i + 1; j < z; j++) {
				if (Ar[j] > x) {
					k = j;
					x = Ar[j];
				}
			}
			if (k != i) {
				Ar[k] = Ar[i];
				Ar[i] = x;
			}
			f++;
		}
		//Sortuvanna bylbaskoy
		int r;
		for (int l = z + 1; l < N; l++) {
			for (int j = N - 1; j > l; j--) {
				if (Ar[j - 1] > Ar[j]) {
					r = Ar[j - 1];
					Ar[j - 1] = Ar[j];
					Ar[j] = r;
				}
			}
			f++;
		}
	}
}
void Dii_z_masuvom() {
	/*3. Дан масив із 20 цілих чисел зі значеннями від 1 до 20. Необхідно:
      ■ написати функцію, що розкидає елементи масиву довільним чином;
      ■ створити випадкове число з того ж діапазону і знайти позицію цього випадкового числа в масиві;
      ■ відсортувати елементи масиву, що знаходяться зліва від знайденої позиції за спаданням, 
        а елементи масиву, що знаходяться справа від знайденої позиції, за зростанням.*/
	const int N = 20;
	int Ar[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	Show_masuw<int>(Ar, N);
	Show('\n');
	Show('\n');
	cout << "Masuv zi zmisanumu elementamu:\n";
	Rozkudyvanna_masuva(Ar, N);
	Show_masuw<int>(Ar, N);
	Show('\n');
	Show('\n');
	int n = Randomne_chuslo();
	int m = Indeks_randomnogo_chisla(Ar, N);
	cout << "Vupadkove chuslo " << n << " z indeksom " << m;
	Show('\n');
	Show('\n');
	Sortyvanna_vid_pozusii(Ar, N, m);
	cout << "Vidsortovanui masuv zliva vid elementy " << n << " za spadannam, "
		<< "a sprava za zrostannam\n";
	Show_masuw<int>(Ar, N);
	Show('\n');
}
int Pravui_videmnui(int Ar[], int N) {
	int a = 0;
	for (int i = 0; i < N; i++) {
		if (Ar[i] < 0) {
			a = i;
		}
	}
	return a;
}
int Livui_videmnui(int Ar[],int N) {
	int a = 0;
	for (int i = 0; i < N; i++) {
		if (Ar[i] < 0) {
			a = i;
			break;
		}
	}
	return a;
}
void Sortyvanna_v_diapazoni(int Ar[], int N) {
	//Sortuvanna vuborom
	int Pr = Pravui_videmnui(Ar, N);
	int Lv = Livui_videmnui(Ar, N);
	int x, y;
	for (int k = 0; k < N; k++) {
		if (Ar[k] == Ar[Lv + 1]) {
			for (int i = Lv + 1; i < Pr; i++) {
				x = i;
				y = Ar[i];
				for (int j = i + 1; j < Pr; j++) {
					if (Ar[j] < y) {
						x = j;
						y = Ar[j];
					}
				}
				if (x != i) {
					Ar[x] = Ar[i];
					Ar[i] = y;
				}
				k++;
			}
		}
	}
}
void Vporadkyvanna_v_duapazoni() {
	/*2. Дан масив випадкових чисел у діапазоні від -20 до +20. 
      Необхідно знайти позиції крайніх від'ємних елементів 
      (найлівішого від'ємного елемента і найправішого від'ємного елемента) 
      і впорядкувати елементи, що знаходяться між ними.*/
	int a = 1;
	const int N = 30;
	int Ar[N];
	Masuv_int(Ar, N);
	Show_masuw<int>(Ar, N);
	Show('\n');
	cout << "Samui krainui livui videmnui element: ";
	int Lv = Livui_videmnui(Ar, N);
	Show(Ar[Lv]);
	Show('\n');
	cout << "Samui krainui pravui videmnui element: ";
	int Pr = Pravui_videmnui(Ar, N);
	Show(Ar[Pr]);
	Show('\n');
	Show('\n');
	Sortyvanna_v_diapazoni(Ar, N);
	Show_masuw<int>(Ar, N);
	Show('\n');
}
void Sortyvanna_masuva() {
	/*1. Дан масив чисел розмірністю 10 елементів. 
      Написати функцію, яка сортує масив за зростанням або за спаданням, залежно від третього параметра функції.
      Якщо він дорівнює 1, сортування йде за спаданням, якщо 0, то за зростанням. 
      Перші 2 параметри функції — це масив і його розмір, третій параметр за замовчуванням дорівнює 1.*/
	int a = 1;
	const int N = 10;
	int Ar1[N];
	double Ar2[N];
	while (true) {
		if (a == 3)break;
		Vubir_tupy_masuva();
		Vvod(a);
		Switch_masuvy(a, Ar1,Ar2,N);
	}
	
}
template<typename T>void Za_zrostannam(T Ar[], int n) {
	//Sortuvanna vuborom
	for (int i = 0; i < n; i++) {
		int k = i;
		T x = Ar[i];
		for (int j = i + 1; j < n; j++) {
			if (Ar[j] < x) {
				k = j;
				x = Ar[j];
			}
		}
		if (k != i) {
			Ar[k] = Ar[i];
			Ar[i] = x;
		}
	}
}
template<typename T>void Za_spadannam(T Ar[], int n) {
	//Bylbaskove sortyvanna
	T x;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			if (Ar[j - 1] < Ar[j]) {
				x = Ar[j - 1];
				Ar[j - 1] = Ar[j];
				Ar[j] = x;
			}
		}
	}
}
template<typename T1, typename T2>void Switch_masuvy(int A, T1 Ar1[], T2 Ar2[], int N) {
	switch (A) {
	case 1: {
		Masuv_int(Ar1, N);
		Show_masuw<int>(Ar1, N);
		Show('\n');
		cout << "Vidsortovanui masuv:";
			Show('\n');
		Sortyvanna<int>(Ar1, N);
		Sortyvanna<int>(Ar1, N, false);
	}break;
	case 2: {
		Masuv_double(Ar2, N);
		Show_masuw<double>(Ar2, N);
		Show('\n');
		cout << "Vidsortovanui masuv:";
			Show('\n');
		Sortyvanna<double>(Ar2, N);
		Sortyvanna<double>(Ar2, N, false);
	}break;
	case 3:break;
	default:Default;
	}
	Show('\n');
	Show('\n');
}
void Vubir_tupy_masuva() {
	cout << "Oberite tup masuvy:\n"
		<< "1. Z cilumu chuslamu\n"
		<< "2. Z ne cilumu chuslamu\n"
		<< "3. Vuhid\n";
}
template<typename T>void Sortyvanna(T Ar[], int n, bool s) {
	if (s) {
		cout << "Sortuwanna za spadannam:\n";
		Za_spadannam(Ar, n);
		Show_masuw(Ar, n);
		Show('\n');
	}
	else {
		cout << "Sortuwanna za zrostannam:\n";
		Za_zrostannam(Ar, n);
		Show_masuw(Ar, n);
		Show('\n');
	}
}

template<typename T>void Show_masuw(T Ar[], int n) {
	for (int i = 0; i < n; i++) {
		Show(Ar[i]);
		Show(' ');
	}
	Show('\n');
}
void Masuv_double(double Ar[], int n) {
	Random();
	for (int i = 0; i < n; i++) {
		Ar[i] = (double)(rand() % 50 - 25) / (double)(rand() % 8 + 1);
	}
}
void Masuv_int(int Ar[], int n) {
	Random();
	for (int i = 0; i < n; i++) {
		Ar[i] = rand() % 40 - 20;
	}
}
void Random() {
	srand(time(NULL));
}
void Vubir_zadachi() {
	cout << "Oberite zadachy:\n"
		<< "1. Sortyvanna masuva\n"
		<< "2. Vporadkyvanna v duapazoni\n"
		<< "3. Dii z masuvom\n"
		<< "4. Vuhid";
}
void Switch(int A) {
	switch (A) {
	case 1:Sortyvanna_masuva(); break;
	case 2:Vporadkyvanna_v_duapazoni(); break;
	case 3:Dii_z_masuvom(); break;
	case 4:break;
	default:Default;
	}
}