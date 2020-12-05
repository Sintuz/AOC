#include <iostream>
#include <string.h>

using namespace std;

#define SIZE 11

int calc(string str);
int getRow(string str, int min, int max);
int getCol(string str, int min, int max);

int main() {
    int t, max=0;
    char cur[SIZE];

    do {
        cin.getline(cur, 11);
        if(string(cur).length()) {
            t = calc(string(cur));
            if (t > max) {
                max = t;
            }
        }
    } while(cur[0]!='\0');

    cout << max << endl;

    return 0;
}

int calc(string str) {
    int row = getRow(str.substr(0, 7), 0, 127);
    int col = getCol(str.substr(7, 3), 0, 7);

    return col+row*8;
}

int getRow(string str, int min, int max) {
    int mid = (max-min)/2+1;
    if(str.length() > 0 && str.at(0)=='F') {
        return getRow(str.substr(1, str.length()-1), min, max-mid);
    } else if (str.length() > 0) {
        return getRow(str.substr(1, str.length()-1), min+mid, max);
    } else {
        return min;
    }
}

int getCol(string str, int min, int max) {  	
    int mid = (max-min)/2+1;
    if(str.length() > 0 && str.at(0)=='L') {
        return getCol(str.substr(1, str.length()-1), min, max-mid);
    } else if (str.length() > 0) {
        return getCol(str.substr(1, str.length()-1), min+mid, max);
    } else {
        return min;
    }
}