class Solution {
public:
    int countPrimes(int n) {
       return sieve_of_eratosthenes_method(n); 
    }

    // sieve of eratosthenes
    // Time Complexity O(root(n) * loglogn + n)
    // Space Complexity O(n)  
    int sieve_of_eratosthenes_method(int n) {
        if (n <= 2) {
            return 0;
        }

        vector<bool> sieve(n, true);
        for (int i = 2; i <= sqrt(n); ++i) {
            if (sieve[i]) {
                for (int j = i * i; j < n; j+= i) {
                    sieve[j] = false;
                }
            }
        }
        int numPrimes = 0;
        for (int i = 2; i < n; ++i) {
            if (sieve[i] == true) numPrimes++;
        }
        return numPrimes;
    }
}