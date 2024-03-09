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
    int val = 0, l, r, lazy = 0;
} tree[MAX << 2];

void pushUp(int node)
{
    tree[node].val = tree[node << 1].val + tree[node * 2 + 1].val;
}

void pushDown(int node) // lazy标记下放
{
    int lc = node << 1, rc = node * 2 + 1;
    tree[lc].val = tree[lc].r - tree[lc].l + 1 - tree[lc].val;
    tree[rc].val = tree[rc].r - tree[rc].l + 1 - tree[rc].val;
    tree[lc].lazy ^= 1;
    tree[rc].lazy ^= 1;
    tree[node].lazy = 0;
}

void update(int node, int l, int r, int v) //[l,r]每个值^=v
{
    if (tree[node].r < l || tree[node].l > r) // 当前结点完全没被覆盖
        return;
    if (l <= tree[node].l && tree[node].r <= r) // 当前结点被完全覆盖
    {
        // tree[node].val += (tree[node].r - tree[node].l + 1) * v;
        tree[node].val = tree[node].r - tree[node].l + 1 - tree[node].val;
        tree[node].lazy ^= v; // 打上标记
        return;
    }
    if (tree[node].lazy != 0) // 下放标记
        pushDown(node);
    update(node << 1, l, r, v); // 更新左右孩子结点
    update(node * 2 + 1, l, r, v);
    pushUp(node); // 更新当前结点
}

int query(int node, int l, int r)
{
    if (tree[node].r < l || tree[node].l > r) // 当前结点完全没被覆盖
        return 0;
    if (l <= tree[node].l && tree[node].r <= r) // 当前结点被完全覆盖
        return tree[node].val;
    if (tree[node].lazy != 0) // 下放标记
        pushDown(node);
    int res = query(node << 1, l, r); // 查询左右孩子结点
    res += query(node * 2 + 1, l, r);
    pushUp(node); // 更新当前结点
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
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    for (int i = 1; i <= n; ++i)
        G[i] = str[i - 1] - '0';
    build(1, 1, n);
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 0)
        {
            int x, y, k = 1;
            cin >> x >> y;
            update(1, x, y, k); // [x,y]位置异或k
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << query(1, x, y) << endl; //[x,y]的和
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