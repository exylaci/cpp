# Utak  
  
Meseországban `N` db falu található. Szeretnénk a falvakat aszfaltozott útszakaszokkal összekötni úgy, hogy bármelyikből bármelyikbe el lehessen jutni aszfaltozott úton. Ráadásul a lehető legolcsóbban szeretnénk ezt megúszni. A király `M` db útszakaszra kapott ajánlatot a kivitelezőtől, ezek az útszakaszok kétirányúak lennének, adott falut adott faluval kötnének össze, és adott a megépítésük költsége is. Kezdetben egyik út sincs megépítve. Mennyi a lehető legkisebb költség, amivel meg tudjuk oldani a falvak összekötését?  

## Bemenet:  
- Első sor két, szóközzel elválasztott egész számot tartalmaz: `N`-et és `M`-et.  
- A következő `M` db sor mindegyike három, szóközzel elválasztott nemnegatív egész számot tartalmaz:  
  - A javasolt útszakasz két végpontjának azonosítóját. (A falvakat 0-tól N-1-ig számozzuk.)  
  - Az útszakasz megépítésének költségét.  
  
## Kimenet:  
Egy darab nemnegatív egész szám: a **legolcsóbb összköltség**, amellyel el lehet érni, hogy minden faluból minden faluba el tudjunk jutni aszfaltozott úton.