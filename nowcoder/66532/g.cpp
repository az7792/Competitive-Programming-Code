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
vector<int> fa;
struct Node
{
    int w, u, v;
};
vector<Node> G;
int Find(int p)
{
    if (p != fa[p])
        fa[p] = Find(fa[p]);
    return fa[p];
}
set<ll> S;
void solve(int n)
{
    //     //    ll n;
    //   // cin >> n;
    //     fa.clear();
    //     G.clear();
    //     fa.resize(n + 1);
    //     for (int i = 0; i <= n; ++i)
    //         fa[i] = i;
    //     for (int i = 1; i <= n; ++i)
    //         for (int j = i + 1; j <= n; ++j)
    //         {
    //             Node tmp;
    //             tmp.w = i & j;
    //             tmp.u = i;
    //             tmp.v = j;
    //             G.emplace_back(tmp);
    //         }
    //     sort(all(G), [](Node a, Node b)
    //          { return a.w < b.w; });
    //     int ans = 0;
    //     for (auto &[x, y, z] : G)
    //     {
    //         if (Find(y) != Find(z))
    //         {
    //             fa[Find(y)] = Find(z);
    //             ans += x;
    //         }
    //     }
    //     // cout << ans << endl;
    //     if (ans == 1)
    //         cout << n<<endl;
    ll N;
    cin >> N;
    if (S.find(N) != S.end())
        cout << "1\n";
    else
        cout << "0\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    ll tmp = 3;
    S.insert(3);
    while (tmp <= 1e9)
    {
        tmp = tmp * 2 + 1;
        S.insert(tmp);
    }

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        solve(i);
    }
    return 0;
}