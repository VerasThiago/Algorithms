
#include <bits/stdc++.h>

using namespace std;
bool is_sub(const string& text, const string& pat)
{
    int n = text.size();
    int m = pat.size();

    for (int i = 0; i <= n - m; ++i) 
       if(pat == text.substr(i, m)) return true;

    return false;
}
int main(){
    string a, b;
    cin >> a >> b;

    printf("%s\n",is_sub(a,b)? "Yes":"No" ); //finding string b in a
}

