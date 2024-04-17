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
    cin >> n;
    string A, B;
    cin >> A >> B;
    cin >> q;
    set<int> sa, sb;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (A[i] == '0')
            sa.insert(i + 1);
        if (B[i] == '0')
            sb.insert(i + 1);
        if (A[i] == B[i] && A[i] == '1')
            ans++;
    }
    while (q--)
    {
        char ch;
        int l, r;
        cin >> ch >> l >> r;
        if (ch == 'A')
        {
            set<int>::iterator L = sa.lower_bound(l);
            set<int>::iterator tmpL = L;

            if (L != sa.end())
            {
                set<int>::iterator R = sa.upper_bound(r);

                for (; L != R; L++)
                {
                    if (sb.find(*L) == sb.end())
                        ans++;
                }
                sa.erase(tmpL, R);
            }
        }
        else
        {
            set<int>::iterator L = sb.lower_bound(l);
            set<int>::iterator tmpL = L;
            if (L != sb.end())
            {
                set<int>::iterator R = sb.upper_bound(r);
                for (; L != R; L++)
                {
                    if (sa.find(*L) == sa.end())
                        ans++;
                }
                sb.erase(tmpL, R);
            }
        }
        cout << ans << endl;
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
