#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#include "csse332_lib.h"


int
register_process_pid(pid_t pid)
{
	int fd;

	fd = open(PROCFS_PATH, O_RDWR);
	if (fd < 0) {
		fprintf(stderr, "\t***FAIL***: Could not open procfs entry: %s\n",
			strerror(errno));
		return fd;
	}

	char buff[16];
	int llen = sprintf(buff, "%c, %d\n", REGISTER_CHAR, pid);
	buff[llen] = '\0';
	llen = write(fd, buff, strlen(buff));
	printf("Registering process with pid = %d\n", getpid());
	if (llen != strlen(buff)) {
		fprintf(stderr, "\t*** FAIL ***: Incorrect write to procfs: %s",
			strerror(errno));
		close(fd);
		return llen;
	}

	close(fd);
	return 0;
}

int withdraw_process_pid(pid_t pid)
{
	int fd;

	fd = open(PROCFS_PATH, O_RDWR);
	if (fd < 0) {
		fprintf(stderr, "\t***FAIL***: Could not open procfs entry: %s\n",
			strerror(errno));
		return fd;
	}

	char buff[16];
	int llen = sprintf(buff, "%c, %d\n", WITHDRAW_CHAR, pid);
	buff[llen] = '\0';
	llen = write(fd, buff, strlen(buff));
	printf("Withdrawing process with pid = %d\n", pid);
	if (llen != strlen(buff)) {
		fprintf(stderr, "\t*** FAIL ***: Incorrect write to procfs: %s",
			strerror(errno));
		close(fd);
		return llen;
	}

	close(fd);
	return 0;
}

int
yield_process_pid(pid_t pid)
{
	int fd;

	fd = open(PROCFS_PATH, O_RDWR);
	if (fd < 0) {
		fprintf(stderr, "\t***FAIL***: Could not open procfs entry: %s\n",
			strerror(errno));
		return fd;
	}

	char buff[16];
	int llen = sprintf(buff, "%c, %d\n", YIELD_CHAR, pid);
	buff[llen] = '\0';
	llen = write(fd, buff, strlen(buff));
	printf("Process with pid = %d yielding\n", pid);
	if (llen != strlen(buff)) {
		fprintf(stderr, "\t*** FAIL ***: Incorrect write to procfs: %s",
			strerror(errno));
		close(fd);
		return llen;
	}

	close(fd);
	return 0;
}

int
register_process(void)
{
	return register_process_pid(getpid());
}

int
withdraw_process(void)
{
	return withdraw_process_pid(getpid());
}

int
yield(void)
{
	return yield_process_pid(getpid());
}
