// 12-12. 기둥과 보 설치(p.329)

/*
    기둥을 나타내는 이차원배열 col와 보를 다나태는 이차원배열 row을 저장하여
    매 동작마다 해당 동작을 실행하고 전채 배열이 valid한지 판단하여 
    valid한 경우 동작 유지, invalid한 경우 동작 취소한다.
    모든 동작이 끝난 후 col과 row를 answer 벡터형태로 변환한다.
*/
#include <string>
#include <vector>

using namespace std;

int row[105][105];                  // 보
int col[105][105];                  // 기둥


int check_row(int x, int y) {
    if (y == 0) {
        return 0;
    }
    if (col[x][y - 1] || col[x + 1][y - 1])
        return 1;
    if (x > 0) {
        if (row[x - 1][y] && row[x + 1][y])
            return 1;
    }
    return 0;
}

int check_col(int x, int y) {
    if (y == 0) {
        return 1;
    }
    if (col[x][y - 1])
        return 1;
    if (row[x][y])
        return 1;
    if (x > 0) {

        if (row[x - 1][y])
            return 1;
    }
}

int check_all(int n) {
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            if (col[i][j]) {
                if (!check_col(i, j))
                    return 0;
            }
            if (row[i][j]) {
                if (!check_row(i, j))
                    return 0;
            }
        }
    }
    return 1;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<int> tmp;
    int i, j;
    int len = build_frame.size();
    int x, y, a, b;

    for (i = 0; i < n + 4; i++) {
        for (j = 0; j < n + 4; j++) {
            col[i][j] = 0;
            row[i][j] = 0;
        }
    }

    for (i = 0; i < len; i++) {
        x = build_frame[i][0];
        y = build_frame[i][1];
        a = build_frame[i][2];          // a=0 : 기둥 , a=1 : 보
        b = build_frame[i][3];          // b=0 : 삭제 , b=1 : 설치
        if (a) {
            if (b) {        // create_row(x, y);
                row[x][y] = 1;
                if (!check_row(x,y))
                    row[x][y] = 0;
            }
            else {          // delete_row(x, y);
                row[x][y] = 0;
                if (!check_all(n))
                    row[x][y] = 1;
            }
        }
        else {
            if (b) {        // create_col(x, y);
                col[x][y] = 1;
                if (!check_col(x,y))
                    col[x][y] = 0;
            }
            else {          // delete_col(x, y);
                col[x][y] = 0;
                if (!check_all(n))
                    col[x][y] = 1;
            }
        }
    }

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            if (col[i][j]) {
                tmp.clear();
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(0);
                answer.push_back(tmp);
            }
            if (row[i][j]) {
                tmp.clear();
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(1);
                answer.push_back(tmp);
            }
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> build_frame = { {0, 0, 0, 1}, {2, 0, 0, 1}, {4, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 1}, {3, 1, 1, 1}, {2, 0, 0, 0}, {1, 1, 1, 0}, {2, 2, 0, 1} };
    vector<vector<int>> answer = solution(5, build_frame);
    return 0;
}



/*
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<int> tmp;
    int i, j;
    int len = build_frame.size();
    int x, y, a, b;


    for (i = 0; i < n + 4; i++) {
        for (j = 0; j < n + 4; j++) {
            col[i][j] = 0;
            row[i][j] = 0;
        }
    }

    for (i = 0; i < len; i++) {
        x = build_frame[i][0];
        y = build_frame[i][1];
        a = build_frame[i][2];          // a=0 : 기둥 , a=1 : 보
        b = build_frame[i][3];          // b=0 : 삭제 , b=1 : 설치
        if (a) {
            if (b) {        // create_row(x, y);
                if (col[x][y - 1] || col[x + 1][y - 1])
                    row[x][y] = 1;
                if (x > 0 && x < n) {
                    if (row[x - 1][y] && row[x + 1][y])
                        row[x][y] = 1;
                }
            }
            else {          // delete_row(x, y);
                if (x > 0) {    // 왼쪽 보 체크
                    if (row[x - 1][y]) {
                        if (!(col[x - 1][y - 1] || col[x][y - 1]))
                            continue;
                    }
                }
                if (x < n - 1) {    // 오른쪽 보 체크
                    if (row[x + 1][y]) {
                        if (!(col[x + 1][y - 1] || col[x + 2][y - 1]))
                            continue;
                    }
                }
                if (col[x][y]) {    // 왼쪽 위 기둥 체크
                    if (!col[x][y - 1]) {
                        if (x == 0)
                            continue;
                        if (!row[x - 1][y])
                            continue;
                    }
                }
                if (col[x + 1][y]) {    // 오른쪽 위 기둥 체크
                    if (!col[x + 1][y - 1]) {
                        if (!row[x + 1][y])
                            continue;
                    }
                }
                row[x][y] = 0;
            }
        }
        else {
            if (b) {        // create_col(x, y);
                if (y == 0)
                    col[x][y] = 1;
                else {
                    if (col[x][y - 1])
                        col[x][y] = 1;
                    else if (row[x][y])
                        col[x][y] = 1;
                    else {
                        if (x > 0) {
                            if (row[x - 1][y])
                                col[x][y] = 1;
                        }
                    }
                }
            }
            else {          // delete_col(x, y);
                if (x > 0) {    // 왼쪽 위 보 체크
                    if (row[x - 1][y + 1]) {
                        if (!col[x - 1][y]) {
                            if (x == 1)
                                continue;
                            if (!(row[x - 2][y + 1] && row[x][y + 1]))
                                continue;
                        }
                    }
                }
                if (row[x][y + 1] == 1) {     // 오른쪽 위 보 체크
                    if (!col[x + 1][y]) {
                        if (x == 0)
                            continue;
                        if (!(row[x - 1][y + 1] && row[x + 1][y + 1]))
                            continue;
                    }
                }
                if (col[x][y + 1]) {
                    if (!row[x][y + 1]) {
                        if (x == 0)
                            continue;
                        if (row[x - 1][y + 1])
                            continue;
                    }
                }
                col[x][y] = 0;
            }
        }
    }

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            if (col[i][j]) {
                tmp.clear();
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(0);
                answer.push_back(tmp);
            }
            if (row[i][j]) {
                tmp.clear();
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(1);
                answer.push_back(tmp);
            }
        }
    }

    return answer;
}
*/