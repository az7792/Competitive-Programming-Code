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
vector<int> G(MAX, 0);
struct Node
{
    int F = 0, S = 0, l, r, ctf = 0, cts = 0;
} tree[MAX << 2];

void pushUp(int node)
{
    vector<pii> S;
    S.emplace_back(tree[node << 1].F, tree[node << 1].ctf);
    S.emplace_back(tree[node << 1].S, tree[node << 1].cts);
    S.emplace_back(tree[node * 2 + 1].F, tree[node * 2 + 1].ctf);
    S.emplace_back(tree[node * 2 + 1].S, tree[node * 2 + 1].cts);
    sort(all(S), [](pii a, pii b)
         { return a.first > b.first; });
    vector<pii> arr;
    for (auto v : S)
    {
        if (arr.empty())
            arr.emplace_back(v);
        else if (arr.back().first == v.first)
            arr.back().second += v.second;
        else
            arr.emplace_back(v);
        if (arr.size() > 2)
            break;
    }
    tree[node].F = arr[0].first;
    tree[node].ctf = arr[0].second;

    tree[node].S = arr[1].first;
    tree[node].cts = arr[1].second;
}

void update(int node, int p, int v) //[l,r]每个值+=v
{
    if (tree[node].r < p || tree[node].l > p) // 当前结点完全没被覆盖
        return;
    if (tree[node].r == p && tree[node].l == p)
    {
        tree[node].F = v;
        return;
    }
    update(node << 1, p, v); // 更新左右孩子结点
    update(node * 2 + 1, p, v);
    pushUp(node); // 更新当前结点
}

pair<pii, pii> query(int node, int l, int r)
{
    if (tree[node].r < l || tree[node].l > r) // 当前结点完全没被覆盖
        return {{0, 0}, {0, 0}};
    if (l <= tree[node].l && tree[node].r <= r) // 当前结点被完全覆盖
        return {{tree[node].F, tree[node].ctf}, {tree[node].S, tree[node].cts}};
    pair<pii, pii> resL = query(node << 1, l, r); // 查询左右孩子结点
    pair<pii, pii> resR = query(node * 2 + 1, l, r);

    vector<pii> S;
    S.emplace_back(resL.first);
    S.emplace_back(resL.second);
    S.emplace_back(resR.first);
    S.emplace_back(resR.second);
    sort(all(S), [](pii a, pii b)
         { return a.first > b.first; });
    vector<pii> arr;
    for (auto v : S)
    {
        if (arr.empty())
            arr.emplace_back(v);
        else if (arr.back().first == v.first)
            arr.back().second += v.second;
        else
            arr.emplace_back(v);
        if (arr.size() > 2)
            break;
    }

    resL.first.first = arr[0].first;
    resL.first.second = arr[0].second;

    resL.second.first = arr[1].first;
    resL.second.second = arr[1].second;
    return resL;
}

void build(int node, int L, int R)
{
    tree[node].l = L, tree[node].r = R;
    if (L == R) // 叶子结点
    {
        tree[node].F = G[L];
        tree[node].S = 0;
        tree[node].ctf = 1;
        return;
    }
    int mid = L + R >> 1;
    build(node << 1, L, mid); // 分别建左右树
    build(node * 2 + 1, mid + 1, R);
    pushUp(node); // 更新当前结点
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> G[i];
    build(1, 1, n);
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y;
            cin >> x >> y;
            update(1, x, y);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << query(1, x, y).second.second << endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}