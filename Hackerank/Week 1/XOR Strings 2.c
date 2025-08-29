#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    char p[1001], q[1001], res[1001];
    scanf("%s",p);
    scanf("%s",q);
    int m = strlen(p);
    for(int i = 0; i < m; i++){
        if(p[i] == q[i]){
            res[i] = '0';
        }else{
            res[i] = '1';
        }
    }
    res[m] = '\0';
    printf("%s", res);
    return 0;
}
