CC = g++
CFLAGS = -g

DIR_CUR = /home/bszyk/Projects/FINS/fins-cpp
DIR_BIN = ${DIR_CUR}/bin
DIR_LIB = ${DIR_CUR}/lib
DIR_SRC = ${DIR_CUR}/src


fins: info clean
	@echo " Compiling..."
	@${CC} ${CFLAGS} -o ${DIR_BIN}/fins ${DIR_SRC}/fins.cpp -I ${DIR_LIB}
	@echo "   * Compiled."
	@echo

info:
	@echo " Directories:"
	@echo "   * workdir:		${DIR_CUR}"
	@echo "   * binaries:		${DIR_BIN}"
	@echo "   * libraries:		${DIR_LIB}"
	@echo "   * sources:		${DIR_SRC}"
	@echo

clean:
	@echo " Cleaning..."
	@rm -f ${DIR_BIN}/*
	@echo "   * Cleaned."
	@echo

