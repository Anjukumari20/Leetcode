stringstream ss(s);
string word;
vector<string> words;

while (ss >> word) {  // Extract words while ignoring extra spaces
    words.push_back(word);
}

reverse(words.begin(), words.end());  // Reverse the order of words

string result;
for (int i = 0; i < words.size(); i++) {
    if (i > 0) result += " ";  // Add space between words
    result += words[i];
}

