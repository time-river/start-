#Nginx
======

##Introduction

下面介绍的属于[nginx](https://github.com/time-river/time-river/tree/master/nginx/config/nginx)文件夹下的内容。  
高级使用请点[这里](https://github.com/time-river/time-river/tree/master/nginx/config/docker)  

```
参考书籍: 《精通Nginx》
          ISBN: 978-7-115-38141-5
```

####编译选项
```
> ./configure \
> --prefix=/etc/nginx \
> --sbin-path=/usr/sbin/nginx \
> --conf-path=/etc/nginx/nginx.conf \
> --error-log-path=/home/nginx/log/error.log \
> --http-log-path=/home/nginx/log/access.log \
> --pid-path=/var/run/nginx.pid \
> --lock-path=/var/run/nginx.lock \
> --http-client-body-temp-path=/var/cache/nginx/client_temp \
> --http-proxy-temp-path=/var/cache/nginx/proxy_temp \
> --http-fastcgi-temp-path=/var/cache/nginx/fastcgi_temp \
> --http-scgi-temp-path=/var/cache/nginx/scgi_temp \
> --http-uwsgi-temp-path=/var/cache/nginx/uwsgi_temp \
> --user=nginx \
> --group=nginx \
> --with-cc-opt='-g -O2 -fstack-protector-strong -Wformat -Werror=format-security -Wp,-D_FORTIFY_SOURCE=2' \
> --with-ld-opt='-Wl,-z,relro -Wl,--as-needed' \
> --with-file-aio \
> --with-http_addition_module \
> --with-http_auth_request_module \
> --with-http_dav_module \
> --with-http_flv_module \
> --with-http_mp4_module \
> --with-http_gunzip_module \
> --with-http_gzip_static_module \
> --with-http_random_index_module \
> --with-http_realip_module \
> --with-http_secure_link_module \
> --with-http_spdy_module \
> --with-http_ssl_module \
> --with-http_stub_status_module \
> --with-http_sub_module \
> --with-ipv6 \
> --with-mail \
> --with-mail_ssl_module  \
> --with-openssl=../openssl-1.0.2d \
> --with-pcre=../pcre-8.37 \
> --with-zlib=../zlib-1.2.8 \
> --add-module=../nginx-dav-ext-module \
> --add-module=../nginx-upstream-fair \
> --add-module=../ngx_http_google_filter_module \
> --add-module=../ngx_http_substitutions_filter_module

注:
包含debian 32位安装nginx后所有的编译选项(#nginx -V查看)。
改变了一些设置:
--error-log-path
--http-log-path
额外添加了一些module:
ngx_http_google_filter_module
ngx_http_substitutions_filter_module
用于开启google镜像以及多次替换.
ngxnginx-upstream-fair
增强了Nginx提供的round-robin 负载均衡算法
nginx-dav-ext-module
依赖关系
          相关模块下载可在github上搜索到
编译过程遇到任何问题请Google
在docker中编译时候, --with-ld-opt='-Wl,-z,relro -Wl,--as-needed' 报错, 无法解决, 安装nginx后再次编译成功
```

####配置
```
ssl身份验证、强制ssl加密连接(通过80端口重定向)
多个server_name匹配
反向代理、反向代理性能调优:缓冲、缓存、压缩
```

####参考网址
>[How to force or redirect to SSL in nginx?](http://serverfault.com/questions/250476/how-to-force-or-redirect-to-ssl-in-nginx)  
>[Converting rewrite rules](http://nginx.org/en/docs/http/converting_rewrite_rules.html)  
>[NGINX 配置 SSL 证书 + 搭建 HTTPS 网站教程](https://s.how/nginx-ssl/)  
>[Certificate Installation: NGINX](https://support.comodo.com/index.php?/Default/Knowledgebase/Article/View/789/37/)

####一些遇到的错误
>[Unknown error nginx](http://stackoverflow.com/questions/17241554/unknown-error-nginx)  
>["proxy_set_header" directive is not allowed here](http://serverfault.com/questions/506972/nginx-why-i-cant-put-proxy-set-header-inside-an-if-clause)  
>["sub_filter" directive is duplicate in ...](http://serverfault.com/questions/281741/multiple-sub-filter-rules-for-a-reverse-proxy-on-nginx)  
----注:两种方案:  
--------`Nginx 1.9.4 *) Feature: multiple "sub_filter" directives can be used simultaneously.`<br> --------[ngx_http_substitutions_filter_module](https://github.com/yaoweibin/ngx_http_substitutions_filter_module)

####遇到的问题
>重定向至反向代理的站点: `proxy_redirect`设置问题  
>error404: `proyx_pass`后加一`/`  
>移动设备之重定向(wikipedia访问问题):[区分PC手机访问不同页面地址](http://www.brafox.com/post/2015/server/%E5%8C%BA%E5%88%86PC%E6%89%8B%E6%9C%BA%E8%AE%BF%E9%97%AE%E4%B8%8D%E5%90%8C%E9%A1%B5%E9%9D%A2%E5%9C%B0%E5%9D%80.html)  
>Nginx之set

####拓展阅读
>DNS域名解析
>>[域名解析中A记录、CNAME、MX记录、NS记录的区别和联系](http://blog.csdn.net/crazw/article/details/8986581)  
>>[ DNS解析过程详解](http://blog.csdn.net/meimingming/article/details/9038223)  
>>[What are the types of DNS records?](http://help.slamdot.com/idx/0/057/What-are-the-types-of-DNS-records)  
>>应用:二级域名的使用

>ssl证书
>>[HTTPS 证书简介](https://leonax.net/p/7522/https-certificate-introduction/)  
>>[Linux的加密认证功能以及openssl详解](http://lanlian.blog.51cto.com/6790106/1281720)  
>>[加密、解密及OpenSSL 详解](http://freeloda.blog.51cto.com/2033581/1216176)  
>>[中间人攻击](https://zh.wikipedia.org/zh/%E4%B8%AD%E9%97%B4%E4%BA%BA%E6%94%BB%E5%87%BB)

>正向代理、反向代理、透明代理
>>[代理服务器](https://zh.wikipedia.org/wiki/%E4%BB%A3%E7%90%86%E6%9C%8D%E5%8A%A1%E5%99%A8)  
>>[正向代理、反向代理、透明代理](http://github.thinkingbar.com/reverseProxy/)  
>>[Squid中文权威指南](http://home.arcor.de/pangj/squid/)(注:squid--正向代理中的战斗机)  
>>[反向代理](https://zh.wikipedia.org/wiki/%E5%8F%8D%E5%90%91%E4%BB%A3%E7%90%86)

>正则表达式
>>[正则表达式](https://zh.wikipedia.org/wiki/%E6%AD%A3%E5%88%99%E8%A1%A8%E8%BE%BE%E5%BC%8F)

>Http Header
>>[List of HTTP header fields](https://en.wikipedia.org/wiki/List_of_HTTP_header_fields)  

>Robots
>>[robots.txt](https://zh.wikipedia.org/wiki/Robots.txt)  
>>[Nginx限制搜索引擎爬虫频率、禁止屏蔽网络爬虫配置示例](http://www.jb51.net/article/52569.htm)

>用来黑人的
>>[openresty+lua在反向代理服务中的玩法](http://drops.wooyun.org/tips/6403)

#####该内容遵循[署名(BY)-非商业性(NC)-相同方式共享(SA)协议](https://creativecommons.org/licenses/by-nc-sa/3.0/us/deed.zh)
