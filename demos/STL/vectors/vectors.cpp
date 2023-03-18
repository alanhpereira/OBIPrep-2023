#include <vector>
#include <stdio.h>
#include <utility> //pair
#define MAX 50
using namespace std;

vector<int> vec;
vector<pair<int, int> > adj[MAX];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        vec.push_back(a);
    }
    printf("%d\n", vec.size());
    for(int i = 0; i < vec.size(); i++){
        printf("%d ", vec[i]);
        vec[i] = i*i;
    }
    printf("\n");
    printf("%d\n", vec.size());
    for(int i = 0; i < vec.size(); i++){
        printf("%d ", vec[i]);
        vec[i] = i*i;
    }
    printf("\n");

    int m;
    scanf("%d %d",&n, &m);
    for(int i = 0; i < n; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back(pair<int, int>(b, c));
        adj[b].push_back(pair<int, int>(a, c));
    }

    for(int i = 0 ; i < n; i++){
        printf("adjs de %d:\n",i);
        for(int j = 0; j < adj[i].size(); j++){
            printf("%d ", adj[i][j].first);
        }
        printf("\n");
    }

    return 0;
}

