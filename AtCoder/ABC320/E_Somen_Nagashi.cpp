#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
struct Node
{
    int p, t;
    bool operator<(const Node &a) const
    {
        return t > a.t;
    }
};
void solve()
{
    ll n, m, t, w, s;
    cin >> n >> m;
    vector<ll> ans(n + 1, 0);
    set<int> S;
    for (int i = 1; i <= n; ++i)
        S.insert(i);
    priority_queue<Node> Q;
    while (m--)
    {
        cin >> t >> w >> s;
        while (!Q.empty())
        {
            if (Q.top().t <= t)
            {
                S.insert(Q.top().p);
                Q.pop();
            }
            else
                break;
        }
        if (!S.empty())
        {
            int now = *S.begin();
            S.erase(S.begin());
            ans[now] += w;
            Node tmp;
            tmp.p = now;
            tmp.t = t + s;
            Q.push(tmp);
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';
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
