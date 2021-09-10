// 9-1. 간단한 다익스트라 알고리즘


/*
    코드를 보고 짰으므로 내일 다시 짜볼것!!
*/

/*
예제 입력:
6 11
1
1 2 2
1 3 5
1 4 1
2 3 3
2 4 2
3 2 3
3 6 5
4 3 3
4 5 1
5 3 1
5 6 2

예제 출력:
0
2
3
1
2
4
*/
#include <vector>
#include <stdio.h>

#define MAX_OF_INT 1e9

using namespace std;


int n, m, start;
vector<pair<int, int> > graph[100001];
bool visited[100001];
int d[100001];

int getSmallestNode() {
    int min_value = MAX_OF_INT;
    int index = 0; 
    for (int i = 1; i <= n; i++) {
        if (d[i] < min_value && !visited[i]) {
            min_value = d[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int start) {
    d[start] = 0;
    visited[start] = true;
    for (int j = 0; j < graph[start].size(); j++) {
        d[graph[start][j].first] = graph[start][j].second;
    }
    for (int i = 0; i < n - 1; i++) {
        int now = getSmallestNode();
        visited[now] = true;
        for (int j = 0; j < graph[now].size(); j++) {
            int cost = d[now] + graph[now][j].second;
            if (cost < d[graph[now][j].first]) {
                d[graph[now][j].first] = cost;
            }
        }
    }
}

int main(void) {
    scanf("%d %d %d", &n, &m, &start);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d",&a, &b, &c);
        graph[a].push_back({ b, c });
    }

    fill_n(d, 100001, MAX_OF_INT);

    dijkstra(start);

    for (int i = 1; i <= n; i++) {
        if (d[i] == MAX_OF_INT) {
            printf("INFINITY\n");
        }
        else {
            printf("%d\n", d[i]);
        }
    }
}