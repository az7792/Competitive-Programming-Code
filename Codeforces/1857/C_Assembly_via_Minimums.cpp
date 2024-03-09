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
    ll n, N;
    cin >> n;
    N = n * (n - 1) / 2ll;
    vector<ll> B(N + 10, 0);
    for (int i = 1; i <= N; ++i)
        cin >> B[i];
    sort(B.begin() + 1, B.begin() + 1 + N);
    ll sum = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        sum += i;
        cout << B[sum] << ' ';
    }
    cout << B[N];
    cout << endl;
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