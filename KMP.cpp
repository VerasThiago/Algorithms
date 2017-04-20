#include <bits/stdc++.h>

using namespace std;

vector<int> strong_borders(const string& pat)
{
    int m = pat.size();
    int t = -1;

    vector<int> sbord(m + 1);
    sbord[0] = -1;

    for (int j = 1; j <= m; ++j)    // t é igual a bord[j - 1]
    {
        while (t >= 0 and pat[t] != pat[j - 1])
            t = sbord[t];

        ++t;

        if (j == m or pat[t] != pat[j])
            sbord[j] = t;
        else
            sbord[j] = sbord[t];
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
