Gram=y.tab.c y.tab.h

all: $(Gram) 
	@gcc -o calc y.tab.c -lm 
	@echo Compiled

$(Gram): vector_cal.y
	@yacc -d vector_cal.y

clean:
	@rm -f *.out  *.tab.* calc
	@echo Clean
