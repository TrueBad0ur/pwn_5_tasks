from ubuntu:jammy-20220815

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y gcc socat musl-dev
WORKDIR /pwn_5_med

RUN useradd pwn5
USER pwn5
COPY ./task.c /pwn_5_med/task.c
COPY ./flag.txt /pwn_5_med/flag.txt
#COPY ./task /pwn_5_med/task

USER root
RUN gcc -no-pie -o /pwn_5_med/task /pwn_5_med/task.c
RUN rm /pwn_5_med/task.c
RUN chmod 001 /pwn_5_med/task

RUN chmod go-rx /usr/bin/passwd

USER pwn5

#ENTRYPOINT ["socat"]
CMD ["socat", "-d", "-d", "TCP4-LISTEN:31342,fork,reuseaddr", "EXEC:'timeout 180 /pwn_5_med/task',pty,echo=0,raw,iexten=0"]
EXPOSE 31342
