#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    vector<int> a(4);
    vector<int> vis(4, 1);
    int M, n;
    for (int i = 0; i < 4; ++i)
        cin >> a[i];
    cin >> M >> n;
    for (int i = 0; i < 4; ++i)
    {
        if (a[i] < M || *max_element(all(a)) - a[i] > n)
            vis[i] = 0;
    }
    if (count(all(vis), 0) >= 2)
        cout << "Warning: please check all the tires!";
    else if (count(all(vis), 0) == 0)
        cout << "Normal";
    else
    {
        for (int i = 0; i < 4; ++i)
            if (vis[i] == 0)
            {
                cout << "Warning: please check #" << i + 1 << "!";
                return;
            }
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
