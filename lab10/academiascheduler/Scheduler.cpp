#include "Scheduler.h"

using academia::SchedulingItem;
using academia::Schedule;
using academia::Scheduler;
using academia::GreedyScheduler;

Schedule::Schedule(vector<SchedulingItem> item_v) {
    for(auto item : item_v){
        InsertScheduleItem(item);
    }
}

Schedule Schedule::OfTeacher(int _teacher_id) const {
    Schedule tmp;

    for(auto item : items){
        if(item.teacher_id == _teacher_id)
            tmp.items.push_back(item);
    }
    return tmp;
}

Schedule Schedule::OfRoom(int _room_id) const {
    Schedule tmp;

    for(auto item : items){
        if(item.room_id == _room_id)
            tmp.items.push_back(item);
    }
    return tmp;
}

Schedule Schedule::OfYear(int _year) const {
    Schedule tmp;

    for(auto item : items){
        if(item.year == _year)
            tmp.items.push_back(item);
    }
    return tmp;
}

vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
    vector<int> free_slots;
    vector<int> intersection;
    vector<int> result;

    for (int i=1; i <= n_time_slots; i++){
        free_slots.push_back(i);
    }

    set_intersection(busy_slots.begin(), busy_slots.end(), free_slots.begin(), free_slots.end(), back_inserter(intersection));

    set_difference(free_slots.begin(), free_slots.end(), intersection.begin(), intersection.end(), back_inserter(result));

    return result;
}

void Schedule::InsertScheduleItem(const SchedulingItem &item_) {
    busy_slots.push_back(item_.time_slot);
    items.push_back(item_);
}

size_t Schedule::Size() const {
    return items.size();
}

SchedulingItem Schedule::operator[](int id) const {
    return items[id];
}

Schedule GreedyScheduler::PrepareNewSchedule(const vector<int> &rooms, const map<int, vector<int>> &teacher_courses_assignment, const map<int, set<int>> &courses_of_year, int n_time_slots) {
    vector<SchedulingItem> scheduling_items;

    for(auto tcourses : teacher_courses_assignment) {
        for(auto course : tcourses.second) {
            for(auto ycourse : courses_of_year) {
                if(ycourse.second.find(course) != ycourse.second.end())
                    scheduling_items.push_back(SchedulingItem(course, tcourses.first, 0, 0, ycourse.first));
            }
        }
    }
    for (auto ycourses : courses_of_year) {
        for (auto course : ycourses.second) {
            int number_of_courses = 0;
            for (auto tcourses : teacher_courses_assignment) {
                number_of_courses += count(tcourses.second.begin(), tcourses.second.end(), course);
            }
            if (number_of_courses > n_time_slots)
                throw NoViableSolutionFound();
        }
    }



    if(scheduling_items.size() > rooms.size()*n_time_slots)
        throw NoViableSolutionFound{};

    int i =0;
    for(auto room : rooms) {
        for (int tslot = 1; tslot <= n_time_slots; tslot++){
            if(i<scheduling_items.size()) {
                scheduling_items[i].time_slot = tslot;
                scheduling_items[i].room_id = room;
            }
            i++;
        }
    }

    return Schedule(scheduling_items);
}

//Getters

SchedulingItem::SchedulingItem(int _course, int _teacher, int _room, int _time_slot, int _year) {
    course_id = _course;
    teacher_id = _teacher;
    room_id = _room;
    time_slot = _time_slot;
    year = _year;
}

int SchedulingItem::CourseId() const {
    return course_id;
}

int SchedulingItem::TeacherId() const {
    return teacher_id;
}

int SchedulingItem::RoomId() const {
    return room_id;
}

int SchedulingItem::TimeSlot() const{
    return time_slot;
}

int SchedulingItem::Year() const {
    return year;
}