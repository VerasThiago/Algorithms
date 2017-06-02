Longest Common Subsequence
#define MAX_M   1001
#define MAX_N   1001

#define INF 1000000010

int st[MAX_M][MAX_N], a[MAX_N], b[MAX_N];
int c_i = 0, c_r = 0, c_s = 1;      // Custos adaptados
char ps[MAX_M][MAX_N];

// Implementação _bottom-up_, O(mn), memória O(mn)
int lcs(const string& s, const string& t)
{
    int m = s.size();
    int n = t.size();

    for (int i = 0; i <= m; ++i)
        st[i][0] = i*c_r;

    for (int j = 1; j <= n; ++j)
        st[0][j] = j*c_i;

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int insertion = st[i][j - 1] + c_i;
            int deletion = st[i - 1][j] + c_r; 
            int change = st[i - 1][j - 1] + c_s * (s[i - 1] == t[j - 1] ? 1 : -INF);
            st[i][j] = max(insertion, deletion);
            st[i][j] = max(st[i][j], change);
        }

    return st[m][n];
}
