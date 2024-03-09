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
    int n, m, l;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    cin >> l;
    vector<int> c(l);
    for (int i = 0; i < l; ++i)
        cin >> c[i];
    set<int> s;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < l; ++k)
            {
                s.insert(a[i] + b[j] + c[k]);
            }
    int r;
    cin >> r;
    vector<int> x(r);
    for (int i = 0; i < r; ++i)
        cin >> x[i];

    for (int i = 0; i < r; ++i)
    {
        cout << (s.count(x[i]) == 1 ? "Yes\n" : "No\n");
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
