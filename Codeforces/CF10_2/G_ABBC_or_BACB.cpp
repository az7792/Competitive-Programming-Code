#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n;
    string str;
    cin >> str;
    n = str.size();
    vector<pair<char, ll>> S;
    for (int i = 0; i < n; ++i)
    {
        char ch = str[i];
        if (S.empty())
            S.push_back({ch, 1});
        else
        {
            if (S.back().first == ch)
            {
                S.back().second++;
            }
            else
            {
                S.push_back({ch, 1});
            }
        }
    }
    if (S[0].first == 'A' && S.back().first == 'A')
    {
        bool f = false;
        ll Min = 1e18;
        ll ans = 0;
        for (auto &[x, y] : S)
        {
            if (x == 'B' && y >= 2)
                f = true;
            if (x == 'A')
                ans += y, Min = min(Min, y);
        }
        if (f)
            cout << ans << endl;
        else
            cout << ans - Min << endl;
    }
    else
    {
        ll ans = 0;
        for (auto &[x, y] : S)
            ans += (x == 'A' ? y : 0);
        cout << ans << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
