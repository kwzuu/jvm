FILENAME := "./jvm"
CXXFLAGS := "-Wall -Wextra -Wpedantic -Wshadow -Werror -std=c++23"

build:
	echo "MEOW MEOW MEOW MEOW..."
	g++ ${CXXFLAGS} -o ${FILENAME} $(shell find . -name "*.cpp")

run: build
	${FILENAME}
