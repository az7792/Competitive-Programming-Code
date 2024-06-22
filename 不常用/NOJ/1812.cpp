#pragma warning(disable:4996)
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define endl '\n'
#define FAST {ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}
const ll MAX = 1e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{    
    int A[MAX], B[MAX],C[MAX];
    int n;
    map<int, int>MAP;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> A[i];
    for (int i = 1; i <= n; ++i)
    {
        cin >> B[i];
        MAP[B[i]] = i;
    }    
    for (int i = 1; i <= n; ++i)       
        C[i] = MAP[A[i]];
    int Max=0,ans =0;
    for (int i = 1; i <= n; ++i)
    {
        if (C[i] < Max)
            ans++;
        Max = max(Max, C[i]);        
    }
    cout << ans;
}
int main()
{    
    FAST;
    int t = 1;
    //cin >> t;
    while (t--)
    {        
        solve();
    }
    return 0;
}
/*
1
13
1 3 5 6 7 8 10 11 12 13 14 15 20

*/