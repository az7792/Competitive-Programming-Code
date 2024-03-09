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
    ll duo = 0;
    for (int i = 1; i <= n; ++i)
    {
        ll tmp;
        cin >> tmp;
        if (tmp == 1)
            duo--;
        else
            duo += tmp - 1;
    }
    if (n == 1)
    {
        cout << "NO\n";
        return;
    }
    if (duo < 0)
        cout << "NO\n";
    else
        cout << "YES\n";
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