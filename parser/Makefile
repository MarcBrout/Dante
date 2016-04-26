##
## Makefile for Makefile in /home/duhieu_b/IA/dante/parser
## 
## Made by benjamin duhieu
## Login   <duhieu_b@epitech.net>
## 
## Started on  Fri Apr 22 15:00:17 2016 benjamin duhieu
## Last update Sat Apr 23 15:08:39 2016 benjamin duhieu
##

# USEFUL VARIABLES

RM		=	rm -rf

GREEN		=	\033[1;32m

WHITE		=	\033[0m

ECHO		=	echo -e

# COREWAR VARIABLES

PARS	=	./

SRC		=	$(PARS)pars.c \
			$(PARS)link_direction.c \
			$(PARS)move_in_list.c \
			$(PARS)add_cas_list.c \

OBJS    	=	$(SRC:.c=.o)


# LIBRARY VARIABLES

LIBPATH		=       ../lib/

LIB		=	../lib/libmy.a

SRCLIB		=	$(LIBPATH)my/get_next_line.c \
			$(LIBPATH)my/my_getnbr.c \
			$(LIBPATH)my/my_power_rec.c \
			$(LIBPATH)my/my_printf.c \
			$(LIBPATH)my/my_printfcsspb.c \
			$(LIBPATH)my/my_printfdiouxx.c \
			$(LIBPATH)my/my_printfmetc.c \
			$(LIBPATH)my/my_putchar.c \
			$(LIBPATH)my/my_put_nbr.c \
			$(LIBPATH)my/my_putstr.c \
			$(LIBPATH)my/my_put_error.c \
			$(LIBPATH)my/my_revstr.c \
			$(LIBPATH)my/my_strcmp.c \
			$(LIBPATH)my/my_strdup.c \
			$(LIBPATH)my/my_strlen.c \
			$(LIBPATH)my/my_strncmp.c \

LDFLAGS		=       -lmy -L$(LIBPATH)

OBJSLIB		=	$(SRCLIB:.c=.o)


# PROJECT VARIABLES

NAME		=	pars

IFLAG		=	-I../include/

CFLAGS		=	-W -Wall -Wextra

CC		=	gcc -g $(CFLAGS) $(IFLAG)


# PROJECT RULES

$(NAME)		: 	$(LIB) $(OBJS)
			@$(ECHO) "$(GREEN)\n>>>>>>>>>>>>>>>>\n\n> Linking \"$(NAME)\"\n\twith \
\"$(CC)\"\n\n>>>>>>>>>>>>>>>\t DONE\n$(WHITE)"
			@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(LIB)		:	$(OBJSLIB)
			@ar rc $(LIB) $(OBJSLIB)
			@ranlib $(LIB)
			@cp $(LIBPATH)/my/my.h ../include/
			@cp $(LIBPATH)/my/get_next_line.h ../include/
			@$(ECHO) "$(GREEN)\n> Compiling Library\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"


all		:	$(NAME)

clean		:
			@$(RM) $(OBJS)
			@$(RM) $(OBJSLIB)
			@$(ECHO) "$(GREEN)\n> Cleaning repository\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

fclean		: 	clean
			@$(RM) $(NAME)
			@$(RM) $(LIBPATH)/libmy.a
			@$(ECHO) "$(GREEN)\n> Cleaning exec\t\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

re		:	fclean all

.c.o		:
			@$(CC) -c $< -o $@
			@$(ECHO) "$(GREEN)[OK] > $<\t \t $(WHITE)"
