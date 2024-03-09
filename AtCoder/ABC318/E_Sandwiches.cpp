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
    ll n, num, ans = 0;
    cin >> n;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        mp[num].push_back(i);
    }
    for (auto &[x, v] : mp)
        for (int i = 1; i < v.size(); ++i)
            ans += (v[i] - v[i - 1] - 1) * (i * (v.size() - i));
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}