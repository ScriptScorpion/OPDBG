#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdint>

struct Commands {
     const uint16_t code;
     const std::string call;
};

bool isLittleEndian() {
    const uint16_t test = 0x0001;
    return ((const uint8_t)test == 0x01);
}

uint16_t readLittleEndian(std::istream& file) {
    uint16_t value;
    file.read(reinterpret_cast<char*>(&value), sizeof(value));
    if (!isLittleEndian()) {
        value = ((value & 0xFF00) >> 8) | ((value & 0x00FF) << 8); // changes byte places, example: 0x1011 will be 0x1110 if this completed
    }
    return value;
}

void Parse(std::vector <std::string> &string, std::string Format, std::ifstream &File) {
     // needs to return changed string
     std::vector <Commands> commands64bit = {
          {0x00, "read"},
          {0x01, "write"},
          {0x02, "open"},
          {0x03, "close"},
          {0x04, "stat"},
          {0x05, "fstat"},
          {0x06, "lstat"},
          {0x07, "poll"},
          {0x08, "lseek"},
          {0x09, "mmap"},
          {0x0a, "mprotect"},
          {0x0b, "munmap"},
          {0x0c, "brk"},
          {0x0d, "rt_sigaction"},
          {0x0e, "rt_sigprocmask"},
          {0x0f, "rt_sigreturn"},
          {0x10, "ioctl"},
          {0x11, "pread64"},
          {0x12, "pwrite64"},
          {0x13, "readv"},
          {0x14, "writev"},
          {0x15, "access"},
          {0x16, "pipe"},
          {0x17, "select"},
          {0x18, "sched_yield"},
          {0x19, "mremap"},
          {0x1a, "msync"},
          {0x1b, "mincore"},
          {0x1c, "madvise"},
          {0x1d, "shmget"},
          {0x1e, "shmat"},
          {0x1f, "shmctl"},
          {0x20, "dup"},
          {0x21, "dup2"},
          {0x22, "pause"},
          {0x23, "nanosleep"},
          {0x24, "getitimer"},
          {0x25, "alarm"},
          {0x26, "setitimer"},
          {0x27, "getpid"},
          {0x28, "sendfile"},
          {0x29, "socket"},
          {0x2a, "connect"},
          {0x2b, "accept"},
          {0x2c, "sendto"},
          {0x2d, "recvfrom"},
          {0x2e, "sendmsg"},
          {0x2f, "recvmsg"},
          {0x30, "shutdown"},
          {0x31, "bind"},
          {0x32, "listen"},
          {0x33, "getsockname"},
          {0x34, "getpeername"},
          {0x35, "socketpair"},
          {0x36, "setsockopt"},
          {0x37, "getsockopt"},
          {0x38, "clone"},
          {0x39, "fork"},
          {0x3a, "vfork"},
          {0x3b, "execve"},
          {0x3c, "exit"},
          {0x3d, "wait4"},
          {0x3e, "kill"},
          {0x3f, "uname"},
          {0x40, "semget"},
          {0x41, "semop"},
          {0x42, "semctl"},
          {0x43, "shmdt"},
          {0x44, "msgget"},
          {0x45, "msgsnd"},
          {0x46, "msgrcv"},
          {0x47, "msgctl"},
          {0x48, "fcntl"},
          {0x49, "flock"},
          {0x4a, "fsync"},
          {0x4b, "fdatasync"},
          {0x4c, "truncate"},
          {0x4d, "ftruncate"},
          {0x4e, "getdents"},
          {0x4f, "getcwd"},
          {0x50, "chdir"},
          {0x51, "fchdir"},
          {0x52, "rename"},
          {0x53, "mkdir"},
          {0x54, "rmdir"},
          {0x55, "creat"},
          {0x56, "link"},
          {0x57, "unlink"},
          {0x58, "symlink"},
          {0x59, "readlink"},
          {0x5a, "chmod"},
          {0x5b, "fchmod"},
          {0x5c, "chown"},
          {0x5d, "fchown"},
          {0x5e, "lchown"},
          {0x5f, "umask"},
          {0x60, "gettimeofday"},
          {0x61, "getrlimit"},
          {0x62, "getrusage"},
          {0x63, "sysinfo"},
          {0x64, "times"},
          {0x65, "ptrace"},
          {0x66, "getuid"},
          {0x67, "syslog"},
          {0x68, "getgid"},
          {0x69, "setuid"},
          {0x6a, "setgid"},
          {0x6b, "geteuid"},
          {0x6c, "getegid"},
          {0x6d, "setpgid"},
          {0x6e, "getppid"},
          {0x6f, "getpgrp"},
          {0x70, "setsid"},
          {0x71, "setreuid"},
          {0x72, "setregid"},
          {0x73, "getgroups"},
          {0x74, "setgroups"},
          {0x75, "setresuid"},
          {0x76, "getresuid"},
          {0x77, "setresgid"},
          {0x78, "getresgid"},
          {0x79, "getpgid"},
          {0x7a, "setfsuid"},
          {0x7b, "setfsgid"},
          {0x7c, "getsid"},
          {0x7d, "capget"},
          {0x7e, "capset"},
          {0x7f, "rt_sigpending"},
          {0x80, "rt_sigtimedwait"},
          {0x81, "rt_sigqueueinfo"},
          {0x82, "rt_sigsuspend"},
          {0x83, "sigaltstack"},
          {0x84, "utime"},
          {0x85, "mknod"},
          {0x86, "uselib"},
          {0x87, "personality"},
          {0x88, "ustat"},
          {0x89, "statfs"},
          {0x8a, "fstatfs"},
          {0x8b, "sysfs"},
          {0x8c, "getpriority"},
          {0x8d, "setpriority"},
          {0x8e, "sched_setparam"},
          {0x8f, "sched_getparam"},
          {0x90, "sched_setscheduler"},
          {0x91, "sched_getscheduler"},
          {0x92, "sched_get_priority_max"},
          {0x93, "sched_get_priority_min"},
          {0x94, "sched_rr_get_interval"},
          {0x95, "mlock"},
          {0x96, "munlock"},
          {0x97, "mlockall"},
          {0x98, "munlockall"},
          {0x99, "vhangup"},
          {0x9a, "modify_ldt"},
          {0x9b, "pivot_root"},
          {0x9c, "_sysctl"},
          {0x9d, "prctl"},
          {0x9e, "arch_prctl"},
          {0x9f, "adjtimex"},
          {0xa0, "setrlimit"},
          {0xa1, "chroot"},
          {0xa2, "sync"},
          {0xa3, "acct"},
          {0xa4, "settimeofday"},
          {0xa5, "mount"},
          {0xa6, "umount2"},
          {0xa7, "swapon"},
          {0xa8, "swapoff"},
          {0xa9, "reboot"},
          {0xaa, "sethostname"},
          {0xab, "setdomainname"},
          {0xac, "iopl"},
          {0xad, "ioperm"},
          {0xae, "create_module"},
          {0xaf, "init_module"},
          {0xb0, "delete_module"},
          {0xb1, "get_kernel_syms"},
          {0xb2, "query_module"},
          {0xb3, "quotactl"},
          {0xb4, "nfsservctl"},
          {0xb5, "getpmsg"},
          {0xb6, "putpmsg"},
          {0xb7, "afs_syscall"},
          {0xb8, "tuxcall"},
          {0xb9, "security"},
          {0xba, "gettid"},
          {0xbb, "readahead"},
          {0xbc, "setxattr"},
          {0xbd, "lsetxattr"},
          {0xbe, "fsetxattr"},
          {0xbf, "getxattr"},
          {0xc0, "lgetxattr"},
          {0xc1, "fgetxattr"},
          {0xc2, "listxattr"},
          {0xc3, "llistxattr"},
          {0xc4, "flistxattr"},
          {0xc5, "removexattr"},
          {0xc6, "lremovexattr"},
          {0xc7, "fremovexattr"},
          {0xc8, "tkill"},
          {0xc9, "time"},
          {0xca, "futex"},
          {0xcb, "sched_setaffinity"},
          {0xcc, "sched_getaffinity"},
          {0xcd, "set_thread_area"},
          {0xce, "io_setup"},
          {0xcf, "io_destroy"},
          {0xd0, "io_getevents"},
          {0xd1, "io_submit"},
          {0xd2, "io_cancel"},
          {0xd3, "get_thread_area"},
          {0xd4, "lookup_dcookie"},
          {0xd5, "epoll_create"},
          {0xd6, "epoll_ctl_old"},
          {0xd7, "epoll_wait_old"},
          {0xd8, "remap_file_pages"},
          {0xd9, "getdents64"},
          {0xda, "set_tid_address"},
          {0xdb, "restart_syscall"},
          {0xdc, "semtimedop"},
          {0xdd, "fadvise64"},
          {0xde, "timer_create"},
          {0xdf, "timer_settime"},
          {0xe0, "timer_gettime"},
          {0xe1, "timer_getoverrun"},
          {0xe2, "timer_delete"},
          {0xe3, "clock_settime"},
          {0xe4, "clock_gettime"},
          {0xe5, "clock_getres"},
          {0xe6, "clock_nanosleep"},
          {0xe7, "exit_group"},
          {0xe8, "epoll_wait"},
          {0xe9, "epoll_ctl"},
          {0xea, "tgkill"},
          {0xeb, "utimes"},
          {0xec, "vserver"},
          {0xed, "mbind"},
          {0xee, "set_mempolicy"},
          {0xef, "get_mempolicy"},
          {0xf0, "mq_open"},
          {0xf1, "mq_unlink"},
          {0xf2, "mq_timedsend"},
          {0xf3, "mq_timedreceive"},
          {0xf4, "mq_notify"},
          {0xf5, "mq_getsetattr"},
          {0xf6, "kexec_load"},
          {0xf7, "waitid"},
          {0xf8, "add_key"},
          {0xf9, "request_key"},
          {0xfa, "keyctl"},
          {0xfb, "ioprio_set"},
          {0xfc, "ioprio_get"},
          {0xfd, "inotify_init"},
          {0xfe, "inotify_add_watch"},
          {0xff, "inotify_rm_watch"},
          {0x100, "migrate_pages"},
          {0x101, "openat"},
          {0x102, "mkdirat"},
          {0x103, "mknodat"},
          {0x104, "fchownat"},
          {0x105, "futimesat"},
          {0x106, "newfstatat"},
          {0x107, "unlinkat"},
          {0x108, "renameat"},
          {0x109, "linkat"},
          {0x10a, "symlinkat"},
          {0x10b, "readlinkat"},
          {0x10c, "fchmodat"},
          {0x10d, "faccessat"},
          {0x10e, "pselect6"},
          {0x10f, "ppoll"},
          {0x110, "unshare"},
          {0x111, "set_robust_list"},
          {0x112, "get_robust_list"},
          {0x113, "splice"},
          {0x114, "tee"},
          {0x115, "sync_file_range"},
          {0x116, "vmsplice"},
          {0x117, "move_pages"},
          {0x118, "utimensat"},
          {0x119, "epoll_pwait"},
          {0x11a, "signalfd"},
          {0x11b, "timerfd_create"},
          {0x11c, "eventfd"},
          {0x11d, "fallocate"},
          {0x11e, "timerfd_settime"},
          {0x11f, "timerfd_gettime"},
          {0x120, "accept4"},
          {0x121, "signalfd4"},
          {0x122, "eventfd2"},
          {0x123, "epoll_create1"},
          {0x124, "dup3"},
          {0x125, "pipe2"},
          {0x126, "inotify_init1"},
          {0x127, "preadv"},
          {0x128, "pwritev"},
          {0x129, "rt_tgsigqueueinfo"},
          {0x12a, "perf_event_open"},
          {0x12b, "recvmmsg"},
          {0x12c, "fanotify_init"},
          {0x12d, "fanotify_mark"},
          {0x12e, "prlimit64"},
          {0x12f, "name_to_handle_at"},
          {0x130, "open_by_handle_at"},
          {0x131, "clock_adjtime"},
          {0x132, "syncfs"},
          {0x133, "sendmmsg"},
          {0x134, "setns"},
          {0x135, "getcpu"},
          {0x136, "process_vm_readv"},
          {0x137, "process_vm_writev"},
          {0x138, "kcmp"},
          {0x139, "finit_module"},
          {0x13a, "sched_setattr"},
          {0x13b, "sched_getattr"},
          {0x13c, "renameat2"},
          {0x13d, "seccomp"},
          {0x13e, "getrandom"},
          {0x13f, "memfd_create"},
          {0x140, "kexec_file_load"},
          {0x141, "bpf"},
          {0x142, "execveat"},
          {0x143, "userfaultfd"},
          {0x144, "membarrier"},
          {0x145, "mlock2"},
          {0x146, "copy_file_range"},
          {0x147, "preadv2"},
          {0x148, "pwritev2"},
          {0x149, "pkey_mprotect"},
          {0x14a, "pkey_alloc"},
          {0x14b, "pkey_free"},
          {0x14c, "statx"},
          {0x14d, "io_pgetevents"},
          {0x14e, "rseq"},
          {0x14f, "uretprobe"},
          {0x1a8, "pidfd_send_signal"},
          {0x1a9, "io_uring_setup"},
          {0x1aa, "io_uring_enter"},
          {0x1ab, "io_uring_register"},
          {0x1ac, "open_tree"},
          {0x1ad, "move_mount"},
          {0x1ae, "fsopen"},
          {0x1af, "fsconfig"},
          {0x1b0, "fsmount"},
          {0x1b1, "fspick"},
          {0x1b2, "pidfd_open"},
          {0x1b3, "clone3"},
          {0x1b4, "close_range"},
          {0x1b5, "openat2"},
          {0x1b6, "pidfd_getfd"},
          {0x1b7, "faccessat2"},
          {0x1b8, "process_madvise"},
          {0x1b9, "epoll_pwait2"},
          {0x1ba, "mount_setattr"},
          {0x1bb, "quotactl_fd"},
          {0x1bc, "landlock_create_ruleset"},
          {0x1bd, "landlock_add_rule"},
          {0x1be, "landlock_restrict_self"},
          {0x1bf, "memfd_secret"},
          {0x1c0, "process_mrelease"},
          {0x1c1, "futex_waitv"},
          {0x1c2, "set_mempolicy_home_node"},
          {0x1c3, "cachestat"},
          {0x1c4, "fchmodat2"},
          {0x1c5, "map_shadow_stack"},
          {0x1c6, "futex_wake"},
          {0x1c7, "futex_wait"},
          {0x1c8, "futex_requeue"},
          {0x1c9, "statmount"},
          {0x1ca, "listmount"},
          {0x1cb, "lsm_get_self_attr"},
          {0x1cc, "lsm_set_self_attr"},
          {0x1cd, "lsm_list_modules"},
          {0x1ce, "mseal"}
     };
     std::vector <uint8_t> opcodes;
     uint64_t entry {};
     uint8_t byte {}; // std::byte
     uint16_t Arch {};
     std::string builder {};
     string.clear();
     if (Format == "ELF") {
          File.seekg(0x12); 
          File.read(reinterpret_cast<char*>(&Arch), sizeof(Arch));
          if (Arch == 0x3E) {
               string.push_back("x86-64");
          }
          else if (Arch == 0x03) {
               string.push_back("x86");
          }
          else {
               std::cerr << "Unknown Linux architecture \n";
               return;
          }
          File.seekg(0x18);
          File.read(reinterpret_cast<char*>(&entry), sizeof(entry));
          File.seekg(entry);
          for (int i = 0; File.read(reinterpret_cast<char*>(&byte), 1); ++i) {
               opcodes.push_back(byte);
          }
     }
     else if (Format == "WIN") {
          File.seekg(0x3C);
          File.read(reinterpret_cast<char*>(&Arch), sizeof(Arch));
          File.seekg(Arch + 4);
          Arch = readLittleEndian(File);
          if (Arch == 0x8664) {
               string.push_back("x86-64");
          }
          else if (Arch == 0x014C) {
               string.push_back("x86");
          }
          else {
               std::cerr << "Unknown Windows architecture \n";
               return;
          }
          File.seekg(0x18);
          File.read(reinterpret_cast<char*>(&entry), sizeof(entry));
          File.seekg(entry);
          for (int i = 0; File.read(reinterpret_cast<char*>(&byte), 1); ++i) {
               opcodes.push_back(byte);
          }
     }
     else {
          std::cerr << "Format error \n";
          std::cerr.flush();
          return;
     }
     
     for (int y = 0; y < opcodes.size() - 1; y++) {
          for (int x = 0; x < commands64bit.size() - 1; x++) {
               if (commands64bit[x].code == opcodes[y]) {
                    builder = (commands64bit[x].call);
                    builder += " ";
                    builder += std::to_string(opcodes[y + 1]);
                    string.push_back(builder);
                    builder.clear();
               }
               else {
                    continue;
               }
          }
         // std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(y) << " ";
     }
     return;
}
