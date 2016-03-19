SUBDIRS=2DArray \
		matrix \
		diagonalMatrix \
		lowerTriangularMatrix \
		linkedMatrix \
		sparseMatrix \
		tridiagonalMatrix

.PHONY:all clean $(SUBDIRS)


all clean:$(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -j2 -C $@ $(MAKECMDGOALS)

