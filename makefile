GCC = gcc
CFLAGS=-D TEST

postfix:
	@echo "Executing postfix code...."
	${GCC} 03stack/in_post_pre_fix/postfix.c && ./a.out
postfixtest:
	@echo "Testing postfix...."
	${GCC} ${CFLAGS} 03stack/in_post_pre_fix/postfix.c && ./a.out
prefix:
	@echo "Executing prefix code... exercise 2.3.7"
	${GCC} 03stack/in_post_pre_fix/ex2_3_7.c && ./a.out
eval1:
	@echo "Evaluating prefix by postfix method... exercise 2.3.6"
	${GCC} 03stack/in_post_pre_fix/ex2_3_6.c && ./a.out
