#include <stdio.h>
#include <stdbool.h>

#define SIZE 300

int main() {
    int arr[SIZE], prod, len;
    size_t i=0, j=0;

    bool flag=true;
    while(flag) {
        int newNum;
        scanf("%d", &newNum);
        if(newNum!=-1) {
            arr[i++]=newNum;
        }
        else {
            flag=false;
        }
    }
    len=i;

	for(i=0;i<len;i++) {
        for(j=0;j<len;j++) {
            if((arr[i]+arr[j])==2020) {
                prod=arr[i]*arr[j];
            }
        }
    }
    printf("\n%d", prod);

    return 0;
}
