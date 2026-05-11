class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> resultStack;
        string currentString = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                // Handle multi-digit numbers (e.g., "100[a]")
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                // Push the current multiplier and the string built so far onto stacks
                counts.push(k);
                resultStack.push(currentString);
                // Reset for the new context inside the brackets
                currentString = "";
                k = 0;
            } else if (c == ']') {
                // Pop the multiplier and the previous string context
                string temp = currentString;
                currentString = resultStack.top();
                resultStack.pop();
                
                int repeatTimes = counts.top();
                counts.pop();
                
                // Append the repeated block to the previous context
                while (repeatTimes--) {
                    currentString += temp;
                }
            } else {
                // Just a normal character, add it to our current working string
                currentString += c;
            }
        }

        return currentString;
    }
};