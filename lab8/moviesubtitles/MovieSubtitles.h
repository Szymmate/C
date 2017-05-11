//
// Created by mateusz on 2.05.17.
//

#ifndef JIMP_EXERCISES_MICRODVDSUBTITLES_H
#define JIMP_EXERCISES_MICRODVDSUBTITLES_H

#include <sstream>
#include <regex>
#include <stdexcept>

namespace moviesubs{
    class MovieSubtitles{
    public:
        virtual void ShiftAllSubtitlesBy(int,int, std::stringstream*,std::stringstream*)=0;
    };

    class MicroDvdSubtitles: public MovieSubtitles{
    public:
        void ShiftAllSubtitlesBy(int,int, std::stringstream*,std::stringstream*);
    };
    
    class NegativeFrameAfterShift: public std::runtime_error{
    public:
        NegativeFrameAfterShift()=delete;
        NegativeFrameAfterShift(std::string str):std::runtime_error(str){};
    };
    class SubtitleEndBeforeStart: public std::runtime_error{
    public:
        SubtitleEndBeforeStart()=delete;
        SubtitleEndBeforeStart(std::string str, int l):std::runtime_error("At line "+std::to_string(l)+": "+str),line_(l){};
        int LineAt () const {return line_;}
    private:
        int line_;
    };
    class InvalidSubtitleLineFormat: public std::runtime_error{
    public:
        InvalidSubtitleLineFormat()=delete;
        InvalidSubtitleLineFormat(std::string str):std::runtime_error(str){};
    };
    class MissingTimeSpecification: public std::runtime_error{
    public:
        MissingTimeSpecification()=delete;
        MissingTimeSpecification(std::string str):std::runtime_error(str){};
    };
    class OutOfOrderFrames: public std::runtime_error{
    public:
        OutOfOrderFrames()=delete;
        OutOfOrderFrames(std::string str):std::runtime_error(str){};
    };
}

#endif //JIMP_EXERCISES_MICRODVDSUBTITLES_H