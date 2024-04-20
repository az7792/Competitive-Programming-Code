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
ll a;
double x, y;
map<ll, double> mp;
double dfs(ll n)
{
    if (mp.find(n) != mp.end())
        return mp[n];
    if (n == 0)
        return 0;
    double res = dfs(n / a) + x;
    double RES = y;
    for (ll i = 2; i <= 6; ++i)
    {
        RES += dfs(n / i) / 6.0;
    }    

    mp[n] = min(res, 6*RES/5.0);
    return mp[n];
}
void solve()
{
    ll n;
    cin >> n >> a >> x >> y;
    printf("%.7lf", dfs(n));
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
