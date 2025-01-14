CC = gcc
CFLAGS = -Wall -g
OBJ = pilha.o deque.o hash.o codificacao.o main.o
TARGET = sistema_codificacao

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)
