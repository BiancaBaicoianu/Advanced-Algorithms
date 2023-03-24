#include <bits/stdc++.h>

using namespace std;

struct pct{
    long long x, y;
};

long long det(pct a, pct b, pct c){
    return b.x * c.y + a.x * b.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
};

bool inDisk(pct a, pct b, pct p) {
    return ((a.x - p.x) * (b.x - p.x) + (a.y - p.y) * (b.y - p.y)) <= 0;
}

// numar intersectii cu muchii, daca avem intersectie cu un varf, numaram de 2 ori
long long intersectie(vector<pair<pct, pct>>& segm, pct p){
    long long nr = 0;

    for(auto& s : segm){
        // calculam determinantul
        long long d = det(s.first, s.second, p);
        
        if(d == 0 && inDisk(s.first, s.second, p)) 
            return -1;  // BOUNDARY

        if(s.first.y > s.second.y){ 
            if(d < 0 && (s.second.y < p.y && p.y <= s.first.y)){ //viraj la dreapta
                nr++;
            }
        }
        if(s.first.y < s.second.y){ 
            if(d > 0 && (s.first.y < p.y && p.y <= s.second.y)){ // viraj la stanga
                nr++;
            }
        }
    }

    return nr;
}

int main()
{
    int n, m;
    pct p, pct_curent, start;
    vector<pair<pct, pct>> segm;

    cin >> n;
    cin >> start.x >> start.y;  // primul punct
    
    pct_curent = start;
    
    for(int i = 1; i <= n - 1; ++i){
        cin >> p.x >> p.y;
        segm.push_back({pct_curent, p});    // in lista vom avea perechi continand capetele unui segment
        pct_curent = p;
    }
    
    segm.push_back({pct_curent, start}); // segm intre primul si ultimul nod

    cin>>m;
    
    for(int i = 1; i <= m; ++i){
        cin >> p.x >> p.y;
        long long sol = intersectie(segm, p);
        
        if(sol < 0)
            cout << "BOUNDARY" << endl;
        
        else 
            if(sol % 2 == 1) //impar => INSIDE
                cout << "INSIDE" << endl;
              
            else
                cout << "OUTSIDE" << endl;
            
    }

return 0;
}