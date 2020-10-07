##Dockerfile of Nginx

####Introduction

这是一个Nginx的Dockerfile。使用它，可以很方便的建立Google镜像；经过简单的设置，还可以使用反向代理功能。  
Nginx Version 1.8.0  
额外添加的模块：  
[nginx-dav-ext-module](https://github.com/arut/nginx-dav-ext-module)  
[nginx-upstream-fair](https://github.com/gnosek/nginx-upstream-fair)  
[ngx_http_substitutions_filter_module](https://github.com/yaoweibin/ngx_http_substitutions_filter_module)  
[ngx_http_google_filter_module](https://github.com/cuber/ngx_http_google_filter_module)  
相关编译参数如下：  
```
>./configure \
>--prefix=/var/www \
>--sbin-path=/usr/sbin/nginx \
>--conf-path=/etc/nginx/nginx.conf \
>--error-log-path=/var/log/nginx/log/error.log \
>--http-log-path=/var/log/nginx/access.log \
>--pid-path=/var/run/nginx.pid \
>--lock-path=/var/run/nginx.lock \
>--http-client-body-temp-path=/var/cache/nginx/client_temp \
>--http-proxy-temp-path=/var/cache/nginx/proxy_temp \
>--http-fastcgi-temp-path=/var/cache/nginx/fastcgi_temp \
>--http-scgi-temp-path=/var/cache/nginx/scgi_temp \
>--http-uwsgi-temp-path=/var/cache/nginx/uwsgi_temp \
>--user=nginx \
>--group=nginx \
>--with-cc-opt='-g -O2 -fstack-protector-strong -Wformat -Werror=format-security -Wp,-D_FORTIFY_SOURCE=2' \
>--with-ld-opt='-Wl,-z,relro -Wl,--as-needed' \
>--with-file-aio \
>--with-http_addition_module \
>--with-http_auth_request_module \
>--with-http_dav_module \
>--with-http_flv_module \
>--with-http_mp4_module \
>--with-http_gunzip_module \
>--with-http_gzip_static_module \
>--with-http_random_index_module \
>--with-http_realip_module \
>--with-http_secure_link_module \
>--with-http_spdy_module \
>--with-http_ssl_module \
>--with-http_stub_status_module \
>--with-http_sub_module \
>--with-ipv6 \
>--with-mail \
>--with-mail_ssl_module  \
>--with-openssl=../openssl \
>--with-pcre=../pcre \
>--with-zlib=../zlib \
>--add-module=../nginx-dav-ext-module \
>--add-module=../nginx-upstream-fair \
>--add-module=../ngx_http_google_filter_module \
>--add-module=../ngx_http_substitutions_filter_module
```

####Usage

通过该Dockerfile创建的image有4个卷挂载点：  
`VOLUME ["/var/www", "/etc/nginx/conf.d", "/var/log/nginx", "/var/cache/nginx"]`  
查看image中`/etc/nginx/nginx.conf`内容请点[这里](https://github.com/time-river/time-river/blob/master/nginx/config/docker/nginx.conf)  
[这里](https://github.com/time-river/time-river/blob/master/nginx/config/docker/conf.d/nginx.conf)是示范设置
