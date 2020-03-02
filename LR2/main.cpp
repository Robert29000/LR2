//
//  main.cpp
//  LR2
//
//  Created by Роберт Артур Меликян on 22/02/2020.
//  Copyright © 2020 Роберт Артур Меликян. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Vector.h"

using namespace std;

int main(int argc, const char * argv[]) {
    int n = 5;
    double *arr = new double[n];
    for(int i = 0 ; i < n;i++){
        arr[i] = (i+1)*(i+1);
    }
    Vector v2(arr,n);
    Vector v1;
    ifstream fin("input.txt");
    fin >> v1;
    cout << v1;
    ofstream fout("output.txt");
    fout << v1 * v2;
    return 0;
}
