xmlPath = xml/
xsdPath = xsd/
xslPath = ../src/XSL/

#pour l'instant il construit l'exe qu'à partir de cXML
all: cXML cXSL
	g++ -std=c++11 -g -DFLEXDEBUG -DYYDEBUG -o xmltool main.cpp $(xmlPath)*.cpp $(xslPath)*.cpp xml.tab.c xsl.tab.c lex.xml.c lex.xsl.c

#pour ajouter par exemple la compilation de xsd :
# all: cXML cXSD
#	g++ -std=c++11 -g -DFLEXDEBUG -DYYDEBUG -o xmltool main.cpp $(xmlPath)*.cpp $(xsdPath)*.cpp xml.tab.c xsd.tab.c lex.xml.c lex.xsd.c

cXML: xml.l xml.y $(xmlPath)*
	flex -P xml xml.l
	g++ -std=c++11 -c $(xmlPath)*.cpp
	bison -p xml --debug --verbose --defines=xml.tab.h xml.y
	touch cXML

cXSD: xsd.l xsd.y $(xsdPath)*
	flex -P xsd xsd.l
	g++ -std=c++11 -c $(xsdPath)*.cpp
	bison -p xsd --debug --verbose --defines=xsd.tab.h xsd.y
	touch cXML

cXSL: xsl.l xsl.y $(xslPath)*
	flex -P xsl xsl.l
	g++ -std=c++11 -c $(xslPath)*.cpp
	bison -p xsl --debug --verbose --defines=xsl.tab.h xsl.y
	touch cXSL

clean:
	-rm -rf *.tab.c lex.x*.c *.tab.h *.output xmltool cXML cXSD cXSL *.o

test:
	cd Tests; ./mktest.sh
