#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (n == 1)
    {
        cout << "1\n";
        return;
    }
    sort(all(a));
    ll Gcd = a[1] - a[0];
    for (int i = 2; i < n; ++i)
    {
        Gcd = gcd(Gcd, a[i] - a[i - 1]);
    }
    set<ll> s;
    for (auto v : a)
        s.insert(v);
    ll ans = 0;
    for (auto v : a)
        ans += (a.back() - v) / Gcd;
    for (int i = 1; i <= n; ++i)
    {
        if (s.find(a.back() - i * Gcd) == s.end())
        {
            ans += i;
            break;
        }
    }
    cout << ans << endl;
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
