SRC_DIR         = src/
OBJ_DIR         = objs/
INC_DIR         = header/

PARS_DIR        = $(SRC_DIR)pars/
PARS_OBJDIR     = $(OBJ_DIR)pars/

LIB             = $(SRC_DIR)/libft/libft.a

PARS_FILES      =	get_texture.c	\
					parsing_servo.c	\
					pars_utils.c	\
					error_messages.c\

SRC_FILES       =	main.c			\

SOURCES         = $(addprefix $(SRC_DIR), $(SRC_FILES)) \
                  $(addprefix $(PARS_DIR), $(PARS_FILES)) \

OBJS            = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o)) \
                  $(addprefix $(PARS_OBJDIR), $(PARS_FILES:.c=.o)) \

HEADER          = $(INC_DIR)cub3D.h
NAME            = cub3D

CC              = cc
FLAGS           = -Wall -Wextra -Werror -I$(INC_DIR)

all: $(OBJ_DIR) $(PARS_OBJDIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(PARS_OBJDIR):
	mkdir -p $(PARS_OBJDIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(PARS_OBJDIR)%.o: $(PARS_DIR)%.c $(HEADER)
	mkdir -p $(PARS_OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIB) $(HEADER) Makefile
	$(CC) $(FLAGS) -o $@ $(OBJS) $(LIB)

$(LIB): FORCE
	make -C $(SRC_DIR)libft

FORCE:

clean:
	make clean -C $(SRC_DIR)libft/
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(SRC_DIR)libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re FORCE

