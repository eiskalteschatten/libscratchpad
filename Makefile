.PHONY: test

default:
	g++ -lboost_filesystem \
		./src/*.cpp \
		-o ./build/libscratchpad

test:
	g++ -lboost_unit_test_framework \
		-lboost_filesystem \
		./src/*.cpp \
		./test/*.cpp \
		-o ./build/test
	chmod u+x ./build/test
	./build/test

install-libs-mac:
	brew install boost
