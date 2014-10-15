.PHONY: all clean

all: madhacks.pdf

madhacks.pdf: madhacks.tex $(wildcard code/*.cpp) conf/vimrc conf/Makefile
	pdflatex madhacks.tex
