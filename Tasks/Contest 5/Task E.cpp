#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    if (std::cin >> t) {
        long long b1, q, n, num, inv, p;
        long long mod = 1000000007;

        while (t--) {
            std::cin >> b1 >> q >> n;

            if (n == 0 || b1 == 0) { std::cout << 0 << "\n"; continue; }
            if (q == 1) { std::cout << (b1 * (n % mod)) % mod << "\n"; continue; }
            if (q == 0) { std::cout << b1 % mod << "\n"; continue; }

            inv = 1; p = mod - 2;
            num = (q - 1 + mod) % mod;
            while (p > 0) {
                if (p % 2 == 1) inv = (inv * num) % mod;
                num = (num * num) % mod;
                p /= 2;
            }

            num = 1;
            while (n > 0) {
                if (n % 2 == 1) num = (num * q) % mod;
                q = (q * q) % mod;
                n /= 2;
            }
            num = (num - 1 + mod) % mod;

            std::cout << (((b1 % mod) * num % mod) * inv) % mod << "\n";
        }
    }
    return 0;
}
