#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve(int t)
{
    ll ans = 0;
    string str;
    cin >> str;
    map<char, ll> mp;
    for (auto v : str)
        mp[v]++;
    for (auto &[x, y] : mp)
        ans = max(ans, y);
    cout << "Case #" << t << ": " << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        solve(i);
    }
    return 0;
}
