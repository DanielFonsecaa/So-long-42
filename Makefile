MAKE	= make -C

#==============================================================================#
#                                RESOURCES URLS                                #
#==============================================================================#

LIBFT_URL 	= git@github.com:DanielFonsecaa/libft_gnl_printf.git
MLX_URL			= https://cdn.intra.42.fr/document/document/32396/minilibx-linux.tgz

#==============================================================================#
#                                     NAMES                                    #
#==============================================================================#

NAME 			= so_long

### Message Vars
_SUCCESS 		= [$(GRN)SUCCESS$(D)]
_INFO 			= [$(BLU)INFO$(D)]
_NORM 			= [$(MAG)Norminette$(D)]
_NORM_SUCCESS 	= $(GRN)=== OK:$(D)
_NORM_INFO 		= $(BLU)File no:$(D)
_NORM_ERR 		= $(RED)=== KO:$(D)
_SEP 			= =====================

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

SRC_PATH		= .
INC_PATH		= .
LIBS_PATH		= lib
BUILD_PATH		= .build


FILES	= main.c game.c movements/movements.c movements/check_mov.c check_map/check_map.c \
	player/check_player.c check_map/init_map.c check_map/create_map.c free.c player/init_player.c

SRC						= $(addprefix $(SRC_PATH)/, $(FILES))
OBJS					= $(SRC:$(SRC_PATH)/%.c=$(BUILD_PATH)/%.o)
HEADERS				= $(INC_PATH)/so_long.h

LIBFT_PATH		= $(LIBS_PATH)/libft
LIBFT_ARC			= $(LIBFT_PATH)/libft.a

MLX_PATH			= $(LIBS_PATH)/mlx
MLX_ARC				= $(MLX_PATH)/libmlx_Linux.a


#==============================================================================#
#                              COMPILER & FLAGS                                #
#==============================================================================#

CC						= cc

CFLAGS				= -Wall -Wextra -Werror -g

RFLAGS				= -lm -lX11 -lXext
INC						= -I $(INC_PATH)

RM		= rm -rf
AR		= ar rcs
MKDIR_P	= mkdir -p

#==============================================================================#
#                                  RULES                                       #
#==============================================================================#


all: deps $(BUILD_PATH) $(NAME)	## Compile

$(NAME): $(BUILD_PATH) $(LIBFT_ARC) $(MLX_ARC) $(OBJS)			## Compile
	@echo "$(YEL)Compiling $(MAG)$(NAME)$(YEL) mandatory version$(D)"
	$(CC) $(CFLAGS) $(OBJS) $(INC) $(LIBFT_ARC) $(MLX_ARC) $(RFLAGS) -o $(NAME)
	@echo "[$(_SUCCESS) compiling $(MAG)$(NAME)$(D) $(YEL)🖔$(D)]"

deps:		## Download/Update deps
	@if test -d "$(LIBFT_PATH)" && test -d "$(MLX_PATH)"; then \
		echo " $(RED)$(D) [$(GRN)Nothing to be done!$(D)]"; fi
	@if test ! -d "$(LIBFT_PATH)"; then make get_libft; \
		else echo "$(YEL)[libft]$(D) folder found 🖔"; fi
	@if test ! -d "$(MLX_PATH)"; then make get_mlx; \
		else echo "$(YEL)[mlx]$(D) folder found 🖔"; fi
	

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c $(HEADERS)
	@echo -n "$(MAG)█$(D)"
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH):
	$(MKDIR_P) $(BUILD_PATH)
	$(MKDIR_P) $(BUILD_PATH)/check_map
	$(MKDIR_P) $(BUILD_PATH)/player
	$(MKDIR_P) $(BUILD_PATH)/movements
	@echo "* $(YEL)Creating $(CYA)$(BUILD_PATH)$(YEL) folder:$(D) $(_SUCCESS)"

$(LIBFT_ARC):
	$(MAKE) $(LIBFT_PATH) extra

get_libft:
	@echo "* $(CYA)Getting Libft submodule$(D)"
	@$(MKDIR_P) $(LIBS_PATH)
	@if test ! -d "$(LIBFT_PATH)"; then \
		git clone $(LIBFT_URL) $(LIBFT_PATH); \
		echo "* $(GRN)Libft submodule download$(D): $(_SUCCESS)"; \
	else \
		echo "* $(GRN)Libft submodule already exists 🖔"; \
	fi

$(MLX_ARC):
	$(MAKE) $(MLX_PATH)

get_mlx:
	@echo "* $(CYA)Getting MLX submodule$(D)"
	@$(MKDIR_P) $(LIBS_PATH)
	@if test ! -d "$(MLX_PATH)"; then \
		curl -kL $(MLX_URL) | tar zxvf -; \
		mv minilibx-linux ./lib/mlx; \
		echo "* $(GRN)MLX submodule download$(D): $(_SUCCESS)"; \
	else \
		echo "* $(GRN)MLX submodule already exists 🖔"; \
	fi

clean:				## Remove object files
	@echo "*** $(YEL)Cleaning object files$(D)"
	$(RM) $(BUILD_PATH); \
	echo "* $(YEL)Removing $(CYA)$(BUILD_PATH)$(D) folder & files$(D): $(_SUCCESS)"; \

fclean: clean			## Remove executable and .gdbinit
	@echo "*** $(YEL)Cleaning executables$(D)"
	$(RM) $(NAME);
	echo "* $(YEL)Removing $(CYA)$(NAME)$(D) file: $(_SUCCESS)"; \

libclean: fclean	## Remove libs
	@echo "*** $(YEL)Cleaning libraries$(D)"
	$(RM) $(LIBS_PATH)
	@echo "* $(YEL)Removing lib folder & files!$(D) : $(_SUCCESS)"

re: libclean all	## Purge & Recompile

.PHONY: bonus clean fclean re help

#==============================================================================#
#                                  UTILS                                       #
#==============================================================================#

# Colors
#
# Run the following command to get list of available colors
# bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'
#
B  		= $(shell tput bold)
BLA		= $(shell tput setaf 0)
RED		= $(shell tput setaf 1)
GRN		= $(shell tput setaf 2)
YEL		= $(shell tput setaf 3)
BLU		= $(shell tput setaf 4)
MAG		= $(shell tput setaf 5)
CYA		= $(shell tput setaf 6)
WHI		= $(shell tput setaf 7)
GRE		= $(shell tput setaf 8)
BRED 	= $(shell tput setaf 9)
BGRN	= $(shell tput setaf 10)
BYEL	= $(shell tput setaf 11)
BBLU	= $(shell tput setaf 12)
BMAG	= $(shell tput setaf 13)
BCYA	= $(shell tput setaf 14)
BWHI	= $(shell tput setaf 15)
D 		= $(shell tput sgr0)
BEL 	= $(shell tput bel)
CLR 	= $(shell tput el 1)
