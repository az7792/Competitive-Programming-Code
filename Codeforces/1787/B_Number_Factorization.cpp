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
    ll N = n;
    unordered_map<ll, ll> mp;
    for (ll i = 2; i <= N / i; ++i)
    {
        while (N % i == 0)
        {
            mp[i]++;
            N /= i;
        }
    }
    if (N != 1)
        mp[N]++;
    ll ans = 0, tmp = 0;
    bool f = true;
    while (f)
    {
        f = 0;
        tmp = 1;
        for (auto &[x, y] : mp)
        {
            if(y>=1)
            {
                f = 1;
                tmp *= x;
                y--;
            }
        }
        if(f)
            ans += tmp;
    }

    cout << ans << endl;
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