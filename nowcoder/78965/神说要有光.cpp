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
    vector<vector<char>> g(n + 1, vector<char>(n + 1, 'a'));
    int q;
    cin >> q;
    while (q--)
    {
        int op, a;
        char b;
        cin >> op;
        if (op == 1)
        {
            cin >> a >> b;
            for (int i = 1; i <= n; ++i)
                g[a][i] = b;
        }
        else if (op == 2)
        {
            cin >> a >> b;
            for (int i = 1; i <= n; ++i)
                g[i][a] = b;
        }
        else if (op == 3)
        {
            cin >> a >> b;
            for (int i = 1; i <= n; ++i)
                if (a - i >= 1 && a - i <= n)
                    g[i][a - i] = b;
        }
        else if (op == 4)
        {
            cin >> a >> b;
            for (int i = 1; i <= n; ++i)
                if (i - a >= 1 && i - a <= n)
                    g[i][i - a] = b;
        }
        else if (op == 5)
        {
            cin >> a;
            for (int i = 1; i <= n; ++i)
                cout << g[a][i];
            cout << endl;
        }
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
