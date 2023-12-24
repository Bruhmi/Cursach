#include <iostream>
#include <cstdlib>

using namespace std;

int Practice1();
int Practice2();
int Practice3();
int Practice4();

int main() {
	system("chcp 1251");
	setlocale(LC_ALL, "ru");
	int lab = 1;
	while (lab != 0) {
		system("CLS");  
		cout << 
			"Выберете практическую работу: " << endl
			<< "1. Practice1" << endl << "2. Practice2" << endl
			<< "3. Practice3" << endl << "4. Practice4" << endl
			<< "0. Завершить работу программы" << endl;  cin >> lab;
		switch (lab) {
		case 1:
			Practice1();
			break;
		case 2: 
			Practice2(); 
			break;
		case 3:
			Practice3(); 
			break;
		case 4:
			Practice4(); 
			break;
		case 0:
			lab = 0;
			break;
		default:
			cout << "Такой практической работы нет\n";   
			system("Pause");
			break;
		}
	}
}