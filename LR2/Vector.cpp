//
//  Vector.cpp
//  LR2
//
//  Created by Роберт Артур Меликян on 22/02/2020.
//  Copyright © 2020 Роберт Артур Меликян. All rights reserved.
//

#include <stdio.h>
#include "Vector.h"

Vector::Vector(){
    this->n = 0;
    this->p = nullptr;
}

Vector::Vector(double *p,int n){
    this->n = n;
    this->p = new double[n];
    for(int i = 0;i < n;i++){
        this->p[i] = p[i];
    }
}

Vector::Vector(const Vector & v){
    this->n = v.n;
    this->p = new double[n];
    for(int i = 0;i < n;i++){
        this->p[i] = v.p[i];
    }
}

Vector::Vector(Vector&& v){
    this->n = v.n;
    this->p = v.p;
    v.n = 0;
    v.p = nullptr;
}

double& Vector::operator[](int i){
    return p[i];
}

Vector& Vector::operator =(Vector &v2){
    this->n = v2.n;
    p = new double[n];
    for(int i = 0 ; i < this-> n ; i++){
        this->p[i] = v2[i];
    }
    return *this;
}

double Vector::operator*(Vector &v2){
    double rez = 0;
    for(int i = 0; i < this->n ; i++){
        rez += this->p[i] * v2[i];
    }
    return rez;
}

std::ostream& operator<<(ostream& out,Vector& v){
    out << "Кол-во элементов " << v.n << endl;
    for(int i = 0 ; i < v.n ; i++){
        out << v[i] << " ";
    }
    out << endl;
    return out;
}

std::istream& operator>>(istream& in,Vector& v){
    in >> v.n;
    if(v.p == nullptr){
        v.p = new double[v.n];
    }
    for(int i = 0 ; i < v.n ; i++){
        in >> v[i];
    }
    return in;
}

std::ofstream& operator<<(ofstream& fout,Vector& v){
    fout << "Кол-во элементов " << v.n << endl;
    for(int i = 0 ; i < v.n ; i++){
        fout << v[i] << " ";
    }
    fout << endl;
    return fout;
}

std::ifstream& operator>>(ifstream& fin,Vector& v){
    fin >> v.n;
    fin.ignore();
    if(v.p == nullptr){
        v.p = new double[v.n];
    }
    for(int i = 0 ; i < v.n ; i++){
        fin >> v[i];
    }
    return fin;
}
