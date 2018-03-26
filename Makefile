default:
	g++ -o ./build/libscratchpad.o src/*.cpp -lboost_filesystem

install-libs:
	brew install boost

unit-test:
	g++ -o ./build/test.o ./test/*.cpp -lboost_unit_test_framework
