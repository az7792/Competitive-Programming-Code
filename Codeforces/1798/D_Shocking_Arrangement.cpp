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
    ll n, Min = 1e9, Max = -1e9, tmp;
    cin >> n;
    vector<ll> A, B, Z, ans;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        Min = min(Min, tmp);
        Max = max(Max, tmp);
        if (tmp > 0)
            A.eb(tmp);
        else if (tmp < 0)
            B.eb(tmp);
        else
            Z.eb(tmp);
    }
    if (Z.size() == n)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        ll sum = 0;
        while (!A.empty() || !B.empty())
        {
            if (sum <= 0)
            {
                sum += A.back();
                ans.eb(A.back());
                A.pop_back();
            }
            else if (sum > 0)
            {
                sum += B.back();
                ans.eb(B.back());
                B.pop_back();
            }
        }

        for (auto v : ans)
            cout << v << ' ';
        for (auto v : Z)
            cout << v << ' ';
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