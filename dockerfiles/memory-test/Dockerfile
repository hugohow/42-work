FROM ubuntu:latest

RUN apt-get update
RUN apt-get install -y \
    valgrind gcc make libc-dev ca-certificates emacs strace sudo
RUN apt-get install -y ltrace
ENV TERM=xterm-256color
RUN apt-get install -y nasm
RUN apt-get install -y gcc-multilib
RUN apt-get install -y curl
RUN apt-get install -y bsdmainutils
RUN apt-get install -y iproute2
RUN apt-get install -y iptables
RUN mkdir -p /42
WORKDIR /42