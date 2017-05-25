#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using std::vector;
using std::map;
using std::set;
using std::pair;

namespace academia {
    class SchedulingItem {
    public:
        SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year);
        ~SchedulingItem(){};

        int CourseId() const;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;

        int course_id; // identyfikator kursu
        int teacher_id; // identyfikator nauczyciela akademickiego prowadzącego te zajęcia o tej godzinie
        int room_id; // identyfikator pomieszczenia w którym odbywają się zajęcia
        int time_slot; // okno czasowe, w którym odbywają się zajęcia, dla uproszczenia cały tydzień jest podzielony na N okien czasowych nie zachodzących na siebie (np. dla 20: 1 ⇒ pon 8:00-10:00, 2 ⇒ pon 10:00-12:00, … 20 ⇒ pią 14:00-16:00). Zajęcia wymagają zawsze pojedynczego okna czasowego i zawsze są z nim wyrównane tzn. nie mogą zajmować połowę 12ego i połowę 13ego
        int year; // rok studiów na którym obowiązuje przedmiot
    };

    class Schedule {
    public:
        Schedule () {};
        Schedule (std::vector <SchedulingItem> item_v);

        Schedule OfTeacher(int teacher_id) const; // wylicza fragment harmonogramu związany z danym nauczycielem akademickim (może się przydać copy_if…)
        Schedule OfRoom(int room_id) const; // j.w. tylko związany z danym pomieszczeniem
        Schedule OfYear(int year) const; // j.w. dla danego roku studiów
        vector<int> AvailableTimeSlots(int n_time_slots) const; // wylicza wektor jeszcze nie zajętych okien czasowych, gdzie n_time_slots jest maksymalną wartością okna czasowego
        void InsertScheduleItem(const SchedulingItem &item); // wstawia nowy element planu
        size_t Size() const; // zwaraca rozmiar planu
        SchedulingItem operator[](int id) const;

        ~Schedule() {};

    private:
        vector<SchedulingItem> items;
        vector <int> busy_slots;


    };

    class Scheduler {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) = 0;
    };

    // Wyjątek wyrzucany, gdy nie udaje się stworzyć planu
    class NoViableSolutionFound {
    };

    // Wersja zachłanna implentacji algorytmu układacza planu
    class GreedyScheduler : public Scheduler{
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots);
    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
