#include <iostream>
#include <vector>
#include <cctype>
#include <string.h>

using namespace std;

/*
byr (Birth Year)
iyr (Issue Year)
eyr (Expiration Year)
hgt (Height)
hcl (Hair Color)
ecl (Eye Color)
pid (Passport ID)
cid (Country ID)        optional
*/

#define MAX 300

bool validate(string str);

vector<string> fields {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};

int main() {
	int tot=0;
    char cur_in[MAX];
    char cur_str[MAX];


    string str,t;
    do {
        cur_str[0]=0;
        do {
            cin.getline(cur_in, MAX);
            if (cur_in[0] == '0') {
                break;
            }
            strcat(cur_str, cur_in);
            strcat(cur_str, " ");
        } while (cur_in[0] != '\0');
        if (validate(string(cur_str))) {
            cout << cur_str << endl;
            tot++;
        }
    } while (cur_in[0] != '0');
    
    cout << tot;

    return 0;
}

bool validate(string str) {
    for (string i : fields) {
        if (str.find(i)==string::npos) {
            return false;
        }
    }

    return true;
}