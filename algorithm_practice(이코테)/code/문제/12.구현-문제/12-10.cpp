// 12-10. ÀÚ¹°¼è¿Í ¿­¼è(p.325)

/*
    
*/
#include <string>
#include <vector>

using namespace std;

int lock_num;
int n, m;
vector<vector<int>> global_key;
vector<vector<int>> global_lock;

bool check_1(int x, int y) {
    int i, j;
    int lock_x, lock_y;
    int lock_n = lock_num;

    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            lock_x = i + x;
            lock_y = j + y;
            if (lock_x < 0 || lock_x >= n)
                continue;
            if (lock_y < 0 || lock_y >= n)
                continue;
            if (global_key[i][j] == global_lock[lock_x][lock_y])
                return false;
            if (global_lock[lock_x][lock_y] == 0)
                lock_n--;
        }
    }
    if (lock_n == 0)
        return true;
    return false;
}

bool check_2(int x, int y) {
    int i, j;
    int lock_x, lock_y;
    int lock_n = lock_num;

    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            lock_x = i + x;
            lock_y = j + y;
            if (lock_x < 0 || lock_x >= n)
                continue;
            if (lock_y < 0 || lock_y >= n)
                continue;
            if (global_key[j][m - i-1] == global_lock[lock_x][lock_y])
                return false;
            if (global_lock[lock_x][lock_y] == 0)
                lock_n--;
        }
    }
    if (lock_n == 0)
        return true;
    return false;
}

bool check_3(int x, int y) {
    int i, j;
    int lock_x, lock_y;
    int lock_n = lock_num;

    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            lock_x = i + x;
            lock_y = j + y;
            if (lock_x < 0 || lock_x >= n)
                continue;
            if (lock_y < 0 || lock_y >= n)
                continue;
            if (global_key[m - i-1][m - j-1] == global_lock[lock_x][lock_y])
                return false;
            if (global_lock[lock_x][lock_y] == 0)
                lock_n--;
        }
    }
    if (lock_n == 0)
        return true;
    return false;
}

bool check_4(int x, int y) {
    int i, j;
    int lock_x, lock_y;
    int lock_n = lock_num;

    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            lock_x = i + x;
            lock_y = j + y;
            if (lock_x < 0 || lock_x >= n)
                continue;
            if (lock_y < 0 || lock_y >= n)
                continue;
            if (global_key[m-j-1][i] == global_lock[lock_x][lock_y])
                return false;
            if (global_lock[lock_x][lock_y] == 0)
                lock_n--;
        }
    }
    if (lock_n == 0)
        return true;
    return false;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int i, j;

    lock_num = 0;
    n = lock.size();
    m = key.size();

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (lock[i][j] == 0)
                lock_num++;
        }
    }

    global_key = key;
    global_lock = lock;

    for (i = -1*m + 1; i < n + m - 1; i++) {
        for (j = -1 * m + 1; j < n + m - 1; j++) {
            if (check_1(i, j))
                return true;
            if (check_2(i, j))
                return true;
            if (check_3(i, j))
                return true;
            if (check_4(i, j))
                return true;
        }
    }
    
    return false;
}

int main() {
    vector<vector<int>> key = { {0, 0, 0}, {1, 0, 0}, {0, 1, 1} };
    vector<vector<int>> lock = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    if (solution(key, lock))
        printf("true\n");
    else
        printf("false\n");

}