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
    vector<ll> a;
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ll tmp;
        cin >> tmp;
        if (tmp % 2 == 0)
            ans += tmp;
        else
            a.push_back(tmp);
    }
    sort(all(a), [](ll a, ll b)
         { return a > b; });
    if (a.size() % 2 == 1)
        a.pop_back();
    for (int i = 0; i < a.size(); i += 2)
    {
        ans += a[i] + a[i + 1];
    }
    cout << ans;
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