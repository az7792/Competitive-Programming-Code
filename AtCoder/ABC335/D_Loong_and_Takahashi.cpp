#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> mp(n + 1, vector<int>(n + 1));
    mp[(n + 1) / 2][(n + 1) / 2] = -1;

    int N = (n - 1) / 2;
    int ct = 1;
    for (int I = 1; I <= N; ++I)
    {
        int X, Y;
        X = Y = I;
        int len = n - (I - 1) * 2;
        for (int i = 0; i < len; ++i)
            mp[X][Y + i] = ct++;

        for (int i = 0; i < len - 1; ++i)
            mp[X + i + 1][Y + len - 1] = ct++;

        for (int i = 0; i < len - 1; ++i)
            mp[X + len - 1][Y + len - 2 - i] = ct++;

        for (int i = 0; i < len - 2;++i)
            mp[X + len - 2 - i][Y] = ct++;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            if (mp[i][j] == -1)
                cout << "T ";
            else
                cout << mp[i][j] << ' ';
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
