// 13-22. 블록 이동하기(p.353) (카카오 2020 신입공채)

/*
	bfs사용.
    현재상태를 x,y,row(col)을 이용하여 표현
*/

#include <string>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
struct node {
    int x, y;   // 두 점 중 오른쪽 or 아래에 있는 점
    int row;    // 1 : 좌우, 0 : 위 아래
    int col;    // 0 : 좌우, 1 : 위 아래
};

bool is_valid(node next, int n) {
    if (next.x < next.col || next.x >= n)
        return false;
    if (next.y < next.row || next.y >= n)
        return false;
    return true;
}

int solution(vector<vector<int>> board) {
    int depth[2][105][105];         // [0][x][y] : [x-1][y] 와 [x][y] 가 이미 확인한 상태인지(0이면 아직 가지 않은 상태)
                                    // [1][x][y] : [x][y-1] 과 [x][y] 가 이미 확인한 상태인지(0이면 아직 가지 않은 상태) 
    int d;
    int i, j;
    int dx[4] = { 1,-1,0,0 };       // 평행이동시의 dx
    int dy[4] = { 0,0,1, -1 };      // 평행이동시의 dy
    int rdx[2][4] = { {0,0,1,1},{-1,-1,0,0} };  // 회전이동시의 dx    [0][i] : row->col의 회전이동
    int rdy[2][4] = { {-1,0,-1,0},{0,1,0,1} };  // 회전이동시의 dy    [1][i] : col->row의 회전이동
    int checking_x[2][4] = { {-1,-1,1,1}, {0,0,-1,-1} };    // i,j회전이동을 위해 체크해야하는 보드의 위치 x
    int checking_y[2][4] = { {0, -1,0,-1}, {-1,1,-1,1} };   // i,j회전이동을 위해 체크해야하는 보드의 위치 y
    queue<node> que;
    node current, next;
    int n = board.size();


    for (i = 0; i < n; i++) {
        memset(depth[0][i], 0, n * sizeof(int));
        memset(depth[1][i], 0, n * sizeof(int));
    }

    que.push({ 0,1,1,0 });
    depth[1][0][1] = 1;

    while (!que.empty()) {
        current = que.front();
        que.pop();
        d = depth[current.row][current.x][current.y];

        // 평행이동
        next.row = current.row; // 이동할 수 있는 다음 상태 저장
        next.col = current.col;
        for (i = 0; i < 4; i++) {
            next.x = current.x + dx[i]; // 이동할 수 있는 다음 상태 저장
            next.y = current.y + dy[i];
            if (!is_valid(next, n))     // board 크기 범위 내의 상태인지 확인
                continue;
            if (board[next.x][next.y] == 1)                         // 위치1이 벽인지 확인
                continue;
            if (board[next.x - next.col][next.y - next.row] == 1)   // 위치2가 벽인지 확인
                continue;
            if (depth[next.row][next.x][next.y] != 0)               // 이미 확인한 상태인지 확인
                continue;

            if (next.x == n - 1 && next.y == n - 1)                 // n,n에 도달하면 depth를 return
                return d;

            depth[next.row][next.x][next.y] = d + 1;                // 다음 상태를 queue에 저장
            que.push(next);
        }

        // 회전이동
        next.row = current.col; // 이동할 수 있는 다음 상태 저장
        next.col = current.row;
        for (i = 0; i < 4; i++) {
            next.x = current.x + rdx[next.row][i];  // 이동할 수 있는 다음 상태 저장
            next.y = current.y + rdy[next.row][i];
            if (!is_valid(next, n))                 // board 크기 범위 내의 상태인지 확인
                continue;
            if (board[current.x + checking_x[next.row][i]][current.y + checking_y[next.row][i]] == 1)   // 회전 범위가 벽인지 확인
                continue;
            if (board[next.x][next.y] == 1)                         // 위치1이 벽인지 확인
                continue;
            if (board[next.x - next.col][next.y - next.row] == 1)   // 위치2가 벽인지 확인
                continue;
            if (depth[next.row][next.x][next.y] != 0)               // 이미 확인한 상태인지 확인
                continue;

            if (next.x == n - 1 && next.y == n - 1)                 // n,n에 도달하면 depth를 return
                return d;

            depth[next.row][next.x][next.y] = d + 1;                // 다음 상태를 queue에 저장
            que.push(next);

        }
    }

    return -1;
}

int main() {
    vector<vector<int>> board = { {0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0} };
    printf("%d", solution(board));
}