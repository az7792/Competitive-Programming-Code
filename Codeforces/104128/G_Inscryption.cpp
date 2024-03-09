#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int o = 0, p = 0, q = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            o++;
        }
        else if (a[i] == 1)
        {
            p++;
        }
        else
        {
            q++;
        }
        if (p < q + o)
        {
            if (o > 0)
            {
                p++;
                o--;
            }
            else
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    q += o;
    int x = p + 1;
    int y = p - q + 1;

    cout << x / gcd(x, y) << ' ' << y / gcd(x, y) << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}