#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define LMAX 5

int main() {
    char line[LMAX];
    vector<int> adapters;
    int n1=0, n3=1;

    adapters.push_back(0); // consider the outlet

    do {
        cin.getline(line, LMAX);
        if (line[0] != '\0') {
            adapters.push_back(atoi(line));
        }
    } while (line[0] != '\0');

    sort(adapters.begin(), adapters.end());

    for(auto i=adapters.begin()+1; i!=adapters.end(); i++) {
        cout << *i << endl;
        if(*i-*(i-1)==1) n1++;
        else if(*i-*(i-1)==3) n3++;
    }
    
    cout << n1*n3;

    return 0;
}