FROM nginx

WORKDIR /home/

COPY ./nginx/nginx.conf /etc/nginx/nginx.conf
COPY ./server/server.c .
COPY ./run.sh .

RUN apt-get update && apt-get install -y gcc libfcgi-dev spawn-fcgi

ENTRYPOINT [ "bash", "./run.sh" ]
