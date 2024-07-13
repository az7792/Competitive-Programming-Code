#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
double get(pair<double, double> a, pair<double, double> b)
{
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}
void solve()
{
    vector<pair<double, double>> p(5);
    for (int i = 0; i < 3; ++i)
        cin >> p[i].first >> p[i].second;
    p[3] = p[0];
    p[4] = p[1];
    for (int i = 0; i < 3; ++i)
    {
        pair<ll, ll> f, s;
        f = pair<ll, ll>(p[i + 1].first - p[i].first, p[i + 1].second - p[i].second);
        s = pair<ll, ll>(p[i + 2].first - p[i].first, p[i + 2].second - p[i].second);
        if (f.first * s.first+ f.second * s.second == 0)
        {
            cout << "Yes";
            return;
        }
    }
    cout << "No";
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
