#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define eb emplace_back
#define MP make_pair
#define pb push_back
#define pf push_front
#define ins insert
#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define tr(c,it) for(auto it=c.begin();it!=c.end();it++)
#define fr(i,n) for(lli i=0;i<(n);i++)
#define inc(i,a,b) for(lli i=a;i<=b;i++)
#define dec(i,a,b) for(lli i=a;i>=b;i--)
#define fr2(i,n) for(lli i=0;i<(n);i++)
#define inc2(i,a,b) for(lli i=a;i<=b;i++)
#define dec2(i,a,b) for(lli i=a;i>=b;i--)
#define ymin(a,b)  (a=min((a),(b)))
#define ymax(a,b)  (a=max((a),(b)))
#define sz(x) (lli)(x).size()
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr<< *it << " = " << a << endl;
	err(++it, args...);
}

typedef long long int lli;
typedef long double ld;
typedef pair<lli,lli> pii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<lli> vi;
//typedef  vector<vector<lli> >ncr(1001,vector<lli>(1001,0))
typedef vector<plli> vplli;
long long MOD=1000000007;
#define addm(x,y) (x+y>=MOD? (x+y-MOD):(x+y))
lli add(lli a,lli b)
{
	lli res=a+b;
	if(res>=MOD)
		return res-MOD;
	return res;

}
lli  mult(lli a,lli b)
{
	lli res=a;
	res*=b;
	if(res>=MOD)
		return res%MOD;
	return res;

}
//lli n,k;
const lli n=51;
struct matrix
{
	lli arr[n][n];
	//vector<vector<lli> >arr;
	// matrix(){

	// }
	// matrix(lli _n)
	// {
	// 	n=_n;
	// 	arr.resize(n,vector<lli>(n));


	// }
	
	void reset()
	{
		memset(arr,0,sizeof(arr));
	}
	void makeiden()
	{
		reset();
		for(lli i=0;i<n;i++)
			arr[i][i]=1;
	}
	matrix operator +(const matrix &o) const
	{
		matrix res;
		for(lli i=0;i<n;i++)
		{
			for(lli j=0;j<n;j++)
				res.arr[i][j]=add(arr[i][j],o.arr[i][j]);
		}
		return res;
	}
	matrix operator *(const matrix &o) const
	{
		matrix res;
		for(lli i=0;i<n;i++)
		{
			for(lli j=0;j<n;j++)
			{
				res.arr[i][j]=0;
				for(lli k=0;k<n;k++)
				{
					res.arr[i][j]=add(res.arr[i][j],mult(arr[i][k],o.arr[k][j]));
				}
			}
		}
		return res;
	}

};
matrix power(matrix a,lli b)
{
	matrix res;
	res.makeiden();
	while(b)
	{
		if(b&1)
			res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
///to declare a matrix first write matrix M ,THEN ACCESSTHE ARRAY ELEMENTS BY M.arr[i][j]
//to find the exponent write 
//matrix expo=power(M,n);
int main()
{
	// 	#ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	IOS
	// clock_t start,end;
	// start=clock();
	// lli t;
	// cin>>t;
	// for(lli i=1;i<=t;i++)
	// {
	// 	cout<<"Case #"<<i<<": ";
	// 	solve();

	// }
	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
	//lli a[n][n];
	lli nn,k;
	cin>>nn>>k;
	matrix A;

	for(lli i=0;i<nn;i++)
	{
		for(lli j=0;j<nn;j++)
		{
			lli p;
			cin>>p;
		A.arr[i][j]=p;
		}
	}
	

	matrix B;

	B=power(A,k);
	lli ans=0;
	for(lli i=0;i<nn;i++)
	{
		for(lli j=0;j<nn;j++)
		{
			ans=(ans+B.arr[i][j])%MOD;
		}

	}
	cout<<ans<<endl;

	
}
