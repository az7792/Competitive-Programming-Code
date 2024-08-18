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
    int a, b, c;
    cin >> a >> b >> c;
    if (b <= c)
    {
        if (b <= a && a < c)
            cout << "No";
        else
            cout << "Yes";
    }
    else
    {
        c += 24;
        for (int i = b; i < c; ++i)
        {
            if (i % 24 == a || i == a)
            {
                cout << "No";
                return;
            }
        }
        cout << "Yes";
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
