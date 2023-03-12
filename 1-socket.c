







#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <sys/socket.h>

#

if (argc < 3

   )



	{


		printf("Usage: %s <server_ip> <server_port>\n", argv[0

		]);


		return (1

		       );



			}


int sock = socket(AF_INET, SOCK_STREAM, 0

		);


if (sock == -1

   )



	{



				perror(

						"socket"

				      );


				return (1
	}

struct sockaddr_in server_addr;
memset(&server_addr, 0, sizeof
(server_addr));
server_addr.sin_family = AF_INET;
server_addr.sin_addr.s_addr = inet_addr(argv[1]);
server_addr.sin_port = htons(atoi(argv[2]));
if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1
)
{
perror("connect");
return (1);
}
printf("Connected to server at %s:%s\n", argv[1], argv[2]);


char

msg[MAX_MSG_LENGTH];
while (fgets(msg, MAX_MSG_LENGTH, stdin) != NULL
       )


int len = strlen
(msg);
if (send(sock, msg, len, 0
) != len)
{
									perror(

	"send"
    );
break

}

}
close(sock);
return (0);
}
```
