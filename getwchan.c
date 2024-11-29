#include <stdio.h>
#include <stdlib.h>

// note: for libprocstat.h (you'll get errors from compiler without sys/* includes)
#include <sys/param.h>
#include <sys/queue.h>
#include <sys/socket.h>
#include <libprocstat.h>

// note: for KERN_PROC_PID
#include <sys/sysctl.h>

// note : for struct kinfo_proc
#include <sys/user.h>

int main(int argc, const char* argv[]) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s <pid>\n", argv[0]);
    return 1;
  }
  int pid = atoi(argv[1]);
  struct procstat* procstat = procstat_open_sysctl();
  unsigned int count = 0;
  struct kinfo_proc* kinfo = procstat_getprocs(procstat, KERN_PROC_PID, pid, &count);
  if (count != 1) {
    fprintf(stderr, "count != 1, PID %d not found?\n", count);
    return 1;
  }
  if (kinfo == NULL) {
    fprintf(stderr, "panic: kinfo is NULL\n");
    return 1;
  }
  printf("%s\n", kinfo->ki_wmesg);
  procstat_freeprocs(procstat, kinfo);
  procstat_close(procstat);
  return 0;
}

