#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void) {
  int server_fd;

  struct sockaddr_in address;

  // 1. TCPソケットを作成する
  server_fd = socket(AF_INET, SOCK_STREAM, 0);

  if (server_fd == -1) {
    perror("socket");
    return 1;
  };

  // 2. アドレス情報を初期化する
  memset(&address, 0, sizeof(address));

  address.sin_family = AF_INET;
  address.sin_port = htons(8080);
  address.sin_addr.s_addr = htonl(INADDR_ANY);

  // 3. ソケットにポート番号を割り当てる
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == -1) {
    perror("bind");
    close(server_fd);
    return 1;
  }

printf("Socket bound to port 8080\n");
printf("PID: %d\n", getpid());

if (listen(server_fd, 10) == -1) {
    perror("listen");
    close(server_fd);
    return 1;
}

printf("Listening on port 8080...\n");
sleep(60);

close(server_fd);
return 0;
  
}
