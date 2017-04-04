

int ans(n+1);
ans[0] = 0;
        for(int i = 1 ; i <= m ; i++)
            for(int j = 0 ; j < n ; j++)
                if(v[j] <= i){
                   
                    ans[i] = min(ans[i], (1 + ans[i-v[j]]));
                }
        