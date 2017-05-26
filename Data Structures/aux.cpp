#include <bits/stdc++.h>
using namespace std;

bool ok(double a , double b){
    return fabs(a-b) < 0.0001;
}

int main() {
    int n, quero;
    while(cin >> n >> quero){
        if(n == 0 and quero == 0) return 0;
        vector<double> v(n);
        double L = 0 , R = 0;
        int total2 = 0;
        for(int i = 0 ; i < n ; i++){
            cin >> v[i];
            total2 += v[i];
            R = max(R,v[i]);
        }
        //cout << "L e R vale " << L << " " << R << endl;       
        bool penis = true;
        double mid;
        if(total2 == quero)
            cout << ":D" << endl;
        else{
            for(int j = 0 ; j <= 100 ; j++){
                double total = 0;
                mid = (L+R)/2;
                for(int i = 0 ; i < n ; i++) total += max(0.0,v[i]-mid );
                if(ok(total,quero)){
                    penis = false;
                    printf("%.4lf\n",mid);
                    break;
                }
                else if(total > quero)
                    L = mid;
                else
                    R = mid;
            }
            if(penis)
                cout << "-.-" << endl;
        }
    }        
}
