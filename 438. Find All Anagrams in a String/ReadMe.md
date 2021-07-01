# Solution

https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/92027/C%2B%2B-O(n)-sliding-window-concise-solution-with-explanation

用sliding window 看到新的字就新增，並刪除第一個字。

每次都進行比對，直接用長度26的vector比對就好。