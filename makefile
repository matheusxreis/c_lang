GCC = gcc
CFLAGS=-D TEST

postfix:
	@echo "Executing postfix code...."
	${GCC} 03stack/in_post_pre_fix/postfix.c && ./a.out
postfixtest:
	@echo "Testing postfix...."
	${GCC} ${CFLAGS} 03stack/in_post_pre_fix/postfix.c && ./a.out
