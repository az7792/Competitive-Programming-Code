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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int ct = 0;
    for (int i = 1; i <= n; ++i)
    {
        int p = lower_bound(all(a), a[i - 1] + m) - a.begin();
        if (p < n)
            if (a[p] == a[i - 1] + m)
                ct++;
    }
    cout << ct;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}