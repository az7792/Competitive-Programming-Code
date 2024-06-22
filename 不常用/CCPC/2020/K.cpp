#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
vector<vector<double>> C(vector<vector<double>> &A, vector<vector<double>> &K)
{
    vector<vector<double>> CC = A;
    int n = A.size() - 1;
    for (int x = 1; x <= n; ++x)
        for (int y = 1; y <= n; ++y)
        {
            CC[x][y] = 0;
            for (int i = 1; i <= min(n - x + 1, 3); ++i)
                for (int j = 1; j <= min(n - y + 1, 3); ++j)
                    CC[x][y] += A[x + i - 1][y + j - 1] * K[i][j];
        }
    return CC;
}
void _solve()
{
    int n = 3;
    vector<vector<double>> K_(n + 1, vector<double>(n + 1, 0));
    vector<vector<double>> K(n + 1, vector<double>(n + 1, 0));
    cin >> n;
    vector<vector<double>> A(n + 1, vector<double>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> A[i][j];
    double sum = 0;
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
            cin >> K_[i][j], sum += K_[i][j];
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
            K[i][j] = K_[i][j] / sum;
    int t = 100;
    A = C(A, K);
    for (int i = 1; i <= 100; ++i)
    {
        A = C(A, K);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cout << A[i][j] << " \n"[j == n];
}
void solve()
{
    int n = 3;
    vector<vector<double>> K_(n + 1, vector<double>(n + 1, 0));
    cin >> n;
    vector<vector<int>> A(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> A[i][j];
    ll sum = 0;
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
            cin >> K_[i][j], sum += K_[i][j];
    if (K_[1][1] == sum)
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                cout << A[i][j] << " \n"[j == n];
    }
    else
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                cout << 0 << " \n"[j == n];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
