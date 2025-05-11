#!/bin/bash

# Ждём, пока manager01 создаст токен
while [ ! -f /vagrant/swarm-token ]; do
    echo "Ожидание swarm-token..."
    sleep 5
done

# Получаем токен из файла
SWARM_TOKEN=$(cat /vagrant/swarm-token)

# Подключаемся к Swarm (если ещё не подключены)
if [ ! "$(docker info | grep Swarm | sed 's/Swarm: //g')" = "active" ]; then
    docker swarm join --token $SWARM_TOKEN 192.168.56.10:2377
fi
