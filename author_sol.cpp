#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

void Sieve(int mx) {
	vector<int> array(mx + 1, 0);
	array[1] = 1;
	for (int i = 2; i <= mx; i++) {
		if (array[i] == 0) {
			for (int j = i * 2; j <= mx; j += i) {
				array[j] = 1;
			}
		}
	}
	for (int i = 1; i <= mx; i++) {
		if (array[i] == 0) {
			primes.emplace_back(i);
		}
	}
}
	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Sieve(100000);
	int tt;
	cin >> tt;
	while (tt--) {
		int L, R;
		cin >> L >> R;
		if (L == 1) {
			L++;
		}
		int mx = R - L + 1;
		vector<int> array(mx, 0);
		for (long long p : primes) {
			if (p * p <= R) {
				int i = (L / p) * p;
				if (i < L) {
					i += p;
				}
				for(; i <= R; i += p) {
					if (i != p) {
						array[i - L] = 1;
					}
				}
			}
		}
		for (int i = 0; i < mx; i++) {
			if (array[i] == 0) {
				cout << L + i << '\n';
			}
		}
		cout << '\n';
	}
	return 0;
}
