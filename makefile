# the compiler: defined as g++ for C++
CC=g++
CFLAGS=-D_GLIBCXX_USE_CXX11_ABI=1 -I.
# Target is xmlHtml executable binary which is dependent on HTMLTable class and tinyxml2 (XML parser)
xmlHtml: main.o	HTMLTable.o tinyxml2.o
	$(CC) -o xmlHtml main.o	HTMLTable.o tinyxml2.o
# Remove the executable binary, object files and output file
clean:
	rm main.o	HTMLTable.o tinyxml2.o	xmlHtml cd_catalog.html