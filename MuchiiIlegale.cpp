#include <iostream>
#include <cmath>

using namespace std;

struct pct {
    double x, y;
};

// functie care calculeaza distanta dintre 2 puncte
double dist(pct p1, pct p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

int insideCircle(pct A, pct B, pct C, pct D) {

    //lungimile laturilor triunghiului ABC
    double BC = dist(B, C);
    double AC = dist(A, C);
    double AB = dist(A, B);

    //Formula 2(A.x *(B.y-C.y) + B.x *(C.y-A.y)+ C.x*(A.y-B.y))
    double d = 2 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));

    //coordonate centru cerc
    double x = ((A.x*A.x+A.y*A.y)*(B.y-C.y)+(B.x*B.x+B.y*B.y)*(C.y-A.y)+(C.x*C.x+C.y*C.y)*(A.y-B.y))/d;
    double y = ((A.x*A.x+A.y*A.y)*(C.x-B.x)+(B.x*B.x+B.y*B.y)*(A.x-C.x)+(C.x*C.x+C.y*C.y)*(B.x-A.x))/d;

    pct CC;
    CC.x = x;
    CC.y = y;

    //raza cercului
    double r = (AB*BC*AC) / abs(d);
    //    r=a*b*c/4Aria
    //    Formula lui Heron pt arie NU merge pe echilateral si isoscel:
    //    Aria=sqrt(p(a-b)(a-c)(b-c)
    //    p=(a+b+c)/2

    //distanta dintre punctul D si centrul cercului
    double distanta = dist(CC, D);

    //daca distanta este mai mica decat raza, atunci punctul D este in interiorul cercului
    if (abs(distanta*100) == abs(r*100))
        return 0; // punctul D este pe cerc
    if (distanta < r) {
        return -1; // punctul D este in interiorul cercului
    }
    else {
        return 1; // punctul D este in exteriorul cercului
    }
}

int main() {
    pct A,B,C,D;

    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cin >> D.x >> D.y;

    if (insideCircle(A, B, C, D) == -1)
        cout << "AC: ILLEGAL" << endl;
    else
        cout<< " AC: LEGAL" << endl;

    if (insideCircle(A, B, D, C) == -1)
        cout << "BD: ILLEGAL" << endl;
    else
        cout<< "BD: LEGAL" << endl;

    return 0;
}
