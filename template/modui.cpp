#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 5e4 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
struct Node
{
    int l, r, p;
} q[MAX];
ll res = 0;
vector<int> pos(MAX), num(MAX), a(MAX), ans(MAX);
void ADD(int p)
{
    res += num[a[p]] * 2 + 1;
    num[a[p]]++;
}
void SUB(int p)
{
    res += 1 - 2 * num[a[p]];
    num[a[p]]--;
}
void solve()
{
    int n, m, k, siz;
    cin >> n >> m >> k;
    // 分块
    siz = sqrt(n);
    for (int i = 1; i <= n; ++i)
        pos[i] = i / siz;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 0; i < m; ++i)
    {
        cin >> q[i].l >> q[i].r;
        q[i].p = i;
    }
    // 排序询问 左区间所在的块相同就按右区间排，否则按左区间所在块排
    sort(q, q + m, [](Node A, Node B)
         { return pos[A.l] == pos[B.l] ? A.r < B.r : pos[A.l] < pos[B.l]; });
    int l = 1, r = 0;
    for (int i = 0; i < m; ++i)
    {
        while (q[i].l < l)
            ADD(--l);
        while (q[i].l > l)
            SUB(l++);
        while (q[i].r < r)
            SUB(r--);
        while (q[i].r > r)
            ADD(++r);
        ans[q[i].p] = res;
    }
    for (int i = 0; i < m; ++i)
        cout << ans[i] << endl;
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
