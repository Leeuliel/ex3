#include "HealthPoints.h"

std::ostream& operator<<(std::ostream& os, const HealthPoints& hp){

    os << hp.m_current_hp << "(" << hp.m_max_hp << ")";
    return os;

}


HealthPoints& HealthPoints::operator +=(int hp){

    if (m_current_hp + hp > m_max_hp) {

        m_current_hp = m_max_hp;

    } else {

        m_current_hp += hp;
    }
    if (m_current_hp < 0) 
    {
        m_current_hp = 0;
    }

    return *this;
}



HealthPoints HealthPoints::operator +(int hp) const
{
    HealthPoints current_hp(*this);

    return (current_hp += hp);
}


HealthPoints operator+(const int& hp, const HealthPoints& other) 
{

    return (other + hp);

}

HealthPoints& HealthPoints::operator -=(int hp){


    if (m_current_hp - hp > m_max_hp) {

        m_current_hp = m_max_hp;

    } else {

        m_current_hp -= hp;

    }
    if (m_current_hp < 0) 
    {
        m_current_hp = 0;
    }

    return *this;
}

HealthPoints HealthPoints::operator-(int hp) const
{
    HealthPoints current_hp(*this);

    return (current_hp -= hp);
}

bool operator==(const HealthPoints& hp1, const HealthPoints& hp2)
{
    return (hp1.get_current_hp() == hp2.get_current_hp());
}

bool operator!=(const HealthPoints& hp1, const HealthPoints& hp2)
{
    return (!(hp1 == hp2));
}

bool operator<=(const HealthPoints& hp1, const HealthPoints& hp2){

    bool result = hp1.get_current_hp() <= hp2.get_current_hp();

    return result;
    
} 

bool operator >(const HealthPoints& hp1, const HealthPoints& hp2){ // > will be !<=

    return (!(hp1 <= hp2));

}

bool operator>=(const HealthPoints& hp1, const HealthPoints& hp2){


    bool result = hp1.get_current_hp() >= hp2.get_current_hp();

    return result;


}
bool operator <(const HealthPoints& hp1, const HealthPoints& hp2){ // < will be !>=

    return (!(hp1 >= hp2));

}


