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
    vector<ll> a(n + 1);
    vector<vector<int>> num(n + 1, vector<int>(33, 0));
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        bitset<33> tmp(a[i]);
        for (int j = 0; j < 33; ++j)
        {
            num[i][j] = num[i - 1][j];
            if (tmp[j] == 0)
                num[i][j] += 1;
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        ll l, k;
        cin >> l >> k;
        int L = l, R = n, mid;
        while (L < R)
        {
            mid = (L + R + 1) / 2;
            int ans = 0;
            for (int i = 0; i < 33; ++i)
                if (num[mid][i] - num[l - 1][i] == 0)
                    ans += (1 << i);
            if (ans >= k)
                L = mid;
            else
                R = mid - 1;
        }
        int ans = 0;
        for (int i = 0; i < 32; ++i)
            if (num[L][i] - num[l - 1][i] == 0)
                ans += (1 << i);
        if(ans>=k)
            cout << L << ' ';
        else
            cout << "-1 ";
    }
    cout << endl;
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