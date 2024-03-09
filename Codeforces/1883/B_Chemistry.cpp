#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    map<char, int> mp;
    for (auto v : str)
        mp[v]++;
    int ct = 0;
    for (auto v : mp)
        if (v.second % 2 == 1)
            ct++;
    if (ct == 0)
    {
        cout << "YES\n";
    }
    else
    {
        ct--;
        if (ct > k)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
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