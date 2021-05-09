#ifndef __CSSE332_LIB_H
#define __CSSE332_LIB_H

#include <stdlib.h>

#define PROCFS_PATH "/proc/csse332/status"

/* Change these values if you are using different characters */
#define REGISTER_CHAR 'R'
#define WITHDRAW_CHAR 'W'
#define YIELD_CHAR 'Y'

/* register_process_pid - Register a process with the module
 *
 * @pid the pid of the process to register
 *
 * @return 0 on success, error number on failure
 */
int register_process_pid(pid_t pid);

/* withdraw_process_pid - Withdraw a process from the module
 *
 * @pid the pid of the process to withdraw
 *
 * @return 0 on success, error number on failure
 */
int withdraw_process_pid(pid_t pid);

/* yield_process_pid - voluntarily yield the CPU
 *
 * @pid the pid of the process yielding
 *
 * @return 0 on success, error number on failure
 */
int yield_process_pid(pid_t pid);

/* register_process - Register a process by extracting its pid
 *
 * @return 0 on success, error number on failure
 */
int register_process(void);

/* withdraw_process - Withdraw a process by extracting its pid
 *
 * @return 0 on success, error number on failure
 */
int withdraw_process(void);

/* yield - voluntarily yield the CPU
 *
 * @return 0 on success, error number on failure
 */
int yield(void);

#endif /* csse332_lib.h */
