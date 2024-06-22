#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
vector<int> a, b;
void dfs(int p)
{
    if (p >= a.size())
        return;
    dfs(p * 2);
    dfs(p * 2 + 1);
    a[p] = b.back();
    b.pop_back();
}
void solve()
{
    a.clear(), b.clear();
    int n;
    cin >> n;
    a.resize(n + 1, 0), b.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    reverse(all(b));
    dfs(1);
    queue<int> Q;
    Q.push(1);
    vector<int> ans;
    while (!Q.empty())
    {
        int pp = Q.front();
        Q.pop();
        if (pp > n)
            continue;
        ans.push_back(a[pp]);
        Q.push(pp * 2);
        Q.push(pp * 2 + 1);
    }
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i];
        if (i != n - 1)
            cout << " ";
    }
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
