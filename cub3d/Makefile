SRC_DIR         = src/
OBJ_DIR         = objs/
INC_DIR         = header/

PARS_DIR        = $(SRC_DIR)pars/
PARS_OBJDIR     = $(OBJ_DIR)pars/

MOV_DIR        = $(SRC_DIR)mov/
MOV_OBJDIR     = $(OBJ_DIR)mov/

RAY_DIR        = $(SRC_DIR)ray/
RAY_OBJDIR     = $(OBJ_DIR)ray/

RENDER_DIR        = $(SRC_DIR)render/
RENDER_OBJDIR     = $(OBJ_DIR)render/

EXIT_DIR        = $(SRC_DIR)exit/
EXIT_OBJDIR     = $(OBJ_DIR)exit/

MLX_INIT_DIR        = $(SRC_DIR)mlx_init/
MLX_INIT_OBJDIR     = $(OBJ_DIR)mlx_init/

LIB            = $(SRC_DIR)/libft/libft.a
MLXPATH        = ../minilibx-linux
MLX            =$(MLXPATH)/libmlx.a

PARS_FILES      =	get_texture.c		\
					get_color.c			\
					parsing_servo.c		\
					pars_utils.c		\
					error_messages.c	\
					pars_free.c			\
					validation.c		\
					get_map.c			\
					error.c				\
					print_utils.c		\
					is_something.c		\
					copy_utils.c		\
					map_parsing.c		\
					texture_dispatcher.c\

MOV_FILES		=	mov.c			\
					mov_utils.c		\
					player.c		\
					pov.c			\
					wasd.c			\

RAY_FILES		=	ray.c			\
					dda.c			\
					fast_trig.c		\
					wall_height.c	\

SRC_FILES       =	main.c			\

RENDER_FILES	=	rendering.c		\
					texturing_west.c	\
					texturing_north.c	\
					texturing_south.c	\
					texturing_east.c	\
					floor_ceiling.c		\

EXIT_FILES		=	free_mlx.c			\
					exit_game.c			\

MLX_INIT_FILES	=	mlx_init.c			\
					get_images.c		\

SOURCES         = $(addprefix $(SRC_DIR), $(SRC_FILES)) \
                  $(addprefix $(PARS_DIR), $(PARS_FILES)) \
                  $(addprefix $(MOV_DIR), $(MOV_FILES)) \
                  $(addprefix $(RAY_DIR), $(RAY_FILES)) \
                  $(addprefix $(RENDER_DIR), $(RENDER_FILES)) \
				  $(addprefix $(EXIT_DIR), $(EXIT_FILES)) \
				  $(addprefix $(MLX_INIT_DIR), $(MLX_INIT_FILES)) \

OBJS            = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o)) \
                  $(addprefix $(PARS_OBJDIR), $(PARS_FILES:.c=.o)) \
                  $(addprefix $(MOV_OBJDIR), $(MOV_FILES:.c=.o)) \
                  $(addprefix $(RAY_OBJDIR), $(RAY_FILES:.c=.o)) \
                  $(addprefix $(RENDER_OBJDIR), $(RENDER_FILES:.c=.o)) \
				  $(addprefix $(EXIT_OBJDIR), $(EXIT_FILES:.c=.o)) \
				  $(addprefix $(MLX_INIT_OBJDIR), $(MLX_INIT_FILES:.c=.o)) \

HEADER          = $(INC_DIR)cub3D.h
NAME            = cub3D

CC              = cc
FLAGS           = -Wall -Wextra -Werror -g3 -I$(INC_DIR)

all: $(OBJ_DIR) $(PARS_OBJDIR) $(MOV_OBJDIR) $(RAY_OBJDIR) $(RENDER_OBJDIR) $(EXIT_OBJDIR) $(MLX_INIT_OBJDIR) makelibft makemlx $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(PARS_OBJDIR):
	mkdir -p $(PARS_OBJDIR)

$(MOV_OBJDIR):
	mkdir -p $(MOV_OBJDIR)

$(RAY_OBJDIR):
	mkdir -p $(RAY_OBJDIR)

$(RENDER_OBJDIR):
	mkdir -p $(RENDER_OBJDIR)

$(EXIT_OBJDIR):
	mkdir -p $(EXIT_OBJDIR)

$(MLX_INIT_OBJDIR):
	mkdir -p $(MLX_INIT_OBJDIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(PARS_OBJDIR)%.o: $(PARS_DIR)%.c $(HEADER)
	mkdir -p $(PARS_OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

$(MOV_OBJDIR)%.o: $(MOV_DIR)%.c $(HEADER)
	mkdir -p $(MOV_OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

$(RAY_OBJDIR)%.o: $(RAY_DIR)%.c $(HEADER)
	mkdir -p $(RAY_OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

$(RENDER_OBJDIR)%.o: $(RENDER_DIR)%.c $(HEADER)
	mkdir -p $(RENDER_OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

$(EXIT_OBJDIR)%.o: $(EXIT_DIR)%.c $(HEADER)
	mkdir -p $(EXIT_OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

$(MLX_INIT_OBJDIR)%.o: $(MLX_INIT_DIR)%.c $(HEADER)
	mkdir -p $(MLX_INIT_OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIB) $(HEADER) Makefile
	$(CC) $(FLAGS) -o $@ $(OBJS) $(LIB) -L$(MLXPATH) -lmlx -lXext -lX11 -lm -lz

$(MLX) :
	make -C $(MLXPATH) all

$(LIB):
	make bonus -C $(SRC_DIR)libft

makelibft :
	make -C $(SRC_DIR)libft all

makemlx :
	make -C $(MLXPATH) all

clean:
	make -C $(SRC_DIR)libft/ clean
	make -C $(MLXPATH) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(SRC_DIR)libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re FORCE
