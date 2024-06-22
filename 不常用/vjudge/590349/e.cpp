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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    ll g1 = 0, g2 = 0;
    for (int i = 0; i < n; ++i)
        if (i % 2 == 0)
            g1 = gcd(g1, a[i]);
    for (int i = 0; i < n; ++i)
        if (i % 2 == 1)
            g2 = gcd(g2, a[i]);
    bool f1 = true, f2 = true;
    for (int i = 0; i < n; ++i)
        if (i % 2 == 1 && a[i] % g1 == 0)
        {
            f1 = false;
            break;
        }
    if (f1)
    {
        cout << g1 << endl;
        return;
    }
    for (int i = 0; i < n; ++i)
        if (i % 2 == 0 && a[i] % g2 == 0)
        {
            f2 = false;
            break;
        }
    if (f2)
    {
        cout << g2 << endl;
        return;
    }
    cout << 0 << endl;
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