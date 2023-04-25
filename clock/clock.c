#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct clock {
  int hour;
  int minute;
  int second;
} Clock;

void start_clock(Clock *clock, int hour, int minute, int second);
void printf_time(Clock *clock);

int main() {
  Clock *clock = (Clock *)malloc(sizeof(Clock));
  start_clock(clock, 12, 0, 0);
  return 0;
}

void start_clock(Clock *clock, int hour, int minute, int second) {
  clock->hour = hour;
  clock->minute = minute;
  clock->second = second;

  while (1)
  {
    printf_time(clock);
    sleep(1);

    clock->second += 1;

    if (clock->second > 59)
    {
      clock->minute += 1;
      clock->second = 0;
    }
    if (clock->minute > 59)
    {
      clock->minute = 0;
      clock->hour += 1;
    }
    if (clock->hour > 12)
    {
      clock->hour = 1;
    }
  }
}

void printf_time(Clock *clock) {
  system("clear");
  printf("%02d:%02d:%02d\n", clock->hour, clock->minute, clock->second);
}
