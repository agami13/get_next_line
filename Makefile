SRC = get_next_line.c get_next_line_utils.c get_next_line_utils_bonus.c get_next_line_bonus.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42

all : bin

bin : $(OBJ)
	$(CC) -o $@ $^

%.o : %.c
		$(CC) $(CFLAGS) -c -o $@ $^

clean :
		rm -f $(OBJ) bin

re : clean all

.PHONY : all clean re