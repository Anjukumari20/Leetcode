class Solution {
    public String getHappyString(int n, int k) {
        List<String> happyStrings = new ArrayList<>();
        generateHappyStrings("", n, happyStrings);
        
        // Check if k is within the bounds of the happyStrings list
        if (k > happyStrings.size()) {
            return "";
        }
        
        return happyStrings.get(k - 1); // k is 1-indexed
    }

    private void generateHappyStrings(String current, int n, List<String> happyStrings) {
        // Base case: if the current string length is n, add it to the list
        if (current.length() == n) {
            happyStrings.add(current);
            return;
        }

        // Try to append 'a', 'b', and 'c' to the current string
        for (char c : new char[] {'a', 'b', 'c'}) {
            // Ensure the last character is not the same as the current character
            if (current.length() == 0 || current.charAt(current.length() - 1) != c) {
                generateHappyStrings(current + c, n, happyStrings);
            }
        }
    }
}
