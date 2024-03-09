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
map<int, int> mp;
vector<int> G(MAX, 0);
void solve()
{
    mp.clear();
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> G[i], mp[G[i]]++;
    int S = G[1], E = G[n];
    if (S == E)
    {
        if (mp[G[1]] >= k)
            cout << "YES\n";
        else
            cout << "NO\n";
        return;
    }
    bool f = 1;
    int ct1 = 0, ct2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (f)
        {
            if (G[i] == S)
                ct1++;
            if (ct1 == k)
                f = 0;
        }
        else
        {
            if (G[i] == E)
                ct2++;
        }
    }
    if (ct1 == k && ct2 >= k)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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