#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int randInt(int n) {
  return rand() % n;
}

int main() {
  // Initialize random number generator
  time_t t;
  time(&t);
  srand((unsigned) t);

  int n = randInt(16);
  if (n == 0) {
    printf("Nope\n");
    return 0;
  }

  puts("你好世界！");

  for (int i=1; i <= n; i++) {
    if (i % 7 == 0) {
      printf("%d. 再见宇宙！\n", i);
    } else {
      printf("%d. 你好世界！\n", i);
    }
  }
  return 0;
}
