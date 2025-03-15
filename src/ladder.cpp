#include "ladder.h"


void error(string word1, string word2, string msg) {
    std::cerr << word1 << word2 << msg << endl;
};;
bool edit_distance_within(const std::string& str1, const std::string& str2, int d);
bool is_adjacent(const string& word1, const string& word2);
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list);
void load_words(set<string> & word_list, const string& file_name) {
    ifstream filename(file_name);
    if (!filename) {
        cerr << "Could not open file" << endl;
    }
    string line;
    while (std::getline(file, line)) {
        word_list.insert(line); // Insert each line into the set
    }
    file.close();
};
void print_word_ladder(const vector<string>& ladder) {
    for (word : ladder) {
        cout << word <<  endl;
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