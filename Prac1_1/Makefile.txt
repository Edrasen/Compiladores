Gram=y.tab.c y.tab.h

all: $(Gram) 
	@gcc -o calc y.tab.c -lm 
	@echo Compiled

$(Gram): vec_calc.y
	@yacc -d vec_calc.y

clean:
	@rm -f *.out  *.tab.* calc
	@echo Clean
