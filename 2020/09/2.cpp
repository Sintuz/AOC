#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

#define LMAX 20
typedef long long int ll;
pair<int, int> find(ll* cur, vector<ll>* preamble);
ll find_weakness(vector<ll>* c_buffer, ll num);

int main() {
    char line[LMAX];

    vector<ll> preamble;
    vector<ll> c_buffer;
    ll cur, num;

    for (int i = 0; i < 25; i++) {
        cin.getline(line, LMAX);

        if (line[0] != '\0') {
            preamble.push_back(atoll(line));
            c_buffer.push_back(preamble.back());
        }
        else {
            throw "Invalid string";
        }
    }
    do {
        cin.getline(line, LMAX);
        if (line[0] != '\0') {
            cur = atoll(line);
            c_buffer.push_back(cur);

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

    ll c = find_weakness(&c_buffer, num);

    cout << endl << "Found: " << c << endl;

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

ll find_weakness(vector<ll>* c_buffer, ll num) {
    int l = c_buffer->size();
    cout << "SZ: " << l << endl;

    for(auto i=c_buffer->begin(); i!=c_buffer->end(); i++) {
        ll sum=0;
        for(auto j=i; j!=c_buffer->end(); j++) {
            sum+=*j;
            if(sum==num) {
                auto p = minmax_element(i, j);
                return *p.first + *p.second;
            }
        }
    }

    throw "Not found weakness";
}
