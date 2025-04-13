#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> ans;
        if (nums.empty()) {
            return ans;
        }
        int start = nums[0];
        for (int i = 1; i <= nums.size(); i++) {
            if (i == nums.size() || nums[i] != nums[i - 1] + 1) {
                if (start == nums[i - 1]) {
                    ans.push_back(to_string(start));
                } else {
                    ans.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }
                if (i < nums.size()) {
                    start = nums[i];
                }
            }

        }
        return ans;
    }

    static int compress(vector<char> &chars) {
        if (chars.size() == 1) {
            return 1;
        }
        int ans = 0;
        for (int i = 0; i < chars.size();) {
            char letter = chars[i];
            int count = 0;
            while (i < chars.size() && chars[i] == letter) {
                count++;
                i++;
            }
            chars[ans++] = letter;
            if (count > 1) {
                for (auto s: to_string(count)) {
                    chars[ans++] = s;
                }
            }
        }
        return ans;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr) {
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }

    void solve(int open, int close, string s, vector<string> &ans) {
        if (open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }
        if (open == close) {
            s.push_back('(');
            solve(open - 1, close, s, ans);
        } else if (open == 0) {
            s.push_back(')');
            solve(open, close - 1, s, ans);
        } else if (close == 0) {
            s.push_back('(');
            solve(open - 1, close, s, ans);
        } else {
            string s1 = s;
            string s2 = s;
            s1.push_back('(');
            s2.push_back(')');
            solve(open - 1, close, s1, ans);
            solve(open, close - 1, s2, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        string output = "";
        vector<string> ans;
        solve(open, close, output, ans);
        return ans;
    }

    void moveZeroes(vector<int> &nums) {
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] != 0) {
                swap(nums[l], nums[r]);
                l++;
            }
        }
    }

    bool isPalindrome(string s) {
        string str;
        for (auto c: s) {
            if (isalnum(c)) {
                str += tolower(c);
            }
        }
        int l = 0;
        int r = str.size() - 1;
        while (l < r) {
            if (str[l] != str[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mapchik;
        for (string s: strs) {
            string key = s;
            sort(key.begin(), key.end());
            mapchik[key].push_back(s);
        }
        for (auto s: mapchik) {
            ans.push_back(s.second);
        }
        return ans;
    }

    int longestSubarray(vector<int> &nums) {
        int left = 0, maxl = 0, count = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) {
                count++;
            }
            while (count > 1) {
                if (nums[left] == 0) {
                    count--;
                }
                left++;
            }
            maxl = max(maxl, r - left);
        }
        return maxl;
    }

    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> sum;
        sum[0] = 1;
        int total = 0, count = 0;
        for (auto n: nums) {
            total += n;
            if (sum.find(total - k) != sum.end()) {
                count += sum[total - k];
            }
            sum[total]++;
        }
        return count;
    }

    bool isValid(string s) {
        stack<char> st;
        for (char cur: s) {
            if (!st.empty()) {
                char last = st.top();
                if ((last == '(' && cur == ')') || (last == '{' && cur == '}') || (last == '[' && cur == ']')) {
                    st.pop();
                    continue;
                }
            }
            st.push(cur);

        }
        return st.empty();
    }

    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> par;
        int num = 0;
        for(int i = 0; i < nums.size();i++){
            num = nums[i];
            if(par.find(target - num) != par.end()){
                return {i, par[target - num]};
            }
            par[num] = i;
        }
        return {};

    }

};

int main() {

    return 0;
}