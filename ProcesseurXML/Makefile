xmlPath = xml/
xsdPath = XSD/

#pour l'instant il construit l'exe qu'à partir de cXML
#all: cXML
#	g++ -std=c++11 -g -DFLEXDEBUG -DYYDEBUG -o xmltool main.cpp $(xmlPath)*.cpp xml.tab.c lex.xml.c 

#pour ajouter par exemple la compilation de xsd :
all: cXML cXSD
	g++ -std=c++11 -g -DYYDEBUG -o xmltool main.cpp $(xmlPath)*.cpp $(xsdPath)*.cpp xml.tab.c xsd.tab.c lex.xml.c lex.xsd.c

cXML: xml.l xml.y $(xmlPath)*
	flex -P xml xml.l
	g++ -std=c++11 -c $(xmlPath)*.cpp
	bison -p xml --debug --verbose --defines=xml.tab.h xml.y
	touch cXML

cXSD: xsd.l xsd.y $(xsdPath)*
	flex -P xsd xsd.l
	g++ -std=c++11 -c $(xsdPath)*.cpp
	bison -p xsd --debug --verbose --defines=xsd.tab.h xsd.y
	touch cXSD

clean:
	-rm -rf *.tab.c lex.x*.c *.tab.h *.output xmltool cXML cXSD *.o

test:
	cd Tests; ./mktest.sh
