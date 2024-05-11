#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
struct Node
{
    char ch;
    int end = 0;
    map<char, int> pos;
};
vector<Node> q;
void solve()
{
    int n;
    cin >> n;
    Node Head;
    Head.ch = '*';
    q.push_back(Head);
    vector<string> a(n + 2);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        int now = 0;
        for (int j = 0; j < a[i].size(); ++j)
        {
            auto it = q[now].pos.find(a[i][j]);
            if (it == q[now].pos.end())
            {
                Node tmp;
                tmp.ch = a[i][j];
                tmp.end++;
                q.push_back(tmp);
                q[now].pos[a[i][j]] = q.size() - 1;
                now = q.size() - 1;
            }
            else
            {
                now = q[now].pos[a[i][j]];
                q[now].end++;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int now = 0;
        for (int j = 0; j < a[i].size(); ++j)
        {
            auto it = q[now].pos.find(a[i][j]);
            now = (*it).second;
            q[now].end--;
            ans += q[now].end;
        }
    }
    cout << ans;
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
