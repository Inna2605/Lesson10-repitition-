/*1. Написати програму, що виконує сортування одновимірного масиву цілих чисел методом бульбашкового сортування.
2. Написати програму, що виконує сортування одновимірного масиву цілих чисел методом вставок.
3. Написати програму «успіхи». Користувач вводить 10 оцінок студента. Реалізувати меню для користувача:
■ Вивід оцінок (вивід вмісту масиву);
■ Перездача іспиту (користувач вводить номер елемента масиву й нову оцінку);
■ Чи виходить стипендія (стипендія виходить, якщо середній бал є не нижчим за 10.7).
4. Написати програму, що виконує сортування одновимірного масиву цілих чисел методом швидкого пошуку.
5. Необхідно відсортувати перші дві третини масиву в порядку зростання 
якщо середнє арифметичне всіх елементів більше нуля; інакше — лише першу третину. 
Іншу частину масиву не сортувати, а розташувати у зворотному порядку*/

#include<iostream>
#include<stdlib.h>
#include<time.h>
#define Vvod(A)cin>>A;
#define Show(A)cout<<A;
#define Default cout<<"Ne virno zroblenui vubir!";

using namespace std;

void Vubir_zadachi();
void Switch_zadach(int A);
void Random();
void Randomnui_masuv(int Ar[], int N);
void Show_masuv(int Ar[], int N);

void Bylbaskove_sortuvanna();
void Bulbaska(int Ar[], int N);

void Vstavku(int Ar[], int N);
void Sortyvanna_vstavkamu();

void Peresdacha(int Ar[], int N);
void Vvod_ocinok(int Ar[], int N);
void Ocinku_ychna(int Ar[], int N);
void Svitch_yspixu(int A, int Ar[], int N);
void Menu();
void Yspixu();

void Sortyvanna_svudkum_posykom();
void Svudkui_poshyk(int Ar[], int N);

void Rizne_sortyvanna_masuvy();

int main() {
	int a = 0;
	while (true) {
		if (a == 6)break;
		Vubir_zadachi();
		Vvod(a);
		Switch_zadach(a);
		Show('\n');
	}
}
float Seredne_arufmetuchne(int Ar[], int N) {
	int Sum = 0;
	for (int i = 0; i < N; i++) {
		Sum += Ar[i];
	}
	return (float)Sum / N;
}
void Rizne_sortyvanna_masuvy() {
	/*5. Необхідно відсортувати перші дві третини масиву в порядку зростання 
      якщо середнє арифметичне всіх елементів більше нуля; інакше — лише першу третину. 
      Іншу частину масиву не сортувати, а розташувати у зворотному порядку*/
	const int N = 21;
	int Ar[N];
	int y;
	Randomnui_masuv(Ar, N);
	Show_masuv(Ar, N);
	float Sa = Seredne_arufmetuchne(Ar, N);
	cout << "\nYmova:\nYakso seredne arufmetuchne bilse nyla,\nza zrostannam persi dvi tretnnu,\ninakse - odny tretuny."
		<< "\nOstanny chastuny - y zvorotnomy poradky\n\n";
	cout << "\nSeredne arufmetuchne = ";
	Show(Sa);
	Show('\n');
	cout << "\nZa ymovoiy vidozminenui masuv\n";
	if (Sa > 0) {
		//bylbaska
		//za zrostannam dvi persi tretunu
		Bulbaska(Ar, ((N / 3) + (N / 3)));
	}
	else {
		//vuborka
		//za zrostannam persy tretunu
		Svudkui_poshyk(Ar, N/3);
	}
	// y zvorotnomy poradky
	y = N - 1;
	int x, n = 0;
	for (int l = ((N / 3) + (N / 3)); l < (N - 1); l++) {
		if (n == ((N / 3) / 2))break;
		x = Ar[y];
		Ar[y] = Ar[l];
		Ar[l] = x;
		y--;
		n++;
	}
	Show_masuv(Ar, N);
	Show('\n');
}
void Svudkui_poshyk(int Ar[], int N) {
	int min, n;
	for (int k = 0; k < N; k++) {
		n = k;
		min = Ar[k];
		for (int i = k + 1; i < N; i++) {
			if (Ar[i] <= min) {
				min = Ar[i];
				n = i;
			}
		}
		if (n != k) {
			Ar[n] = Ar[k];
			Ar[k] = min;
		}
	}
}
void Sortyvanna_svudkum_posykom() {
	//4. Написати програму, що виконує сортування одновимірного масиву цілих чисел методом швидкого пошуку.
	const int N = 20;
	int Ar[N];
	Randomnui_masuv(Ar, N);
	Show_masuv(Ar, N);
	cout << "\nMasuv vidsortovanui metodom svudkogo posyky:\n";
	Svudkui_poshyk(Ar, N);
	Show_masuv(Ar, N);
	Show('\n');
}

void Vvod_ocinok(int Ar[], int N) {
	for (int i = 0; i < N; i++) {
		cin >> Ar[i];
	}
}
void Peresdacha(int Ar[], int N) {
	int E, O;
	cout << "Vvedite nomer elementa ta novy ocinky: ";
	Vvod(E);
	Vvod(O);
	Show('\n');
	for (int i = 0; i < N; i++) {
		if (i == E - 1) {
			Ar[i] = O;
		}
	}
	Show_masuv(Ar, N);
	Show('\n');
}
void Ocinku_ychna(int Ar[], int N) {
	cout << "Vvedite ocinku ychna:\n";
	Vvod_ocinok(Ar, N);
}
void Stependia(int Ar[], int N) {
	int Sum = 0;
	for (int i = 0; i < N; i++) {
		Sum += Ar[i];
	}
	if ((float)Sum / N >= 10.7) {
		cout << "Student mae stupendiy\n";
	}
	else 
		cout << "Student ne mae stupendiy\n";
	Show('\n');
}
void Svitch_yspixu(int A, int Ar[], int N) {
	switch (A) {
	case 1:Show_masuv(Ar, N); break;
	case 2:Peresdacha(Ar, N); break;
	case 3:Stependia(Ar, N); break;
	case 4:Svudkui_poshyk(Ar, N); break;
	case 5:Sortyvanna_svudkum_posykom(); break;
	case 6:break;
	default:Default;
	}
}
void Menu() {
	cout << "\nOberute diy:\n"
		<< "1. Vuvid ocinok\n"
		<< "2. Peresdacha\n"
		<< "3. Stupendia\n"
		<< "4. Svudkui posyk\n"
		<< "5. Rizne sortyvannam asuvy\n"
		<< "6. Vuhid\n";
}
void Yspixu() {
	/*3. Написати програму «успіхи». Користувач вводить 10 оцінок студента. Реалізувати меню для користувача:
      ■ Вивід оцінок (вивід вмісту масиву);
      ■ Перездача іспиту (користувач вводить номер елемента масиву й нову оцінку);
      ■ Чи виходить стипендія (стипендія виходить, якщо середній бал є не нижчим за 10.7).*/
	int a = 0;
	const int N = 10;
	int Ar[N];
	Ocinku_ychna(Ar, N);
	while (a != 4) {
		Menu();
		Vvod(a);
		Svitch_yspixu(a, Ar, N);
		Show('\n');
	}
}
void Posyk_minimalnogo(int Ar[], int N) {
	int min = Ar[0];
	for (int i = 0; i < N; i++) {
		if (Ar[i] < min) {
			min = Ar[i];
		}
	}
	Ar[0] = min;
}
void Vstavku(int Ar[], int N) {
	int x, i, j;
	int y = Ar[0];
    Posyk_minimalnogo(Ar, N);
	for (i = 1; i < N; i++) {
		x = Ar[i];
		for (j = i - 1; Ar[j] > x; j--) {
			Ar[j + 1] = Ar[j];
		}
		Ar[j + 1] = x;
	}
	for (j = 1; j < N && Ar[j] < y; j++) {
		Ar[j - 1] = Ar[j];
	}
	Ar[j - 1] = y;
}
void Sortyvanna_vstavkamu() {
	//2. Написати програму, що виконує сортування одновимірного масиву цілих чисел методом вставок.
	const int N = 20;
	int Ar[N];
	Randomnui_masuv(Ar, N);
	Show_masuv(Ar, N);
	Show('\n');
	Vstavku(Ar, N);
	Show_masuv(Ar, N);
	Show('\n');
}
void Bulbaska(int Ar[], int N) {
	int r;
	for (int i = 0; i < N; i++) {
		for (int j = N - 1; j > i; j--) {
			if (Ar[j - 1] > Ar[j]) {
				r = Ar[j - 1];
				Ar[j - 1] = Ar[j];
				Ar[j] = r;
			}
		}
	}
}
void Bylbaskove_sortuvanna() {
	//1. Написати програму, що виконує сортування одновимірного масиву цілих чисел методом бульбашкового сортування.
	const int N = 20;
	int Ar[N];
	Randomnui_masuv(Ar, N);
	Show_masuv(Ar, N);
	Show('\n');
	Bulbaska(Ar, N);
	Show_masuv(Ar, N);
	Show('\n');
}
void Show_masuv(int Ar[], int N) {
	for (int i = 0; i < N; i++) {
		Show(Ar[i]);
		Show(' ');
	}
	Show('\n');
}
void Randomnui_masuv(int Ar[], int N) {
	Random();
	for (int i = 0; i < N; i++) {
		Ar[i] = rand() % 50 - 25;
	}
}
void Random() {
	srand(time(NULL));
}
void Switch_zadach(int A) {
	switch (A) {
	case 1:Bylbaskove_sortuvanna(); break;
	case 2:Sortyvanna_vstavkamu(); break;
	case 3:Yspixu(); break;
	case 4:Sortyvanna_svudkum_posykom(); break;
	case 5:Rizne_sortyvanna_masuvy(); break;
	case 6:break;
	default:Default;
	}
}
void Vubir_zadachi() {
	cout << "Oberite zadachy:\n"
		<< "1. Bylbaskove sortuvanna\n"
		<< "2. Sortyvanna vstavkamu\n"
		<< "3. Yspixu\n"
		<< "4. Sortyvanna svudkum posykom\n"
		<< "5. Rizne sortyvanna masuvy\n"
		<< "6. Vuxid\n";
}