#include <bits/stdc++.h>
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
    ll a, b;
    bool operator<(const Node &tmp) const
    {
        return a == tmp.a ? b < tmp.b : a > tmp.a;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    set<Node> Q;
    for (int i = 1; i <= n; ++i)
    {
        Q.insert({0, i});
    }
    vector<ll> a(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int sp;
        cin >> sp;
        auto it = Q.find({a[sp], sp});
        a[sp]++;
        Node tmp = *it;
        Q.erase(it);
        tmp.a++;
        Q.insert(tmp);
        cout << (*Q.begin()).b << endl;
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
