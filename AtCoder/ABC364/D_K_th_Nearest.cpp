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
    int n, q, b, k;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    while (q--)
    {
        cin >> b >> k;
        int p = upper_bound(a.begin() + 1, a.end(), b) - a.begin();
        int l = max(1, p - k), r = p - 1, L = p, R = min(n, p + k - 1), mid;
        if (r <= 0)
        {
            cout << abs(a[R] - b) << endl;
            continue;
        }
        else if (L > n)
        {
            cout << abs(a[l] - b) << endl;
            continue;
        }
        int nl = min(abs(b - a[r]), abs(b - a[L]));
        int nr = max(abs(b - a[l]), abs(b - a[R]));
        while (nl < nr)
        {
            mid = (nl + nr + 1) / 2;
            int n1 = lower_bound(a.begin() + L, a.begin() + R + 1, mid + b) - a.begin() - L;
            int n2 = r - (upper_bound(a.begin() + l, a.begin() + r + 1, b - mid) - a.begin()) + 1;

            int N1 = upper_bound(a.begin() + L, a.begin() + R + 1, mid + b) - a.begin() - L;
            int N2 = r - (lower_bound(a.begin() + l, a.begin() + r + 1, b - mid) - a.begin()) + 1;
            if (n1 + n2 >= k)
                nr = mid - 1;
            else if (N1 + N2 < k)
                nl = mid + 1;
            else
                nl = mid;
        }
        cout << nl << endl;
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
