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
    ll a, b, C;
    ll Ma = 1ll << 60;
    cin >> a >> b >> C;
    bitset<60> cc(C);
    bitset<60> A(0);
    bitset<60> B(0);
    int one = cc.count();
    int zero = 60 - one;
    if (a + b < one)
    {
        cout << -1;
        return;
    }
    for (int XX = 0; XX <= min(a, (ll)one); ++XX)
    {
        int x = XX;
        int y = one - x;
        if (y > b || y < 0)
            continue;
        int zx = a - x;
        int zy = b - y;
        if (zx != zy || zx > zero || zx < 0)
            continue;
        // yes
        for (int i = 0; i < 60; ++i)
        {
            if (cc[i] == 1)
            {
                if (x > 0)
                {
                    A[i] = 1;
                    x--;
                }
                else if (y > 0)
                {
                    B[i] = 1;
                    y--;
                }
                else
                    break;
            }
        }

        for (int i = 0; i < 60; ++i)
        {
            if (zx <= 0)
                break;
            if (A[i] == 0 && B[i] == 0)
            {
                A[i] = 1;
                B[i] = 1;
                zx--;
            }
        }

        ll ans1 = 0, ans2 = 0;
        for (int i = 0; i < 60; ++i)
            ans1 += (1ll << i) * A[i];

        for (int i = 0; i < 60; ++i)
            ans2 += (1ll << i) * B[i];

        bitset<60> result = A ^ B;
        if (A.count() == a && B.count() == b && result == cc)
        {
            if ((ans1 < Ma && ans1 >= 0) && (ans2 < Ma && ans2 >= 0))
            {
                cout << ans1 << " " << ans2;
                return;
            }
        }
    }
    cout << -1;
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
