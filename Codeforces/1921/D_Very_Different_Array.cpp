#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
vector<ll> a, b;
void solve()
{
    a.clear(), b.clear();
    ll n, m;
    cin >> n >> m;
    a.resize(n), b.resize(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    sort(all(b));
    sort(all(a));
    deque<ll> A, B;
    for (auto v : a)
        A.push_back(v);
    for (auto v : b)
        B.push_back(v);
    ll ans = 0;
    while (!A.empty())
    {
        if (abs(A.front() - B.back()) >= abs(A.back() - B.front()))
        {
            ans += abs(A.front() - B.back());
            A.pop_front();
            B.pop_back();
        }
        else
        {
            ans += abs(A.back() - B.front());
            A.pop_back();
            B.pop_front();
        }
    }
    cout << ans << endl;
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
