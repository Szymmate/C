//
// Created by mateusz on 25.03.17.
//

#include "SimpleTemplateEngine.h"
using namespace std;
namespace nets {
    View::View(std::string tekst) {
            wzor=tekst; }
    string View::Render(const std::unordered_map<std::string, std::string> &model) const {
            string gotowe="";
            string klucz="";
            size_t k=0;
            auto i=wzor.find("{{");
            auto j=wzor.find("}}");
            while (i!=string::npos && j!=string::npos){
                while (wzor[i+2]=='{') ++i;
                gotowe+=wzor.substr(k,i-k);
                klucz=wzor.substr(i+2,j-i-2);
                auto l=model.find(klucz);
                if (l!=model.end()){
                    gotowe+=l->second; }
                else if (klucz.find("}")!=string::npos){
                    gotowe=gotowe+"{{"+klucz+"}}"; }
                k=j+2;
                i=wzor.find("{{",k);
                j=wzor.find("}}",i);}
            if (k<wzor.size()){
                gotowe+=wzor.substr(k);}
            return gotowe; }
}