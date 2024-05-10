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
    int n, a, k;
    cin >> n >> a >> k;
    int now = a + 1;
    string str = to_string(now);
    bool f = 1;
    for (auto v : str)
        if (v == '7')
            f = 0;
    if (now % 7 != 0 && f)
        cout << now << " ";
    else
        cout << "p"
             << " ";
    for (int i = 1; i < k; ++i)
    {
        now += n;
        str = to_string(now);
        f = 1;
        for (auto v : str)
            if (v == '7')
                f = 0;
        if (now % 7 != 0 && f)
            cout << now << " ";
        else
            cout << "p"
                 << " ";
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
