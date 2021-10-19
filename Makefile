# -----------------------------------------------------------------------------
#                            TO-DO LIST
# -----------------------------------------------------------------------------
#  * bonus rule, adding it into all ?
#  * sani rule
#  * test rule
#  * debug rule & debug-full rule
#  *
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

# -----------------------------------------------------------------------------
#                                  FILES
# -----------------------------------------------------------------------------
SRCS_CLT=$(addprefix srcs/, $(addsuffix .c, \
	 client\
	 utils\
	 ))
OBJ_CLT=$(SRCS_CLT:.c=.o)
SRCS_SRV= $(addprefix srcs/, $(addsuffix .c, \
	 server\
	 utils\
	 ))
OBJ_SRV=$(SRCS_SRV:.c=.o)

SRCS_BONUS_CLT=$(addprefix srcs/, $(addsuffix _bonus.c, \
	 client\
	 utils\
	 ))
OBJ_BONUS_CLT=$(SRCS_BONUS_CLT:.c=.o)
SRCS_BONUS_SRV= $(addprefix srcs/, $(addsuffix _bonus.c, \
	 server\
	 utils\
	 ))
OBJ_BONUS_SRV=$(SRCS_BONUS_SRV:.c=.o)

NAME=minitalk
CLIENT=client
SERVER=server

# -----------------------------------------------------------------------------
#                            RULES
# -----------------------------------------------------------------------------
.PHONY: all clean fclean re $(NAME) bonus clean_bonus 

all: $(NAME)

$(NAME): server client

bonus: server_bonus client_bonus

client: $(OBJ_CLT)
	@$(ECHO) "$(GRE)"
	$(CC) $(LDFLAGS) $^ -o $@
	@$(ECHO) "$(NO_COL)"

server: $(OBJ_SRV)
	@$(ECHO) "$(GRE)"
	$(CC) $(LDFLAGS) $^ -o $@
	@$(ECHO) "$(NO_COL)"

client_bonus: $(OBJ_BONUS_CLT)
	@$(ECHO) "$(GRE)"
	$(CC) $(LDFLAGS) $^ -o $(CLIENT)
	@$(ECHO) "$(NO_COL)"

server_bonus: $(OBJ_BONUS_SRV)
	@$(ECHO) "$(GRE)"
	$(CC) $(LDFLAGS) $^ -o $(SERVER)
	@$(ECHO) "$(NO_COL)"

%.o: %.c
	@$(ECHO) "$(GRE)"
	$(CC) $(ALL_FLAGS) -c $< -o $@
	@$(ECHO) "$(NO_COL)"

clean:
	@$(ECHO) "$(RED)"
	$(RM) $(OBJ_CLT) $(OBJ_SRV)
	@$(ECHO) "$(NO_COL)"

clean_bonus:
	@$(ECHO) "$(RED)"
	$(RM) $(OBJ_BONUS_CLT) $(OBJ_BONUS_SRV)
	@$(ECHO) "$(NO_COL)"

fclean: clean clean_bonus
	@$(ECHO) "$(RED)"
	$(RM) $(SERVER) $(CLIENT)
	@$(ECHO) "$(NO_COL)"

re: fclean all
