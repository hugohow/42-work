#!/bin/sh
ifconfig -a | awk '/ether/{print $2}'
