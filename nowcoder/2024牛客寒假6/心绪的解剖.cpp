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
vector<int> fb;
struct Node
{
    ll ans, a, b, c;
    bool operator<(const Node &t) const
    {
        return ans < t.ans;
    }
};

set<Node> s;
void init()
{
    fb.push_back(0);
    fb.push_back(1);
    while (1)
    {
        ll now = fb.back() + fb[fb.size() - 2];
        if (now > 1e9)
            return;
        fb.push_back(now);
    }
}
void solve()
{
    int n;
    cin >> n;
    if (s.find({n, 0, 0, 0}) != s.end())
    {
        auto aa = s.find({n, 0, 0, 0});
        cout << (*aa).a << " " << (*aa).b << " " << (*aa).c << endl;
    }
    else
        cout << "-1\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    init();
    for (int i = 0; i < fb.size(); ++i)
        for (int j = 0; j < fb.size(); ++j)
            for (int k = 0; k < fb.size(); ++k)
                s.insert({fb[i] + fb[j] + fb[k], fb[i], fb[j], fb[k]});
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
