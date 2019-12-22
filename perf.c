#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  char ch;
  int i;
  struct timeval tv1, tv2;
  close(100);
  gettimeofday(&tv1, NULL);
  for (i = 0; i < 10*1000*1000; i++)
  {
    if (read(100, &ch, 1) != -1)
    {
      abort();
    }
  }
  gettimeofday(&tv2, NULL);
  printf("%g MOPS\n", 10/(tv2.tv_sec-tv1.tv_sec + (tv2.tv_usec-tv1.tv_usec)/1e6));
  return 0;
}
