#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    vector<double> p(n + 1, 0);
    vector<double> tim(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> b[i] >> p[i];
        tim[i] = (a[i] + b[i]) * p[i] + (a[i]) * (1 - p[i]);
    }
    sort(tim.begin() + 1, tim.begin() + n + 1);
    double ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        tim[i] += tim[i - 1];
        ans += tim[i];
    }
    printf("%.10lf\n", ans);
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}