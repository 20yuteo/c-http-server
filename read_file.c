#include <stdio.h>

int main(void) {
  FILE *file = fopen("index.html", "r");

  if (file == NULL) {
    perror("fopen");
    return 1;
  }

  char buffer[1024];

  size_t bytes_read = fread(
    buffer,
    1,
    sizeof(buffer) -1,
    file
  );

  buffer[bytes_read] = '\0';

  printf("%s", buffer);

  fclose(file);

  return 0;
}