#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
struct punct{
    long long x, y;
    friend bool operator<(const punct& a, const punct& b);
    friend punct operator-(const punct& a, const punct& b);
    friend long long operator*(const punct& a, const punct& b);
};


bool operator<(const punct& a, const punct& b) {
    if(a.x < b.x){
        return true;
    }else if(a.x == b.x){
        return a.y < b.y;
    }else{
        return false;
    }
}

punct operator-(const punct& a, const punct& b){
    punct newPoint;
    newPoint.x = a.x - b.x;
    newPoint.y = a.y - b.y;
    return newPoint;
}

long long operator*(const punct& a, const punct& b){
    return a.x * b.y - a.y * b.x;
}

long long dot(const punct& a, const punct& b){
    return a.x * b.x + a.y * b.y;
}


bool inDisk(punct a, punct b, punct q) {
    long long dp = dot((a - q), (b - q));
    return dp <= 0;
}

short testPoint(punct a, punct b, punct c){
    long long sol = (a - c) * (b - c);
    if(!sol) return 0;
    else return sol < 0 ? (-1) : 1; ///1 = right, -1 = left
}

int findPointBS(const vector<punct>& lista, const punct q){
    int left = 1, right = n - 1;
    int rez = 0;
    while(left <= right){
        int mij = left + (right - left) / 2;
        short testbs = testPoint(q, lista[mij], lista[0]);
        if(testbs >= 0) right = mij - 1;
        else{
            left = mij + 1;
            rez = mij;
        }
    }
    return rez;
}

int findMinimum(const vector<punct>& lista){
    punct minim = lista[0]; int poz = 0;

    for(int i = 1; i < n; ++i){
        if(lista[i] < minim){
            minim = lista[i];
            poz = i;
        }
    }

    return poz;
}

short verifyNode(const vector<punct>& lista, const punct q){
    short test1 = testPoint(q, lista[1], lista[0]);
    short test2 = testPoint(q, lista[n - 1], lista[0]);
    bool disk1 = inDisk(lista[0], lista[1], q), disk2 = inDisk(lista[0], lista[n - 1], q);

    if(test1 > 0 || test2 < 0) return 1;
    if((test1 == 0 && disk1) || (test2 == 0 && disk2)) return 0;

    int poz = findPointBS(lista, q);
    short test3 = testPoint(q, lista[poz + 1], lista[poz]);

    return test3;
}

void cleanData(vector<punct>& lista){
    int poz = 0;
    for(int i = 1; i <= n; ++i){
        if(lista[0].y == lista[i].y){
            poz = i;
        }else{
            break;
        }
    }
    if(poz) lista.erase(lista.begin() + 1, lista.begin() + poz);
    n = lista.size();

    poz = 0;
    for(int i = n - 2; i >= 0; i--){
        if(lista[n - 1].x == lista[i].x){
            poz = i;
        }else{
            break;
        }
    }
    if(poz) lista.erase(lista.begin() + poz + 1, lista.end());
    n = lista.size();
}

int main()
{
    punct a, q;
    vector<punct> lista;

    cin>>n;
    for(int i = 1; i <= n; ++i){
        cin>>a.x>>a.y;
        lista.push_back(a);
    }

    rotate(lista.begin(), lista.begin()+findMinimum(lista), lista.end());
    cleanData(lista);

    cin>>m;
    for(int i = 1; i <= m; ++i){
        cin>>q.x>>q.y;
        short sol = verifyNode(lista, q);
        if(!sol) cout<<"BOUNDARY"<<endl;
        else sol < 0 ? cout<<"INSIDE"<<endl : cout<<"OUTSIDE"<<endl;
    }
    return 0;
}
