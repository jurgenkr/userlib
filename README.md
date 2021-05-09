# User Space Library

This repository contains a user space library for you to use when testing your
project kernel module. It contains a bunch of helper functions for registering,
withdrawing, and yielding, as well as two user space applications that you can
use to test your scheduler.

# Adjusting Parameters

The library assumes that you are using the characters `R`, `W`, and `Y` for
registering, withdrawing, and yielding, respectively. If you are using a
different interface, then modify the corresponding macros in `csse332_lib.h` as
follows
```c
/* Change these values if you are using different characters */
#define REGISTER_CHAR 'R'
#define WITHDRAW_CHAR 'W'
#define YIELD_CHAR 'Y'
```

__IMPORTANT NOTE__: My library assumes that the format of your module is `R,
1000` for registering process with process id of 1000 (Note the comma after the
first character). You can adjust the code in `csse332_lib.c` to remove this
comma, but I do recommend that you change your module format to accept this
comma so that I can test things out easily when grading.

# Usage

There are two applications in this repository, `userapp` and `yieldapp`. Take a
look at the source code to figure out exactly what they do. Here is a quick
summary:

- `userapp`: This application will run 50 iterations of doing some useless work,
  but will not call yield. Use this application to test whether your module
  preempts running process correctly.
- `yieldapp`: This application is identical to `userapp` except for the fact
  that it will yield execution after each iteration of the loop. Use this
  application to test if your module correctly implements the `yield` interface.

