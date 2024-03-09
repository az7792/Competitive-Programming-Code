#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n;
    cin >> n;
    vector<pii> d(n);
    int Max = 1;
    for (int i = 0; i < n; ++i)
    {
        cin >> d[i].first >> d[i].second;
    }
    sort(
        all(d), [](pii a, pii b)
                { return a.first < b.first; });
    int ans = 1e9;
    for(auto v:d)
    {
        int len = (v.second - 1) / 2;
        //v.first + len
        ans = min(ans, v.first + len);
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}