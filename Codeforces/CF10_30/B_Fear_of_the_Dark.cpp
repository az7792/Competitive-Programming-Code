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
double len(pair<double, double> a, pair<double, double> b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
void solve()
{
    pair<double, double> p, a, b, z = {0, 0};
    cin >> p.first >> p.second >> a.first >> a.second >> b.first >> b.second;
    double l = 0, r = 1e9, mid, lab = len(a, b), lap = len(a, p), lbp = len(b, p);
    double laz = len(a, z), lbz = len(b, z);
    while (l < r && r - l >= 1e-8)
    {
        mid = (l + r) / 2;
        if (2 * mid >= lab)
        {
            if ((lap <= mid || lbp <= mid) && (laz <= mid || lbz <= mid))
                r = mid;
            else
                l = mid;
        }
        else
        {
            if ((laz <= mid && lap <= mid) || (lbz <= mid && lbp <= mid))
                r = mid;
            else
                l = mid;
        }
    }
    cout << fixed << mid << endl;
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