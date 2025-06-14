
Apache2¶

Assuming you have both Apache2 and the modules proxy, proxy_http, proxy_html (if you plan on serving HTML pages), and proxy_wstunnel (if you plan on using websockets). You will need to enable those modules, which you can do using the following commands:
```bash
a2enmod proxy
a2enmod proxy_http
a2enmod proxy_html
a2enmod proxy_wstunnel
```
Next up you'll need to change your configuration (default is /etc/apache2/sites-enabled/000-default.conf) and add the following lines (replace localhost and 40080 with the address and port you defined for your Crow App):

ProxyPass / http://localhost:40080
ProxyPassReverse / http://localhost:40080

If you want crow to run in a subdirectory (such as domain.abc/crow) you can use the location tag:
```bash
<Location "/crow">

    ProxyPass http://localhost:40080

    ProxyPassReverse http://localhost:40080

</Location>
```
Note

If you're using an Arch Linux based OS. You will have to access /etc/httpd/conf/httpd.conf to enable modules and change configuration.
Nginx¶

Setting Nginx up is slightly simpler than Apache, all you need is the Nginx package itself. Once you've installed it, go to the configuration file (usually a .conf file located in /etc/nginx) and add the following lines to your server section (replace localhost and 40080 with the address and port you defined for your Crow App):
```bash
location / {
    proxy_pass http://localhost:40080/;
    proxy_http_version 1.1;
}
```
Remember to remove or comment out any existing location / section.

Alternatively, if you want to use a subdirectory, you can simply change the location parameter as such:
```bash
location /crow/ {
    proxy_pass http://localhost:40080/;
    proxy_http_version 1.1;
}

```