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
struct Node
{
    int x, y;
    bool operator<(const Node a) const
    {
        return x + y < a.x + a.y;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    priority_queue<Node> q;
    set<int> s;
    for (int i = 1; i <= n; ++i)
    {
        if (s.find(a[i] + i) == s.end())
            s.insert(a[i] + i);
        else
            q.push({a[i], i});
    }
    int r = 2e9;
    while (!q.empty())
    {
        Node tmp = q.top();
        q.pop();
        r = min(r, tmp.x + tmp.y);
        bool f = 1;
        for (int i = r; i >= 1; --i)
        {
            if (s.find(i) == s.end())
            {
                s.insert(i);
                r = i - 1;
                f = 0;
                break;
            }
        }
        if (f)
            break;
    }
    vector<int> ans;
    for (auto v : s)
        ans.push_back(v);
    for (int i = ans.size() - 1; i >= 0; --i)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
