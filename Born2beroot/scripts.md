## User
- user, usergroup

## hostname
`hostnamectl` check host name

## SSH
`ssh id@ip -p 4242`

## AppArmor
`sudo aa-status` Apparmor status

## ufw
`sudo ufw status` ufw status

## monitors
`uname -a` os and kernel version
`nproc --all` processor
`grep 'processor' /proc/cpuinfo | uniq | wc -l` vprocessor
`free -m | grep Mem: | awk '{printf"%.2f%%\n", $3 / $2 * 100'}` usage RAM rate
`df -Bm | grep /dev/ | grep -v /boot | awk '{used += $3} {full += $2} END {printf("%d%%\n"), used / full * 100}'` usage Memory
`mpstat | grep all | awk '{printf "%.2f%%\n", 100-$13}'` cpu usage
`who -b | awk '{print $3" "$4}'` last boot
`if [lsblk | grep lvm | wc -l -eq 0]; then echo no; else echo yes; fi` lvm or not
`cat /proc/net/sockstat{,6} | awk '$1 == "TCP:"{print $3 - 1 " ESTABLISHED"}'` connections
`who | wc -l` users
`hostname -I` IP
`ip addr | grep "ether " | awk '{print $2}' | sed -n '1p'` MAC
`journalctl _COMM=sudo | wc -l` sudo

