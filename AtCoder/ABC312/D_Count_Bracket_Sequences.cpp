// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define eb emplace_back
// const ll MAX = 2e5 + 10;
// const ll MOD = 998244353;
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pll;
// vector<ll> A(MAX, 0);
// vector<ll> B(MAX, 0);
// void solve()
// {
//     string str;
//     cin >> str;
//     if (str.size() % 2 == 1)
//     {
//         cout << 0;
//         return;
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     srand(time(nullptr));
//     int t = 1;
//     // cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
string a;
int dp[3001][3001],m=998244353;
int main()
{
	cin>>a;
	dp[0][0]=1;
	for(int i=1;i<=a.size();i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(a[i-1]!=')'&&j)
			{
				dp[i][j]+=dp[i-1][j-1];
			}
			if(a[i-1]!='(')
			{
				dp[i][j]+=dp[i-1][j+1];
			}
			dp[i][j]%=m;
		}
	}
	cout<<dp[a.size()][0];
}