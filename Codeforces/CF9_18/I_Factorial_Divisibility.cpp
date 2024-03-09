#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 1e6 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll ct[MAX];
void solve()
{
    ll n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
    {
        ll a;
        cin >> a;
        ct[a]++;
    }
    for (int i = 1; i < x; ++i)
    {
        if (ct[i] >= i + 1)
        {
            ct[i + 1] += ct[i] / (i + 1);
            ct[i] %= (i + 1);
        }
        if (ct[i] != 0)
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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