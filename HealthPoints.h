#include <iostream>
#include <exception>
#include <string>



class HealthPoints {

    private:

        int m_max_hp;
        int m_current_hp;



    public:
    

    // -----------------------------------  Exceptions section  ------------------------------------


    class InvalidArgument : public std::exception { // inherited from std::exception

        public:

            InvalidArgument(const std::string& message) : message(message) {} // build it up with the message from the throw

            const char* what() const noexcept override { // override what() from std::exception 

                return message.c_str();
            }

        private:
            std::string message;
    };


    // --------------------------------  C'tors/D'tors section  ------------------------------------

    HealthPoints(int max_hp) { // regular c'tor

        if (max_hp <= 0) {

            throw InvalidArgument("MaxHealthPoints cannot be less than or equal 0");
        }

        m_max_hp = max_hp;
        m_current_hp = max_hp; 
    }

    HealthPoints() : m_max_hp(100), m_current_hp(100) {} // default c'tor

    HealthPoints (const HealthPoints& hp){ // copy c'tor

        if (hp.m_max_hp <= 0){
                
            throw InvalidArgument("MaxHealthPoints cannot be less than or equal 0");
        }

        m_max_hp = hp.m_max_hp;
        m_current_hp = hp.m_current_hp;

    }

    HealthPoints operator=(const HealthPoints& other){ // copy assignment operator

        m_max_hp = other.m_max_hp;
        m_current_hp = other.m_current_hp;
        return *this;
    }

    ~HealthPoints () {} // d'tor - nothing to do here because we don't have any dynamic memory allocation

    int get_current_hp() const { 

        return m_current_hp;
    }

     int get_max_hp() const {

        return m_max_hp;
    }

    void set_current_hp(int set_hp) {

        if (set_hp > m_max_hp) {

            throw InvalidArgument("HealthPoints cannot setted to be greater than max_hp");
        }

        if (set_hp < 0) {

            throw InvalidArgument("HealthPoints cannot setted to be less than 0");
        }

        m_current_hp = set_hp;
    }   

    void set_max_hp(int set_hp) {

        if (m_current_hp > set_hp) {

            throw InvalidArgument("max_hp cannot be less than current_hp");
        }

        if (set_hp <= 0) {

            throw InvalidArgument("max_hp cannot be less than or equal 0");
        }

        m_max_hp = set_hp;
    }

    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& hp);

    HealthPoints& operator +=(int hp); 
    HealthPoints operator +(int hp) const;

    HealthPoints& operator -=(int hp); 
    HealthPoints operator -(int hp) const;


};

HealthPoints operator+(const int& hp, const HealthPoints& other);

bool operator==(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator!=(const HealthPoints& hp1, const HealthPoints& hp2);

bool operator<=(const HealthPoints& hp1, const HealthPoints& hp2); // > will be !<=
bool operator >(const HealthPoints& hp1, const HealthPoints& hp2); 

bool operator>=(const HealthPoints& hp1, const HealthPoints& hp2); // < will be !>=
bool operator <(const HealthPoints& hp1, const HealthPoints& hp2);






