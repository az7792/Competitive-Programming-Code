#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define FAST                         \
    {                                \
        ios::sync_with_stdio(false); \
        cin.tie(nullptr);            \
        cout.tie(nullptr);           \
    }
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
map<ll, ll> mp;
string str[210];
bool f[210][210];
bool F[210][210];
int tx[] = {0, 0, -1, 1};
int ty[] = {-1, 1, 0, 0};
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> str[i];
        str[i] = "0" + str[i];
    }
    queue<pii> Q;
    Q.push({2, 2});
    F[2][2]=f[2][2]=1;
    while (!Q.empty())
    {
        auto [x, y] = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int X = x, Y = y;
            while (str[X][Y] == '.')
            {
                F[X][Y] = 1;
                X += tx[i], Y += ty[i];                
            }
            X -= tx[i], Y -= ty[i];
            if (!f[X][Y])
            {
                f[X][Y] = true;
                Q.push({X, Y});
            }
        }
    }
    ll ans=0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (F[i][j])
                ans++;
    cout << ans;
}
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    FAST;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*




*/