Gram=y.tab.c y.tab.h

all: $(Gram) 
	@gcc -o calc y.tab.c code.c symbol.c init.c math.c -lm
	@echo Compiled

$(Gram): hoc5.y
	@yacc -d hoc5.y
clean:
	@rm -f  *.tab.* calc 
	@echo Clean
