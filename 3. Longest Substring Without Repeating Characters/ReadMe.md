+ 用 idxmap 來記錄 char 是在哪個時間點被看到

```
idxmap[int(s[i])] = i;
```
+ 用 sidx 紀錄這次的字串，是從哪個index開始
    + 假設p上次出現在字串的2，這次又看到p，那新句子的sidx，就是上次看到 p 再+1

```cpp=
    sidx = max(  sidx , idxmap[int(s[i])] + 1 );    
```
+ 以下情況， 當第二次看到a時，新句子的頭就該從b開始
+ a b c a 
+ 0 1 2 
