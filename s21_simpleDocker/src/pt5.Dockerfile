FROM nginx

RUN useradd -ms /bin/bash lunchlma

WORKDIR /home/

COPY ./nginx/nginx.conf /etc/nginx/nginx.conf
COPY ./server/server.c .
COPY ./run.sh .

RUN apt-get update && apt-get install -y gcc libfcgi-dev spawn-fcgi && \
  chown -R lunchlma:lunchlma /home && chmod -R 755 /home && \
  chown -R lunchlma:lunchlma /var/cache/nginx && \
  chown -R lunchlma:lunchlma /var/log/nginx && \
  chown -R lunchlma:lunchlma /etc/nginx/conf.d && \
  chown -R lunchlma:lunchlma /var/lib/dpkg && \
  touch /var/run/nginx.pid && \
  chown -R lunchlma:lunchlma /var/run/nginx.pid && \
  rm -rf /var/lib/apt/lists

USER lunchlma

ENTRYPOINT [ "bash", "./run.sh" ]
