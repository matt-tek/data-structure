##
## EPITECH PROJECT, 2020
## lib
## File description:
## Makefile
##

all:
	make -C generator/ all
	make -C solver/ all

clean:
	make -C generator/ clean
	make -C solver/ clean
	find . -type f -name "*~" -o -name "#*#" -delete
	rm -f *gc*
	rm -f *~*

fclean: clean
	make -C ./solver fclean
	make -C ./generator fclean

re: fclean all
