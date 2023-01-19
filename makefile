make:
	g++ main.cpp Link.cpp ObjectCurl.cpp Data.cpp -lcurl -o main
	./main