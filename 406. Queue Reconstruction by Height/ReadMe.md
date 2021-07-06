# 406. Queue Reconstruction by Height

https://leetcode.com/problems/queue-reconstruction-by-height/discuss/673204/Tried-making-video-or-C%2B%2B-solution



# 解法

首先按照兩種規則進行初步排序

+ 身高高的人在前面
+ 身高相同時，順位大的在後面


```c++
sort(people.begin(), people.end(), [](vector<int> &a, vector<int>&b) {
	return ( (a[0]==b[0] && a[1]<b[1])  ||  (a[0] > b[0])   ); 
});
```

接著按照上述排序，根據他的順位來安插他在隊伍裡面的哪個index

```c++
for(int i=0;i<people.size();i++){
	ans.insert( ans.begin()+people[i][1] , people[i] );
}
```
照這麼安插可以發現:

+ 身高高的人，安插的優先權比較高。先把高的人擺入後，不管後面塞多少人進去，比他高的人數量都不會變
+ 在後面安排 people[ j ] 進列隊，可以確保前面會有 people[j] [1] 個人比他高，因為插入的index是看people [ j ]

