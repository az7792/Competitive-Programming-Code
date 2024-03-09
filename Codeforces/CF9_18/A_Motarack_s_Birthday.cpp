#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    ll n, sum = 0;
    cin >> n;
    vector<ll> a(n + 1);
    vector<ll> b;
    ll ct = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == -1)
        {
            if (i - 1 >= 1 && a[i - 1] != -1)
                b.push_back(a[i - 1]);
            if (i + 1 <= n && a[i + 1] != -1)
                b.push_back(a[i + 1]);
        }
    }
    sort(all(b));
    ll L, R;
    if (b.size() == 0)
    {
        cout << "0 0\n";
        return;
    }
    if (b.size() == 1)
    {
        L = R = b.back();
    }
    else
    {
        L = (b.back() + b[0]) / 2;
        R = (b.back() + b[0] + 1) / 2;
    }
    ll Max1 = 0, Max2 = 0;
    for (int i = 1; i < n; ++i)
    {
        Max1 = max(Max1, abs((a[i] == -1 ? L : a[i]) - (a[i + 1] == -1 ? L : a[i + 1])));
        Max2 = max(Max2, abs((a[i] == -1 ? R : a[i]) - (a[i + 1] == -1 ? R : a[i + 1])));
    }
    cout << min(Max1, Max2) << ' ';
    if (Max1 < Max2)
        cout << L << endl;
    else
        cout << R << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}