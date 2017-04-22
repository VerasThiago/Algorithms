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

bool KMP(const string& text, const string& pat){
    int n = text.size()-1;
    int m = pat.size()-1;
    int i = 0, j = 0, occ = 0, k = 0;

    vector<int> bords = strong_borders(pat);

    while (n - k >= m)
    {
        while (j <= m and text[i] == pat[j]){
            ++j;
            ++i;
        }

        if (j > m) return true;

        if(j-1 >= 0 and bords[j-1] > 0)           
                k = i - bords[j-1];
   
        else{
            if(i == k) i++;
               k = i;
        }
        
        if(j > 0) j = bords[j-1];
    }
    return false;     
}
int main (){
    int n , m, tam;
    scanf("%d", &m);
    
    for(int j = 0 ; j < m ;j++){
        bool ans = true;
        scanf("%d", &tam);
        
        vector<string> v(tam);
        for(int i = 0 ; i < tam ; i++)
            cin >> v[i];       
         
        int k, l;
        for( k = 0 ; k < tam-1 ; k++){
            for( l = k+1; l < tam ; l++){
                if(KMP(v[l],v[k])){
                    ans = false;
                    break;
                }
            }
            
        }
        printf("%s\n",ans? "YES":"NO" );   
    }
    
}
