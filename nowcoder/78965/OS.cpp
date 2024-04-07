#include <bits/stdc++.h>//ji
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
struct Node
{
    ll s, len, pos, wait;
};

void solve()
{
    int n;
    cin >> n;
    vector<Node> q(n);
    ll now = 1e18;
    for (int i = 0; i < n; ++i)
    {
        cin >> q[i].s >> q[i].len;
        q[i].pos = i;
        now = min(now, q[i].s);
    }
    sort(all(q), [](Node A, Node B)
         { return A.s > B.s; });
    vector<ll> ans(n);
    vector<Node> nowq;
    for (int i = 1; i <= n; ++i)
    {

        while (!q.empty() && q.back().s <= now)
        {
            nowq.push_back(q.back());
            q.pop_back();
        }
        for (auto &v : nowq)
            v.wait = now - v.s;
        sort(all(nowq), [](Node A, Node B)
             { ll a = A.len + A.wait;
              ll b = A.wait;
              ll c = B.len + B.wait;
              ll d = B.wait;
              return fabs(1.0*b/a-1.0*d/c)<=0.0000001 ?(A.s==B.s?A.pos<B.pos:A.s<B.s):1.0*b/a>1.0*d/c; });
        ans[nowq[0].pos] = now;
        now += nowq[0].len;

        swap(nowq[0], nowq.back());
        nowq.pop_back();
    }
    for (auto v : ans)
        cout << v << endl;
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
