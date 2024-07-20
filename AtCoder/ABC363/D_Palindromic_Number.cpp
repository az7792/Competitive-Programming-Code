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
vector<ll> a;
vector<ll> dex;
void init()
{
    a.push_back(10);
    a.push_back(9);
    ll de = 10;
    for (int i = 3; i <= 38; ++i)
    {
        if (i % 2 == 1)
        {
            a.push_back(de * 9);
            de *= 10;
        }
        else
            a.push_back(a.back());
    }
    dex.push_back(1);
    de = 1;
    for (int i = 1; i <= 18; ++i)
    {
        de *= 10;
        dex.push_back(de);
    }
}

void solve()
{
    ll n;
    cin >> n;
    if (n <= 10)
    {
        cout << n - 1;
        return;
    }
    init();
    ll now = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        if (now >= n - a[i])
        {
            // cout << i + 1 << " " << n - now;
            n -= now;
            vector<int> ans(i + 2, 0);

            for (int l = 1; l <= (i + 2) / 2; ++l)
            {
                int len = ((i + 1 - l) - (l + 1) + 1 + 1) / 2;
                for (int r = (l == 1 ? 1 : 0); r <= 9; ++r)
                {
                    if (dex[len] >= n)
                    {
                        ans[l] = ans[i + 1 - l + 1] = r;
                        break;
                    }
                    n -= dex[len];
                }
            }

            for (int kkk = 1; kkk < ans.size(); ++kkk)
                cout << ans[kkk];
            return;
        }
        else
            now += a[i];
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
