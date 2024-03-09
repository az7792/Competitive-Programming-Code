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
vector<ll> num(61);
void solve()
{
    ll n, m, ans = 0, f = 1, ct = 0;
    cin >> n >> m;
    n %= m;
    while (n != 0)
    {
        ans += n;
        n = (n * 2) % m;
        ct++;
        if (ct >= 1000)
        {
            f = 0;
            break;
        }
    }
    if (f == 0)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    for (int i = 0; i <= 60; ++i)
        num[i] = (1ll << i);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}