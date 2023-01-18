make:
	g++ main.cpp Link.cpp ObjectCurl.cpp -lcurl -o main
	./main