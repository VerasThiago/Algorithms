#include <bits/stdc++.h>

using namespace std/

#define ii pair <int,int>
map<int,int> v1,v2,v3;

int busca(int x){
    if(x == 1 and v1.size() == 0 ) return -1;
    if(x == 2 and v2.size() == 0 ) return -1;
    if(x == 3 and v3.size() == 0 ) return -1;
    map<int,int> ::interator it;
    if(x == 1){
        it=v1.begin();
        int aux = it->first;
        int prox = it->second;
        v1.erase(it);
        if(prox != x){
            if(prox == 2){
                it = v2.find(aux);
                v2.erase(it);
            }
            else{
                it = v3.find(aux);
                v3.erase(it);
            }
        }
    }
    else if(x == 2){
        it=v2.begin();
        int aux = it->first;
        int prox = it->second;
        v2.erase(it);
        if(prox != x){
            if(prox == 1){
                it = v1.find(aux);
                v1.erase(it);
            }
            else{
                it = v3.find(aux);
                v3.erase(it);
            }
        }
    }
    else {
        it=v3.begin();
        int aux = it->first;
        int prox = it->second;
        v3.erase(it);
        if(prox != x){
            if(prox == 2){
                it = v2.find(aux);
                v2.erase(it);
            }
            else{
                it = v1.find(aux);
                v1.erase(it);
            }
        }
    }
    return aux;
}

int main(){
    int n, x;
    cin >> n;
    vector<int> preco(n);
    vector<int> num(n);
    vector<int> qnt(4);
    for(int i = 0 ; i < n ; i++) cin >> preco[i];
    for(int i = 0 ; i < n ; i++) cin >> num[i];
    for(int i = 0 ; i < n ; i++){
        int aux = num[i];
        cin >> x;
        qnt[x]aux++;
        if(aux != x) qnt[aux]++;
        num[i].first = min(aux,x);
        num[i].second = max(aux,x);
    }    

    for(int i = 0 ; i < n ; i++){
        v1[i] = num[i]; 
    }
    int cliente;
    cin >> cliente;
    for(int i = 0 ; i < cliente ; i++){
        cin >> x;
       cout << busca(x) << " " << endl;        
    }

}       
        http://codeforces.com/contest/799/problem/B
        http://codeforces.com/blog/entry/51947

