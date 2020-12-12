#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

#define LMAX 20
typedef long long int ll;
pair<int, int> find(ll* cur, vector<ll>* preamble);

int main() {
    char line[LMAX];

    vector<ll> preamble;
    ll cur, num;

    for (int i = 0; i < 25; i++) {
        cin.getline(line, LMAX);

        if (line[0] != '\0') {
            preamble.push_back(atoll(line));
        }
        else {
            throw "Invalid string";
        }
    }
    do {
        cin.getline(line, LMAX);
        if (line[0] != '\0') {
            cur = atoll(line);

            pair<int, int> result = find(&cur, &preamble);
            if (result.first == -1) {
                num = cur;
                break;
            }

            preamble.erase(preamble.begin());
            preamble.push_back(cur);
        }
    } while (line[0] != '\0');

    do {
        cin.getline(line, LMAX);
    } while (line[0] != '\0');

    cout << "Found: " << num << endl;

    return 0;
}

pair<int, int> find(ll* cur, vector<ll>* preamble) {
    for (ll n1 : *preamble) {
        for (ll n2 : *preamble) {
            if (n1 != n2 && n1 + n2 == *cur) {
                return { n1, n2 };
            }
        }
    }
    return { -1, -1 };
}
