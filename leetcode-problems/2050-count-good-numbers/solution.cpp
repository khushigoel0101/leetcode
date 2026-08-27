class Solution {
private:
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        if(exp==0) return 1;
        long long half = power(base,exp/2);
        long long res = (half*half)% MOD;
        if(exp%2==1){
            res = (base * res) % MOD;
        }
        return res;
    }

public:
    int countGoodNumbers(long long n) {
        long long eve = (n + 1) / 2;
        long long odd = n / 2;

        long long even = power(5, eve);
        long long oddn = power(4, odd);

        return (even * oddn) % MOD;
    }
};
