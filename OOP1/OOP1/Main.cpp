#include "stdafx.h"
#include <iostream>
#include "Vector.h"
const int indexForMass = 10;
Vector obj[indexForMass];
int colVectors = 0;
using namespace std;



void main(){
	setlocale (LC_CTYPE, "Russian");
	Vector obj1(1,2,3,4);
	cout << " (для демонстрации конструктора с параметрами) "; obj1.viewVector(); cout << endl;
	int indexformenu;
	int n, n2, allObjs[indexForMass], mod, min, max, minI = 0, maxI = 0;
	bool exit = false;
	for(;;){
		cout << "\n 1 - новый вектор ";
		cout << "\n 2 - просмотреть вектор ";
		cout << "\n 3 - просмотреть все векторы ";
		cout << "\n 4 - модуль вектора ";
		cout << "\n 5 - скалярное произведение векторов ";
		cout << "\n 6 - коллиниарны/ортогональны ли вектора ";
		cout << "\n 7 - сложение векторов ";
		cout << "\n 8 - разность векторов ";
		cout << "\n 9 - умножить вектор на 5(константу)";
		cout << "\n 10 - найти вектора по модулю";
		cout << "\n 11 - вектора с макс/мин суммой элементов";
		cout << "\n 0 - выход \n";
		cin >> indexformenu;
		switch (indexformenu)
		{
		case 1: if(colVectors<indexForMass) {
					obj[colVectors].enterVector();
					colVectors++;
				}
				else 
					cout << "\n Нет памяти";
			break;
		case 2: cout << "\n номер вектора: ... "; cin >> n; 
			if(n <= colVectors && n > 0)
				obj[n - 1].viewVector();
			else 
				cout << "\n неверный номер ";
			break;
		case 4: cout << "\n номер вектора: ... "; cin >> n; 
			if(n <= colVectors && n > 0)
					cout << "\n" << obj[n - 1].Modul();
			else 
					cout << "\n неверный номер ";
			break;

		case 3: for(int i = 0; i < colVectors; i++)
					 obj[i].viewVector(); 
			break;
		case 5: cout << " номер вектора: ... (Vector1) "; cin >> n; 
				cout << " номер вектора: ... (Vector2) "; cin >> n2;
				if(n <= colVectors && n > 0 && n2 <= colVectors && n2 > 0)
					cout << "\n" << obj[n - 1].Skalar(obj[n2-1]);
				else 
					cout << "\n неверный номер ";
			break;
			case 6: cout << " number: ... (Vector1) "; cin >> n; 
				cout << " number: ... (Vector2) "; cin >> n2;
				if(n <= colVectors && n > 0 && n2 <= colVectors && n2 > 0)
					obj[n - 1].CollOrOrto(obj[n2-1]);
				else 
					cout << "\n неверный номер ";
			break;
		default: cout << " ?! ";
			break;
		case 0: exit = true; break;
		case 7: cout << "\n Vector1 + Vector2 \n";
				cout << " номер вектора: ... (Vector1) "; cin >> n; 
				cout << " номер вектора: ... (Vector2) "; cin >> n2;
				if(n <= colVectors && n > 0 && n2 <= colVectors && n2 > 0)
					obj[n - 1].ONEplusONE(obj[n2-1]);
				else 
					cout << "\n неверный номер ";
			break;
			case 8: cout << "\n Vector1 - Vector2 \n";
				cout << " номер вектора: ... (Vector1) "; cin >> n; 
				cout << " номер вектора: ... (Vector2) "; cin >> n2;
				if(n <= colVectors && n > 0 && n2 <= colVectors && n2 > 0)
					obj[n - 1].ONEminsONE(obj[n2-1]);
				else 
					cout << "\n неверный номер ";
			break;
			case 10: cout << "\n введите модуль: "; cin >> mod;
				for(int i = 0; i < colVectors; i++){
					if(obj[i].Modul() == mod)
						obj[i].viewVector(); cout << endl;
				   }
				break;
			case 11: for(int i = 0; i < colVectors; i++){
						allObjs[i] = obj[i].sumelements();
					 }
					 min = allObjs[0]; max = allObjs[0]; 
					 for(int i = 0; i < colVectors; i++){
						if(min > allObjs[i]){
							min = allObjs[i]; minI = i; }
						if(max < allObjs[i]){
							max = allObjs[i]; maxI = i; }
					 }
					 				obj[minI].viewVector();
									obj[maxI].viewVector();break;
			case 9: cout << "\n номер вектора: ... "; cin >> n; 
			if(n <= colVectors && n > 0)
				obj[n - 1].ConstProizv();
			else 
				cout << "\n неверный номер ";
			break;
		}
		if(exit)
			break;
	}
}
