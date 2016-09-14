#include "stdafx.h"
#include <iostream>

class Vector{
private:
	int pointA[2];
	int pointB[2];
	int dlinaV[2];
	const static int con = 5;
public:
	void CollOrOrto(Vector &Obj);
	void enterVector();
	void viewVector();
	float Modul();
	int Skalar(Vector &Obj);
	void ONEplusONE(Vector &Obj);
	void ONEminsONE(Vector &Obj);
	const void ConstProizv();
	int sumelements();
	Vector(){}
	Vector(int a, int b, int c, int d) {pointA[0] = a; pointB[0] = b; pointA[1] = c; pointB[1] = d;dlinaV[1] = Vector::pointB[1] - Vector::pointB[0]; dlinaV[0] = Vector::pointA[1] - Vector::pointA[0];};
	Vector(const Vector&);
	~Vector(){}
} ;

