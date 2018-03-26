.PHONY: test

default:
	g++ -lboost_filesystem \
		./src/*.cpp \
		-o ./build/libscratchpad.o

install-libs-mac:
	brew install boost

test:
	g++ -lboost_unit_test_framework \
		-lboost_filesystem \
		./test/*.cpp \
		-o ./build/test
	chmod u+x ./build/test
	./build/test
