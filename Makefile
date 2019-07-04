CC := gcc
RM := rm -rf

EXEC := main.out
TEXEC := test.out

DIR_SRC := ./src
DIR_INC := ./include
DIR_MOCK := ./mock_framework
DIR_TEST := ./test
DIR_APP := ./app

all: FORCE
	$(CC) $(DIR_SRC)/*.c $(DIR_APP)/*.c  -I$(DIR_INC) -I$(DIR_MOCK)  -o $(EXEC)

.PHONY:clean
test: FORCE
	$(CC) -DTEST_MODE $(DIR_SRC)/*.c $(DIR_TEST)/*.c -I$(DIR_INC) -I$(DIR_MOCK) -o $(TEXEC)

FORCE:

clean:
	$(RM) *.o
	$(RM) $(EXEC)
	$(RM) $(TEXEC)
