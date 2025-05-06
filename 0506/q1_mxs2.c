#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int hour;
    int minute;
} Time;

Time* createTime(int hour, int minute) {
    Time* time = (Time*)malloc(sizeof(Time));
    time->hour = hour;
    time->minute = minute;
    return time;
}

void freeTime(Time* time) {
    free(time);
}

int calculateSleepMinutes(Time* current, Time* alarm) {
    int currentInMinutes = current->hour * 60 + current->minute;
    int alarmInMinutes = alarm->hour * 60 + alarm->minute;

    if (alarmInMinutes <= currentInMinutes) {
        alarmInMinutes += 24 * 60;
    }

    return alarmInMinutes - currentInMinutes;
}

int main() {
    int h1, m1, h2, m2;

    while (1) {
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
        if (h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) {
            break;
        }

        Time* currentTime = createTime(h1, m1);
        Time* alarmTime = createTime(h2, m2);

        int sleepMinutes = calculateSleepMinutes(currentTime, alarmTime);
        printf("%d\n", sleepMinutes);

        freeTime(currentTime);
        freeTime(alarmTime);
    }

    return 0;
}
