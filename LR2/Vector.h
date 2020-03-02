//
//  Vector.h
//  LR2
//
//  Created by Роберт Артур Меликян on 22/02/2020.
//  Copyright © 2020 Роберт Артур Меликян. All rights reserved.
//

#ifndef Vector_h
#define Vector_h

#include <iostream>
#include <fstream>
using namespace std;

class Vector{
    double *p;
    int n;
public:
    Vector();
    Vector(double *p,int n);
    Vector(const Vector &v);//Конструктор копирования
    Vector(Vector&& v);//Конструктор перемещения
    double operator *(Vector& v2);
    double& operator [](int i);
    Vector& operator =(Vector & v2);
    friend ostream& operator<<(ostream& out,Vector& v);
    friend istream& operator>>(istream& in,Vector& v);
    friend ofstream& operator<<(ofstream& fout,Vector& v);
    friend ifstream& operator>>(ifstream& fin,Vector& v);
};

#endif /* Vector_h */
