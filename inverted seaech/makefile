CC = gcc
CFLAGS = -Wall -Wextra -g

OBJ = main.o \
      file_list.o \
      hash.o \
      create_database.o \
      word_list.o \
      link_table.o \
      update_word_count.o \
      display_database.o \
      search.o \
      update_database.o \
      save_database.o

TARGET = invsearch

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c inverted_Search.h
	$(CC) $(CFLAGS) -c main.c

file_list.o: file_list.c inverted_Search.h
	$(CC) $(CFLAGS) -c file_list.c

hash.o: hash.c inverted_Search.h
	$(CC) $(CFLAGS) -c hash.c

create_database.o: create_database.c inverted_Search.h
	$(CC) $(CFLAGS) -c create_database.c

word_list.o: word_list.c inverted_Search.h
	$(CC) $(CFLAGS) -c word_list.c

link_table.o: link_table.c inverted_Search.h
	$(CC) $(CFLAGS) -c link_table.c

update_word_count.o: update_word_count.c inverted_Search.h
	$(CC) $(CFLAGS) -c update_word_count.c

display_database.o: display_database.c inverted_Search.h
	$(CC) $(CFLAGS) -c display_database.c

search.o: search.c inverted_Search.h
	$(CC) $(CFLAGS) -c search.c

update_database.o: update_database.c inverted_Search.h
	$(CC) $(CFLAGS) -c update_database.c

save_database.o: save_database.c inverted_Search.h
	$(CC) $(CFLAGS) -c save_database.c

clean:
	rm -f $(OBJ) $(TARGET)