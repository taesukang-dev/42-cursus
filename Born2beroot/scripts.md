## User
- user, usergroup

<br />

## hostname
`hostnamectl` check host name

<br />

## SSH
`ssh id@ip -p 4242`

<br />

## AppArmor
`sudo aa-status` Apparmor status

<br />

## ufw
`sudo ufw status` ufw status

<br />

## monitors
`uname -a` os and kernel version

<br />

`nproc --all` processor

<br />

`grep 'processor' /proc/cpuinfo | uniq | wc -l` vprocessor

<br />

`free -m | grep Mem: | awk '{printf"%.2f%%\n", $3 / $2 * 100'}` usage RAM rate

<br />

`df -Bm | grep /dev/ | grep -v /boot | awk '{used += $3} {full += $2} END {printf("%d%%\n"), used / full * 100}'` usage Memory

<br />

`mpstat | grep all | awk '{printf "%.2f%%\n", 100-$13}'` cpu usage

<br />

`who -b | awk '{print $3" "$4}'` last boot

<br />

`if [lsblk | grep lvm | wc -l -eq 0]; then echo no; else echo yes; fi` lvm or not

<br />

`cat /proc/net/sockstat{,6} | awk '$1 == "TCP:"{print $3 - 1 " ESTABLISHED"}'` connections

<br />

`who | wc -l` users

<br />

`hostname -I` IP

<br />

`ip addr | grep "ether " | awk '{print $2}' | sed -n '1p'` MAC

<br />

`journalctl _COMM=sudo | wc -l` sudo

