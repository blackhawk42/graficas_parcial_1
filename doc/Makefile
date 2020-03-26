DISTDIR=dist/

LATEXC=pdflatex
LATEXCFLAGS=--file-line-error-style --output-directory=$(DISTDIR)
VISOR=evince
BIBC=biber

SOURCE=documento.tex
DISTFILE=$(SOURCE:.tex=.pdf)
BIBFILE=$(SOURCE:.tex=)

all: latex

latex:
	mkdir -p $(DISTDIR)
	$(LATEXC) $(LATEXCFLAGS) $(SOURCE)
	$(LATEXC) $(LATEXCFLAGS) $(SOURCE)

clean:
	rm -rf $(DISTDIR)*

show:	$(DISTDIR)$(DISTFILE)
	$(VISOR) $(DISTDIR)$(DISTFILE) &

bib: $(BIBFILE).bib
	$(BIBC) $(DISTDIR)$(BIBFILE)
