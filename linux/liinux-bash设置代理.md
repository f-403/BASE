---
layout: post
tags: [linux]
---


```bash
# set http or socks proxy environment variables


# set http proxy
export http_proxy=http://PROXYHOST:PROXYPORT

# set http proxy with user and password
export http_proxy=http://USERNAME:PASSWORD@PROXYHOST:PROXYPORT

# set http proxy with user and password (with special characters)
export http_proxy=http://`urlencode 'USERNAME'`:`urlencode 'PASSWORD'`@PROXYHOST:PROXYPORT
#这里的username与password要用urlencode转换成url编码
# set socks proxy (local DNS)
export http_proxy=socks5://PROXYHOST:PROXYPORT    
#----------------------------------------------------------------
#设置SOCKS5代理
#注意设置socks4/5的时候跟http_proxy是一样的
#export http_proxy="socks5://127.0.0.1:1080"
#export https_proxy="socks5://127.0.0.1:1080"
# 设置 socks 代理，自动识别socks版本
#export http_proxy=socks://10.0.0.52:1080
# 设置 socks4 代理
#export http_proxy=socks4://10.0.0.52:1080
# 设置 socks5 代理
#export http_proxy=socks5://10.0.0.52:1080
#----------------------------------------------------------------

# set socks proxy (remote DNS)
export http_proxy=socks5://PROXYHOST:PROXYPORT



# export other env variables
export https_proxy=$http_proxy \
ftp_proxy=$http_proxy \
rsync_proxy=$http_proxy \
all_proxy=$http_proxy

# export other env variables (another way)
export {https,ftp,rsync,all}_proxy=$http_proxy

export HTTP_PROXY=$http_proxy \
HTTPS_PROXY=$http_proxy \
FTP_PROXY=$http_proxy \ 
RSYNC_PROXY=$http_proxy \
ALL_PROXY=$http_proxy \
NO_PROXY=$no_proxy

export {HTTP,HTTPS,FTP,RSYNC,ALL}_PROXY=$http_proxy

# set git http(s) proxy
git config --global http.sslverify false
git config --global http.proxy $http_proxy
git config --global https.proxy $http_proxy

# only for 'github.com'
git config --global http.https://github.com.proxy $http_proxy


# set ssh proxy environment variables


# use 'nc' with http protocol
export ssh_proxy='ProxyCommand=nc -X connect -x PROXYHOST:PROXYPORT %h %p'

# use 'nc' with http protocol and proxy user
export ssh_proxy='ProxyCommand=nc -X connect -x PROXYHOST:PROXYPORT -P 'USERNAME' %h %p'

# use 'nc' with socks5 protocol
export ssh_proxy='ProxyCommand=nc -X 5 -x PROXYHOST:PROXYPORT %h %p'

# use 'connect' with http protocol
export ssh_proxy='ProxyCommand=connect -H PROXYHOST:PROXYPORT %h %p'

# use 'connect' with http protocol and proxy user
export ssh_proxy='ProxyCommand=connect -H USER@PROXYHOST:PROXYPORT %h %p'

# use 'connect' with HTTP_PROXY environment
export ssh_proxy='ProxyCommand=connect -h %h %p'

# use 'connect' with socks5 protocol
export ssh_proxy='ProxyCommand=connect -S PROXYHOST:PROXYPORT %h %p'

# use 'connect' with socks5 protocol and user
export ssh_proxy='ProxyCommand=connect -S USER@PROXYHOST:PROXYPORT %h %p'

# use 'connect' with SOCKS5_SERVER environment
export SOCKS5_SERVER='PROXYHOST:PROXYPORT'
export SOCKS5_USER='USERNAME'
export SOCKS5_PASSWD='PASSWORD'
export ssh_proxy='ProxyCommand=connect -s %h %p'

# connect to ssh server over proxy
ssh -o "$ssh_proxy" USER@FINAL_DEST

# set git ssh proxy
git config --global core.sshCommand "ssh -o $ssh_proxy"


# set no proxy to ignore private network address


no_proxy="127.0.0.1,localhost,.localdomain.com"
no_proxy=$no_proxy,`echo 10.{0..255}.{0..255}.{0..255}|tr ' ' ','`
no_proxy=$no_proxy,`echo 172.{16..31}.{0..255}.{0..255}|tr ' ' ','`
no_proxy=$no_proxy,`echo 192.168.{0..255}.{0..255}|tr ' ' ','`
export no_proxy

# for more private network addresses, check following url
# https://segmentfault.com/q/1010000010521593
# https://en.wikipedia.org/wiki/Private_network


# unset proxy environment variables

unset http_proxy https_proxy ftp_proxy rsync_proxy all_proxy HTTP_PROXY HTTPS_PROXY FTP_PROXY RSYNC_PROXY ALL_PROXY
unset {http,https,ftp,rsync,all}_proxy {HTTP,HTTPS,FTP,RSYNC,ALL}_PROXY

git config --global --unset http.proxy
git config --global --unset https.proxy
git config --global --unset core.sshCommand

git config --global --unset http.https://github.com.proxy

unset ssh_proxy

#如果要查询
env|grep -i proxy
#或者直接打印一下
echo $http_proxy
echo $https_proxy

#清除代理
$ unset http_proxy
$ unset https_proxy
$ unset ftp_proxy

#下面代码更新于20210311
$ export http_proxy=http://proxy:8089
$ export https_proxy=https://proxy:8090
$ export timeout=10
$ explo ...

```