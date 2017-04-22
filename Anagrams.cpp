#include <bits/stdc++.h>
using namespace std;


int main()
{
    string s = "banana";
    string base = s;
    int number = 0;

    sort(s.begin(), s.end());

    do {
        printf("%02d. ", ++number);
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    cout << base;
    printf(" has %d anagrams\n", number);

    return 0;
}
