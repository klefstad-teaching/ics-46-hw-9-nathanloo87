#include "ladder.h"
#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}


void error(string word1, string word2, string msg) {
    std::cerr << word1 << word2 << msg << endl;
};
// checks whether the edit distance between the two strings is d characters
bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int len1 = str1.length(), len2 = str2.length();
    if (abs(len1 - len2) > 1) { // length differencce is greater than d, theres no possible way to change it. false
        return false;
    }
    if (str1 == str2) { // strings are same
        return (d >= 1);
    }
    if (len1 == len2) { // same length
        int diff = 0;
        for (int i = 0; i < len1; i++) {
            if (str1[i] != str2[i]) { // count how many characters are different
                diff++;
            }
            if (diff > d) { // too many different characters to change, words are too far apart
                return false;
            }
        }
        return (diff == d);
    }
    int x = 0, y = 0;
    bool is_diff = false;
    while (x < len1 && y < len2) { // x and y are going to be the indices
        if (str1[x] != str2[y]) {
            if (is_diff) {
                return false;
            }
            is_diff = true;
            y++;
        } else {
            x++;
            y++;
        }
    }
    return true;
};
bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
};
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    queue<vector<string>> lq;
    lq.push(vector<string>{begin_word});
    set<string> visited;
    visited.insert(begin_word);
    while (!lq.empty()) {
        vector<string> ladder = lq.front();
        lq.pop();
        string last = ladder.back();
        for (const string& word : word_list) {
            if (is_adjacent(last, word) && !visited.contains(word)) {
                visited.insert(word);
                vector<string> nl = ladder;
                nl.push_back(word);
                if (word == last) {
                    return nl;
                }
                lq.push(nl);
            }
        }
    }
    return vector<string>{};
};
void load_words(set<string> & word_list, const string& file_name) {
    ifstream filename(file_name);
    if (!filename) {
        error("","", "file not found");
    }
    string line;
    while (std::getline(filename, line)) {
        word_list.insert(line); // Insert each line into the set
    }
    filename.close();
};
void print_word_ladder(const vector<string>& ladder) {
    if (ladder.empty()) {cout << "No word ladder found." << endl;}
    else {
        cout << "Word ladder found: ";
        for (size_t i = 0; ladder[i] < ladder.end(); i++) {
            cout << ladder[i];
            if (ladder[i] != ladder.end() - 1) {
                cout << " ";
            }
        }
        cout << " " << endl;
    }
};
void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
};

/*
BFS {
    VertexList  result;
    vector<bool> visited(graph.size(), false);
    queue<Vertex> queue;
    visited[startVertex] = true;
    queue.push(startVertex);

    while (!queue.empty()) {
        Vertex vertex = queue.front();
        queue.pop();
        result.push_back(vertex);
        for (Vertex v : graph.edges_from(vertex))
            if (!visited[v]) {
                visited[v] = true;
                queue.push(v);
            }
    }
    return result;
};*/