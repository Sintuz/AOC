#include <stdio.h>
#include <string.h>

int main() {
    int min, max;
    char character, passwd[100];
    int tot=0;
    
    while(scanf("%d-%d %c: %s", &min, &max, &character, passwd) == 4) {
        int num=0;
        for(size_t i=0;i<strlen(passwd);i++) {
            if(passwd[i]==character) {
                num++;
            }
        }
        if (num >= min && num <= max) {
            tot++;
        }
    }

    printf("%d", tot);

    return 0;
}