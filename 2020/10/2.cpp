#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define LMAX 5

typedef long long ll;

int fact(int n);

int main() {
    char line[LMAX];
    vector<int> adapters;
    ll combs=0;

    adapters.push_back(0); // consider the outlet

    do {
        cin.getline(line, LMAX);
        if (line[0] != '\0') {
            adapters.push_back(atoi(line));
        }
    } while (line[0] != '\0');

    sort(adapters.begin(), adapters.end());

    adapters.push_back(*max_element(adapters.begin(), adapters.end())+3);

    int c=1;
    for(auto i=adapters.begin(); i!=adapters.end()-1; i++) {
        int num=0;
        for(auto j=i+1; j!=adapters.end() && j-i < 4; j++) { // j-i < 4 -> after passing 3rd el. after i, no more combos are possible
            cout << "I: " << *i << " J: " << *j << endl;
            if((*j-*i)<=3) {
                num++;
            }
        }
        cout << "N: " << num << endl;

        if(num!=1) {
            c*=num;
        } else if(c!=1) {
            combs+=c;
            c=1;
        }
    }

    cout << combs << endl;

    return 0;
}

int fact(int n) {
   if ((n==0)||(n==1))
   return 1;
   else
   return n*fact(n-1);
}