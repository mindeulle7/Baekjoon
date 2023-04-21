#include <iostream>
#include <queue>
using namespace std;

bool graph[1001][1001] = { 0 };
bool visit[1001] = { 0 };

void input(int m, int n);
int solve(int n);
int find_s(int n);
bool check(int n);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    input(m, n);
    cout << solve(n);
}

void input(int m, int n) {
    for (int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        graph[n1][n2] = true;
        graph[n2][n1] = true;
    }

    for (int i = 1; i <= n; i++) {
        graph[i][i] = true;
    }
}

int solve(int n) {
    int cnt = 0;
    while (check(n)) {
        queue<int> q;
        int start = find_s(n);
        q.push(start);
        visit[start] = true;
        while (!q.empty()) {
            int next = q.front();
            q.pop();
            for (int i = 1; i <= n; i++) {
                if (graph[next][i] && !visit[i]) {
                    q.push(i);
                    visit[i] = true;
                }
            }
        }
        cnt++;
    }
    return cnt;
}

int find_s(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] && !visit[j]) {
                return j;
            }
        }
    }
    return -1;
}

bool check(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] && !visit[j]) {
                return true;
            }
        }
    }
    return false;
}
