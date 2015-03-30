BASENAME = DP_Zak_Jan_2015
PDFLATEX = pdflatex -shell-escape

default:
	$(PDFLATEX) $(BASENAME).tex

full:
	$(PDFLATEX) $(BASENAME).tex
	bibtex $(BASENAME)
	$(PDFLATEX) $(BASENAME).tex
	$(PDFLATEX) $(BASENAME).tex

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
