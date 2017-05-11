//
// Created by mateusz on 2.05.17.
//

#include "MovieSubtitles.h"
using namespace std;
namespace moviesubs{

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay,int fps, std::stringstream *in,std::stringstream *out){

        if(fps<0){
            throw invalid_argument("fps");
        }
        string str;
        regex pattern {R"(\{(\d+)\}\{(\d+)\}(.*))"};
        smatch matches;
        int i=0;
        while(getline(*in,str,'\n')){
            ++i;
            if(regex_search(str, matches, pattern)) {
                int st = stoi(matches[1]) + (delay * fps / 1000);
                int en = stoi(matches[2]) + (delay * fps / 1000);
                if(en<st){
                    throw SubtitleEndBeforeStart(str,i);
                }
                if(st<0){
                    throw NegativeFrameAfterShift(str);
                }
                (*out) << "{" << st << "}";
                (*out) << "{" << en << "}";
                (*out) << matches[3] << "\n";
            }
            else{
                throw InvalidSubtitleLineFormat("Format");
            }
        }
    }
}