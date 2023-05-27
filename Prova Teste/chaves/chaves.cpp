#include <stdio.h>

int main(){
    int chaves = 0;
    char c;
    while(scanf("%c", &c) != EOF){
        if(c == '{') chaves++;
        if(c == '}') chaves--;
        if(chaves < 0){
            printf("N\n");
            return 0;
        }
    }
    if(chaves == 0)
        printf("S\n");
    else printf("N\n");
    return 0;
}