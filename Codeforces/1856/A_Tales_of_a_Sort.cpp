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
void solve()
{
    ll n;
    cin >> n;
    vector<ll> G, tmp;
    for (int i = 1; i <= n; ++i)
    {
        ll t;
        cin >> t;
        G.eb(t);
    }
    tmp = G;
    sort(all(tmp));
    for (int i = n-1; i >= 0; --i)
    {
        if(tmp[i]!=G[i])
        {
            cout << tmp[i] << endl;
            return;
        }
    }
    cout << 0 << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}