//
// Created by mateusz on 25.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>
using namespace std;
namespace nets {
    class View {
        string wzor;
    public:
        View(string tekst);
        string Render(const std::unordered_map <std::string, std::string> &model) const;
    };
}


#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H