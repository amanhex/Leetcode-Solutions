/*
You are given a string s of even length. Split this string into two halves of equal lengths, 
and let a be the first half and b be the second half.
Two strings are alike if they have the same number of vowels 
('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.
Return true if a and b are alike. Otherwise, return false.

Example 1:
Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.

Example 2:
Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.

Constraints:
2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters.
*/

// Using Hashmaps to store vowels

class Solution {
public:
    unordered_map<char, int> vowels{
        {'a', 1},
        {'A', 1},
        {'e', 1},
        {'E', 1},
        {'i', 1},
        {'I', 1},
        {'o', 1},
        {'O', 1},
        {'u', 1},
        {'U', 1},
    };

    int vowelCounter(string& s, int start, int end){
        int ans = 0;
        for (int i = start; i < end; i++)
            if (vowels.count(s[i]) > 0)
                ans++;
        return ans;
    }

    bool halvesAreAlike(string s) {
        int size = s.size();
        int firstHalfAnswer = vowelCounter(s, 0, size / 2);
        int secondHalfAnswer = vowelCounter(s, size / 2, size);
        if (firstHalfAnswer == secondHalfAnswer)
            return true;
        return false;
    }
};

// Without HashMap (Best Approach)

class Solution {
public:
    int vowelCounter(string& s, int start, int end){
        int ans = 0;
        for (int i = start; i < end; i++){
            if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
                ans++;
        }
            return ans;
    }
    bool halvesAreAlike(string s) {
        int size = s.size();
        int firstHalfAnswer = vowelCounter(s, 0, size / 2);
        int secondHalfAnswer = vowelCounter(s, size / 2, size);
        if (firstHalfAnswer == secondHalfAnswer)
            return true;
        return false;
    }
};