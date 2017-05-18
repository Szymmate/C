//
// Created by mateusz on 15.05.17.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <vector>
#include <ostream>
#include <functional>
#include <experimental/optional>

using ::std::reference_wrapper;
using ::std::vector;
using ::std::ostream;
using ::std::string;

namespace academia {
    class Serializer;
    class BuildingRepository;

    class Serializable {
    public:
        virtual void Serialize(Serializer *ser) const=0;
    };

    class Serializer {
    public:
        Serializer(){};
        Serializer(ostream *os):os(os){}
        virtual ~Serializer() {};
        virtual void IntegerField(const std::string &field_name, int value) =0;
        virtual void DoubleField(const std::string &field_name, double value) =0;
        virtual void StringField(const std::string &field_name, const std::string &value) =0;
        virtual void BooleanField(const std::string &field_name, bool value) =0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) =0;
        virtual void ArrayField(const std::string &field_name,
                                const vector<reference_wrapper<const academia::Serializable>> &value) =0;
        virtual void Header(const std::string &object_name) =0;
        virtual void Footer(const std::string &object_name) =0;
    protected:
        ostream *os;
    };

    class Room : public Serializable{
    public:
        enum class Type{
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        Room(int id_, const string &name_, Type room_type_);
        void Serialize(Serializer *serializer) const override;
    private:
        int id_;
        string name_;
        Type type;
    };

    class Building : public Serializable{
    public:
        void Serialize(Serializer *serializer) const override;
        Building(int id_, const string &name_, const vector<Room> &rooms_vector_);
        int Id(void) const { return id_;}
    private:
        int id_;
        string name_;
        vector<Room> vector_of_room_;
    };

    class XmlSerializer : public Serializer{
    public:
        XmlSerializer(){};
        XmlSerializer(ostream *my_ostream):Serializer(my_ostream){};
        ~XmlSerializer() override;
        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        void ArrayField(const std::string &field_name,
                        const vector<reference_wrapper<const academia::Serializable>> &value) override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;
    };


    class BuildingRepository{
    public:
        BuildingRepository(){};
        ~BuildingRepository(){};
        BuildingRepository(const std::initializer_list<Building> buildings): vector_of_building_(buildings){};
        void StoreAll(Serializer *serializer) const;
        //void Serialize(Serializer *serializer) const override;
        void Add(const Building &new_building);
        std::experimental::optional<Building> operator[](int building) const;
    private:
        vector<Building> vector_of_building_;
    };

    class JsonSerializer : public Serializer{
    public:
        JsonSerializer(ostream *my_ostream):Serializer(my_ostream), comma_needed(false){};
        ~JsonSerializer() override;
        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        void ArrayField(const std::string &field_name,
                        const vector<reference_wrapper<const academia::Serializable>> &value) override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;

    private:
        bool comma_needed;
    };


}

#endif