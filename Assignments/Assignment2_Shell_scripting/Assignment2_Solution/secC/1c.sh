#c) List out all processes whose parent is init
#!/bin/bash
ps -ef | grep "init"
