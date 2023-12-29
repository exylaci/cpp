# Menetred  
  
Adott egy város tömegközlekedésének a menetrendje a következő formátumban:  
Első busz:  
`{{"Első megálló", 0 }, {"Második megálló", távolság percben az első megállótól}, {"Harmadik megálló", távolság percben az első megállótól} .... }`  
Második busz:  
`{{"Első megálló", 0 }, {"Második megálló", távolság percben az első megállótól}, {"Harmadik megálló", távolság percben az első megállótól} .... }`  
...  
A távolság mindig az első megállóhoz viszonyítva van megadva, nem az előzőhöz.  
  
A menetrendet figyelembe véve írjunk egy programot, ami megkeresi a legrövidebb utat két megálló között! Amennyiben két útnak ugyanaz az időbeli hossza, válaszd azt amelyik kevesebb megállót érint. Kevesebb megálló, nem kevesebb átszállás!  
Helyes megoldás csak egy van, vagyis nem lesz két út, aminek az időbeli hossza és a megállók száma is megegyezik és nincs gyorsabb útvonal. A menetrend csak egy irányba érvényes, visszafelé ezek a buszok nem szállítanak utasokat.  
  
## Milyen hosszú percben a legrövidebb útvonal `A` és `W` között?  
## Az `A` és `W` közötti legrövidebb időhöz tartozó lépésszám?  
## Legrövidebb idő `B` és `Y` között?  
## Az `B` és `Y` közötti legrövidebb időhöz tartozó lépésszám?  
