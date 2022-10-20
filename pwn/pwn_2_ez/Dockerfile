from ubuntu:jammy-20220815

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y gcc socat musl-dev
WORKDIR /pwn_2_ez

RUN useradd hacker2
USER hacker2
COPY ./task.c /pwn_2_ez/task.c
COPY ./flag.txt /pwn_2_ez/flag.txt

USER root
RUN gcc -fno-stack-protector -mpreferred-stack-boundary=4 -z execstack -o /pwn_2_ez/task /pwn_2_ez/task.c
RUN rm /pwn_2_ez/task.c
RUN chmod 001 /pwn_2_ez/task
RUN chmod 004 /pwn_2_ez/flag.txt

RUN chmod go-rx /usr/bin/passwd

USER hacker2

ENTRYPOINT ["socat"]
CMD ["-d", "-d", "TCP4-LISTEN:31339,fork,reuseaddr", "EXEC:'/pwn_2_ez/task',pty,echo=0,raw,iexten=0"]
EXPOSE 31339
