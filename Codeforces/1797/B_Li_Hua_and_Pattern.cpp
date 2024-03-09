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
map<ll, ll> mp;
int tx[] = {0, 0, -1, 1};
int ty[] = {-1, 1, 0, 0};
int A[1010][1010];
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> A[i][j];
    int ct = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (A[i][j] != A[n - i + 1][n - j + 1])
                ct++;
    ct /= 2;
    if (ct > k)
        cout << "NO\n";
    else
    {
        if ((k - ct) % 2 == 0)
            cout << "YES\n";
        else
        {
            if(n%2==1)
                cout << "YES\n";
            else
                cout<<"NO\n";
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*




*/