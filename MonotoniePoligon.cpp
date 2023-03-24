#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,x,y;
    vector<pair<int,int>> varfuri;
    // citim nr de puncte si perechile(abscisa, ordonata)
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        varfuri.push_back({x,y});
    }
    
    int nr_pct_inflexiune = 0;
    
    // x-monoton
    // comparam abscisele, numaram acolo unde se 'schimba directia'(pct de inflexiune)
    for(int i = 2; i < n; i++){
        if(varfuri[i].first > varfuri[i-1].first && varfuri[i-1].first < varfuri[i-2].first || 
            varfuri[i].first < varfuri[i-1].first && varfuri[i-1].first > varfuri[i-2].first )
            nr_pct_inflexiune++;
    }
    
    // daca sunt mai mult de 2 pct de inflexiune => nu este monoton
    if(nr_pct_inflexiune > 2)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
        
    nr_pct_inflexiune = 0;
    
    // y-monoton
    // idem ca la x-mnoton, dar comparam ordonatele
    for(int i = 2; i < n; i++){
        if(varfuri[i].second > varfuri[i-1].second && varfuri[i-1].second < varfuri[i-2].second || 
            varfuri[i].second < varfuri[i-1].second && varfuri[i-1].second > varfuri[i-2].second )
            nr_pct_inflexiune++;
    }
    
    if(nr_pct_inflexiune > 2)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;

    return 0;
}