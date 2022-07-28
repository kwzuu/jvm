#!/bin/bash
fname="./jvm"

echo "MEOW MEOW MEOW MEOW..."

g++ -Wall -Wextra -Wpedantic -Wshadow -Werror -std=c++20 -o "$fname" $(find . -name "*.cpp")

if [[ "$1" = "run" ]]; then
  shift 1
  $fname "$@"
fi
