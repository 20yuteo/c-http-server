# include <stdio.h>
# include <sys/socket.h>
# include <unistd.h>

int main(void) {
  int server_fd = socket(
    AF_INET,
    SOCK_STREAM,
    0
  );

  if (server_fd == -1) {
    perror("socket");
    return 1;
  };

  printf("Socket created successfully!\n");
  printf("File descriptor: %d\n", server_fd);

  close(server_fd);

  return 0;
}
