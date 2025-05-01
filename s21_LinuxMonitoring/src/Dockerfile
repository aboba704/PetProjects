FROM ubuntu:20.04

RUN apt-get update && \
    apt-get install -y bash goaccess nginx && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /DO4

COPY . /DO4
COPY entrypoint.sh /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]

EXPOSE 7890

RUN chmod +x */*.sh && \
    chmod +x /entrypoint.sh
