CC            := cc
CFLAGS        := -Wall -Wextra -Werror
NAME          := printf_tester
TESTSRC       := Casetester.c
PERTESTSRC    := percenttest.c
SRC           := main.c
PRINTFDIR     := ..
PRINTFLIB     := $(PRINTFDIR)/libftprintf.a
OBJ           := ${SRC:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

eval: $(NAME) $(PRINTFLIB)
	$(CC) $(CFLAGS) $(TESTSRC) $(PRINTFLIB) -o a.out
	$(CC) -w $(PERTESTSRC) $(PRINTFLIB) -o percent
	bash printf.bash 2> /dev/null
	./$(NAME) eval

show: $(NAME) $(PRINTFLIB)
	$(CC) $(CFLAGS) $(TESTSRC) $(PRINTFLIB) -o a.out
	$(CC) -w $(PERTESTSRC) $(PRINTFLIB) -o percent
	bash printf.bash 2> /dev/null
	./$(NAME) show

test: $(NAME) $(PRINTFLIB)
	$(CC) $(CFLAGS) $(TESTSRC) $(PRINTFLIB) -o a.out
	$(CC) -w $(PERTESTSRC) $(PRINTFLIB) -o percent
	bash printf.bash 2> /dev/null
	./$(NAME) test

$(NAME): $(OBJ) $(PRINTFLIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(PRINTFLIB):
	$(MAKE) -C $(PRINTFDIR) fclean
	$(MAKE) -C $(PRINTFDIR) all


clean:
	$(MAKE) -C $(PRINTFDIR) clean
	rm -f $(OBJ) 
	rm -f a.out
	rm -f percent
	rm -f main
	rm -rf Text

fclean: clean
	$(MAKE) -C $(PRINTFDIR) fclean
	rm -f $(NAME)

re: fclean all
