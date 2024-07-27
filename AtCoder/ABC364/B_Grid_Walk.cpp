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
    int n, m;
    cin >> n >> m;
    vector<string> mp(n);
    int x, y;
    cin >> x >> y;
    x--, y--;
    for (int i = 0; i < n; ++i)
        cin >> mp[i];
    string path;
    cin >> path;
    int nx = x, ny = y;
    for (auto v : path)
    {
        if (v == 'L')
        {
            ny--;
        }
        else if (v == 'R')
        {
            ny++;
        }
        else if (v == 'U')
        {
            nx--;
        }
        else
            nx++;
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
        {
            nx = x, ny = y;
        }
        else if (mp[nx][ny] == '#')
        {
            nx = x, ny = y;
        }
        else
        {
            x = nx, y = ny;
        }
    }
    cout << x + 1 << " " << y + 1;
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
