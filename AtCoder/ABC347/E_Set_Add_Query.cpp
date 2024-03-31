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
    vector<ll> a(n + 1);
    ll tmp = 0;
    set<ll> s;
    while (q--)
    {
        int x;
        cin >> x;
        if (s.find(x) == s.end())
        {
            s.insert(x);
            a[x] -= tmp;
            tmp += s.size();
        }
        else
        {
            s.erase(x);
            a[x] += tmp;
            tmp += s.size();
        }
    }
    for (auto v : s)
        a[v] += tmp;
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
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
