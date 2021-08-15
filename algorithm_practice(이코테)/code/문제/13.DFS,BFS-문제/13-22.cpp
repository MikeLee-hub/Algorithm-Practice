// 13-22. ��� �̵��ϱ�(p.353) (īī�� 2020 ���԰�ä)

/*
	bfs���.
    ������¸� x,y,row(col)�� �̿��Ͽ� ǥ��
*/

#include <string>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
struct node {
    int x, y;   // �� �� �� ������ or �Ʒ��� �ִ� ��
    int row;    // 1 : �¿�, 0 : �� �Ʒ�
    int col;    // 0 : �¿�, 1 : �� �Ʒ�
};

bool is_valid(node next, int n) {
    if (next.x < next.col || next.x >= n)
        return false;
    if (next.y < next.row || next.y >= n)
        return false;
    return true;
}

int solution(vector<vector<int>> board) {
    int depth[2][105][105];         // [0][x][y] : [x-1][y] �� [x][y] �� �̹� Ȯ���� ��������(0�̸� ���� ���� ���� ����)
                                    // [1][x][y] : [x][y-1] �� [x][y] �� �̹� Ȯ���� ��������(0�̸� ���� ���� ���� ����) 
    int d;
    int i, j;
    int dx[4] = { 1,-1,0,0 };       // �����̵����� dx
    int dy[4] = { 0,0,1, -1 };      // �����̵����� dy
    int rdx[2][4] = { {0,0,1,1},{-1,-1,0,0} };  // ȸ���̵����� dx    [0][i] : row->col�� ȸ���̵�
    int rdy[2][4] = { {-1,0,-1,0},{0,1,0,1} };  // ȸ���̵����� dy    [1][i] : col->row�� ȸ���̵�
    int checking_x[2][4] = { {-1,-1,1,1}, {0,0,-1,-1} };    // i,jȸ���̵��� ���� üũ�ؾ��ϴ� ������ ��ġ x
    int checking_y[2][4] = { {0, -1,0,-1}, {-1,1,-1,1} };   // i,jȸ���̵��� ���� üũ�ؾ��ϴ� ������ ��ġ y
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

        // �����̵�
        next.row = current.row; // �̵��� �� �ִ� ���� ���� ����
        next.col = current.col;
        for (i = 0; i < 4; i++) {
            next.x = current.x + dx[i]; // �̵��� �� �ִ� ���� ���� ����
            next.y = current.y + dy[i];
            if (!is_valid(next, n))     // board ũ�� ���� ���� �������� Ȯ��
                continue;
            if (board[next.x][next.y] == 1)                         // ��ġ1�� ������ Ȯ��
                continue;
            if (board[next.x - next.col][next.y - next.row] == 1)   // ��ġ2�� ������ Ȯ��
                continue;
            if (depth[next.row][next.x][next.y] != 0)               // �̹� Ȯ���� �������� Ȯ��
                continue;

            if (next.x == n - 1 && next.y == n - 1)                 // n,n�� �����ϸ� depth�� return
                return d;

            depth[next.row][next.x][next.y] = d + 1;                // ���� ���¸� queue�� ����
            que.push(next);
        }

        // ȸ���̵�
        next.row = current.col; // �̵��� �� �ִ� ���� ���� ����
        next.col = current.row;
        for (i = 0; i < 4; i++) {
            next.x = current.x + rdx[next.row][i];  // �̵��� �� �ִ� ���� ���� ����
            next.y = current.y + rdy[next.row][i];
            if (!is_valid(next, n))                 // board ũ�� ���� ���� �������� Ȯ��
                continue;
            if (board[current.x + checking_x[next.row][i]][current.y + checking_y[next.row][i]] == 1)   // ȸ�� ������ ������ Ȯ��
                continue;
            if (board[next.x][next.y] == 1)                         // ��ġ1�� ������ Ȯ��
                continue;
            if (board[next.x - next.col][next.y - next.row] == 1)   // ��ġ2�� ������ Ȯ��
                continue;
            if (depth[next.row][next.x][next.y] != 0)               // �̹� Ȯ���� �������� Ȯ��
                continue;

            if (next.x == n - 1 && next.y == n - 1)                 // n,n�� �����ϸ� depth�� return
                return d;

            depth[next.row][next.x][next.y] = d + 1;                // ���� ���¸� queue�� ����
            que.push(next);

        }
    }

    return -1;
}

int main() {
    vector<vector<int>> board = { {0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0} };
    printf("%d", solution(board));
}