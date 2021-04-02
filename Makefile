
CMP := clang++
ARGS := -std=c++17 -Wall
OUT := translator.out

OBJ/ := ./objects/
HED/ := ./headers/
SRC/ := ./source/

OBJECTS := $(shell find $(OBJ/) -name '*.o')

IN := in.txt
OUT := out.txt

translator: main
	./$(OUT) $(IN) $(OUT)

main: $(OBJECTS)
	$(CMP) $(ARGS) -o $(OUT) $^

$(OBJ/)%.o: $(SRC/)%.c
	$(CMP) $(ARGS) -o $@ -c $<
	

