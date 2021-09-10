T_CFLAGS   = -g -O0
T_CPPFLAGS = -g -O0
T_LIBS     = -lcrypto

TARGET=  test
SOURCES= open_ssl_test.c
HEADERS= open_ssl_test.h
OBJECTS= open_ssl_test.o

all: $(TARGET)

%.o : %.c $(HEADERS) Makefile
	$(CXX) $(T_CFLAGS) -o $@ -c $<

%.o : %.cpp $(HEADERS) Makefile
	$(CXX) $(T_CPPFLAGS) -o $@ -c $<

$(TARGET): $(OBJECTS) $(HEADERS) Makefile
	$(CXX) $(T_CPPFLAGS) $(OBJECTS) -o $@ $(T_LIBS)

clean:
	rm -f $(OBJECTS) $(TARGET)

