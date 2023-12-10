#a) To count no.of processes which are running or ready in the system (Hint:- ps -e-o pid,ppid,cmd,stat, grep )


#!/bin/bash
echo Total number of process running in your systems:
ps -A --no-headers | wc -l
