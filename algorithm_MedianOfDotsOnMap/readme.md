# Manhatten  
  
Mint tudjuk, Manhattan lakói egy mindkét irányban végtelen négyzetrácson, azaz egész koordinátájú helyeken élnek. Szeretnénk egy fagyizót nyitni Manhattanben, amely tetszőleges olyan rácspontra kerülhet, ahol még nem lakik senki. A forgalom maximalizálása érdekében ezek közül a szabad rácspontok közül egy "súlyponti" helyre akarjuk tenni a fagyizót, azaz olyan rácspontra, melynek az egyes lakosoktól mért Manhattan-távolságainak összege minimális.  
Az (x1, y1) és (x2, y2) rácspontok Manhattan-távolsága: abs(x1 - x2) + abs(y1 - y2).  

## Bemenet:  
  
A fájl `N` sorból áll, ahol `N` a lakosok száma.  
Mindegyik sorban két egész szám található, szóközzel elválasztva, mégpedig egy lakó házának `x` és `y` koordinátája.  
  
## Kimenet:  
  
2 db egész szám legyen, szóközzel elválasztva:  
1) a minimálisan elérhető össz-Manhattan-távolság.  
2) a minimumhelyek száma,  
azaz hogy a még nem foglalt rácspontok közül hány adja a minimális össztávolságot. A második szám tehát azt adja meg, hogy hányféle szabad helyre rakhatjuk a fagyizót úgy, hogy a Manhattan-távolságösszeg minimális legyen. A második szám tehát sosem lehet O.  
