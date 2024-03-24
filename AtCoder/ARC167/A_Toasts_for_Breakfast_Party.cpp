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
    ll n, m;
    cin >> n >> m;
    deque<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    ll Max = m * 2 - n, ans = 0;
    for (int i = 0; i < Max; ++i)
    {
        ans += a.back() * a.back();
        a.pop_back();
    }
    for (int i = 0; i < n - Max; i += 2)
    {
        ans += (a.back() + a.front()) * (a.back() + a.front());
        a.pop_back();
        a.pop_front();
    }
    cout << ans;
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
