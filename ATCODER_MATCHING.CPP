    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    const ll MOD = 1e9+7;
    const int N = 1<<22;

    int n;
    int mat[22][22];
    ll dp[22][N];
    vector<int>v[22];

    int main()
    {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>mat[i][j];
            }
        }

        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<(1<<n);j++){
                for(int e=0;e<n;e++){
                    if(mat[i][e+1]){
                        int p=(1<<e);
                        if(j&p)dp[i][j]=(dp[i][j]+dp[i-1][j-p])%MOD;
                    }
                }
            }
        }
        cout<<dp[n][(1<<n)-1];
        return 0;
    }
