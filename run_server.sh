#!/bin/bash

docker build . -t node:v0.1
docker run -it node:v0.1 /bin/bash