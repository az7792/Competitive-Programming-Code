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
    int n, ct = 0;
    cin >> n;
    vector<int> num(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; ++i)
    {
        cin >> num[i];
        mp[num[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (num[i] != i)
        {
            mp[num[i]] = mp[i];
            swap(num[i], num[mp[i]]);
            ct++;
        }
    }
    cout << ct;
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