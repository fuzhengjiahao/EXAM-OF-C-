#include <iostream>
#include "exam.h"

using namespace std;

int main()
{
    int value = 0, n = 0;
    double PMT = 0.0, PV = 0.0, r = 0.0;

//PROVIDING VALUES
    cout << "First,please input numbers of 1,2,3,4" << endl;
    cout << "1:PMT  2:PV  3:n  4:r" << endl;
    cout << "value to be computed : "; cin >> value;
    while (value != 1 && value != 2 && value != 3 && value != 4) {
        cout << "You should select and input 1, 2, 3 or 4! Please input: "; cin >> value;
    }

    cout << "Second, Please input the other three values: " << endl;
    if (1 != value) {
        cout << "PMT : "; cin >> PMT;
        checkDouble(PMT, "PMT");
    }
    if (2 != value) {
        cout << "PV : "; cin >> PV;
        checkDouble(PV, "PV");
    }
    if (3 != value) {
        cout << "n : "; cin >> n;
        checkInt(n, "n");
    }
    if (4 != value) {
        cout << "r (i.e. 5.0 means 5.0%): "; cin >> r;
        checkDouble(r, "r");
        r /= 100;
    }

    cout << endl;
    if (1 != value) cout << "PMT = " << PMT << endl;
    if (2 != value) cout << "PV = " << PV << endl;
    if (3 != value) cout << "n = " << n << endl;
    if (4 != value) cout << "r = " << r * 100 << "%" << endl;

    if (1 == value) {
        PMT = calcPMT(n, PV, r);
        cout << "PMT : " << PMT;
    }
    if (2 == value) {
        PV = calcPV(PMT, n, r);
        cout << "PV = " << PV;
    }
    if (3 == value) {
        n = calcN(PMT, PV, r);
        cout << "n = " << n;
    }
    if (4 == value) {
        r = calcR(PMT, n, PV);
        cout << "r = " << r * 100 << "%";
    }
    return 0;
}
