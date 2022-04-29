Uhm... LesezugriffVerletzung...? das ist ein Runtime Error. 
In class PersonDB::createNonDuplicateNewUserNum Methode,
wenn Iterator referensieren map containor, das muss einen integer zurückgeben.
aber in diese zeile gibt es immer einen lesezugirffverletzung bekommen.

jetzt meinen lösung für diese Probleme ist Benutzung von Unique_ptr.

Hoffentlich...
