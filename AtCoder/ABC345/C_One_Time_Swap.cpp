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
    string str;
    cin >> str;
    map<char, ll> mp;
    for (auto v : str)
        mp[v]++;
    ll ans = 0;
    for (auto v : mp)
        if (v.second >= 2)
            ans = 1;
    ll sum = str.size();
    for (auto v : str)
    {
        mp[v]--;
        sum--;
        ans += sum - mp[v];
    }
    cout << ans;
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
