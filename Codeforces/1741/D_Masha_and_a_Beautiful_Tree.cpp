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
vector<pii> G[2],tmp;
void solve()
{
    G[0].clear();
    G[1].clear();
    int m;
    cin >> m;
    for (int i = 1, tmp; i <= m; ++i)
    {
        cin >> tmp;
        G[0].eb(tmp, tmp);
    }
    int n = log2(m);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int a = i % 2;
        int b = (a + 1) % 2;
        tmp.clear();
        for (int j = 0; j < G[b].size(); j += 2)
        {
            int L,R;
            L = min(G[b][j].first, G[b][j + 1].first);
            R = max(G[b][j].second, G[b][j + 1].second);
            if(R-L+1!=pow(2,i))
            {
                cout << -1 << endl;
                return;
            }
            if(G[b][j].second+1!=G[b][j+1].first)
                ans++;
            tmp.eb(L, R);
        }
        G[a] = tmp;
    }
    cout << ans << endl;
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