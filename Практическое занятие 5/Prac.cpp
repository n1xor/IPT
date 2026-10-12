#include <iostream>
using namespace std;
int main()
{
	//Задание 1
	setlocale(LC_ALL, "ru");
	double X, Y;
	cout << "Введите X\n";
	cin >> X;
	cout << "Введите Y\n";
	cin >> Y;


	for (int i = 1;; i++) {
		X *= 1.1;
		if (X >= Y) {
			cout << "ФНС заинтересовалась Иваном Ивановичем на " << i << " день";
			break;
		}
	} 
	 
	
	int i = 1;
	while (X < Y) {
		X *= 1.1;
		i++;
	}
	cout << "ФНС заинтересовалась Иваном Ивановичем на " << i << " день";


	int i = 1;
	do {
		X *= 1.1;
		i++;
	} while (X < Y);
	cout << "ФНС заинтересовалась Иваном Ивановичем на " << i - 1 << " день";
}


