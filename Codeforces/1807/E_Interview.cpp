#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 5e5 + 10;
const ll MOD = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    vector<ll> sum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int L = 1, R = n, mid;
    while (L<R)
    {
        mid = (L + R) / 2;
        cout << "? " << (mid - L + 1) << ' ';
        for (int i = L; i <= mid;++i)
            cout << i << " \n"[i == mid];
        cout.flush();
        ll x;
        cin >> x;
        if(x==sum[mid]-sum[L-1])
            L = mid + 1;
        else
            R = mid;
    }
    cout << "! " << L << endl;
    cout.flush();
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}