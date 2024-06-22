#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const ll MAX = 1e2 + 10;
const ll MOD = 998244353;
void solve()
{
    double x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    double r = sqrt((y3 - y4) * (y3 - y4) + (x3 - x4) * (x3 - x4)) / 2;
    double x0, y0;
    x0 = (x1 + x2) / 2;
    y0 = (y1 + y2) / 2;
    x3 -= x0;
    x4 -= x0;
    y3 -= y0;
    y4 -= y0;
    x0 = (x3 + x4) / 2;
    y0 = (y3 + y4) / 2;
    x0 = fabs(x0);
    y0 = fabs(y0);
    printf("%.10lf\n", x0 + y0 - sqrt(2) * r);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}