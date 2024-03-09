#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
vector<int> a;
void dfs(int p)
{
    cout << p << " ";
    if (a[p] == 0)
        return;
    dfs(a[p]);
}
void solve()
{
    int n, tmp;
    cin >> n;
    a.resize(n + 1, 0);
    int h;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tmp;
        if (tmp == -1)
            h = i;
        else
            a[tmp] = i;
    }
    dfs(h);
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
