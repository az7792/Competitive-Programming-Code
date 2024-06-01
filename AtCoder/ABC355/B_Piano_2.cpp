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
    int a, b;
    cin >> a >> b;
    vector<int> A(a), B(b);
    set<int> s;
    vector<int> C;
    for (int i = 0; i < a; ++i)
    {
        cin >> A[i];
        C.push_back(A[i]);
    }
    for (int i = 0; i < A.size(); ++i)
    {
        s.insert(A[i]);
    }
    for (int i = 0; i < b; ++i)
    {
        cin >> B[i];
        C.push_back(B[i]);
    }
    sort(all(C));
    for (int i = 1; i < C.size(); ++i)
    {
        if (s.find(C[i - 1]) != s.end() && s.find(C[i]) != s.end())
        {
            cout << "Yes";
            return;
        }
    }
    cout << "No";
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
