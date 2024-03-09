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
    int n, k;
    cin >> n >> k;
    k %= (n + 1);
    vector<int> a(n);
    vector<int> ct(n + 2, 0);
    set<int> S;
    for (int i = 0; i <= n + 1; ++i)
        S.insert(i);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ct[a[i]]++;
        S.erase(a[i]);
    }
    if (k == 0)
        for (int i = 0; i < n; ++i)
            cout << a[i] << " \n"[i == n - 1];
    else
    {
        int End = n + 1 - k;
        for (int i = 0; i < End; ++i)
        {
            int tmp = a[i];
            a[i] = *S.begin();
            S.erase(S.begin());
            ct[tmp]--;
            if (ct[tmp] == 0)
                S.insert(tmp);
        }
        int CT = 0;
        for (int i = (End % n); CT < n; i = (i + 1) % n, ++CT)
            cout << a[i] << " \n"[CT == n - 1];
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