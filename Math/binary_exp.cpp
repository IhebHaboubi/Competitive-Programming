ll modpow(ll a, ll k, ll mod)
{
    ll ans = 1;
    while (k)
    {
        if (k & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        k >>= 1;
    }
    return ans;
}

// Note 1: this formula works only if mod is a prime number
// for a general solution, use euler's totient function
// Note 2: a and mod need to be relatively prime,
// otherwise the answer does not exist
inline ll modinv(ll a, ll mod) { return modpow(a, mod - 2, mod); }
