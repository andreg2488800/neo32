#!/bin/bash

# this is root script which should be run to do everything
# build for ubuntu jammy (22.04 LTS)

distr=jammy
image=ubuntu:$distr
. debian.sh
