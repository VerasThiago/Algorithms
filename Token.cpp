#include <bits/stdc++.h>
using namespace std;

int main (){
    string a;
    getline(cin,a);
    a+=' ';
    stringstream ss(a);
    int cont = 0;
    for(int i = 0 ; i < a.size() ; i++)
        if(a[i] == ' ')
            cont++;
    vector<string> v(cont);
    int i = 0;
    while (getline(ss, a, ' ')) {
        v[i++] = a;
    }
    for(int i = 0 ; i < cont ; i++)
        cout << v[i] << endl;
}
