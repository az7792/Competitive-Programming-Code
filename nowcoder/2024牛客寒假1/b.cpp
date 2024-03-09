#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    map<pii, bool> mp;
    int l = 2, r = 2;
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        cin >> x >> y;
        mp[{x, y}] = 1;
    }
    int ans1 = 0;
    if (mp.find({1, -1}) == mp.end())
        ans1++;
    if (mp.find({1, 1}) == mp.end())
        ans1++;
    if (mp.find({2, 0}) == mp.end())
        ans1++;
    for (auto [x, y] : mp)
    {
        if (x.second == 0)
            continue;
        if (x.first == 1)
        {
            if (x.second >= 1)
                r = min(r, 1);
            else
                l = min(l, 1);
            continue;
        }
        for (int i = x.second - 1; i <= x.second + 1; ++i)
        {
            if (mp.find({1, i}) != mp.end())
            {
                if (x.second >= 1)
                    r = 0;
                else
                    l = 0;
                break;
            }
        }
        if (x.second >= 1)
            r = min(r, 1);
        else
            l = min(l, 1);
    }
    int L, R;
    if (mp.find({2, 0}) != mp.end())
        L = R = 0;
    else
        L = R = 1;
    if (mp.find({1, -1}) == mp.end())
        L++;
    if (mp.find({1, 1}) == mp.end())
        R++;
    cout << min({ans1, l + r, l + R, L + r}) << endl;
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
