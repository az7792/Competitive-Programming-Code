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
    int k, n;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; ++i)
    {
        ll t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        a[i] = t1 + t2 + t3;
    }
    b = a;
    sort(all(a));
    for (int i = 0; i < n; ++i)
    {
        ll s = b[i] + 300;
        int p = upper_bound(all(a), s) - a.begin();
        int tk = n - p + 1;
        if (tk <= k)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
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