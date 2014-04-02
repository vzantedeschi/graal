echo "Fichier XML bien formé
"
./xmltool -p ./files/head_comment_cdata_empty.xml
read r
echo "Fichier XML avec erreur de namespace et de tag
"
./xmltool -p ./files/catalog_bad_markup_name_and_ns.xml
read r
echo "Parsage d'un fichier XML dont un des éléments n'est pas fermé. Le fichier ne contient donc pas suffisamment de balises fermantes.
"
./xmltool -p ./files/catalog_missing_markup.xml