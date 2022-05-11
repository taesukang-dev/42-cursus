## system
`sudo systemctl status ufw` ufw <br />
`sudo systemctl status ssh` ssh <br />
`hostnamectl` debian <br />

## group
`cat /etc/group | grep tkang`

<br />

## User
`sudo useradd 'user'` <br />
`usermod -aG 'group' 'user'` <br />
`cut -f1 -d: /etc/passwd` <br />

<br />

## password policy
`vi /etc/login.defs` password expire days
<br />

`libpam-pwquality` 패스워드 설정 강화를 위한 모듈 <br />
`vi /etc/pam.d/common-password` password regex

<br />

## hostname
`hostnamectl` check host name <br />
`hostnamectl set-hostname 'change-name'`

<br />

## LVM
`lsblk` check partitioning scheme

<br />

## sudoers
`visudo /etc/sudoers` sudoers path <br />
`requiretty` tty환경에서만 sudo를 실행하겠다. <br />
`log_input` , `log_output` pseudo tty (pts, 의사 tty)에서 sudo 명령을 실행하고 모든 사용자 입력과 출력을 화면에 수신 가능하게 기록 <br />

<br />

sudoers는 일반 계정에 sudo 명령어를 이용하여 임시로 root 권한을 주는 것을 의미한다.

## check log
`/var/log/sudo`

<br />

## ufw
`sudo systemctl status ufw` ufw <br />
`sudo ufw allow 'port-number'` allow <br />
`sudo ufw delete allow 'port-number'` delete <br />

## SSH
`ssh id@ip -p 4242` <br />
`vim /etc/ssh/sshd_config ` config file <br />
`ss -tupln` ss로 리눅스 시스템 소켓 상태를 조회 <br />
`/etc/network/interfaces` interface settings

<br />

## AppArmor
`sudo aa-status` Apparmor status

<br />

## ufw
`sudo ufw status` ufw status

<br />

## monitors
`sysstat` 리눅스 성능 측정 도구, cpu memory network 등 지표를 수치화한다. <br />
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

## cron
`crontab -e` settings <br />
`wall` 사용자의 터미널로 메세지를 보낸다.

## WordPress
- php로 작성된 온라인 오픈소스 웹사이트 제작 도구
`ufw allow 80` well-known port
`/var/www/html/wordpress`
`/var/www/html/wordpress/wp-config.php`

## Lighttpd
- 오픈소스 경량 웹 서버

```bash
$ sudo systemctl stop lighttpd.service	// 서버 중지
$ sudo systemctl start lighttpd.service	// 서버 시작
$ sudo systemctl enable lighttpd.service	// 서버 부팅 (enable with start up)
```
` vi /etc/lighttpd/lighttpd.conf` lighttpd 설정

## MariaDB
- RDBMS
```bash
$ sudo systemctl stop mysql.service	// DB 중지
$ sudo systemctl start mysql.service	// DB 시작
$ sudo systemctl enable mysql.service	// DB 부팅 (enable with start up)
$ sudo mysql_secure_installation // 보안 설정
$ sudo mysql -u root -p
```

## PHP
`vim /etc/lighttpd/conf-available/15-fastcgi-php.conf` fastcgi 적용

## ftp, vsftpd
`dpkg -l | grep vsftpd` vsftpd <br />
`dpkg -l | grep ftp` ftp <br />
`ufw status` check 21 prot (well known port) <br />
`vim /etc/vsftpd.conf` vsftpd setting <br />
```bash
write_enable=YES // 업로드 가능하게
user_sub_token=$USER
local_root=/home/$USER/ftp // ftp root directory
```

<br />

`vim /etc/vsftpd.userlist` vsftpd user list <br />
```bash
userlist_enable=YES
userlist_file=/etc/vsftpd.userlist
userlist_deny=NO // userlist 등록된 계정만 접속 가능
```
