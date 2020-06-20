int solve(int x,int y){

	if(x >= N || y >= M) return 0;
	if(entrada[x][y] == '#') return 0;

	if(vis[x][y]) return dp[x][y];
	if(x == N - 1 && y == M - 1) return dp[x][y] = 1;

	vis[x][y] = 1;
	return dp[x][y] = (solve(x+1,y) + solve(x,y+1)) % MOD;

}