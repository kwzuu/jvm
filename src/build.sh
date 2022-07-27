#!/bin/bash
fname="./jvm"

g++ -Wall -Wextra -Wpedantic -Wshadow -Werror -std=c++23 -o "$fname" $(find . -name "*.cpp")

if [[ "$1" = "run" ]]; then
  shift 1
  $fname "$@"
fi
