class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //auto: 类似于Java中的Object的，但是在编译时推断变量类型
        auto wordDictSet = unordered_set <string> ();

         //这里是将字典存入一个散列表
        for (auto word: wordDict) {
            wordDictSet.insert(word);
        }

        //动态规划数组，逐个检查是否为单词
        auto dp = vector <bool> (s.size() + 1);
        //空串返回真
        dp[0] = true;

        //逐个字符遍历
        for (int i = 1; i <= s.size(); ++i) {

            for (int j = 0; j < i; ++j) {
                //匹配字符串与字典
                //存在分割点j  find()匹配key值   end()迭代器到底
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        //返回最后一个字符的布尔值
        return dp[s.size()];
    }
};