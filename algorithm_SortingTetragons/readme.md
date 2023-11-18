# Négyszög  
  
Móricka a négyszögekről tanul az iskolában. Mivel óra alatt rágógumit dobált osztálytársai hajába, a tanár nénitől büntetésül extra házi feladatot kapott. 1 millió négyszöget kell osztályoznia. A négyszögek a csúcsok koordinátáival vannak megadva.  
A következő típusú négyszögek léteznek (ezek bárhogy el lehetnek forgatva, tehát pl. nem csak a tengelypárhuzamos négyzetek/téglalapok számítanak):  
- `E`: elfajuló: legalább 3 csúcs egy egyenesbe esik. Ennek egy speciális esete az, amikor két csúcs egybeesik.  
- `M`: önmetsző: nem elfajuló, de van két oldal, ami metszi egymást (mármint nem a négyszög egy csúcsában, hanem a szakaszok egy-egy belső pontjában).  
- `N`: nem elfajuló négyzet.  
- `T`: olyan téglalap, ami nem elfajuló és nem négyzet.  
- `R`: olyan rombusz, ami nem elfajuló és nem négyzet.  
- `P`: olyan parallelogramma, ami nem elfajuló, nem téglalap és nem rombusz.  
- `Z`: olyan trapéz, ami nem elfajuló és nem parallelogramma.  
- `D`: olyan deltoid, ami nem elfajuló, nem rombusz és nem négyzet. A konkáv deltoidok is ide számítanak.  
- `L`: általános négyszög, azaz a fenti kategóriák egyikébe sem sorolható.  
  
## Bemenet:  
A fájl **N db** sorból áll. Mindegyik sorban **8 db** egész szám található, szóközzel elválasztva: `x1 y1 x2 y2 x3 y3 x4 y4`. Ezek a négyszög négy csúcsának `x`, illetve `y` koordinátái. Ha a négyszög csúcsai `A`, `B`, `C` és `D`, akkor a négyszög oldalai az `AB`, `BC`, `CD` és `DA` szakaszok, a koordináták pedig: `A = (x1, y1)`, `B = (x2, y2)`, `C = (x3, y3)` és `D = (x4, y4)`.  
  
## Kimenet:  
Egy SHA-256 hash legyen, mégpedig annak a stringnek a hashe, amit úgy kapunk, hogy az egyes négyszögek kategóriáinak megfelelő betűjeleket összekonkatenáljuk. A betűjelek definícióját ld: fent.  
  
## Példa:  
Ha a négyszögek kategóriái rendre: `N`, `Z`, `Z`, `D`; akkor ez a string az `NZZD` szó lesz. A megoldás pedig, `f4a06e5ab277977faffa2630c7f674e9fb14396712983a2ef416b917a9d0971f`.  
A hasht kis- és nagybetűkkel is meg lehet adni, de a string, amit behashelünk, csupa nagybetűs kell, hogy legyen!  
Hogy ellenőrizni lehessen a megoldás helyességét, a példa inputokhoz a megoldás-hashek és a kategória-stringek is meg lettek adva.  