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
    ll n, ct = 0;
    cin >> n;
    vector<double> x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            for (int k = j + 1; k < n; ++k)
            {
                if (x[i] == x[j] && x[j] == x[k])
                    continue;
                double k1 = (y[i] - y[j]) / (x[i] - x[j]);
                double k2 = (y[i] - y[k]) / (x[i] - x[k]);
                double k3 = (y[k] - y[j]) / (x[k] - x[j]);
                if (k1 == k2 && k2 == k3)
                    continue;
                ct++;
            }
    cout << ct;
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