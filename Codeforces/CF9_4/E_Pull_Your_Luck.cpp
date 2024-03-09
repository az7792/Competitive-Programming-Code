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
    ll n, x, q;
    cin >> n >> x >> q;
    for (ll i = 1; i <= min(2 * n, q); ++i)
    {
        if ((x + ((1 + i) * i) / 2) % n == 0)
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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