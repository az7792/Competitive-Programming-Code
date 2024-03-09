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
vector<int> a;
bool cmp(int x, int y)
{
    return a[x] > a[y];
}
void solve()
{
    int n, m;
    cin >> n >> m;
    a.resize(m);
    for (int i = 0; i < m; ++i)
        cin >> a[i];
    vector<string> str(n + 1);
    vector<vector<int>> G(n + 1);
    vector<int> sum(n + 1);
    multiset<int> S;
    for (int i = 1; i <= n; ++i)
    {
        cin >> str[i];
        for (int j = 0; j < m; ++j)
            if (str[i][j] == 'o')
                sum[i] += a[j];
            else
                G[i].push_back(j);
        sum[i] += i;
        S.insert(sum[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        auto now = S.find(sum[i]);
        S.erase(sum[i]);
        if (sum[i] > *S.rbegin())
            cout << 0 << endl;
        else
        {
            int tmp = sum[i];
            sort(all(G[i]), cmp);
            for (int j = 0; j < G[i].size(); ++j)
            {
                tmp += a[G[i][j]];
                if (tmp > *S.rbegin())
                {
                    cout << j + 1 << endl;
                    break;
                }
            }
        }
        S.insert(sum[i]);
    }
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