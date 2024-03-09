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
    ll n, m, ct = 0, s;
    cin >> n >> m;
    if (n == m)
    {
        cout << 0;
        return;
    }
    n -= m;
    s = m;
    while (n > 0)
    {
        if (s == 1)
        {
            ct += n;
            break;
        }
        s = (s + 1) / 2;
        ct++;
        n -= s;
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