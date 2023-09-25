# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 11:21:53 by fgomes-f          #+#    #+#              #
#    Updated: 2023/09/22 16:59:16 by fgomes-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c utils_pipex.c

SRC_BONUS = pipex_bonus.c utils_pipex_bonus.c

OBJS = ${SRC:.c=.o}

OBJS_BONUS = ${SRC_BONUS:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I libftplus

all: ${NAME}

${NAME}: ${OBJS}
		make -C ./libftplus
		${CC} ${CFLAGS} ${OBJS} -L ./libftplus -lft -o ${NAME} ${INCLUDE}

bonus:  ${OBJS_BONUS}
		make -C ./libftplus
		${CC} ${CFLAGS} ${OBJS_BONUS} -L ./libftplus -lft -o ${NAME} ${INCLUDE}
		
%.o : %.c
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

clean:
		make -C libftplus clean
		${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
		make -C libftplus fclean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

tests: test_norm test_mandatory test_m_basic test_m_arguments test_m_file_permissions test_m_no_infile test_m_bad_command test_m_no_rights_and_bad_command test_m_no_file_and_bad_command

# check the norm
test_norm:
	@echo "\n\n$(YELLOW)------NORM ERRORS------$(DEF_COLOR)"
	@norminette

# test the mandatory part
test_mandatory:
	@echo "\n\n$(BLUE)------MANDATORY PART------$(DEF_COLOR)"

# test the mandatory part with existing infile, good rights and existing commands
test_m_basic:
	@echo "\n$(GREEN)BASIC TESTS$(DEF_COLOR)\n"
	@echo "a a a" > infile.txt
	@chmod 777 infile.txt
	@echo "\nInput file content:"
	@cat infile.txt | cat -e
	@echo "\n$(CYAN)Test 1 = ./pipex infile.txt \"grep a\" \"wc -w\" outfile.txt $(DEF_COLOR)"
	@echo "\nShell exit code:"
	@< infile.txt grep a | wc -w > outfile1.txt; echo "$$?"
	@echo "Output file content:"
	@cat outfile1.txt | cat -e
	@echo "----\nYour exit code:"
	@./pipex infile.txt "grep a" "wc -w" outfile2.txt; echo "$$?"
	@echo "Output file content:"
	@cat outfile2.txt | cat -e
	@if diff -q outfile1.txt outfile2.txt > /dev/null ; then \
   		echo "\n$(GREEN)Result: Output files are equal$(DEF_COLOR)"; \
	else \
    	echo "\n$(RED)Result: Output files are not equal$(DEF_COLOR)"; \
	fi
	@rm -f outfile1.txt outfile2.txt
	@echo "\n$(CYAN)Test 2 = ./pipex infile.txt \"cat -e\" \"cat -e\" outfile.txt$(DEF_COLOR)"
	@echo "\nShell exit code:"
	@< infile.txt cat -e | cat -e > outfile1.txt; echo "$$?"
	@echo "Output file content:"
	@cat outfile1.txt | cat -e
	@echo "----\nYour exit code:"
	@./pipex infile.txt "cat -e" "cat -e" outfile2.txt; echo "$$?"
	@echo "Output file content:"
	@cat outfile2.txt | cat -e
	@if diff -q outfile1.txt outfile2.txt > /dev/null ; then \
   		echo "\n$(GREEN)Result: Output files are equal$(DEF_COLOR)"; \
	else \
		echo "\n$(RED)Result: Output files are not equal$(DEF_COLOR)"; \
	fi
	@rm -f outfile1.txt outfile2.txt
	@echo "\n$(CYAN)Test 3 = ./pipex infile.txt \"grep a\" \"cat -e\" outfile.txt$(DEF_COLOR)"
	@echo "\nShell exit code:"
	@< infile.txt grep a | cat -e > outfile1.txt; echo "$$?"
	@echo "Output file content:"
	@cat outfile1.txt | cat -e
	@echo "----\nYour exit code:"
	@./pipex infile.txt "grep a" "cat -e" outfile2.txt; echo "$$?"
	@echo "Output file content:"
	@cat outfile2.txt | cat -e
	@if diff -q outfile1.txt outfile2.txt > /dev/null ; then \
   		echo "\n$(GREEN)Result: Output files are equal$(DEF_COLOR)"; \
	else \
		echo "\n$(RED)Result: Output files are not equal$(DEF_COLOR)"; \
	fi
	@rm -f outfile1.txt outfile2.txt infile.txt
	@echo "Line1\nLine2\nLine3\nLine4" > infile.txt
	@chmod 777 infile.txt
	@echo "\nInput file content:"
	@cat infile.txt | cat -e
	@echo "\n$(CYAN)Test 4 = ./pipex infile.txt \"grep Line\" \"wc -w\" outfile.txt$(DEF_COLOR)"
	@echo "\nShell exit code:"
	@< infile.txt grep Line | wc -w > outfile1.txt; echo "$$?"
	@echo "Output file content:"
	@cat outfile1.txt | cat -e
	@echo "----\nYour exit code:"
	@./pipex infile.txt "grep Line" "wc -w" outfile2.txt; echo "$$?"
	@echo "Output file content:"
	@cat outfile2.txt | cat -e
	@if diff -q outfile1.txt outfile2.txt > /dev/null ; then \
   		echo "\n$(GREEN)Result: Output files are equal$(DEF_COLOR)"; \
	else \
		echo "\n$(RED)Result: Output files are not equal$(DEF_COLOR)"; \
	fi
	@rm -f outfile1.txt outfile2.txt
	@echo "\n$(CYAN)Test 5 = ./pipex infile.txt \"cat -e\" \"cat -e\" outfile.txt$(DEF_COLOR)"
	@echo "\nShell exit code:"
	@< infile.txt cat -e | cat -e > outfile1.txt; echo "$$?"
	@echo "Output file content:"
	@cat outfile1.txt | cat -e
	@echo "----\nYour exit code:"
	@./pipex infile.txt "cat -e" "cat -e" outfile2.txt; echo "$$?"
	@echo "Output file content:"
	@cat outfile2.txt | cat -e
	@if diff -q outfile1.txt outfile2.txt > /dev/null ; then \
   		echo "\n$(GREEN)Result: Output files are equal$(DEF_COLOR)"; \
	else \
		echo "\n$(RED)Result: Output files are not equal$(DEF_COLOR)"; \
	fi
	@rm -f outfile1.txt outfile2.txt
	@echo "\n$(CYAN)Test 6 = ./pipex infile.txt \"grep Line\" \"cat -e\" outfile.txt$(DEF_COLOR))"
	@echo "\nShell exit code:"
	@< infile.txt grep Line | cat -e > outfile1.txt; echo "$$?"
	@echo "Output file content:"
	@cat outfile1.txt | cat -e
	@echo "----\nYour exit code:"
	@./pipex infile.txt "grep Line" "cat -e" outfile2.txt; echo "$$?"
	@echo "Output file content:"
	@cat outfile2.txt | cat -e
	@if diff -q outfile1.txt outfile2.txt > /dev/null ; then \
   		echo "\n$(GREEN)Result: Output files are equal$(DEF_COLOR)"; \
	else \
		echo "\n$(RED)Result: Output files are not equal$(DEF_COLOR)"; \
	fi
	@rm -f outfile1.txt outfile2.txt infile.txt
	@echo "\n$(YELLOW)All basic tests done!$(DEF_COLOR)\n"

# test that mandatory only takes 4 arguments (argc = 5)
test_m_arguments:
	@echo "\n\n$(GREEN)------ARGUMENT CHECK------$(DEF_COLOR)"
	@echo "a a a" > infile.txt
	@echo "\n$(CYAN)5 arguments\nTest 1 = ./pipex infile.txt \"cat -e\" \"cat -e\" \"cat -e\" outfile.txt$(DEF_COLOR)"
	@echo "----\nYour exit code:"
	@./pipex infile.txt "cat -e" "cat -e" "cat -e" outfile2.txt; echo "$$?"
	@echo "Output file content:"
	@cat outfile2.txt | cat -e
	@rm -f outfile2.txt
	@echo "\n$(CYAN)3 arguments\nTest 2 = ./pipex infile.txt \"cat -e\" outfile.txt$(DEF_COLOR)"
	@echo "----\nYour exit code:"
	@./pipex infile.txt "cat -e" outfile2.txt; echo "$$?"
	@echo "Output file content:"
	@cat outfile2.txt | cat -e
	@rm -f outfile2.txt infile.txt
	@echo "\n$(YELLOW)Argument tests done!$(DEF_COLOR)\n"
	
# test the mandatory part with existing infile, bad rights and existing commands
test_m_file_permissions:
	@rm -f outfile1.txt outfile2.txt outfile3.txt outfile4.txt no_permissions.txt infile.txt outfile.txt
	@echo "\n\n$(GREEN)------BAD INFILE RIGHTS------$(DEF_COLOR)"
	@echo "a a a" > no_permissions.txt
	@chmod 000 no_permissions.txt
	@echo "\n$(CYAN)Test = ./pipex no_permissions.txt \"cat -e\" \"cat -e\" outfile.txt$(DEF_COLOR)"
	@echo "\nShell exit code:"
	@< no_permissions.txt cat -e | cat -e > outfile1.txt; echo "$$?" >> outfile3.txt
	@cat outfile3.txt
	@echo "Output file content:"
	@cat outfile1.txt | cat -e
	@echo "----\nYour exit code:"
	@./pipex no_permissions.txt "cat -e" "cat -e" outfile2.txt; echo "$$?" >> outfile4.txt
	@cat outfile4.txt
	@echo "Output file content:"
	@cat outfile2.txt | cat -e
	@if diff -q outfile3.txt outfile4.txt > /dev/null ; then \
   		echo "\n$(GREEN)Result: Exit codes are equal$(DEF_COLOR)"; \
	else \
		echo "\n$(RED)Result: Exit codes are not equal$(DEF_COLOR)"; \
	fi
	@rm -f outfile1.txt outfile2.txt no_permissions.txt outfile3.txt outfile4.txt
	@echo "\n$(YELLOW)Bad infile rights tests done!$(DEF_COLOR)\n"

# test the mandatory part with no infile and existing commands
test_m_no_infile:
	@echo "\n\n$(GREEN)------NO INFILE------$(DEF_COLOR)"
	@echo "\n$(CYAN)Test = ./pipex \"cat -e\" \"cat -e\" outfile.txt$(DEF_COLOR)"
	@echo "\nShell exit code:"
	@< infile.txt cat -e | cat -e > outfile1.txt; echo "$$?" >> outfile3.txt
	@cat outfile3.txt
	@echo "Output file content:"
	@cat outfile1.txt | cat -e
	@echo "----\nYour exit code:"
	@./pipex infile.txt "cat -e" "cat -e" outfile2.txt; echo "$$?" >> outfile4.txt
	@cat outfile4.txt
	@echo "Output file content:"
	@cat outfile2.txt | cat -e
	@if diff -q outfile3.txt outfile4.txt > /dev/null ; then \
   		echo "\n$(GREEN)Result: Output files are equal$(DEF_COLOR)"; \
	else \
		echo "\n$(RED)Result: Output files are not equal$(DEF_COLOR)"; \
	fi
	@rm -f outfile1.txt outfile2.txt outfile3.txt outfile4.txt
	@echo "\n$(YELLOW)No infile tests done!$(DEF_COLOR)\n"

# test the mandatory part with existing infile, good rights and bad commands
test_m_bad_command:
	@echo "\n\n$(GREEN)------BAD COMMAND------$(DEF_COLOR)"
	@echo "a a a" > infile.txt
	@chmod 777 infile.txt
	@echo "\n$(CYAN)Test 1 = ./pipex infile.txt \"cat -e\" \"John Cena\" outfile.txt$(DEF_COLOR)"
	@echo "\nShell exit code:"
	@< infile.txt cat -e | John Cena > outfile1.txt; echo "$$?" >> outfile3.txt
	@cat outfile3.txt
	@echo "Output file content:"
	@cat outfile1.txt | cat -e
	@echo "----\nYour exit code:"
	@./pipex infile.txt "cat -e" "John Cena" outfile2.txt; echo "$$?" >> outfile4.txt
	@cat outfile4.txt
	@echo "Output file content:"
	@cat outfile2.txt | cat -e
	@if diff -q outfile3.txt outfile4.txt > /dev/null ; then \
   		echo "\n$(GREEN)Result: Exit codes are equal$(DEF_COLOR)"; \
	else \
		echo "\n$(RED)Result: Exit codes are not equal$(DEF_COLOR)"; \
	fi
	@rm -f outfile1.txt outfile2.txt
	@echo "\n$(CYAN)Test 2 = ./pipex infile.txt \"asdf\" \"cat -e\" outfile.txt$(DEF_COLOR)"
	@echo "\nShell exit code:"
	@< infile.txt asdf | cat -e > outfile1.txt; echo "$$?"
	@echo "Output file content:"
	@cat outfile1.txt | cat -e
	@echo "----\nYour exit code:"
	@./pipex infile.txt "asdf" "cat -e" outfile2.txt; echo "$$?"
	@echo "Output file content:"
	@cat outfile2.txt | cat -e
	@if diff -q outfile3.txt outfile4.txt > /dev/null ; then \
   		echo "\n$(GREEN)Result: Exit codes are equal$(DEF_COLOR)"; \
	else \
		echo "\n$(RED)Result: Exit codes are not equal$(DEF_COLOR)"; \
	fi
	@rm -f outfile1.txt outfile2.txt infile.txt outfile.txt outfile3.txt outfile4.txt
	@echo "\n$(YELLOW)Bad command tests done!$(DEF_COLOR)\n"

# test the mandatory part with with infile, bad infile rights and bad commands
test_m_no_rights_and_bad_command:
	@echo "\n\n$(GREEN)------BAD INFILE RIGHTS AND BAD COMMAND------$(DEF_COLOR)"
	@echo "a a a" > no_permissions.txt
	@chmod 000 no_permissions.txt
	@echo "\n$(CYAN)Test 1 = ./pipex no_permissions.txt \"cat -e\" \"John Cena\" outfile.txt$(DEF_COLOR)"
	@echo "\nShell exit code:"
	@< no_permissions.txt cat -e | John Cena > outfile1.txt; echo "$$?" >> outfile3.txt
	@cat outfile3.txt
	@echo "Output file content:"
	@cat outfile1.txt | cat -e
	@echo "----\nYour exit code:"
	@./pipex no_permissions.txt "cat -e" "John Cena" outfile2.txt; echo "$$?" >> outfile4.txt
	@cat outfile4.txt
	@echo "Output file content:"
	@cat outfile2.txt | cat -e
	@if diff -q outfile3.txt outfile4.txt > /dev/null ; then \
   		echo "\n$(GREEN)Result: Exit codes are equal$(DEF_COLOR)"; \
	else \
		echo "\n$(RED)Result: Exit codes are not equal$(DEF_COLOR)"; \
	fi
	@rm -f outfile1.txt outfile2.txt no_permissions.txt outfile3.txt outfile4.txt
	@echo "\n$(CYAN)Test 2 = ./pipex no_permissions.txt \"John Cena\" \"cat -e\" outfile.txt$(DEF_COLOR)"
	@echo "\nShell exit code:"
	@< no_permissions.txt John Cena | cat -e > outfile1.txt; echo "$$?" >> outfile3.txt
	@cat outfile3.txt
	@echo "Output file content:"
	@cat outfile1.txt | cat -e
	@echo "----\nYour exit code:"
	@./pipex no_permissions.txt "John Cena" "cat -e" outfile2.txt; echo "$$?" >> outfile4.txt
	@cat outfile4.txt
	@echo "Output file content:"
	@cat outfile2.txt | cat -e
	@if diff -q outfile3.txt outfile4.txt > /dev/null ; then \
   		echo "\n$(GREEN)Result: Exit codes are equal$(DEF_COLOR)"; \
	else \
		echo "\n$(RED)Result: Exit codes are not equal$(DEF_COLOR)"; \
	fi
	@rm -f outfile1.txt outfile2.txt no_permissions.txt outfile3.txt outfile4.txt
	@echo "\n$(YELLOW)Bad infile rights and bad command tests done!$(DEF_COLOR)\n"
	
# test the mandatory part with no infile and bad commands
test_m_no_file_and_bad_command:
	@echo "\n\n$(GREEN)------NO INFILE AND BAD COMMAND------$(DEF_COLOR)"
	@echo "\n$(CYAN)Test 1 = ./pipex infile.txt \"John Cena\" \"cat -e\" outfile.txt$(DEF_COLOR)"
	@echo "\nShell exit code:"
	@< infile.txt John Cena | cat -e > outfile1.txt; echo "$$?" >> outfile3.txt
	@cat outfile3.txt
	@echo "Output file content:"
	@cat outfile1.txt | cat -e
	@echo "----\nYour exit code:"
	@./pipex infile.txt "John Cena" "cat -e" outfile2.txt; echo "$$?" >> outfile4.txt
	@cat outfile4.txt
	@echo "Output file content:"
	@cat outfile2.txt | cat -e
	@if diff -q outfile3.txt outfile4.txt > /dev/null ; then \
   		echo "\n$(GREEN)Result: Exit codes are equal$(DEF_COLOR)"; \
	else \
		echo "\n$(RED)Result: Exit codes are not equal$(DEF_COLOR)"; \
	fi
	@rm -f outfile1.txt outfile2.txt outfile3.txt outfile4.txt
	@echo "\n$(CYAN)Test 2 = ./pipex infile.txt \"cat -e\" \"John Cena\" outfile.txt$(DEF_COLOR)"
	@echo "\nShell exit code:"
	@< infile.txt cat -e | John Cena > outfile1.txt; echo "$$?" >> outfile3.txt
	@cat outfile3.txt
	@echo "Output file content:"
	@cat outfile1.txt | cat -e
	@echo "----\nYour exit code:"
	@./pipex infile.txt "cat -e" "John Cena" outfile2.txt; echo "$$?" >> outfile4.txt
	@cat outfile4.txt
	@echo "Output file content:"
	@cat outfile2.txt | cat -e
	@if diff -q outfile3.txt outfile4.txt > /dev/null ; then \
   		echo "\n$(GREEN)Result: Exit codes are equal$(DEF_COLOR)"; \
	else \
		echo "\n$(RED)Result: Exit codes are not equal$(DEF_COLOR)"; \
	fi
	@rm -f outfile1.txt outfile2.txt outfile3.txt outfile4.txt
	@echo "\n$(YELLOW)No infile and bad command tests done!$(DEF_COLOR)\n"
