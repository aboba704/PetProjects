#!/bin/bash

# Обновляем пакеты и устанавливаем зависимости
sudo apt-get update
sudo apt-get install -y apt-transport-https ca-certificates curl software-properties-common

# Добавляем ключ Docker
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -

# Добавляем репозиторий Docker
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu focal stable"

# Устанавливаем Docker
sudo apt-get install -y docker-ce docker-ce-cli containerd.io

# Добавляем текущего пользователя в группу docker (чтобы не использовать sudo)
sudo usermod -aG docker vagrant

# Включаем и запускаем Docker
sudo systemctl enable docker
sudo systemctl start docker
