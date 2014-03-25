STRUCT = Attribut.cpp CDSect.cpp Comment.cpp ContentItem.cpp DocTypeDecl.cpp Document.cpp Donnees.cpp Element.cpp EmptyElement.cpp Misc.cpp NonEmptyElement.cpp PI.cpp Prolog.cpp

all: commun
commun: *.l *.y *.cpp *.h
	g++ -std=c++11 -c $(STRUCT)
	flex -P xml xml.l
	bison -p xml --debug --verbose --defines=xml.tab.h xml.y
	g++ -std=c++11 -g -DFLEXDEBUG -DYYDEBUG -o xmltool main.cpp $(STRUCT) xml.tab.c lex.xml.c
	touch commun
clean:
	-rm -rf xml.tab.c lex.xml.c xml.tab.h xml.output xmltool commun
test:
	cd Tests; ./mktest.sh
