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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    a[0] = -1e18;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    multiset<ll> S;
    S.insert(-1e18);
    for (int i = 1; i <= m - 1; ++i)
        S.insert(a[i]);
    for (int i = m; i <= n; ++i)
    {
        auto v = S.find(a[i - m]);
        S.erase(v);
        S.insert(a[i]);
        cout << *S.begin() << endl;
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