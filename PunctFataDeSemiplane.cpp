#include <bits/stdc++.h>

using namespace std;
struct semiplan {
    double a, b, c;
};
struct punct {
    double x, y;
};

double intersectie(vector<semiplan> semiplane, punct q) {
    double maxX = 9999999999, maxY = 9999999999;
    double minX = -9999999999, minY = -9999999999;


    for (auto s: semiplane) {

        if (s.a == 0) {
            if (s.c + s.b * q.y >= 0)
                continue;
        } else {
            if (s.c + s.a * q.x >= 0)
                continue;
        }

        //semiplanul este vertical
        if (s.a == 0) {
            double aux = (-1) * s.c / s.b;
            if (aux < q.y) {
                minY = max(minY, aux);
            } else {
                maxY = min(maxY, aux);
            }
        } else {
            double aux = (-1) * s.c / s.a;
            if (aux < q.x) {
                minX = max(minX, aux);
            } else {
                maxX = min(maxX, aux);
            }
        }

    }
    if (max(maxX, maxY) == 9999999999 || min(minX, minY) == -9999999999) {
        return 0;
    }
    return (maxX - minX) * (maxY - minY);
}

int main() {
    double n, m;
    cin >> n;
    vector<semiplan> semiplane;
    for (double i = 0; i < n; i++) {
        semiplan s;
        cin >> s.a >> s.b >> s.c;
        semiplane.push_back(s);
    }
    cin >> m;
    for (double i = 0; i < m; i++) {
        punct q;
        cin >> q.x >> q.y;
        double rez = intersectie(semiplane, q);
        if (rez == 0)
            cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            cout<<setprecision(6)<<fixed<<rez<< endl;
        }
    }
    return 0;
}