#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
map<ll, ll> mp;
void solve()
{    
    vector<int> G(200, 0), S;
    int n, k,sum=0;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> G[i];
    for (int i = 2; i <= n; ++i)
        S.eb(abs(G[i] - G[i - 1])), sum += abs(G[i] - G[i - 1]);
    sort(all(S), [](int a, int b)
         { return a > b; });
    for (int i = 0; i < k - 1;++i)
        sum -= S[i];
    cout << sum << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*




*/