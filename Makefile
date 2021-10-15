# -----------------------------------------------------------------------------
#                            TO-DO LIST
# -----------------------------------------------------------------------------
#  * bonus rule, adding it into all ?
#  * sani rule
#  * test rule
#  * debug rule & debug-full rule
# -----------------------------------------------------------------------------
#                            COLORS
# -----------------------------------------------------------------------------
RED=\033[1;31m
GRE=\033[1;32m
YEL=\033[1;33m
BLU=\033[1;34m
MAG=\033[1;35m
CYA=\033[1;36m
NO_COL=\033[0m

# -----------------------------------------------------------------------------
#                            COMMANDS
# -----------------------------------------------------------------------------
CC=-gcc
ECHO=-echo
RM=-rm -rf
MAKE=make

CFLAGS=-Wall -Werror -Wextra
CHEADERS= -I ./includes
ALL_FLAGS= $(CHEADERS) $(CFLAGS)
LDFLAGS=

# -----------------------------------------------------------------------------
#                            FILES
# -----------------------------------------------------------------------------
SRCS_CLT=$(addprefix srcs/, $(addsuffix .c, \
	 client\
	 ))
OBJ_CLT=$(SRCS_CLT:.c=.o)
SRCS_SRV= $(addprefix srcs/, $(addsuffix .c, \
	 server\
	 ))
OBJ_SRV=$(SRCS_SRV:.c=.o)
NAME=minitalk
CLIENT=client
SERVER=server

# -----------------------------------------------------------------------------
#                            RULES
# -----------------------------------------------------------------------------
.PHONY: all clean fclean re server client test debug debug-full sani 

all: $(NAME)

$(NAME): server client

bonus: $(NAME)

client: $(OBJ_CLT)
	@$(ECHO) "$(GRE)"
	$(CC) $(LDFLAGS) $^ -o $@
	@$(ECHO) "$(NO_COL)"

server: $(OBJ_SRV)
	@$(ECHO) "$(GRE)"
	$(CC) $(LDFLAGS) $^ -o $@
	@$(ECHO) "$(NO_COL)"

test: $(NAME)
	./$(CLIENT)
	./$(SERVER)
	@$(MAKE) fclean
	
sani: $(OBJ)
	@$(ECHO) "$(GRE)"
	$(CC) -g -fsanitize=address -fno-omit-frame-pointer -static-libsan $(LDFLAGS) $^ -o $(NAME) 
	@$(ECHO) "$(NO_COL)"
	./$(NAME)
	@$(MAKE) fclean-debug

debug: $(OBJ)
	@$(ECHO) "$(BLU)"
	$(CC) -g $(LDFLAGS) $^ -o $(NAME)
	@$(ECHO) "$(NO_COL)"
	valgrind ./$(NAME)
	@$(MAKE) fclean-debug

debug-full: $(OBJ)
	@$(ECHO) "$(BLU)"
	$(CC) -g $(LDFLAGS) $^ -o $(NAME)
	@$(ECHO) "$(NO_COL)"
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)
	@$(MAKE) fclean-debug

%.o: %.c
	@$(ECHO) "$(GRE)"
	$(CC) $(ALL_FLAGS) -c $< -o $@
	@$(ECHO) "$(NO_COL)"

clean:
	@$(ECHO) "$(RED)"
	$(RM) $(OBJ_CLT) $(OBJ_SRV)
	@$(ECHO) "$(NO_COL)"

fclean: clean
	@$(ECHO) "$(RED)"
	$(RM) $(SERVER) $(CLIENT)
	@$(ECHO) "$(NO_COL)"

fclean-debug: fclean
	@$(ECHO) "$(RED)"
	$(RM) $(NAME).dSYM
	@$(ECHO) "$(NO_COL)"

re: fclean all
