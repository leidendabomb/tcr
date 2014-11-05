.PHONY: all clean

all: madhacks.pdf

madhacks.pdf: madhacks.tex $(wildcard code/*) conf/vimrc conf/Makefile
	pdflatex madhacks.tex
