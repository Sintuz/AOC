#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

#include "./tools.h"

int main() {
    bool flag = true;
    int s=0,people;
    char str[50];
    vector<char> cur,b;

    do {
        people = 0;
        do {
            cleanCharArr(str, sizeof(str));
            cin.getline(str, 50);

            if(str[0]=='0') {
                flag=false;
                break;
            } else if (str[0] != '\0') {
                people++;
            }

            for (int i = 0; str[i] != '\0'; i++) {
                if (find(cur.begin(), cur.end(), str[i])==cur.end()) {
                    b.push_back(str[i]);
                }
                cur.push_back(str[i]);
            }
        } while (str[0] != '\0');
        for (vector<char>::iterator i = b.begin(); i != b.end(); i++) {
            if (findCharOccurrencesInVector(cur, *i) == people) {
                s++;
            }
        }
        cur.clear();
        b.clear();
    } while(flag);

    cout << s << endl;

    return 0;
}