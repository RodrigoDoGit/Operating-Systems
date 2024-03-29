#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
   int sock;
   socklen_t length;
   struct sockaddr_in name;
   char buf[1024];

   /* create socket from which to read */
   if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
      perror("opening datagram socket");
      return EXIT_FAILURE;
   }

   /* create name with wildcards - port will be given by OS */
   name.sin_family = AF_INET;
   name.sin_addr.s_addr = INADDR_ANY;
   name.sin_port = 0;
   if (bind(sock, (struct sockaddr *)&name, sizeof(name))) {
      perror("binding datagram socket");
      return EXIT_FAILURE;
   }

   /* find assigned port value and print it out */
   length = (socklen_t)sizeof(name);
   if (getsockname(sock, (struct sockaddr *)&name, &length)) {
      perror("getting socket name");
      return EXIT_FAILURE;
   }
   printf("Socket has port #%d\n", ntohs(name.sin_port));

   /* read from the socket */
   if (read(sock, buf, sizeof(buf)) < 0)
      perror("receiving datagram packet");
   printf("received:\n%s\n", buf);
   close(sock);
   return EXIT_SUCCESS;
}
