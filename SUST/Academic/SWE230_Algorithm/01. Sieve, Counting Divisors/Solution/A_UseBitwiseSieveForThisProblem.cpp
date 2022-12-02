/*
* @Last Modified by:   Sakib62
* @Last Modified time: 2022-12-03 01:38:32
*/
//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;

#define N 1e8

//each int is represented by 32 bit, so primality of 32 numbers can be expressed using these bits.
vector < int > isComposite(N / 32 + 5); //initialized with 0, all are assumed prime

bool checkBit(int n, int pos) {//checking if pos'th bit in n is set
    return (bool) (n & (1 << pos));//parenthesis important
}

int setBit(int n, int pos) {//setting the pos'th bit in n
    return n |= (1 << pos);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); int testCase = 1;
    //cin >> testCase;
    while(testCase--) {
        //sieve of eratosthenes using bitwise operation, making it space efficient
        vector < int > primes;
        primes.push_back(2);
        for(int i = 3; i <= N; i += 2) {
            if(checkBit(isComposite[i / 32], i % 32) == 0) { //number i is in i/32 th index, and whether it is prime is indicated by i%32th bit of that index.
                primes.push_back(i);
                for(long long j = 1ll * i * i; j <= N; j += 2*i) {
                    isComposite[j / 32] = setBit(isComposite[j / 32], j % 32);//set the corresponding bit to 1, meaning it is a composite number
                }
            }
        }
        for(int i = 0; i < primes.size(); i += 100) {
            cout << primes[i] << "\n";
        }
    }
}