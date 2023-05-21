#include "Shuffle.h"

std::vector<std::vector<QString>> getShuffledWords(int height, int width)
{
    std::vector<std::vector<QString>> cardGrid(height, std::vector<QString>(width));

    std::vector<std::string> resource_files = {"D:/boun-cmpe/cmpe230/cmpe230-p3/animals.txt",
                                               "D:/boun-cmpe/cmpe230/cmpe230-p3/countries.txt",
                                               "D:/boun-cmpe/cmpe230/cmpe230-p3/fruits.txt"};
    srand(time(0));

    int randomIndex = rand() % 3;
    std::string random_resource_file = resource_files[randomIndex];

    std::ifstream inputFile(random_resource_file);

    std::vector<std::string> total_words;
    std::string word;

    while (inputFile >> word) {
        total_words.push_back(word);
    }

    inputFile.close();

    std::unordered_set<int> randomIndices;
    while (randomIndices.size() < static_cast<std::size_t>(height * width / 2)) {
        int index = rand() % total_words.size();
        randomIndices.insert(index);
    }

    std::vector<std::pair<std::string,int>> selected_words;
    selected_words.reserve(randomIndices.size());
    for (int i : randomIndices){
        selected_words.emplace_back(total_words[i], 0);
    }

    std::vector<std::pair<int,int>> grid_indices;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            grid_indices.emplace_back(i,j);
        }
    }

    while (!grid_indices.empty()){
        int index = rand() % grid_indices.size();
        std::pair<int,int> selected_grid_location = grid_indices[index];
        if(selected_words.back().second == 2){
            selected_words.pop_back();
        }
        QString QStringWord = QString::fromStdString(selected_words.back().first);
        cardGrid[selected_grid_location.first][selected_grid_location.second] = QStringWord;
        selected_words.back().second++;
        grid_indices.erase(grid_indices.begin() + index);
    }

    return cardGrid;
}
