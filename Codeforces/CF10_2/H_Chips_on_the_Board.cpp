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
    ll n, s1 = 0, s2 = 0;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        s1 += a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
        s2 += b[i];
    }
    sort(all(a));
    sort(all(b));
    cout << min(s1 + b[0]*n, s2 + a[0]*n) << endl;
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