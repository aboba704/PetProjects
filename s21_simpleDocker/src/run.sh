#!/bin/bash

gcc server.c -o server.fcgi -lfcgi
spawn-fcgi -p 8080 server.fcgi
nginx -g "daemon off;"