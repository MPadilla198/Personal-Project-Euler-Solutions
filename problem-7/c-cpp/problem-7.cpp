#include <iostream>

#include "../../utils/cpp/prime_sieve.cpp"

using namespace std;

int main()
{
    // This size is a rough estimate for how high the result might be
    int size = 400000;

    // Create prime sieve
    bool *prime_sieve = newPrimeSieve(size);

    int count = 1;
    for (int i = 2; i < size; i++) {
        if (prime_sieve[i]) {
            count++;
            if (count == 10001) {
                cout << i << endl;
                break;
            }
        }
    }

    delete prime_sieve;
    return 0;
}