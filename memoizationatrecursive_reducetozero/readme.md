Feladat: Minél kevesebb lépéssel eljutni egy adott számtól a 0-ig.
Szabály: Lehet osztani 3-mal, 2-vel vagy levonni 1-et. És ezt kell ismételgetni amíg el nem érjük a 0-át.
Példa: 10 --- 5 --- 4 --- 2 --- 1 --- 0 (Ez 5 lépés.)
       10 --- 9 --- 3 --- 1 --- 0       (Ez 4 lépés. Ez a helyes megoldás.)

(Első megoldás egy egyszerű rekurziv hívás. Aztán ennek gyorsítása memoization-nel.Végül egy másik megoldás for ciklussal.)