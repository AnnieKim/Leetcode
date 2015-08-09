/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 29, 2013
 Update:     Sep 2, 2013
 Problem:    Permutations II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_47
 Notes:
 Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 For example,
 [1,1,2] have the following unique permutations:
 [1,1,2], [1,2,1], and [2,1,1].

 Solution: dfs...
 Solution2：non-recursive. Find the next permutation and add it to result set, 
			this will miss permutations that 'smaller' than the given 'nums'. 
			So, at first,we sort the nums. This is the fastest one in all test case. 
 */

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int> &num) {
        res.clear();
        sort(num.begin(), num.end());
        bool avail[num.size()];
        memset(avail, true, sizeof(avail));
        vector<int> pum;
        permuteUniqueRe(num, pum, avail);
        return res;
    }

    void permuteUniqueRe(vector<int> &num, vector<int> &pum, bool avail[])
    {
        if (pum.size() == num.size())
        {
            res.push_back(pum);
            return;
        }
        int last_index = -1;
        for (int i = 0; i < num.size(); ++i)
        {
            if (!avail[i]) continue;
            if (last_index != -1 && num[i] == num[last_index]) continue;
            
            avail[i] = false;
            pum.push_back(num[i]);
            permuteUniqueRe(num, pum, avail);
            pum.pop_back();
            avail[i] = true;
            last_index = i;
        }
    }
};

class Solution2 {
public:
	//return all possible unique permutations.
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());//!!!
		vector<vector<int>> ret;
		ret.push_back(nums);
		while (1)
		{
			int idx = -1;
			for (int i = nums.size() - 1; i > 0; i--){
				if (nums[i] > nums[i - 1]){
					idx = i - 1;
					break;
				}
			}
			if (idx == -1) break;
			for (int i = nums.size() - 1; i > 0; i--){
				if (nums[i] > nums[idx]){
					int tmp = nums[i];
					nums[i] = nums[idx];
					nums[idx] = tmp;
					break;
				}
			}
			sort(&nums[0] + idx + 1, &nums[0] + nums.size());
			ret.push_back(nums);
		}
		return ret;
	}
};