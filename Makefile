.PHONY: test

default:
	g++ -o ./build/libscratchpad.o ./src/*.cpp \
		-lboost_filesystem

install-libs-mac:
	brew install boost

test:
	g++ -o ./build/test ./test/*.cpp \
		-lboost_unit_test_framework \
		-lboost_filesystem
	chmod u+x ./build/test
	./build/test
