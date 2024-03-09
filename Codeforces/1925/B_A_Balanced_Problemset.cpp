#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    ll n, x,X;
    cin >> x >> n;
    set<ll> s;
    s.insert(1);
    for (int i = 2; i <= x / i; ++i)
    {
        if (x % i == 0)
        {
            s.insert(x / i);
            s.insert(i);
        }
    }
    s.insert(x);
    ll ans = 1;
    for (auto v : s)
    {
        if (x / v >= n)
        {
            ans = v;
        }
    }
    cout << ans << endl;
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
