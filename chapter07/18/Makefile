CXX=g++
RM=rm -rf

EXE_FILES=start
OBJ_FILES=18.o

${EXE_FILES}: ${OBJ_FILES}
	$(CXX) -o ${EXE_FILES} ${OBJ_FILES}

%.o: %.cc
	$(CXX) -c $< -o $@


all: ${EXE_FILES}


.PHONY: clean
clean:
	$(RM) ${EXE_FILES} ${OBJ_FILES}
