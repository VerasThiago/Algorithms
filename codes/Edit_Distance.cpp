Cost to transform string s into r

double st[MAX_M][MAX_N];
double c_i = 2.5, c_r = 0.5, c_s = 1;

double edit(const string& s, const string& r)
{
    int m = s.size();
    int n = r.size();

    for (int i = 0; i <= m; ++i)
        st[i][0] = i*c_r;

    for (int j = 1; j <= n; ++j)
        st[0][j] = j*c_i;

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            double insertion = st[i][j - 1] + c_i;
            double deletion = st[i - 1][j] + c_r;
            double change = st[i - 1][j - 1] + c_s * (s[i - 1] == r[j - 1] ? 0 : 1);
            st[i][j] = min(insertion, deletion);
            st[i][j] = min(st[i][j], change);
        }

    return st[m][n];
}