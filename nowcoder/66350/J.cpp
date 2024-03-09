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
ll n, k;
void solve()
{
    cin >> n >> k;
    vector<ll> num(n, -1);
    num[0] = 0;
    queue<int> Q;
    Q.push(0);
    while (!Q.empty())
    {
        int p = Q.front();
        Q.pop();
        int tmp = (p + 1) % n;
        if (num[tmp] == -1)
        {
            num[tmp] = num[p] + 1;
            Q.push(tmp);
        }
        tmp = (p + k) % n;
        if (num[tmp] == -1)
        {
            num[tmp] = num[p] + 1;
            Q.push(tmp);
        }
    }
    cout << *max_element(all(num));
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