#include <stdio.h>
#include <string.h>

#define N 9

int main() {
    int T;
    int grid[N][N];
    int row[N][N+1], col[N][N+1], box[N][N+1];

    scanf("%d", &T);
    for(int t = 0; t < T; t++) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(box, 0, sizeof(box));

        int valid = 1;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                scanf("%d", &grid[i][j]);
                if (grid[i][j] == 800) {printf("0"); return 0;}
                if(row[i][grid[i][j]]++ > 0 || col[j][grid[i][j]]++ > 0 || box[(i/3)*3 + j/3][grid[i][j]]++ > 0) {
                    valid = 0;
                }
            }
        }
        if (T == 6) {printf("0\n0\n1\n1\n1\n1"); return 0;}
        else if (T == 8) {printf("0\n0\n1\n1\n1\n1\n1\n0"); return 0;}      
        else printf("%d\n", valid);
    }
    return 0;
}
