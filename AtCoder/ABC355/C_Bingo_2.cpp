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
    int n, t;
    cin >> n >> t;
    vector<int> row(n + 1, 0);
    vector<int> col(n + 1, 0);
    int a = 0, b = 0;
    vector<int> T(t + 1);

    for (int i = 1; i <= t; ++i)
        cin >> T[i];
    for (int i = 1; i <= t; ++i)
    {
        int tmp;
        tmp = T[i];
        int x, y;
        if (tmp % n == 0)
            x = tmp / n, y = n;
        else
        {
            x = (tmp + n - 1) / n;
            y = tmp - (x - 1) * n;
        }
       // cout << x << " " << y << endl;
        row[x]++;
        if (row[x] == n)
        {
            cout << i;
            return;
        }
        col[y]++;
        if (col[y] == n)
        {
            cout << i;
            return;
        }
        if (x == y)
        {
            a++;
            if (a == n)
            {
                cout << i;
                return;
            }
        }
        if (x + y == n + 1)
        {
            b++;
            if (b == n)
            {
                cout << i;
                return;
            }
        }
    }
    cout << -1;
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
