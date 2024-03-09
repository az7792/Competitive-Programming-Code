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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    sort(all(a));
    int ans = 2e9, P, pi;
    for (int i = 0; i < n; ++i)
    {
        int p = upper_bound(all(a), b[i]) - a.begin();
        if (p == 0)
        {
            if (abs(b[i] - a[p]) < ans)
            {
                ans = abs(b[i] - a[p]);
                P = p;
                pi = i;
            }
        }
        else if (p == n)
        {
            if (abs(b[i] - a[p - 1]) < ans)
            {
                ans = abs(b[i] - a[p - 1]);
                P = p - 1;
                pi = i;
            }
        }
        else
        {
            if (abs(b[i] - a[p]) < ans)
            {
                ans = abs(b[i] - a[p]);
                P = p;
                pi = i;
            }
            if (abs(b[i] - a[p - 1]) < ans)
            {
                ans = abs(b[i] - a[p - 1]);
                P = p-1;
                pi = i;
            }
        }
    }
    swap(a[pi], a[P]);
    for (auto v : a)
        cout << v << " ";
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
