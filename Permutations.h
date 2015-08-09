/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 29, 2013
 Update:     Jul 19, 2013
 Problem:    Permutations
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_46
 Notes:
 Given a collection of numbers, return all possible permutations.
 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

 Solution: dfs...
 Solution2：non-recursive and unique result. Find the next permutation and add it to result set, 
			this will miss permutations that 'smaller' than the given 'nums'. 
			So, at first,we sort the nums. This is the fastest one in all test case. the dfs's
			result may contain duplicate permutations.
 */

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int> &num) {
        res.clear();
        vector<bool> avail(num.size(), true);
        vector<int> pum;
        permuteRe(num, avail, pum);
        return res;
    }

    void permuteRe(const vector<int> &num, vector<bool> &avail, vector<int> &pum)
    {
        if (pum.size() == num.size())
        {
            res.push_back(pum);
            return;
        }
        for (int i = 0; i < num.size(); ++i)
        {
            if (avail[i])
            {
                avail[i] = false;
                pum.push_back(num[i]);
                permuteRe(num, avail, pum);
                pum.pop_back();
                avail[i] = true;
            }
        }
    }
};

class Solution2 {
public:
	//return all possible unique permutations.
	vector<vector<int>> permute(vector<int>& nums) {
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