BASENAME = DP_Zak_Jan_2015

default:
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

watch:
	while inotifywait -e close_write $(BASENAME).tex; do make; done
