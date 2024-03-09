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
    int n, l, r;
    cin >> n >> l >> r;
    map<int, int> mpl, mpr;
    for (int i = 1; i <= l; ++i)
    {
        ll tmp;
        cin >> tmp;
        mpl[tmp]++;
    }
    for (int i = l + 1; i <= n; ++i)
    {
        int tmp;
        cin >> tmp;
        mpr[tmp]++;
        if (mpl[tmp] > 0)
        {
            mpl[tmp]--;
            mpr[tmp]--;
        }
    }
    int lji = 0, lou = 0, rji = 0, rou = 0;
    for (auto &[x, y] : mpl)
    {
        int tmp = y % 2;
        lji += tmp;
        lou += y - tmp;
    }
    for (auto &[x, y] : mpr)
    {
        int tmp = y % 2;
        rji += tmp;
        rou += y - tmp;
    }
    if (lji + lou == rji + rou)
    {
        cout << lji + lou << endl;
    }
    else if (lji + lou < rji + rou)
    {
        int ans = lji + lou;
        if (ans <= rji)        
            cout << rji + rou / 2 << endl;        
        else        
            cout << ans + (rou + rji - ans) / 2 << endl;        
    }
    else
    {
        int ans = rji + rou;
        if (ans <= lji)        
            cout << lji + lou / 2 << endl;        
        else        
            cout << ans + (lou + lji - ans) / 2 << endl;   
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