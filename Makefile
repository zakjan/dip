BASENAME = DP_Zak_Jan_2015

default:
	pdflatex $(BASENAME).tex

full:
	pdflatex $(BASENAME).tex
	bibtex $(BASENAME)
	pdflatex $(BASENAME).tex
	pdflatex $(BASENAME).tex

clean:
	rm \
	  $(BASENAME).aux \
	  $(BASENAME).bbl \
	  $(BASENAME).blg \
	  $(BASENAME).lof \
	  $(BASENAME).log \
	  $(BASENAME).lot \
	  $(BASENAME).out \
	  $(BASENAME).pdf \
	  $(BASENAME).toc
