#ifndef EXAM_H
#define EXAM_H

#include <iostream>
#include <cmath>

//This is the main code of calculating function on PMT,PV,N,r.
//We use Secant method to optimize and get r.

using namespace std;

//calculating PMT
double calcPMT(int n, double PV, double r) {
    double pmt = 0.0;
    pmt = PV * r * (1 + 1 / (pow((1 + r), n) - 1));
    return pmt;
}

//calculatng PV
double calcPV(double PMT, int n, double r) {
    double PV = 0.0;
    PV = PMT / (r * (1 + 1 / (pow((1+r), n) - 1)));
    return PV;
}

//calculating N
double calcN(double PMT, double PV, double r) {
    double temp = 0;
    temp = (PMT / PV) / r - 1;
    temp = 1 / temp + 1;
    temp = log(temp) / log (1 + r);
    return temp;
}

//equation contain 4 variables
double f(double PMT, double PV, int n, double r) {
    double temp;
    temp = r * (1 + (1 / (pow((1 + r), n) - 1)));
    temp -= (PMT / PV);
    return temp;
}

//calculating r
double calcR(double PMT, int n, double PV) {
    double r = 0.1, temp;
    double rNext = 0.95*r;

    //Secant algorithm
    while (abs(f(PMT, PV, n, rNext)) > 0.000001){
        temp = rNext;
        rNext = rNext - (f(PMT, PV, n, rNext)*(rNext - r))/(f(PMT, PV, n, rNext)-f(PMT, PV, n, r));
        r = temp;
    }

    return r;
}

void checkDouble(double& value, string name) {
    while (value < 0) {
        cout << name << " can't be negative! " << name << " : "; cin >> value;
    }
}

void checkInt(int& value, string name) {
    while (value < 0) {
        cout << name << " can't be negative! " << name << " : "; cin >> value;
    }
}

#endif // EXAM_H_INCLUDED
