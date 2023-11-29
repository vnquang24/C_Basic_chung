#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Event {
    time_t timestamp;
    char user_id[50];
    char question_id[50];
    struct Event* next;
} Event;

Event* create_event(time_t timestamp, char* user_id, char* question_id) {
    Event* event = (Event*)malloc(sizeof(Event));
    event->timestamp = timestamp;
    strcpy(event->user_id, user_id);
    strcpy(event->question_id, question_id);
    event->next = NULL;
    return event;
}

Event* add_event(Event* head, time_t timestamp, char* user_id, char* question_id) {
    Event* new_event = create_event(timestamp, user_id, question_id);
    new_event->next = head;
    return new_event;
}
//LINUX
// time_t convert_to_timestamp(char* date, char* time) {
//     struct tm tm;
//     char datetime[20];
//     strcpy(datetime, date);
//     strcat(datetime, " ");
//     strcat(datetime, time);
//     strptime(datetime, "%Y-%m-%d %H:%M:%S", &tm);
//     return mktime(&tm);
// }
//WINDOW
time_t convert_to_timestamp(char* date, char* time) {
    struct tm tm;
    sscanf(date, "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday);
    sscanf(time, "%d:%d:%d", &tm.tm_hour, &tm.tm_min, &tm.tm_sec);
    tm.tm_year -= 1900; // Thời gian được đếm từ năm 1900
    tm.tm_mon -= 1; // Tháng được đếm từ 0
    return mktime(&tm);
}

void print_time_difference(double diff) {
    int days = diff / (24 * 60 * 60);
    diff = (int)diff % (24 * 60 * 60);
    int hours = diff / (60 * 60);
    diff = (int)diff % (60 * 60);
    int minutes = diff / 60;
    int seconds = (int)diff % 60;

    printf("Time difference: %d days, %d hours, %d minutes, %d seconds\n", days, hours, minutes, seconds);
}
int main() {
    Event* head = NULL;
    char date[11], time[9], user_id[50], question_id[50];

    while (1) {
        scanf("%s", date);
        if (strcmp(date, "*") == 0) break;
        scanf("%s %s %s", time, user_id, question_id);
        time_t timestamp = convert_to_timestamp(date, time);
        head = add_event(head, timestamp, user_id, question_id);
    }

    if (head != NULL && head->next != NULL) {
    Event* first = head;
    while (head->next != NULL) {
        head = head->next;
    }
    Event* last = head;

    double diff = difftime(first->timestamp, last->timestamp);
    print_time_difference(diff);
}

    return 0;
}