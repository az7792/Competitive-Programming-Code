#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {-1, 0, 1, 0};
int ty[] = {0, 1, 0, -1};
void solve()
{
    int n, m, N;
    cin >> n >> m >> N;
    vector g(n, vector<char>(m, '.'));
    int x = 0, y = 0, sp = 0;
    for (int i = 0; i < N; ++i)
    {
        if (g[x][y] == '.')
        {
            g[x][y] = '#';
            sp = (sp + 1) % 4;
            x = (x + tx[sp] + n) % n;
            y = (y + ty[sp] + m) % m;
        }
        else
        {
            g[x][y] = '.';
            sp = (sp - 1 + 4) % 4;
            x = (x + tx[sp] + n) % n;
            y = (y + ty[sp] + m) % m;
        }
        //cerr << x << " " << y << endl;
    }
    for (auto v : g)
    {
        for (auto vv : v)
            cout << vv;
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