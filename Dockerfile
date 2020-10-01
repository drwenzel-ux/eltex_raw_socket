FROM alpine:latest

RUN apk update && apk add bash alpine-sdk net-tools vim gdb

RUN mkdir -p /root/server

WORKDIR /root/server

COPY ./server .
