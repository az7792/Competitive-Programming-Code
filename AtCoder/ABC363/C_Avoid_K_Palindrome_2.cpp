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
    int n, k;
    string s;
    cin >> n >> k >> s;
    set<string> sss;
    vector<int> a(n);
    sort(all(s));
    do
    {
        sss.insert(s);
    } while (next_permutation(all(s)));
    int ct = sss.size();
    bool ok = 0;
    for (auto &v : sss)
    {
        ok = 0;
        for (int i = 0; i + k <= n; ++i)
        {
            bool ok1 = 1;
            for (int l = i, r = i + k - 1; l <= r; ++l, --r)
            {
                if (v[l] != v[r])
                {
                    ok1 = 0;
                    break;
                }
            }
            if (ok1 == 1)
            {
                ok = 1;
                break;
            }
        }
        if (ok)
            ct--;
    }
    cout << ct;
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
