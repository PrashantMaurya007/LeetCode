class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string currentBuffer = "";
        
        // Pre-allocate memory for the string buffer to avoid re-allocations
        currentBuffer.reserve(2 * n); 
        
        backtrack(result, currentBuffer, 0, 0, n);
        return result;
    }

private:
    void backtrack(std::vector<std::string>& result, std::string& current, int openCount, int closeCount, int maxPairs) {
        // Base Case: Valid combination found
        if (current.length() == maxPairs * 2) {
            result.push_back(current);
            return;
        }

        // Choice 1: Add an open parenthesis
        if (openCount < maxPairs) {
            current.push_back('(');                             // Take choice
            backtrack(result, current, openCount + 1, closeCount, maxPairs); // Recurse
            current.pop_back();                                 // Undo choice (Backtrack)
        }

        // Choice 2: Add a close parenthesis
        if (closeCount < openCount) {
            current.push_back(')');                             // Take choice
            backtrack(result, current, openCount, closeCount + 1, maxPairs); // Recurse
            current.pop_back();                                 // Undo choice (Backtrack)
        }
    }
};