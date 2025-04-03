CC = gcc
CFLAGS = -Wall -std=c99 -w

bin/test: TestCode.o unity.o TestCodeRunner.o harness/unity.h harness/CodeUnderTest.h
	$(CC) $(CFLAGS) -o bin/test TestCode.o unity.o TestCodeRunner.o -lm

TestCode.o: harness/TestCode.c unity.o harness/unity.h
	$(CC) $(CFLAGS) -c harness/TestCode.c

unity.o: harness/unity.c harness/unity.h
	$(CC) $(CFLAGS) -c harness/unity.c

TestCodeRunner.o: harness/TestCodeRunner.c harness/unity.h
	$(CC) $(CFLAGS) -c harness/TestCodeRunner.c

clean:
	rm -f *.o bin/test

test: bin/test
	./bin/test
