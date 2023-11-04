# Legkevesebb lépés  

A mérőgépünk egy tengely mentén tud mozogni, balra vagy jobbra. Kiindulópontja a tengely origója (0 pontja). Egy mérés során a megadott **T** egész koordinátájú ponthoz szeretnénk elmozgatni a mérőfejet és ott mérést indítani.  
A mérőgép úgy lett tervezve, hogy 1 egységnyi lépésekben tudjon mozogni, de sajnos egy hibás modul miatt jelenleg csak folyamatosan növekvő lépésekben tud mozogni. Minden egyes mérés indítása során először 1 egységet, utána 2 egységet mozdul aztán hármat és így tovább.  
Szerencsére a mérés konfigurációjában lehetőség van minden egyes lépés irányát (bal, jobb) megadni. Az operátorok rájöttek, hogy amíg a mérnökök kijavítják a hibás modult, addig is képesek elérni bármilyen egész koordinátájú pontot.  
Adja meg, hogy legkevesebb hány lépésre van szükség, hogy eljusson a gép egy adott pontba!  

## Bemenet:  
A bemenet egy egész számból áll:  
**T** amelyre  
-10^9 <= T <= 10^9 teljesül.  

## Példa:  
A bemenet=11 esetén 5 a legkevesebb lépés, mert:  
`1-2+3+4+5=11`  
