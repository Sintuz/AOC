#include <stdio.h>
#include <string.h>

int main() {
    int min, max;
    char character, passwd[100];
    int tot=0;
    
    while(scanf("%d-%d %c: %s", &min, &max, &character, passwd) == 4) {
        if (passwd[min - 1] == character && passwd[max - 1] != character) {
            tot++;
        } else if (passwd[min - 1] != character && passwd[max - 1] == character) {
            tot++;
        }
    }

    printf("%d", tot);

    return 0;
}