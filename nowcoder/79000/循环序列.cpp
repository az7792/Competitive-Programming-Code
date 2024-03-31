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
    int n, q;
    cin >> n >> q;
    vector<int> a(2e6);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = n; i <= 1e6 + 100; ++i)
        a[i] = a[i % n];
    while (q--)
    {
        int l, r, t;
        cin >> l >> r >> t;
        l--, r--;
        ll num = 0;
        for (int i = l; i <= r; ++i)
            if (a[i] == t)
                num++;
        cout << num * (num - 1) / 2 << endl;
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
