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
vector<ll> num((1 << 20) + 100);
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int ct = 0;
    for (int i = 1; i <= n; ++i)
        if (a[i] == 0)
            ct++;
        else
            break;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        // a[x]->y
        // 1 -> 1 + ct
        if ((a[x] == 0 && y == 0) || (a[x] != 0 && y != 0))
            ;
        else if (a[x] == 0 && y != 0)
            ct = min(ct, x - 1);
        else if (a[x] != 0 && y == 0)
        {
            a[x] = y;
            for (int i = ct + 1; i <= n; ++i)
            {
                if (a[i] == 0)
                    ct++;
                else
                    break;
            }
        }
        a[x] = y;
        if (n - ct < 1)
            cout << 1 << endl;
        else
            cout << num[n - ct] << endl;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    //
    // vector<int> a, b;
    // for (int i = 1; i <= 100; ++i)
    // {
    //     a.clear(), b.clear();
    //     a.resize(i, 0);
    //     // for (int j = 0; j < a.size(); ++j)
    //     //     a[j] = j + 1;
    //     // for (int j = 0; j < min(3, (int)a.size()); ++j)
    //     //     a[j] = 0;
    //     // if (i >= 2)
    //     //     a[1] = 1;
    //     b = a;
    //     int ct = 0;
    //     do
    //     {
    //         for (int j = 1; j < i; ++j)
    //             a[j] ^= a[j - 1];
    //         ct++;
    //     } while (a != b);
    //     cout << i << ":" << ct << endl;
    // }
    // return 0;

    int L = 0;
    for (int i = 0; i <= 20; ++i)
    {
        for (int j = L + 1; j <= (1 << i); ++j)
            num[j] = (1 << i);
        L = (1 << i);
    }
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
