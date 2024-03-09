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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    ll l = 1, r = 1e10, mid;
    while (l < r)
    {
        mid = (l + r + 1) / 2;
        ll res = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] < mid)
                res += mid - a[i];
        if (res <= x)
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}