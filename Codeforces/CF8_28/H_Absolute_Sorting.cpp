#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<ll> num;
void solve()
{
    int n;
    cin >> n;
    num.clear();
    num.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> num[i];
    ll L = 0, R = 1e9;
    for (int i = 0; i < n - 1; ++i)
    {
        if (num[i] < num[i + 1])
        {
            // 2R<=a+b
            R = min(R, (num[i] + num[i + 1]) / 2);
        }
        else if(num[i]>num[i+1])
        {
            L = max(L, (num[i] + num[i + 1] + 1) / 2);
        }
    }
    if (L<=R)
        cout << L << endl;
    else
        cout << -1 << endl;
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