#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ull m1 = 1e9 + 7, m2 = 998244353;
ull X1 = 13331, X2 = 133331;
vector<ull> h1, h2;
vector<ull> x1, x2;
set<pair<ull, ull>> ans;

void Hash(string &str, vector<ull> &h, vector<ull> &x, ull &m, ull &X)
{
    h.clear(), x.clear();
    h.resize(str.size());
    x.resize(str.size());
    h[0] = str[0], x[0] = 1;
    for (int i = 1; i < str.size(); ++i)
    {
        h[i] = (h[i - 1] * X + str[i]) % m;
        x[i] = (x[i - 1] * X) % m;
    }
}
ull getHash(int L, int R, vector<ull> &h, vector<ull> &x, ull &m) // hash[L,R]
{
    if (L > R)
        return 0;
    return (h[R] - (L > 0 ? (h[L - 1] * x[R - L + 1]) % m : 0) + m) % m;
}
ull getHash(string &str, int L, int R, vector<ull> &h, vector<ull> &x, ull &m)
{
    ull hashL = getHash(0, L - 1, h, x, m);
    ull hashR = getHash(R + 1, str.size() - 1, h, x, m);
    return ((hashL * x[str.size() - R - 1]) % m + hashR) % m;
}
ull getHash(string str, ull m, ull X)
{
    ull h = str[0];
    for (int i = 1; i < str.size(); ++i)
        h = (h * X + str[i]) % m;
    return h;
}
void solve()
{
    int n;
    cin >> n;
    string str;
    ans.clear();
    cin >> str;
    Hash(str, h1, x1, m1, X1);
    Hash(str, h2, x2, m2, X2);
    for (int i = 0; i + 1 < str.size(); i++)
    {
        ull hash1 = getHash(str, i, i + 1, h1, x1, m1);
        ull hash2 = getHash(str, i, i + 1, h2, x2, m2);
        ans.emplace(hash1, hash2);
    }
    cout << ans.size() << endl;
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