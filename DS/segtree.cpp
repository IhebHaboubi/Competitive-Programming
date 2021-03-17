#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int N = 2e5;
int t[2 * N];
int n;

// change the neutral element and the query function depending on the problem
const int neutral = 0;
inline int f(int x, int y) { return x + y; }

// the tree is 0-indexed
void build()
{
    for (int i = 0; i < n; i++) cin >> t[i + n];
    for (int i = n - 1; i > 0; i--) t[i] = f(t[i << 1], t[i << 1 | 1]);
}

void update(int p, int value)
{
    for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = f(t[p], t[p ^ 1]);
}

// query the range [l, r], l and r are inclusive
int query(int l, int r)
{
    int ans = neutral;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1) ans = f(ans, t[l++]);
        if (r & 1) ans = f(ans, t[--r]);
    }
    return ans;
}
