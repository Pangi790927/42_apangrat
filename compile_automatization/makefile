ifneq ($(RETURN),)
	FLAG_PRINT_RETURN := $(RETURN)
else
	FLAG_PRINT_RETURN :=
endif

ifneq ($(PRINT),)
	FLAG_CAN_PRINT := $(PRINT)
else
	FLAG_CAN_PRINT := 
endif

ifneq ($(NAME),)
	FLAG_NAME := -DFUNCTION_NAME=$(NAME)
else
	FLAG_NAME :=
endif

ifneq ($(ARG),)
	FLAG_ARG := -DFUNCTION_ARG=$(ARG)
else
	FLAG_ARG := 
endif

ifneq ($(VAL),)
	FLAG_VAL := -DFUNCTION_VALUE=$(VAL)
else
	FLAG_VAL := 
endif

ifneq ($(VAR),)
	FLAG_MAIN_VAR := -DMAIN_VAR=$(VAR)
else
	FLAG_MAIN_VAR :=
endif

ifneq ($(RETURN_TYPE),)
	FLAG_RETURN_TYPE := -DRETURN_TYPE=$(RETURN_TYPE)
else
	FLAG_RETURN_TYPE := 
endif

CFLAGS = -Wall -Wextra -Werror

FLAGS = $(FLAG_NAME) $(FLAG_VAL) $(FLAG_ARG) $(FLAG_MAIN_VAR) $(FLAG_CAN_PRINT) $(FLAG_PRINT_RETURN) $(FLAG_RETURN_TYPE)

all: program
	./program

program: main.c ft_putchar.o $(NAME).o
	gcc main.c $(FLAGS) ft_putchar.o $(NAME).o -o program

ft_putchar.o: ft_putchar.c 
	gcc $(CFLAGS) -c ft_putchar.c -o ft_putchar.o

$(NAME).o: $(NAME).c
	gcc $(CFLAGS) -c $(NAME).c -o $(NAME).o

configs:
	@echo NAME: $(NAME) "\t\t\t" 		EXAMPLE: ft_name
	@echo PRINT: $(PRINT) "\t\t\t" 		ACTIVATE: -DMAIN_CAN_PRINT DEACTIVATE:
	@echo RETURN: $(RETURN) "\t\t\t" 	ACTIVATE: -DPRINT_RETURN DEACTIVATE: 
	@echo ARG: $(ARG) "\t\t\t" 			EXAMPLE: int a
	@echo VAL: $(VAL) "\t\t\t" 			EXAMPLE: x
	@echo VAR: $(VAR) "\t\t\t" 			EXAMPLE: int x = 42; 
	@echo RETURN_TYPE: $(RETURN_TYPE) "\t\t\t" EXAMPLE: int; 

clean: 
	rm -f *.o
	rm -f program