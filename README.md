# xv6-Modified
The goal of this project is to modify the [xv6 Operating System](https://github.com/mit-pdos/xv6-public) by adding new features and functionalities like new keyboard shortcuts for console, new system calls, CPU scheduling, and synchronization.

## Phase 1 (Introduction to xv6)
* Add names of contributors to message boot
* Add three new keyboard shortcuts to xv6 shell:
  1. `CTRL + T`: Swap the last two letters before the cursor
  2. `CTRL + O`: Uppercase all letters after the marker
  3. `CTRL + A`: Change the position of the cursor to the beginning of the line
  
* Design and implementation of a user-level program (`factor`)


## Phase 2 (System calls)
* `calculate_sum_of_digits (int num)`: returns the sum value of all digits in `num`
* `get_file_sectors(int fd)`: prints the block number on disk for each block of the file
* `get_parent_id(void)`: prints the parent process id of the currently running process
* `set_process_parent(int pid)`: sets the currently running process as the parent of input process (`pid`)

## Phase 3 (CPU Scheduling)
* In this scheduler, processes are placed in different levels according to their priority, which is assumed in this project that there are three levels and subsequently three priorities:
  1. Round Robin
  2. Last Come First Serve (LCFS)
  3. Modified Highest Response Ratio Next (MHRRN)
* Required system calls:
  * `change_queue(int pid, int queue)`
  * `set_process_MHRRN(int pid, int MHRRN_priority)`
  * `set_system_MHRRN(int MHRRN_priority)`
  *  `print_info(void)`
  
## Phase 4 (Synchronization)
* Implement `Counting Semaphore` with required system calls
* Simulate `Dining Philosophers` problem with 5 philosophers by using a monitor


  

