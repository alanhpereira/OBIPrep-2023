#include <stdio.h>
#include <algorithm>
#define F first
#define S second
#define MAX 11234
using namespace std;
typedef pair<int, int> pii;

pii app[MAX];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n ;i++){
        scanf("%d %d", &app[i].S, &app[i].F);
    }
    sort(app, app+n);
    int ans = 0;
    int lastEnd = 0;
    
    for(int i = 0; i < n ;i++){
        if(app[i].S >= lastEnd){
            lastEnd = app[i].F;
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}