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
ll a, b;
void solve()
{
    // n = a^x + by
    ll n;
    cin >> n >> a >> b;
    if (a == 1)
        cout << (((n - 1) % b == 0) ? "Yes\n" : "No\n");
    else
    {
        ll tmp = 1;
        for (int i = 0; tmp <= n; ++i)
        {
            ll N = n - tmp;
            if (N % b == 0)
            {
                cout << "Yes\n";
                return;
            }
            tmp *= a;
        }
        cout << "No\n";
    }
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