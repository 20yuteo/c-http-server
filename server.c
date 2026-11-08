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

printf("Waiting for connection...\n");

int client_fd = accept(server_fd, NULL, NULL);

if (client_fd == -1) {
    perror("accept");
    close(server_fd);
    return 1;
}

printf("Client connected!\n");
printf("server_fd = %d\n", server_fd);
printf("client_fd = %d\n", client_fd);

// 受信データを格納する領域
char buffer[4096];

// TCPからデータを読み取る
ssize_t bytes_read = read(client_fd, buffer, sizeof(buffer));

if (bytes_read == -1) {
    perror("read");
} else if (bytes_read == 0) {
    printf("Client closed the connection.\n");
} else {
    printf("Received %zd bytes\n", bytes_read);

    // 読み取ったデータを標準出力に表示する
    fwrite(buffer, 1, (size_t)bytes_read, stdout);
    printf("\n");
}

close(client_fd);
close(server_fd);

close(server_fd);
return 0;
  
}
