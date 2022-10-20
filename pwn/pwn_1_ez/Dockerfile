from ubuntu:jammy-20220815

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y gcc net-tools socat musl-dev gdb python3
WORKDIR /pwn_1_ez

RUN useradd pwn1
USER pwn1
COPY ./buffer.c /pwn_1_ez/buffer.c

USER root
#RUN gcc -fno-stack-protector -mpreferred-stack-boundary=4 -z execstack -o /pwn/buffer /pwn/buffer.c
RUN gcc -o /pwn_1_ez/buffer /pwn_1_ez/buffer.c
RUN rm /pwn_1_ez/buffer.c
RUN chmod 001 /pwn_1_ez/buffer

RUN chmod go-rx /usr/bin/passwd

USER pwn1

ENV flag=kubanctf{sup3r_pwn_@ctua11y_e@sy}

#ENTRYPOINT ["socat"]
CMD ["socat", "-d", "-d", "TCP4-LISTEN:31338,fork,reuseaddr", "EXEC:'timeout 180 /pwn_1_ez/buffer',pty,echo=0,raw,iexten=0"]
EXPOSE 31338
