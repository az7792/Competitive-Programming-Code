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
vector<int> G[110];
void solve()
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        for (int j = 1; j <= num; ++j)
        {
            int tmp;
            cin >> tmp;
            G[i].eb(tmp);
        }
    }
    cin >> x;
    vector<int> ans;
    int len = 1e9;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < G[i].size(); ++j)
        {
            if (G[i][j] == x)
            {
                if (ans.empty())
                {
                    ans.eb(i + 1);
                    len = G[i].size();
                }
                else
                {
                    if (G[i].size() < len)
                    {
                        len = G[i].size();
                        ans.clear();
                        ans.eb(i + 1);
                    }
                    else if (len == G[i].size())
                    {
                        ans.eb(i + 1);
                    }
                }
                break;
            }
        }
    }
    sort(all(ans));
    cout << ans.size() << endl;
    for (auto v : ans)
        cout << v << ' ';
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