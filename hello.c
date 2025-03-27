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

int main() {
  setlocale(LC_ALL, ""); // absolutely won't work without calling this

  puts("你好世界！\n");

  puts("Some random hanzi for you:");

  int loopCount = getRandomInt(1, 8);

  for (int i=0; i < loopCount; i++) {
    wchar_t str[9];
    for (int j=0; j < 8; j++) {
      str[j] = getRandomHanzi();
    }
    str[8] = 0;

    wprintf(L"%i %ls\n", i+1, str);
  }

  puts("");

  return 0;
}
