This is an example for builtin libprocstat, shows top(3)'s WCHAN equivalent of a process.

```
# ./getwchan 50818
select
# ./getwchan 19744
zio->io_
```

# References

* https://man.freebsd.org/cgi/man.cgi?libprocstat(3)
* https://github.com/freebsd/freebsd-src/blob/main/usr.bin/procstat/procstat.c
* https://github.com/freebsd/freebsd-src/blob/main/usr.bin/procstat/procstat_basic.c
