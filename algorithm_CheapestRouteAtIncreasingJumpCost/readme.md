# Rét  
  
Adott egy `N`x`M` cellából, azaz `N` sorból és `M` oszlopból álló rét, melynek minden cellája vagy Juli néni, vagy Kati néni tulajdonában van. A bal felső cellából indulunk, és a jobb alsó cellába szeretnénk eljutni. Minden lépésben vagy jobbra, vagy lefelé léphetünk egyet. Minden lépés 1 időegységig tart. Ha két cella oldallal szomszédos, és különböző a tulajdonosa, akkor kerítés választja el őket, és az átjutáskor erőfeszítést kell tennünk. Az erőfeszítés nagysága a túra kezdete óta eltelt idővel egyenesen arányos, mivel folyamatosan fáradunk. Azaz hogyha egy kerítés átlépése az 5. lépés (1-től számozzuk a lépéseket), akkor 5 egységnyi erőfeszítést kell tennünk. Itt az 5 lépésbe beleszámítjuk a kerítésmászás nélkül megtett lépéseket is.  
Írj programot, amely kiszámítja, hogy legkevesebb mennyi erőfeszítésbe kerül eljutni a bal felső cellából a jobb alsó cellába!  
  
## Bemenet:  
`N` sorból áll. Mindegyik sor `M` db bináris számjegyet tartalmaz, szóközök nélkül: a `0`-k jelölik Juli néni, az `1`-esek pedig Kati néni birtokait.  
  
## Kimenet:  
1 db nemnegatív egész szám legyen, az elérhető legkevesebb össz-erőfeszítés.  