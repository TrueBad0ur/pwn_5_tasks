from ubuntu:jammy-20220815

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y gcc socat musl-dev
RUN pip3 install pwntools
WORKDIR /pwn_3_med

RUN useradd hacker3
USER hacker3
COPY ./task.c /pwn_3_med/task.c
COPY ./flag.txt /pwn_3_med/flag.txt

USER root
RUN gcc /pwn_3_med/task.c -fno-stack-protector -no-pie -mpreferred-stack-boundary=4 -o /pwn_3_med/task

RUN rm /pwn_3_med/task.c
COPY ./libc.so.6 /lib/x86_64-linux-gnu/libc.so.6
RUN chmod 644 /lib/x86_64-linux-gnu/libc.so.6
RUN chmod 001 /pwn_3_med/task
RUN chmod 004 /pwn_3_med/flag.txt

RUN chmod go-rx /usr/bin/passwd

USER hacker3

ENTRYPOINT ["socat"]
CMD ["-d", "-d", "TCP4-LISTEN:31340,fork,reuseaddr", "EXEC:'/pwn_3_med/task',pty,echo=0,raw,iexten=0"]
EXPOSE 31340
