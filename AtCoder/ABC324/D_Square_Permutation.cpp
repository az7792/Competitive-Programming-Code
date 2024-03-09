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
    int n;
    vector<int> num(10, 0);
    cin >> n;
    string str;
    cin >> str;
    for (auto v : str)
        num[v - '0']++;
    vector<ll> tmp;
    ll ans = 0;
    for (ll i = 0; i <= 1e7; ++i)
    {
        tmp.push_back(i * i);
    }
    for (auto v : tmp)
    {
        vector<int> tmp(10, 0);
        while (v != 0)
        {
            tmp[v % 10]++;
            v /= 10;
        }
        bool f = true;
        for (int i = 1; i <= 9; ++i)
            if (tmp[i] != num[i])
            {
                f = false;
                break;
            }
        if (tmp[0] > num[0])
            f = false;
        if (f)
            ans++;
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