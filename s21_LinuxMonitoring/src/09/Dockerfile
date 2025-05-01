FROM ubuntu:20.04

RUN apt-get update && \
    apt-get install -y stress && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# COPY ./scripts /DO4/09
# COPY ../02 /DO4/02
# COPY ../common /DO4/common

# RUN chmod +x /DO4/09/*.sh && \
#     bash /DO4/