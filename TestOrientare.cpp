#include <iostream>
using namespace std;

int main() {
    long long i,t, xp ,yp ,xq ,yq ,xr ,yr, val_det;
    
    cin >> t;
    
    for(i = 1; i <= t; i++){
    
        cin >> xp >> yp >> xq >> yq >> xr >> yr;
        //  1   1   1 
        //  xp  xq  xr
        //  yp  yq  yr
        
        val_det = xq*yr + xp*yq + xr*yp - yp*xq - yq*xr - xp*yr;
    
        // calculam natura virajului
        if (val_det == 0)
            cout << "TOUCH" << endl;
        else if (val_det < 0)
            cout << "RIGHT" << endl;
        else
            cout << "LEFT" << endl;
    }
    
    return 0;
}