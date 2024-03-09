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
    vector<ll> a(n + 1, 0);
    vector<ll> b(n + 1, 0);
    ll ct = 0;
    cin >> a[1];
    for (int i = 2; i <= n; ++i)
    {
        cin >> a[i];
        double t = log2(1.0 * a[i - 1] / a[i]);
        ll T = t;
        if (t > 0)
            if (pow(2, T) != 1.0 * a[i - 1] / a[i])
                T++;
        b[i] = max(0ll, b[i - 1] + T);
        ct += b[i];
    }
    // for(int i=1;i<=n;++i)cout << b[i] << endl;
    cout << ct << endl;
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