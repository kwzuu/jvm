FILENAME := "./jvm"
CXXFLAGS := "-Wall -Wextra -Wpedantic -Wshadow -Werror -std=c++23"

build:
	FILES != find . -name "*.cpp"
	g++ ${CXXFLAGS} -o ${FILENAME} ${FILES}
	echo "MEOW MEOW MEOW MEOW..."

run: build
	${FILENAME}
