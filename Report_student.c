#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char day[11];
    int count;
} record;

int compare(const void *a, const void *b) {
    return strcmp(((record *)a)->day, ((record *)b)->day);
}

int main() {
    record records[100000];
    int n = 0;
    char line[200], day[11], hour[9], user_id[51], question_id[51];

    while (fgets(line, sizeof(line), stdin)) {
        if (sscanf(line, "%s %s %s %s", day, hour, user_id, question_id) == 4) {
            int found = 0;
            for (int i = 0; i < n; i++) {
                if (strcmp(records[i].day, day) == 0) {
                    records[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(records[n].day, day);
                records[n].count = 1;
                n++;
            }
        } else if (strcmp(day,"*") == 0) {
            break;
        }
    }

    qsort(records, n, sizeof(record), compare);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", records[i].day, records[i].count);
    }

    return 0;
}
