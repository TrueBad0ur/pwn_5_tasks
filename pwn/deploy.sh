#!/bin/bash

echo 0 > /proc/sys/kernel/randomize_va_space;
sleep 1;
docker compose up --build
echo 2 > /proc/sys/kernel/randomize_va_space;
