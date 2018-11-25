## functions of socket

### socket
#include <sys/socket.h>
int socket (int family, int type, int protocol);
Returns: non-negative descriptor if OK, -1 on error

family specifies the protocol family and is one of the constants shown in Figure 4.2.
This argument is often referred to as domain instead of family. The socket type is one
of the constants shown in Figure 4.3. The protocol argument to the socket function
should be set to the specific protocol type found in Figure 4.4, or 0 to select the
system's default for the given combination of family and type.

### connect
#include <sys/socket.h>
int connect(int sockfd, const struct sockaddr *servaddr, socklen_t addrlen);
Returns: 0 if OK, -1 on error

sockfd is a socket descriptor returned by the socket function. The second and third
arguments are a pointer to a socket address structure and its size, as described in
Section 3.3. The socket address structure must contain the IP address and port
number of the server.

### bind

#include <sys/socket.h>
int bind (int sockfd, const struct sockaddr *myaddr, socklen_t addrlen);
Returns: 0 if OK,-1 on error

The second argument is a pointer to a protocol-specific address, and the third
argument is the size of this address structure. With TCP, calling bind lets us specify a
port number, an IP address, both, or neither.


### listen
#include <sys/socket.h>
#int listen (int sockfd, int backlog);
Returns: 0 if OK, -1 on error

### accept
#include <sys/socket.h>
int accept (int sockfd, struct sockaddr *cliaddr, socklen_t *addrlen);
Returns: non-negative descriptor if OK, -1 on error

The cliaddr and addrlen arguments are used to return the protocol address of the
connected peer process (the client). addrlen is a value-result argument

### fork
#include <unistd.h>
pid_t fork(void);
Returns: 0 in child, process ID of child in parent, -1 on error


### exec
#include <unistd.h>
int execl (const char *pathname, const char *arg0, ... /* (char *) 0 */ );
int execv (const char *pathname, char *const argv[]);
int execle (const char *pathname, const char *arg0, ...
/* (char *) 0, char *const envp[] */ );
int execve (const char *pathname, char *const argv[], char *const envp[]);
int execlp (const char *filename, const char *arg0, ... /* (char *) 0 */ );
int execvp (const char *filename, char *const argv[]);
All six return: -1 on error, no return on success


These functions return to the caller only if an error occurs. Otherwise, control passes
to the start of the new program, normally the main function.


### close
#include <unistd.h>
int close (int sockfd);
Returns: 0 if OK, -1 on error
