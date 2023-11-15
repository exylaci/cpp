# Legtöbb szelet  
  
Mérőgépünkkel sorban lemérjük **N** darab szilícium szelet vastagságát.  
Válasszunk ki a szeletekből minél többet úgy, ahogy azok az eredeti sorrendben egymás után vannak és közülük bármely két szelet vastagsága közötti különbség nem haladja meg a **K** mikrométert.   
Határozzuk meg a feltételeknek megfelelően kiválasztható szeletek maximális számát!  
  
## Bemenet:  
Az első sorban két egész szám szerepel:  
`N K`  
amelyekre igaz, hogy `1 <= N <= 10^5` és `0 <= K <= 10^3`.  
A második sor N darab egész számot tartalmaz:  
`H1, H2... Hn`  
ahol Hi az i-dik szelet vastagsága, melyre igaz, hogy `1 <= Hi <= 10^3`.  
  
## Kimenet:  
Az olyan egymás után következő szeletek maximális száma, ahol **bármely kettő szelet** vastagságának különbsége nem nagyobb, mint `K`.  
  
## Példa:  
**Bemenet:**  
```
20 75  
398 397 350 246 255 296 329 265 309 255 320 399 332 321 247 320 399 301 450 104  
```  
  
**Kimenet:**  
`6`  
  
**Magyarázat:**  
398 397 350 246 255 ***296 329 265 309 255 320*** 399 332 321 247 320 399 301 450 104  
  
A kijelölt szeletekre teljesül, hogy bármely kettő vastagságának különbsége nem haladja meg a `75`-öt. Viszont nem tudunk úgy **7** egymás után következő szeletet kijelölni, hogy ez teljesüljön.  