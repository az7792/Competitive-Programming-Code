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
    ll a, b, r;
    cin >> a >> b >> r;
    int n = 59;
    bitset<60> sa(a);
    bitset<60> sb(b);
    bitset<60> ans(0ll);
    vector<int> tmp;
    for (int i = n; i >= 0; --i)
    {
        if (sa[i] != sb[i])
        {
            ans[i] = 1;
            tmp.push_back(i);
        }
    }
    if (tmp.empty())
    {
        cout << abs(a - b) << endl;
        return;
    }
    bitset<60> tans = ans;
    ll R = r;
    int f = 1;

    for (int i = 0; i < tmp.size(); ++i)
    {
        if (f == 1)
        {
            if (sa[tmp[i]] == 0)
                ans[tmp[i]] = 1;
            else
                ans[tmp[i]] = 0;
            f = 0;
            r -= (1ll << tmp[i]) * ans[tmp[i]];
            if (r < 0)
            {
                r += (1ll << tmp[i]) * ans[tmp[i]];
                ans[tmp[i]] = 0;
                f = 1;
            }
        }
        else
        {
            if (sb[tmp[i]] == 0)
                ans[tmp[i]] = 1;
            else
                ans[tmp[i]] = 0;
            r -= (1ll << tmp[i]) * ans[tmp[i]];
            if (r < 0)
            {
                r += (1ll << tmp[i]) * ans[tmp[i]];
                ans[tmp[i]] = 0;
            }
        }
    }
    f = 1;
    for (int i = 0; i < tmp.size(); ++i)
    {
        if (f == 1)
        {
            if (sb[tmp[i]] == 0)
                tans[tmp[i]] = 1;
            else
                tans[tmp[i]] = 0;
            f = 0;
            R -= (1ll << tmp[i]) * tans[tmp[i]];
            if (R < 0)
            {
                R += (1ll << tmp[i]) * tans[tmp[i]];
                tans[tmp[i]] = 0;
                f = 1;
            }
        }
        else
        {
            if (sa[tmp[i]] == 0)
                tans[tmp[i]] = 1;
            else
                tans[tmp[i]] = 0;
            R -= (1ll << tmp[i]) * tans[tmp[i]];
            if (R < 0)
            {
                R += (1ll << tmp[i]) * tans[tmp[i]];
                tans[tmp[i]] = 0;
            }
        }
    }

    ll ct = 0, tct = 0;
    for (int i = 0; i <= n; ++i)
    {
        ct += (1ll << i) * ans[i];
    }
    for (int i = 0; i <= n; ++i)
    {
        tct += (1ll << i) * tans[i];
    }
    cout << min(abs((a ^ ct) - (b ^ ct)), abs((a ^ tct) - (b ^ tct))) << endl;
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
