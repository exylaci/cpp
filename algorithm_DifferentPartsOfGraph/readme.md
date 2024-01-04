# Maffia  
  
Egy városban egy hierarchikus szerveződésű maffia működik. A keresztapa rájött, hogy már nem látja át a hierarchiát. Meg szeretné tudni, hogy pl. hányféle lényegesen különböző alszervezet létezik a maffián belül. 
A maffiában mindenkinek pontosan egy közvetlen főnöke van, kivéve a keresztapát. Ha X-nek Y a közvetlen főnöke, akkor Y-nak X egy közvetlen beosztottja. Az M azonosítójú maffiataghoz tartozó alszervezetbe pontosan azok a maffiatagok tartoznak bele, akikből M elérhető 0 vagy több olyan lépéssel, melyekben a hierarchiában felfelé lépünk. Azaz az alszervezet M-ből és az ő közvetlen vagy közvetett beosztottjaiból áll. Ha N tagból áll a maffia, akkor N db alszervezetet azonosíthatunk benne.  
Két alszervezetet egyformának nevezünk, ha létezik kölcsönösen egyértelmű megfeleltetés a két alszervezet tagjai között, mely a beosztottsági viszonyt megtartja. Azaz, formálisan, az M1 és M2 tagok által meghatározott alszervezetek egyformák, ha létezik olyan f: M1 -> M2 leképezés, mely bijektív, és melyre minden X, Y ϵ M1-re igaz az, hogy X pontosan akkor közvetlen főnöke Y-nak, ha f(X) közvetlen főnöke f(Y)-nak. Két alszervezet pontosan akkor lényegesen különböző, ha a fenti definíció szerint nem számítanak egyformának.  
(Speciálisan, ha két alszervezet egyforma, akkor ugyanannyi tagból kell, hogy álljanak, visszafelé ez azonban nem igaz. Viszont például azok a tagok, akiknek nincs beosztottjuk, egy 1 emberből álló alszervezetet határoznak meg, és az 1 emberböl álló alszervezetek triviálisan mind egyformák.)  
Segítsünk a keresztapának: írjunk programot, amely adott maffiahierarchiára kiírja az abban megtalálható lényegesen különböző alszervezetek számát!  
  
## Bemenet:  
- Az első sorban egyetlen `N` szám található, a maffiatagok száma.  
- Minden további (N-1 db) sora két, szóközzel elválasztott 2 számot tartalmaz: Ez a két szám `X` és `Y`, mai az azt jelenti, hogy az `X` sorszámú tagnak az `Y` sorszámú tag a közvetlen főnöke. A tagokat 0-tól N-1-ig számozzuk. A 0-s sorszámú tag a keresztapa, akinek nincs főnöke. Mindenki másra igaz az, hogy alacsonyabb sorszámú a közvetlen főnöke, mint ő maga.  
  
## Kimenet:  
Egyetlen szám, a maffiában fellelhető lényegesen különböző alszervezetek száma.  
