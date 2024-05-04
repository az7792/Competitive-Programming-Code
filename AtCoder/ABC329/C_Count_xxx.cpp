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
void solve()
{
    int n;
    cin >> n;
    vector<char> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<pair<char, ll>> ans;
    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
            ans.push_back({a[i], 1});
        else
        {
            if (a[i] == a[i - 1])
                ans.back().second++;
            else
                ans.push_back({a[i], 1});
        }
    }
    map<char, ll> mp;
    for (auto v : ans)
        mp[v.first] = max(mp[v.first], (ll)v.second);
    ll res = 0;
    for (auto [x, y] : mp)
        res += y;
    cout << res;
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
