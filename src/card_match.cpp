#ifndef CARD_MATCH_CPP
#define CARD_MATCH_CPP

#include <vector>
#include <filesystem>
#include <fstream>
#include <unordered_set>
#include "card.cpp"
using namespace std;

struct CardMatchGame {
    int height;
    int width;
    vector<vector<Card>> card_grid;

    int score;
    int remaining_tries;

    Card* first_clicked;
    Card* second_clicked;

    explicit CardMatchGame(int _height=5, int _width=6, int _remaining_tries=50) {
        height = _height;
        width = _width;
        remaining_tries = _remaining_tries;
        score = 0;
        first_clicked = nullptr;
        second_clicked = nullptr;

        card_grid = vector<vector<Card>> (height, vector<Card>(width, Card("empty")));
        srand(static_cast<unsigned int>(std::time(nullptr)));

        initialize_cards();
    }

    void initialize_cards(){
        vector<string> resource_files;
        for (auto const& dir_entry : filesystem::directory_iterator{"../resources"})
        {
            resource_files.push_back(dir_entry.path().string());
        }

        int randomIndex = rand() % resource_files.size();
        string random_resource_file = resource_files[randomIndex];

        ifstream inputFile(random_resource_file);

        vector<string> total_words;
        string word;

        while (inputFile >> word) {
            total_words.push_back(word);
        }

        inputFile.close();

        unordered_set<int> randomIndices;
        while (randomIndices.size() < height * width / 2) {
            int index = rand() % total_words.size();
            randomIndices.insert(index);
        }

        vector<pair<string,int>> selected_words;
        selected_words.reserve(randomIndices.size());
        for (int i : randomIndices){
            selected_words.emplace_back(total_words[i], 0);
        }

        vector<pair<int,int>> grid_indices;

        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                grid_indices.emplace_back(i,j);
            }
        }

        while (!grid_indices.empty()){
            int index = rand() % grid_indices.size();
            pair<int,int> selected_grid_location = grid_indices[index];
            if(selected_words.back().second == 2){
                selected_words.pop_back();
            }
            card_grid[selected_grid_location.first][selected_grid_location.second].content = selected_words.back().first;
            selected_words.back().second++;
            grid_indices.erase(grid_indices.begin() + index);
        }

    };

    bool end() const {
        return remaining_tries <= 0;
    }

    bool clickable(int row, int column) {
        Card& card = card_grid[row][column];
        if(end()) return false;
        if(!card.active) return false;
        if(card.clicked) return false;
        return true;
    }

    void click(int row, int column) {
        Card& card = card_grid[row][column];

        if(!clickable(row, column)) throw "Card is not clickable";

        card.setClicked(true);

        if(first_clicked == nullptr) {
            first_clicked = &card;
        }
        else {
            second_clicked = &card;
        }
    }

    void match() {
        if(first_clicked == nullptr || second_clicked == nullptr) return;

        first_clicked->setClicked(false);
        second_clicked->setClicked(false);

        if(first_clicked->content == second_clicked->content) {
            second_clicked->setActive(false);
            first_clicked->setActive(false);

            score++;
        }

        first_clicked = nullptr;
        second_clicked = nullptr;

        remaining_tries--;
    }

};

#endif //CARD_MATCH_CPP