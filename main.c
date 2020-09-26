#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int count = 0;
  if (argc > 1) {
    count = strtol(argv[1], NULL, 10);
  }

#ifdef USE_ALLOCA
  // using `alloca`
  int *values = (int *)alloca(sizeof(int) * count);
#endif

#ifdef USE_MALLOC_FREE
  // using `malloc` + `free`
  int *values = (int *)malloc(sizeof(int) * count);
#endif

#ifdef USE_VLA
  // using compiler VLA
  int values[count];
#endif

  printf("values: %p\n", values);

  for (int i = 0; i < count; i++) {
    values[i] = i;
  }

  int result = values[count - 1];

#ifdef USE_MALLOC_FREE
  // using `malloc` + `free`
  free(values);
#endif

  return result;
}
