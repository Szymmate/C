//
// Created by mateusz on 15.05.17.
//

#include "Serialization.h"

using ::std::ref;
using ::std::vector;
using ::std::to_string;

namespace academia {

    void Room::Serialize(academia::Serializer *serializer) const {
        serializer->Header("room");
        serializer->IntegerField("id", this->id_);
        serializer->StringField("name", this->name_);
        if(this->type == Type::CLASSROOM){
            serializer->StringField("type", "CLASSROOM");
        }
        else if(this->type == Type::COMPUTER_LAB){
            serializer->StringField("type", "COMPUTER_LAB");
        }
        else{
            serializer->StringField("type", "LECTURE_HALL");
        }
        serializer->Footer("room");
    }

    Room::Room(int id_, const string &name_, academia::Room::Type room_type_) : id_(id_), name_(name_),
                                                                                type(room_type_) {}

    void Building::Serialize(Serializer *serializer) const {
        serializer->Header("building");
        serializer->IntegerField("id", this->id_);
        serializer->StringField("name", this->name_);
        vector<reference_wrapper<const Serializable>> wrappers_vector_;
        for(const Serializable &stuff: this->vector_of_room_){
            wrappers_vector_.emplace_back(stuff);
        }
        serializer->ArrayField("rooms", wrappers_vector_);
        serializer->Footer("building");
    }

    Building::Building(int id_, const string &name_, const vector<Room> &rooms_vector_) : id_(id_), name_(name_),
                                                                                          vector_of_room_(
                                                                                                  rooms_vector_) {}

    XmlSerializer::~XmlSerializer() {}

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        *os << "<" << field_name << ">" << to_string(value) << "<\\" << field_name << ">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        *os << "<" << field_name << ">" << to_string(value) << "<\\" << field_name << ">";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        *os << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        *os << "<" << field_name << ">" << to_string(value) << "<\\" << field_name << ">";
    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        *os<<"<"<<field_name<<">"<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const vector<reference_wrapper<const academia::Serializable>> &value) {
        *os<<"<"<<field_name<<">";

        for(const Serializable &i: value)
        {
            i.Serialize(this);
        }
        *os<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::Header(const std::string &object_name) {
        *os << "<" << object_name << ">";
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        *os << "<\\" << object_name << ">";
    }

    JsonSerializer::~JsonSerializer() {}

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        if(comma_needed){
            (*this->os) << ", ";
        }
        (*this->os) << "\"" << field_name << "\": " << to_string(value);
        comma_needed = true;
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        if(comma_needed){
            (*this->os) << ", ";
        }
        (*this->os) << "\"" << field_name << "\": " << to_string(value);
        comma_needed = true;
    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        if(comma_needed){
            (*this->os) << ", ";
        }
        (*this->os) << "\"" << field_name << "\": \"" << value << "\"";
        comma_needed = true;
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        if(comma_needed){
            (*this->os) << ", ";
        }
        (*this->os) << "\"" << field_name << "\": " << to_string(value);
        comma_needed = true;
    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {

    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const vector<reference_wrapper<const academia::Serializable>> &value) {
        if(comma_needed){
            (*this->os) << ", ";
        }
        (*this->os) << "\"" << field_name << "\": [";
        comma_needed = false;
        for (const Serializable &stuff : value) {
            if(comma_needed){
                (*this->os) << ", ";
            }
            stuff.Serialize(this);
            comma_needed = true;
        }
        (*this->os) << "]";
        comma_needed = true;
    }

    void JsonSerializer::Header(const std::string &object_name) {
        (*this->os) << "{";
        this->comma_needed = false;
    }

    void JsonSerializer::Footer(const std::string &object_name) {
        (*this->os) << "}";
        this->comma_needed = false;
    }

    void BuildingRepository::Add(const Building &new_building) {
        vector_of_building_.push_back(new_building);
    }

    std::experimental::optional<Building> BuildingRepository::operator[](int building) const {
        for(auto n: this->vector_of_building_){
            if(n.Id()==building) return std::experimental::make_optional(n);
        }
    };
    void BuildingRepository::StoreAll(Serializer *serializer) const {
        std::vector<std::reference_wrapper<const Serializable>> v(vector_of_building_.begin(), vector_of_building_.end());
        serializer->Header("building_repository");
        serializer->ArrayField("buildings", v);
        serializer->Footer("building_repository");
    }
}