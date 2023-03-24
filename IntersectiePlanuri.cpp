#include <iostream>
#include <vector>

using namespace std;

struct semiplan{ // ec semiplan: ax + by + c <= 0
    double a,b,c;
};

int intersectie(vector<semiplan>& semiplane) {
    double maxX = 9999999999, maxY = 9999999999;
    double minX = -9999999999, minY = -9999999999;

    for (auto& semiplan : semiplane) {
        double st = -9999999999;
        double dr = 9999999999;
        if (semiplan.a == 0) { // semiplan vertical
            if (semiplan.b < 0) {
                st = -1 * semiplan.c / semiplan.b;
            } else {
                dr = -1 * semiplan.c / semiplan.b;
            }

        } else { // semiplan orizontal
            if (semiplan.a < 0) {
                st = -1 * semiplan.c / semiplan.a;
            } else {
                dr = -1 * semiplan.c / semiplan.a;
            }
        }

        if (semiplan.a == 0) { // semiplan vertical
            if(st > minY)
                minY = st;
            if(dr < maxY)
                maxY = dr;
        }
        else { // semiplan orizontal
            if(st > minX)
                minX = st;
            if(dr < maxX)
                maxX = dr;
        }
    }

    if (minY > maxY || minX > maxX) {
        return 0; // intersectie vida
    }
    else
        if ((minX != -9999999999 && maxX != 9999999999) && (minY != -9999999999 && maxY != 9999999999)) {
            return 1; // intersectia nevida, marginita
    }
        else {
        return 2; // intersectia nevida, nemarginita
    }
}


int main() {
    int m;
    cin >> m;
    vector<semiplan> semiplane;
    for(int i = 0; i<m; i++){
        semiplan s;
        cin >> s.a >> s.b >> s.c;
        semiplane.push_back(s);
    }
    int rez = intersectie(semiplane);
    if(rez == 0){
        cout << "VOID" <<endl;
    }
    else
        if(rez == 1){
            cout << "BOUNDED" << endl;
        }
        else{
            cout << "UNBOUNDED" << endl;
        }
    return 0;
}
