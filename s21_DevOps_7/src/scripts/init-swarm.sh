#!/bin/bash

# Инициализируем Swarm (если ещё не инициализирован)
if [ ! "$(docker info | grep Swarm | sed 's/Swarm: //g')" = "active" ]; then
    docker swarm init --advertise-addr 192.168.56.10
fi

# Сохраняем токен для воркеров в файл (чтобы worker01 и worker02 могли подключиться)
docker swarm join-token worker -q >/vagrant/swarm-token

# Деплой
# sudo docker stack deploy -c /vagrant/docker-compose.yml do7
