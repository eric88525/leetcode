class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {

        // record base info
        int col = words[0].size();
        int row = words.size();

        // the expect combination
        unordered_map<string, int> format;
        for (auto &w : words)
        {
            format[w]++;
        }
        vector<int> result;

        for (int i = 0; i < col; i++)
        {

            // record what have seen
            unordered_map<string, int> seen;

            int start = i, end = i, count = 0;

            while (end < s.size())
            {

                // 當下看到單字
                string voc = s.substr(end, col);

                // 查無此單字 start 和 end 跳過他
                if (format.count(voc) == 0)
                {
                    seen.clear();
                    count = 0;
                    end += col;
                    start = end;
                    // 如果是需要的單字，記錄起來，count++
                }
                else if (seen[voc] < format[voc])
                {
                    seen[voc]++;
                    count++;
                    end += col;
                    // 此單字重複 start持續往後移動 直到排除那個重複的單字
                }
                else if (seen[voc] == format[voc])
                {
                    seen[s.substr(start, col)] -= 1;
                    count--;
                    start += col;
                }
                // 條件齊全 加入答案
                if (count == row)
                {
                    result.push_back(start);
                    seen[s.substr(start, col)]--;
                    start += col;
                    count--;
                }
            }
        }
        return result;
    }
};
