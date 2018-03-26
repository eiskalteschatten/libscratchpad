default:
	g++ -o build/libscratchpad.o src/*.cpp -L/usr/local/lib -lboost_filesystem


install-libs:
	brew install boost