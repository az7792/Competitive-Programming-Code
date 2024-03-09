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
void solve()
{
    int n;
    cin >> n;
    vector<set<int>> g(n + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int ok;
            cin >> ok;
            if (ok == 1)
            {
                g[i].insert(j);
                g[j].insert(i);
            }
        }
    for (int i = 1; i <= n; ++i)
    {
        for (auto v : g[i])
            cout << v << " ";
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
