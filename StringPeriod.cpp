#include <bits/stdc++.h>
using namespace std;
vector<int> strong_borders(const string& pat){
    int m = pat.size();
    vector<int> sbord(m);
    int t = -1;
    sbord[0] = 0;

    for (int j = 1; j < m; ++j){ 
        while( (t > -1) and pat[t+1] != pat[j]){
            t = sbord[t]-1;
        }
        if( pat[t+1] == pat[j])
            t++;
       
        sbord[j] = t+1;
    }
    return sbord;
}


int period(const string& a){
    string aux = a;
    aux += aux;
    int m = aux.size();
    int ans;
    vector<int> v = strong_borders(aux);
    
    for(int i = 0 ; i < aux.size(); i++)
        if(v[i] >= m/2){            
            ans = i - v[i] + 1;
            return ans;
        }
    
}

int main (){
    string a , b;
    cin >> a;
    vector<int> v=  strong_borders(a);
    for(int i = 0 ; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    cout << "The period is " << period(a) << endl;
}
