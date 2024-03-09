#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> p(2 * n);
    for (int i = 0; i < 2 * n; ++i)
        cin >> p[i];
    if (n == 1)
    {
        cout << abs(p[1] - p[0]) << endl;
    }
    else if (n == 2)
    {
        ll ans1 = 0;
        for (auto v : p)
            ans1 += abs(2 - v);
        ll ans3 = 0;
        for (auto v : p)
            ans3 += abs(v);
        ans1 = min(ans1, ans3);
        ll ans2 = 0;
        for (auto v : p)
            ans2 += abs(v + 1);
        for (auto v : p)
            ans1 = min(ans1, ans2 - abs(v + 1) + abs(v - n));
        cout << ans1 << endl;
    }
    else
    {
        ll ans1 = 0;
        for (auto v : p)
            ans1 += abs(v);
        if (n % 2 != 1)
        {
            ll ans2 = 0;
            for (auto v : p)
                ans2 += abs(v + 1);
            for (auto v : p)
                ans1 = min(ans1, ans2 - abs(v + 1) + abs(v - n));
        }
        cout << ans1 << endl;
    }
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