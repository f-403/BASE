---
layout: post
tags: [linux]
---

`tor服务`

`https://community.torproject.org/onion-services/setup/`

`注意HiddenServiceDir不一定要跟apache2目录一样， 可以用其他目录，而且权限要为700`

`启动的话， 不能用root, sudo -u debian-tor tor 方式启动`

`个人理解: apache2用于web服务， tor用于将ip转发， 同时生成.onion网址`

`https://community.torproject.org/onion-services/setup/`

`https://community.torproject.org/onion-services/setup/`

`有问题可以直接运行 tor 命令查看一下输出`



This guide shows you how to set up an onion service for your website. For the technical details of how the onion service protocol works, see our onion service protocol page.

## Step 0: Get a working Tor

As part of this guide, we will assume you have a functional Tor in your machine. To set up Tor, please follow the [Tor installation guide](https://community.torproject.org/onion-services/setup/install/). Tor should be up and running correctly for this guide to work. You should also know where Tor's configuration files are.

## Step 1: Get a web server working

As a first step, you should set up a web server locally, like Nginx, Apache, or your favorite web server. Setting up a web server can be complex. If you get stuck or want to do more, find a friend who can help you or join our [tor-onions](https://lists.torproject.org/cgi-bin/mailman/listinfo/tor-onions) mailing list to speak with other operators.

As an example, we will cover how to set up an onion site with Nginx  and Apache on Debian. We recommend you install a new separate web server for your onion  service, since even if you already have one installed, you may be using  it (or want to use it later) for a regular website.

On this page, the commands to manage the web server are based on  Debian-like operating systems and may differ from other systems. Check your web server and operating system documentation.

### Apache

Apache is available in the main repository of multiple Linux and *BSD distributions. To install `apache2` package:

```
$ sudo apt install apache2
```

### Nginx

Nginx is available in the main repository of multiple Linux and *BSD distributions. To install `nginx` package:

```
$ sudo apt install nginx
```

By default, the web server will be running on `localhost:80` at the end of the installation. If you get an error message, something has gone wrong and you cannot continue until you've figured out why this didn't work.

Once your web server is set up, make sure it works: open your browser and go to http://localhost/. Then try putting a file in the main html directory, and make sure it shows up when you access the site.

## Step 2: Configure your Tor onion service

The next step is opening the config file of Tor (torrc) and doing the appropriate configurations to setup an onion service. Depending on your operating system and setup, your Tor configuration file can be at a different location or look different.

You will need to put the following two lines in your `torrc` file:

```
 HiddenServiceDir /var/lib/tor/my_website/
 HiddenServicePort 80 127.0.0.1:80
```

The `HiddenServiceDir` line specifies the directory which should contain information and cryptographic keys for your onion service. You will want to change the `HiddenServiceDir` line, so that it points to an actual directory that is readable/writeable by the user that will be running Tor.

The `HiddenServicePort` line specifies a *virtual port* (that is, the port that people visiting your onion service will be  using), and in the above case it says that any traffic incoming to port  80 of your onion service should be redirected to `127.0.0.1:80` (which is where the web server from step 1 is listening).

**Tip:** A good practice to avoid leaking an onion  service to a local network is to run onion services over Unix sockets  instead of a TCP socket. You will need to edit and put the following two lines in your `torrc` file:

```
HiddenServiceDir /var/lib/tor/my-website/
HiddenServicePort 80 unix:/var/run/tor-my-website.sock
```

## Step 3: Restart Tor and check that it worked

Now save your `torrc` and restart Tor.

```
$ sudo systemctl restart tor
```

If Tor starts up again, great. Otherwise, something is wrong. First look at your logfiles for hints. It will print some warnings or error messages. That should give you an idea of what went wrong. Typically, there are typos in the `torrc` or wrong directory permissions (See the [logging FAQ](https://www.torproject.org/docs/faq#Logs) entry if you don't know how to enable or find your log file.)

When Tor starts, it will automatically create the `HiddenServiceDir` that you specified (if necessary). Make sure this is the case.

## Step 4: Test that your onion service works

Now to get your onion service address, go to your `HiddenServiceDir` directory, and find a file named `hostname`. The `hostname` file in your onion service configuration directory contains the hostname for your new onion v3 service. The other files are your onion service keys, so it is imperative that these are kept private. If your keys leak, other people can impersonate your onion service, deeming it compromised, useless, and dangerous to visit.

Now you can connect to your onion service using Tor Browser, and you should get the html page you setup back in **Step 1**. If it doesn't work, look in your logs for some hints, and keep playing with it until it works.

It is important to note that an onion service configured like this  will be readable by anybody who knows or discovers the address. You can make onion services require authentication, and only users with a private key will access the service. Read more about [Client authorization](https://community.torproject.org/onion-services/advanced/client-auth/) documentation.

## (Optional) Step 5: Running multiple onion services

If you want to forward multiple virtual ports for a single onion service, just add more `HiddenServicePort` lines. If you want to run multiple onion services from the same Tor client, just add another `HiddenServiceDir` line. All the following `HiddenServicePort` lines refer to this `HiddenServiceDir` line, until you add another `HiddenServiceDir` line:

```
 HiddenServiceDir /var/lib/tor/onion_service/
 HiddenServicePort 80 127.0.0.1:80

 HiddenServiceDir /var/lib/tor/other_onion_service/
 HiddenServicePort 6667 127.0.0.1:6667
 HiddenServicePort 22 127.0.0.1:22
```

If you're running multiple onion sites on the same web server,  remember to edit your web server virtual host file and add the onion  address for each website. For example, in Nginx and using Tor with Unix sockets, the configuration would look like this:

```
server {
        listen unix:/var/run/tor-my-website.sock;
        server_name <your-onion-address>.onion;
        access_log /var/log/nginx/my-website.log;
        index index.html;
        root /path/to/htdocs;
}
```

Or in Apache with Tor service listening on port 80:

```
     <VirtualHost *:80>
       ServerName <your-onion-address.onion>
       DocumentRoot /path/to/htdocs
       ErrorLog ${APACHE_LOG_DIR}/my-website.log
     </VirtualHost>
```

## Step 6: Security advice and more tips

The default version of onion services is version 3 and it has 56 characters long. Onion services version 2 is being deprecated and will be retired soon  from the Tor network, after 0.4.6.x Tor release, in July 2021. Please read the blog post [Onion Service version deprecation timeline](https://blog.torproject.org/v2-deprecation-timeline) for more information.

Some onion site operators may not want to disclose their onion  service location. Therefore, you need to configure your web server so it doesn't give away any information about you, your computer, or your location. That is not an easy task, and these resources will help on how to make  this possible:

- [Operational Security](https://community.torproject.org/onion-services/advanced/opsec/).
- [Onion services best practices](https://riseup.net/en/security/network-security/tor/onionservices-best-practices) by Riseup Collective.
- [OnionScan](https://onionscan.org/) is a tool to check if your onion site is leaking information that could compromise your anonymity like your server IP address.

Finally, if you plan to keep your service available for a long time, you might want to make a backup copy of the `private_key` file somewhere.

Now that you have an onion site working, you may want to deploy [Onion-Location](https://community.torproject.org/onion-services/advanced/onion-location/), or use tools like Docker, [Heroku](https://gitlab.torproject.org/hiro/onions-on-heroku), [Terraform](https://gitlab.torproject.org/hiro/terraform-onions), [Ansible](https://galaxy.ansible.com/systemli/onion) or [stem](https://stem.torproject.org/tutorials/over_the_river.html) to automate the management of your onion services. If you have a static website, but never installed Nginx or Apache, another project to try is [OnionShare](https://onionshare.org), where running an onion site will be easier: guided with a graphic interface and with minimal configuration.
