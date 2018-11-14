// 01
#include <sys/select.h>
#include <sys/time.h>

int select(int maxfdp1, fd_set *readset, fd_set *writeset,
           fd_set *exceptset,
           const struct timeval *timeout);

// 02
/* clear all bits in fdset */
Void FD_ZERO(fd_set *fdset);
/* turn on the bit for fd in fdset */
Void FD_SET(int fd, fd_set *fdset);
/* turn off the bit for fd in fdset*/
Void FD_CLR(int fd, fd_set *fdset);
/* is the bit for fd on in fdset ? */
int FD_ISSET(int fd, fd_set *fdset);

// 03
#include <sys/select.h>
#include <signal.h>
#include <time.h>

int pselect(int maxfdp1, fd_set *readset, fd_set *writeset,
            fd_set *exceptset, const struct timespec *timeout,
            const sigset_t *sigmask)

// 04
#include <poll.h>
  int poll(struct pollfd  *fdarray, unsigned long nfds, int timeout);
/*return : count of ready descriptors, 0 on timeout, -1 on error*/
