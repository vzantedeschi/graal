STRUCTXML = Attribut.cpp CDSect.cpp Comment.cpp ContentItem.cpp DocTypeDecl.cpp Document.cpp Donnees.cpp Element.cpp EmptyElement.cpp Misc.cpp NonEmptyElement.cpp PI.cpp Prolog.cpp
STRUCTXSD = structXSD.cpp

#pour l'instant il construit l'exe qu'à partir de commun
all: cXML
	g++ -std=c++11 -g -DFLEXDEBUG -DYYDEBUG -o xmltool main.cpp $(STRUCTXML) xml.tab.c lex.xml.c 

#pour ajouter par exemple la compilation de xsd :
# all: cXML cXSD
#	g++ -std=c++11 -g -DFLEXDEBUG -DYYDEBUG -o xmltool main.cpp $(STRUCTXML) $(STRUCTXSD) xml.tab.c xsd.tab.c lex.xml.c lex.xsd.c

cXML: *.l xml.y $(STRUCTXML) *.h
	flex -P xml xml.l
	g++ -std=c++11 -c $(STRUCTXML)
	bison -p xml --debug --verbose --defines=xml.tab.h xml.y
	touch commun

cXSD: *.l xsd.y $(STRUCTXSD) *.h
	flex -P xsd xsd.l
	g++ -std=c++11 -c $(STRUCTXSD)
	bison -p xsd --debug --verbose --defines=xsd.tab.h xsd.y
	touch xsd

clean:
	-rm -rf *.tab.c lex.x*.c *.tab.h *.output xmltool commun xsd

test:
	cd Tests; ./mktest.sh
