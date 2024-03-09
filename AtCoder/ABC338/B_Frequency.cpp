#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    string str;
    cin >> str;
    map<char, int> mp;
    for (auto v : str)
        mp[v]++;
    int M = 0;
    char ans;
    for (auto v : mp)
    {
        if (v.second > M)
        {
            M = v.second;
            ans = v.first;
        }
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
