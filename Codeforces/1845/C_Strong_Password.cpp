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
    int m;
    string str, l, r;
    cin >> str >> m >> l >> r;
    int np = -1;
    for (int i = 0; i < m; ++i)
    {
        int Max = np;
        for (int j = l[i]; j <= r[i]; ++j)
        {
            bool f = 0;
            for (int p = np + 1; p < str.size(); ++p)
            {
                if (str[p] == j)
                {
                    Max = max(Max, p);
                    f = 1;
                    break;
                }
            }
            if (!f)
            {
                cout << "YES\n";
                return;
            }
        }
        np = Max;
    }
    cout << "NO\n";
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