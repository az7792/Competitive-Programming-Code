#include <bits/stdc++.h> //寄
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
char A[4][4][4];
char B[4][4][4];
char C[4][4][4];
bool D[4][4];
bool ok()
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (D[i][j] == false)
                return 0;
    return 1;
}
void solve()
{
    for (int j = 0; j < 4; ++j)
        for (int k = 0; k < 4; ++k)
            cin >> A[0][j][k];
    for (int j = 0; j < 4; ++j)
        for (int k = 0; k < 4; ++k)
            cin >> B[0][j][k];
    for (int j = 0; j < 4; ++j)
        for (int k = 0; k < 4; ++k)
            cin >> C[0][j][k];
    for (int i = 1; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                A[i][j][k] = A[i - 1][3 - k][j];
    for (int i = 1; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                B[i][j][k] = B[i - 1][3 - k][j];
    for (int i = 1; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                C[i][j][k] = C[i - 1][3 - k][j];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                for (int ax = -3; ax < 4; ++ax)
                    for (int ay = -3; ay < 4; ++ay)
                        for (int bx = -3; bx < 4; ++bx)
                            for (int by = -3; by < 4; ++by)
                                for (int cx = -3; cx < 4; ++cx)
                                    for (int cy = -3; cy < 4; ++cy)
                                    {
                                        bool f = true;
                                        for (int n = 0; n < 4; ++n)
                                            for (int m = 0; m < 4; ++m)
                                                D[n][m] = false;
                                        for (int n = 0; n < 4; ++n)
                                        {
                                            for (int m = 0; m < 4; ++m)
                                                if (A[i][n][m] == '#')
                                                {
                                                    int X = n + ax;
                                                    int Y = m + ay;
                                                    if (X >= 4 || Y >= 4 || X < 0 || Y < 0)
                                                    {
                                                        f = false;
                                                        break;
                                                    }
                                                    if (D[X][Y])
                                                    {
                                                        f = false;
                                                        break;
                                                    }
                                                    D[X][Y] = true;
                                                }
                                            if (!f)
                                                break;
                                        }
                                        if (!f)
                                            continue;
                                        ;
                                        for (int n = 0; n < 4; ++n)
                                        {
                                            for (int m = 0; m < 4; ++m)
                                                if (B[j][n][m] == '#')
                                                {
                                                    int X = n + bx;
                                                    int Y = m + by;
                                                    if (X >= 4 || Y >= 4 || X < 0 || Y < 0)
                                                    {
                                                        f = false;
                                                        break;
                                                    }
                                                    if (D[X][Y])
                                                    {
                                                        f = false;
                                                        break;
                                                    }
                                                    D[X][Y] = true;
                                                }
                                            if (!f)
                                                break;
                                        }
                                        if (!f)
                                            continue;
                                        for (int n = 0; n < 4; ++n)
                                        {
                                            for (int m = 0; m < 4; ++m)
                                                if (C[k][n][m] == '#')
                                                {
                                                    int X = n + cx;
                                                    int Y = m + cy;
                                                    if (X >= 4 || Y >= 4 || X < 0 || Y < 0)
                                                    {
                                                        f = false;
                                                        break;
                                                    }
                                                    if (D[X][Y])
                                                    {
                                                        f = false;
                                                        break;
                                                    }
                                                    D[X][Y] = true;
                                                }
                                            if (!f)
                                                break;
                                        }
                                        if (!f)
                                            continue;
                                        if (ok())
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