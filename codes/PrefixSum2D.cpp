vector< vector<int> > buildPsum(int n, int m, vector< vector< int > >& mat){
    vector< vector<int> > psum(n + 1, vector<int>(m + 1, 0));
    psum[1][1] = mat[0][0];

    for(int i = 2; i <= m; i++) psum[1][i] = psum[1][i - 1] + mat[0][i - 1];
    for(int i = 2; i <= n; i++) psum[i][1] = psum[i - 1][1] + mat[i - 1][0];
    
    for(int i = 2; i <= n; i++)
        for(int j = 2; j <= m; j++)
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + mat[i - 1][j - 1];
    
    return psum;
    
}

int calcArea(int i, int j, int width, int high, vector< vector< int > > &psum){
    if(i - high < 0 or j - width < 0) return -1;
    return psum[i][j] - psum[i - high][j] - psum[i][j - width] + psum[i - high][j - width];
}