/*Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.
 
Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.*/

// Method-1
string frequencySort(string s) {
 unordered_map<char, int> freq;

        // Step 1: Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Use multimap to sort by frequency (auto sorted by key)
        multimap<int, char, greater<int>> sortedFreq;
        for (auto &p : freq) {
            sortedFreq.insert({p.second, p.first});
        }

        // Step 3: Build result string
        string result;
        for (auto &p : sortedFreq) {
            result.append(p.first, p.second);
        }

        return result;
    } 
    // Time:O(logn) and space :O(k + n) k = number of unique characters (max 256 for extended ASCII, so it’s often treated as constant).n = length of input string.So, in simplified terms:👉 O(n) overall space complexity
    //Method-2 Brute Force
    string frequencySort(string s) {
    string result;
    int n = s.size();
    vector<bool> used(256, false); // to track used characters

    for (int i = 0; i < n; ++i) {
        char current = s[i];
        if (used[current]) continue;

        // Count frequency manually
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (s[j] == current) count++;
        }

        // Mark character as used
        used[current] = true;

        // Insert into result string
        int pos = 0;
        while (pos < result.size() && count <= countOccurrences(result, result[pos])) {
            pos++;
        }
        result.insert(pos, string(count, current));
    }

    return result;
}

// Helper to count how many times a char appears in result so far
int countOccurrences(const string& str, char c) {
    return count(str.begin(), str.end(), c);
}
//Time:O(n2) and Space :O(n)
