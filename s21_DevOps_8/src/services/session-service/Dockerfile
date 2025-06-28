# Stage 1: Build
FROM maven:3.9-eclipse-temurin-8 AS builder

# RUN apk add --no-cache maven
# mvn -B dependency:go-offline
# mvn -N io.takari:maven:wrapper
# mvn -B package -DskipTests

WORKDIR /app

COPY .mvn/ ./.mvn/
COPY mvnw pom.xml ./

# Установка зависимостей
RUN mvn dependency:go-offline

# Копирование исходного кода проекта
COPY src/ ./src

# Запуск проекта
# RUN ./mvnw spring-boot:run
RUN mvn package -DskipTests

# Stage 2: Run
FROM openjdk:8-jdk-alpine

WORKDIR /app

RUN apk add --no-cache bash

# Копирование скопилированного jar и скрипта ожидания БД
COPY --from=builder /app/target/*jar /app/app.jar
COPY wait-for-it.sh ./
RUN chmod +x wait-for-it.sh

# EXPOSE 8081

# CMD ["./wait-for-it.sh", "postgres:5432", "--timeout=30", "--", \
#     "java", "-jar", "app.jar"]
CMD ["./wait-for-it.sh", "-s", "-t", "60", "postgres:5432", \
    "-s", "-t", "60", "rabbitmq:5672", "--", "java", "-jar", "app.jar"]
