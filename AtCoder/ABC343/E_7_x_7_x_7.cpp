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
    int a, b, c;
    Node(int aa, int bb, int cc)
    {
        a = aa, b = bb, c = cc;
    }
    bool operator==(Node A)
    {
        return (a == A.a && b == A.b && c == A.c);
    }
};
int get(Node A, Node B)
{
    int a = max(0, min(A.a + 7, B.a + 7) - max(A.a, B.a));
    int b = max(0, min(A.b + 7, B.b + 7) - max(A.b, B.b));
    int c = max(0, min(A.c + 7, B.c + 7) - max(A.c, B.c));
    return a * b * c;
}
int get3(Node A, Node B, Node C)
{
    int a = max(0, min({A.a + 7, B.a + 7, C.a + 7}) - max({A.a, B.a, C.a}));
    int b = max(0, min({A.b + 7, B.b + 7, C.b + 7}) - max({A.b, B.b, C.b}));
    int c = max(0, min({A.c + 7, B.c + 7, C.c + 7}) - max({A.c, B.c, C.c}));
    return a * b * c;
}
void Print(Node a)
{
    cout << a.a << " " << a.b << " " << a.c << " ";
}
void solve()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    Node A(0, 0, 0), B(0, 0, 0), C(0, 0, 0);
    for (B.a = -7; B.a <= 7; ++B.a)
        for (B.b = -7; B.b <= 7; ++B.b)
            for (B.c = -7; B.c <= 7; ++B.c)
                for (C.a = -7; C.a <= 7; ++C.a)
                    for (C.b = -7; C.b <= 7; ++C.b)
                        for (C.c = -7; C.c <= 7; ++C.c)
                        {
                            int AB = get(A, B), AC = get(A, C), BC = get(B, C);
                            int N1, N2, N3;
                            N3 = get3(A, B, C);
                            N2 = AB + AC + BC - 3 * N3;
                            N1 = 7 * 7 * 7 * 3 - 2 * N2 - 3 * N3;
                            if (N1 == n1 && N2 == n2 && N3 == n3)
                            {
                                cout << "Yes\n";
                                Print(A);
                                Print(B);
                                Print(C);
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
