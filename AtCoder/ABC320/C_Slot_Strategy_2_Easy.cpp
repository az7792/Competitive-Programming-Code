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
    int m;
    cin >> m;
    vector<string> s(3);
    vector<int> nn = {0, 1, 2};
    for (int i = 0; i < 3; ++i)
        cin >> s[i];
    ll Min = 1e18;
    do
    {
        for (char j = '0'; j <= '9'; ++j)
        {
            ll t = 0;
            if (s[nn[0]].find(j) == s[nn[0]].npos)
                continue;
            if (s[nn[1]].find(j) == s[nn[1]].npos)
                continue;
            if (s[nn[2]].find(j) == s[nn[2]].npos)
                continue;
            int p = 0;
            for (int i = 0; i < 3; ++i)
            {
                while (1)
                {
                    if (s[nn[i]][p] == j)
                    {
                        p = (p + 1) % m;
                        t++;
                        break;
                    }
                    p = (p + 1) % m;
                    t++;
                }
            }
            Min = min(Min, t - 1);
        }

    } while (next_permutation(all(nn)));
    if (Min == 1e18)
        cout << -1;
    else
        cout << Min;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
