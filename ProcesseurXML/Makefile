<<<<<<< Updated upstream
all: commun
commun: *.l *.y *.cpp *.h
=======
xmlPath = xml/
xsdPath = XSD/
xslPath = XSL/

#pour l'instant il construit l'exe qu'à partir de cXML
#supprimer l'option -DFLEXDEBUG (ligne 9) pour passer les tests

all: cXML cXSD cXSL
	g++ -std=c++11 -g -DFLEXDEBUG -DYYDEBUG=1 -o xmltool main.cpp $(xmlPath)*.cpp $(xsdPath)*.cpp $(xslPath)*.cpp xml.tab.c xsd.tab.c xsl.tab.c lex.xml.c lex.xsd.c lex.xsl.c

cXML: xml.l xml.y $(xmlPath)*
>>>>>>> Stashed changes
	flex -P xml xml.l
	bison -p xml --debug --verbose --defines=xml.tab.h xml.y
	g++ -std=c++11 -g -DFLEXDEBUG -DYYDEBUG -o xmltool main.cpp xml.tab.c lex.xml.c
	touch commun
clean:
	-rm -rf xml.tab.c lex.xml.c xml.tab.h xml.output xmltool commun
test:
	cd Tests; ./mktest.sh
