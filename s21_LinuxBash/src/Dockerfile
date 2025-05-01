FROM ubuntu:20.04

RUN apt-get update && \
    apt-get install -y systemd lsb-release iproute2 bc && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /DO3

COPY . /DO3

RUN chmod +x */*.sh