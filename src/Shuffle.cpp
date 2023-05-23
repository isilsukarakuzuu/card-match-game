#include "../include/Shuffle.h"
#include <QFile>
#include <QTextStream>

std::vector<std::vector<QString>> getShuffledWords(int height, int width)
{
    std::vector<std::vector<QString>> cardGrid(height, std::vector<QString>(width));

    // resource_files contains the paths to the text files containing the words
    std::vector<QString> resource_files = {QString(":/resources/animals.txt"),
                                               QString(":/resources/countries.txt"),
                                               QString(":/resources/fruits.txt")};

    srand(time(0));

    // Select a random text file
    int randomIndex = rand() % 3;
    QFile random_resource_file(resource_files[randomIndex]);
    random_resource_file.open(QFile::ReadOnly);

    QTextStream inputFile(&random_resource_file);

    std::vector<std::string> total_words;
    QString word;

    while (inputFile.readLineInto(&word))
    {
        total_words.push_back(word.toStdString());
    }

    random_resource_file.close();

    std::unordered_set<int> randomIndices;

    // Select random words from the text file
    while (randomIndices.size() < static_cast<std::size_t>(height * width / 2))
    {
        int index = rand() % total_words.size();
        randomIndices.insert(index);
    }

    std::vector<std::pair<std::string,int>> selected_words;
    selected_words.reserve(randomIndices.size());

    for (int i : randomIndices)
    {
        selected_words.emplace_back(total_words[i], 0);
    }

    std::vector<std::pair<int,int>> grid_indices;

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            grid_indices.emplace_back(i,j);
        }
    }

    // Assign the words to the grid
    while (!grid_indices.empty())
    {
        int index = rand() % grid_indices.size();
        std::pair<int,int> selected_grid_location = grid_indices[index];
        if(selected_words.back().second == 2)
        {
            // If the word has already been assigned twice, remove it from the list
            selected_words.pop_back();
        }

        QString QStringWord = QString::fromStdString(selected_words.back().first);
        cardGrid[selected_grid_location.first][selected_grid_location.second] = QStringWord;
        selected_words.back().second++;
        grid_indices.erase(grid_indices.begin() + index);
    }

    return cardGrid;
}
