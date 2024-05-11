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
    int n, h, x;
    cin >> n >> h >> x;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    for (int i = 1; i <= n; ++i)
        if (p[i] + h >= x)
        {
            cout << i;
            return;
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
