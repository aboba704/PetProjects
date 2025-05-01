FROM ubuntu:20.04

RUN apt-get update && \
    apt-get install -y stress && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*
