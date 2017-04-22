#include <bits/stdc++.h>
using namespace std;

bool palindrome(string a){
    int n = a.size();
    for(int i = 0 ; i < n/2; i++)
        if(a[i] != a[n-1-i])
            return false;
    return true;    
}

int main (){
    string a;
    while(cin >> a){
        int x = a.size()-1; 
        if(palindrome(a))
            cout << a << endl;
        else{
            int big = 0;
            string aux = "";
            for(int i = a.size()-1; i >= 0; i--){
                aux += a[i];
                if(palindrome(aux)){
                   // cout << aux << " EH PALINDROMO" << endl;
                    int l = aux.size();
                    big = max(big,l);
                    //cout << "big vale " << big << endl;
                }
            }
            cout << a;
            for(int i = x - big; i >= 0 ; i--)
                cout << a[i];
            cout << endl;
        }
    }
}
