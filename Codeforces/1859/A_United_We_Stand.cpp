#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b, c;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(all(a));
    if (a == vector<int>(n, a[0]))
    {
        cout << -1 << endl;
    }
    else
    {
        for (int i = 0; i < n;++i)
        {
            if(a[i]==a[0])
                b.eb(a[i]);
            else
                break;
        }
        cout << b.size() << ' ' << n - b.size() << endl;
        for(auto v:b)
            cout << v << ' ';
        cout << endl;
        for (int i = b.size();i<n; ++i)
        {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
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