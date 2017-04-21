#include <bits/stdc++.h>
using namespace std;
vector<int> strong_borders(const string& pat){
    int m = pat.size();
    vector<int> sbord(m);
    int t = 0;

    for (int j = 1; j < m; ++j){
        while (t > 0 and pat[t] != pat[j])
            t = sbord[t];
        if(pat[t] == pat[j])
            t++;
        sbord[j] = t;
    }
    return sbord;
}
int KMP(const string& text, const string& pat)
{
    int n = text.size();
    int m = pat.size();
    int i = 0, j = 0, occ = 0;

    vector<int> bords = strong_borders(pat);

    while (i <= n - m)
    {
        while (j < m and pat[j] == text[i + j])
            ++j;

        if (j == m)
            ++occ;

        int KMP_shift = j - bords[j];

        i += KMP_shift;
        j = max(0, j - KMP_shift);
    } 
    return occ;
}

int main (){
    string a , b;
    cin >> a >> b;
    cout << KMP(a,b) << endl;
}
