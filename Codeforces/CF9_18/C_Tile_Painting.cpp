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
    set<ll> s;
    ll x = n;
    for (ll i = 2; i <= x / i; ++i)
    {
        if (x % i == 0)
        {
            s.insert(i);
            while (x % i == 0)
            {
                x /= i;
            }
        }
    }
    if (x > 1)
        s.insert(x);
    ll ans;
    if (s.size() == 1)
    {
        if (*s.begin() == n)
            ans = n;
        else
            ans = *s.begin();
    }
    else
    {
        ans = 1;
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}