from ubuntu:jammy-20220815

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y gcc socat musl-dev
WORKDIR /pwn_4_med

RUN useradd pwn4
USER pwn4
COPY ./task.c /pwn_4_med/task.c

USER root
#RUN gcc -fno-stack-protector -mpreferred-stack-boundary=4 -z execstack -o /pwn/task /pwn/task.c
#RUN gcc -z execstack -o /pwn_4_med/task /pwn_4_med/task.c
RUN gcc -z execstack -o /pwn_4_med/task /pwn_4_med/task.c
RUN rm /pwn_4_med/task.c
RUN chmod 001 /pwn_4_med/task

RUN chmod go-rx /usr/bin/passwd

USER pwn4

ENV f1=k
ENV f2=u
ENV f3=b
ENV f4=a
ENV f5=n
ENV f6=c
ENV f7=t
ENV f8=f
ENV f9={
ENV f10=y
ENV f11=3
ENV f12=s
ENV f13=_
ENV f14=v
ENV f15=3
ENV f16=3
ENV f17=3
ENV f18=r
ENV f19=y
ENV f20=_
ENV f21=r
ENV f22=@
ENV f23=n
ENV f24=d
ENV f25=0
ENV f26=M
ENV f27=_
ENV f28=T
ENV f29=h
ENV f30=1
ENV f31=N
ENV f32=g
ENV f33=}

#ENTRYPOINT ["socat"]
CMD ["socat", "-d", "-d", "TCP4-LISTEN:31341,fork,reuseaddr", "EXEC:'timeout 180 /pwn_4_med/task',pty,echo=0,raw,iexten=0"]
EXPOSE 31341
