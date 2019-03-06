FROM ubuntu:latest

RUN apt-get update
RUN apt-get install -y \
    valgrind gcc make libc-dev ca-certificates emacs strace sudo
ENV TERM=xterm-256color
RUN apt-get update \
  && apt-get install -y python3-pip python3-dev \
  && cd /usr/local/bin \
  && ln -s /usr/bin/python3 python \
  && pip3 install --upgrade pip
RUN mkdir -p /42
WORKDIR /42