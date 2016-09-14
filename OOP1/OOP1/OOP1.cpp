#include "stdafx.h"
#include <iostream>
#include "Vector.h"
using namespace std;

float Vector::Modul(){
	float modul;
	int dlina[2];
	dlina[1]= Vector::pointB[1] - Vector::pointB[0];
	dlina[0]= Vector::pointA[1] - Vector::pointA[0];
	modul = sqrt((dlina[0]*dlina[0])+(dlina[1]*dlina[1]));
	return modul;
}

int Vector::Skalar(Vector &V2){
	int result;
	result = Vector::dlinaV[0] * V2.dlinaV[0] + Vector::dlinaV[1] * V2.dlinaV[1];
	return result;
}

void Vector::CollOrOrto(Vector &V2){
	setlocale (LC_CTYPE, "Russian");
	if(Vector::dlinaV[1]/Vector::dlinaV[0] == V2.dlinaV[1]*pow(V2.dlinaV[0],-1))
		cout << "\n коллиниарны ";
	else if(Vector::Skalar(V2) == 0 )
		cout << "\n ортогональны ";
	else cout << "  ни те, ни другие  ";
}

void Vector::viewVector(){
	cout << " { " << dlinaV[0] << " , " << dlinaV[1] << " } ";
}

void Vector::enterVector(){
	cout << "point 1 : x = "; cin >> Vector::pointA[0];
	cout << "point 1 : y = "; cin >> Vector::pointB[0];
	cout << "point 2 : x = "; cin >> Vector::pointA[1];
	cout << "point 2 : y = "; cin >> Vector::pointB[1];
	dlinaV[1] = Vector::pointB[1] - Vector::pointB[0]; dlinaV[0] = Vector::pointA[1] - Vector::pointA[0];
}

void Vector::ONEplusONE(Vector &V2){
	cout << "\n { " << Vector::dlinaV[0] + V2.dlinaV[0] << " , " <<  Vector::dlinaV[1] + V2.dlinaV[1] << " } ";
}

void Vector::ONEminsONE(Vector &V2){
	cout << "\n { " << Vector::dlinaV[0] - V2.dlinaV[0] << " , " <<  Vector::dlinaV[1] - V2.dlinaV[1] << " } ";
}

int Vector::sumelements(){
	int result;
	result = Vector::dlinaV[0] + Vector::dlinaV[1];
		return result;
}

const void Vector::ConstProizv(){
	Vector::dlinaV[1] *= Vector::con;
	Vector::dlinaV[0] *= Vector::con;
	Vector::viewVector();
}

