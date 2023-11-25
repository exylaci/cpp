# Parcella  
  
Piripócs Község Önkormányzata sok egyforma apró négyzet alakú parcellára osztotta fel a falu területét. János bácsi birtoka azokból a parcellákból áll, melyek középpontja egy meghatározott ellipszisbe vagy annak határára esik. János bácsi agrártámogatást szeretne igényelni, de ehhez tudnia kell, hogy mekkora területű a birtoka.  
A parcellák azoknak az egységnyi oldalú, tengelypárhuzamos négyzeteknek felelnek meg, melyeknek csúcsai egész koordinátán találhatók. Az egész síkot felosztjuk, így végtelen sok parcella létezik. Minden parcellának tehát 1 a területe. János bácsi birtokát egy tengelypárhuzamos ellipszis határozza meg, melynek 4 egész paramétere van: (`cx`, `cy`, `a`, `b`). Az ellipszis egyenlete: `((x - cx)/a)2 + ((y - cy)/b)2 =1`. Azok a parcellák tartoznak a birtokhoz, melyeknek a középpontja vagy az ellipszis határán, vagy annak belsejében található.  
  
## Bemenet:  
1 db sorból áll, melyben szóközzel elválasztva négy egész szám található: `cx cy a b`.  
  
## Kimenet:  
1 db nemnegatív egész szám legyen, mégpedig az, hogy hány olyan parcella van, melynek középpontja beleesik a megadott ellipszisbe vagy annak határára.  
