#include <time.h>
#include <stdio.h>
// clock_t start, end,
double cpu_time_used(clock_t start, clock_t end)
{
  return ((double)(end - start)) / clocks_per_sec;
}
start = clock(){
    printf} end = clock()
    //     cpu_time_used = ((double)(end - start)) / clock_per_sec
