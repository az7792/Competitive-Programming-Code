#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
bool cmp(pair<vector<int>, int> &a, pair<vector<int>, int> &b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    map<vector<int>, int> mp;
    vector<pair<vector<int>, int>> ans;
    for (int i = 1; i <= n; ++i)
    {
        vector<int> tmp(m);
        for (int j = 0; j < m; ++j)
        {
            cin >> tmp[j];
        }
        mp[tmp]++;
    }
    for (auto &v : mp)
        ans.push_back(v);
    sort(all(ans), cmp);
    cout << ans.size() << endl;
    for (int j = 0; j < ans.size(); ++j)
    {
        cout << ans[j].second << ' ';
        for (int i = 0; i < ans[j].first.size(); ++i)
        {
            cout << ans[j].first[i];
            if (i != ans[j].first.size() - 1)
                cout << " ";
        }
        if (j != ans.size() - 1)
            cout << "\n";
    }
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
