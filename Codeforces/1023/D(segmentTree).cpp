#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e2 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n, q, fq = 0, fz = 0;
vector<int> G(MAX, 1e9), D(MAX, 1e9);
map<int, pii> mp;
struct Node
{
    int val = 1e9, l, r, lazy = 1e9;
} tree[MAX << 2];

void pushUp(int node)
{
    tree[node].val = min(tree[node << 1].val, tree[node * 2 + 1].val);
}

void pushDown(int node) // lazy标记下放
{
    int lc = node << 1, rc = node * 2 + 1;
    tree[lc].val = tree[node].lazy;
    tree[rc].val = tree[node].lazy;
    tree[lc].lazy = tree[node].lazy;
    tree[rc].lazy = tree[node].lazy;
    tree[node].lazy = 1e9;
}

void update(int node, int l, int r, int v) //[l,r]每个值=v
{
    if (tree[node].r < l || tree[node].l > r) // 当前结点完全没被覆盖
        return;
    if (l <= tree[node].l && tree[node].r <= r) // 当前结点被完全覆盖
    {
        tree[node].val = v;
        tree[node].lazy = v; // 打上标记
        return;
    }
    if (tree[node].lazy != 1e9) // 下放标记
        pushDown(node);
    update(node << 1, l, r, v); // 更新左右孩子结点
    update(node * 2 + 1, l, r, v);
    pushUp(node); // 更新当前结点
}

int query(int node, int l, int r)
{
    if (tree[node].r < l || tree[node].l > r) // 当前结点完全没被覆盖
        return 1e9;
    if (l <= tree[node].l && tree[node].r <= r) // 当前结点被完全覆盖
        return tree[node].val;
    if (tree[node].lazy != 1e9) // 下放标记
        pushDown(node);
    int res = min(query(node << 1, l, r), query(node * 2 + 1, l, r)); // 查询左右孩子结点
    pushUp(node);                                                     // 更新当前结点
    return res;
}

void build(int node, int L, int R)
{
    tree[node].l = L, tree[node].r = R;
    if (L == R) // 叶子结点
    {
        tree[node].val = G[L];
        return;
    }
    int mid = L + R >> 1;
    build(node << 1, L, mid); // 分别建左右树
    build(node * 2 + 1, mid + 1, R);
    pushUp(node); // 更新当前结点
}
void solve()
{
    cin >> n >> q;
    build(1, 1, n);
    for (int i = 1, tmp; i <= n; ++i)
    {
        cin >> tmp;
        if (tmp == q)
            fq = 1;
        if (tmp == 0)
            fz = 1;
        if (tmp == 0)
            tmp = 1e9;
        G[i] = tmp;
        update(1, i, i, tmp);
    }
    for (int i = 1; i <= n; ++i)
        if (G[i] != 1e9 && mp[G[i]].first == 0)
            mp[G[i]].first = i, mp[G[i]].second = 0;
    for (int i = n; i >= 1; --i)
        if (G[i] != 1e9 && mp[G[i]].second == 0)
            mp[G[i]].second = i;
    for (auto [x, y] : mp)
    {
        auto [l, r] = y;
        int Min = query(1, l, r);
        if (Min < x)
        {
            cout << "NO";
            return;
        }
    }
    if (!fq && !fz)
    {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    bool f = fq ? 1 : 0;
    if (!fq)
    {
        for (int i = 1; i <= n; ++i)
            if (G[i] == 1e9)
            {
                G[i] = q;
                break;
            }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (G[i] != 1e9)
        {
            G[0] = G[i];
            break;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (G[i] == 1e9)
            G[i] = G[i - 1];
        cout << G[i] << ' ';
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
/*




*/