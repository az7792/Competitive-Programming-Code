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
vector<int> r(10);
int n, k;
vector<string> ans;
string tmp;
void dfs(int p)
{
    if (p == n + 1)
    {
        // cout << tmp << endl;
        int sum = 0;
        for (auto v : tmp)
        {
            sum += (v - '0');
        }
        if (sum % k == 0)
            ans.push_back(tmp);
        return;
    }

    for (int i = 1; i <= r[p]; ++i)
    {
        tmp.push_back(i + '0');
        dfs(p + 1);
        tmp.pop_back();
    }
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> r[i];
    dfs(1);
    sort(all(ans));
    for (auto v : ans)
    {
        for (auto vv : v)
            cout << vv << " ";
        cout << endl;
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
