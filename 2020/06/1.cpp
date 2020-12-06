#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

#include "./tools.h"

int main() {
    bool flag = true;
    int s=0;
    char str[50];
    vector<char> cur;

    do {
        do {
            cleanCharArr(str, sizeof(str));
            cin.getline(str, 50);

            if(str[0]=='0') {
                flag=false;
                break;
            }
            for (int i = 0; str[i] != '\0'; i++) {
                if (find(cur.begin(), cur.end(), str[i])==cur.end()) {
                    //cout << "A: " << str[i] << endl;
                    cur.push_back(str[i]);
                }
            }
        } while (str[0] != '\0');
        s += cur.size();
        cur.clear();
    } while(flag);

    cout << s << endl;

    return 0;
}