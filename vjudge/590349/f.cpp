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
    cin >> n;
    map<string, int> mp;
    int p = 0;
    int Max = -1;
    for (int i = 0; i < n; ++i)
    {
        string s;
        int t;
        cin >> s >> t;
        if (mp.find(s) == mp.end())
        {
            mp[s] = t;
            if (t > Max)
            {
                Max = t;
                p = i;
            }
        }
    }
    cout << p + 1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}