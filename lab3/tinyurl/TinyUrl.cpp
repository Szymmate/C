//
// Created by mateusz on 18.03.17.
//

#include "TinyUrl.h"
using namespace std;
namespace tinyurl{
    unique_ptr<TinyUrlCodec> Init(){
        unique_ptr<TinyUrlCodec> adres = make_unique<TinyUrlCodec>();
        adres->tab={'0','0','0','0','0','0'};
        return adres;
    }

    void NextHash(array<char, 6> *state){
        (*state)[5]+=1;
        for (int i=5;i>=0;i--){
            if((*state)[i]>57 && (*state)[i]<65){
                (*state)[i]='A';
            }
            if((*state)[i]>90 && (*state)[i]<97){
                (*state)[i]='a';
            }
            if((*state)[i]>122){
                (*state)[i]='0';
                (*state)[i-1]+=1;
            }
        }
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec){
        NextHash(&(*codec)->tab);
        string p;
        for (int i=0;i<6;++i){
            p=p+__STRING((*codec)->hash[i]);
        }
        (*codec)->kod[p]=url;
        return p;
    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash){
        return codec->kod[hash];
    }
}
