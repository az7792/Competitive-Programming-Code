#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<ll> a(3, 1);
int ct = 1;
int n;
void solve()
{
    cin >> n;
    int l = 0;
    while (ct < n)
    {
        if (l == 0)
        {
            a[0] = a[0] * 10 + 1;
            a[1] = a[2] = 1;
            l = 1;
            ct++;
        }
        else if (l == 1)
        {
            if (a[0] == a[1] && a[1] == a[2])
                l = 0;
            else if (a[1] == a[2])
            {
                a[1] = a[1] * 10 + 1;
                a[2] = 1;
                ct++;
                l = 2;
            }
        }
        else
        {
            a[2] = a[2] * 10 + 1;
            ct++;
            if (a[2] == a[1])
                l = 1;
        }
    }
    cout << a[0] + a[1] + a[2];
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
