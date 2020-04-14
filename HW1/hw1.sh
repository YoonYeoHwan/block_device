sudo blktrace -d /dev/sda -a issue -a complete -o - | blkparse -f "%M %m %3d %a %10S %6n %5T.%9t\n" -i -
