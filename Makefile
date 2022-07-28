FILENAME := "./jvm"
CXXFLAGS := "-Wall -Wextra -Wpedantic -Wshadow -Werror -std=c++23"

build:
	echo "MEOW MEOW MEOW MEOW..."
	FILES != find . -name "*.cpp"
	g++ ${CXXFLAGS} -o ${FILENAME} ${FILES}

run: build
	${FILENAME}
