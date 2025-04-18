#include <wchar.h>
#include <stdlib.h>
#include <locale.h>

int getRandomInt(int min, int max) {
  static int seeded = 0;
  if (!seeded) {
      srand(time(NULL));
      seeded = 1;
  }
  return min + rand() % (max - min + 1);
}

wchar_t getRandomHanzi() {
  return getRandomInt(0x4e00, 0x9fff);
}

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, ""); // absolutely won't work without calling this

  puts("你好世界！\n");

  puts("Some random hanzi for you:");

  int loopCount = 8;
  if (argc >= 2) {
    int value = atoi(argv[1]);
    if (value > 0) {
      loopCount = value;
    }
  }

  for (int i=1; i <= loopCount; i++) {
    wchar_t str[i + 1];
    for (int j=0; j < i; j++) {
      str[j] = getRandomHanzi();
    }
    str[i] = 0;

    wprintf(L"%i %ls\n", i, str);
  }

  puts("");

  return 0;
}
