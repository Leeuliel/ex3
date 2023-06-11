#include "HealthPoints.h"

int main() {

    // tests for HealthPoints class

    HealthPoints hp1(100);
    HealthPoints hp2(200);

    std::cout << "hp1: " << hp1 << std::endl;
    std::cout << "hp2: " << hp2 << std::endl;

    hp2 -= 100; 

    std::cout << "hp2: " << hp2 << std::endl;

    hp2 += 100;

    std::cout << "hp2: " << hp2 << std::endl;

    hp2 += 100;

    std::cout << "hp2: " << hp2 << std::endl;

    hp2 -= 100;
    hp2 -= 90; 

    std::cout << "hp2: " << hp2 << std::endl;

    hp2 -= 100;

    std::cout << "hp2: " << hp2 << std::endl;

    hp2 = (hp1 - 50);

    std::cout << "hp2: " << hp2 << std::endl;
    std::cout << "hp1: " << hp1 << std::endl;

    hp2 = (hp1 + 50);    
    std::cout << "hp2: " << hp2 << std::endl;

    hp2 = (10 + hp2);
    std::cout << "hp2: " << hp2 << std::endl;

    hp2 -= 70;
    std::cout << "hp2: " << hp2 << std::endl;
    hp2 = (10 + hp2);
    std::cout << "hp2: " << hp2 << std::endl;
    std::cout << "hp1: " << hp1 << std::endl;

    if (hp1 == hp2) {

        std::cout << "hp1 == hp2 " << std::endl;

    } else {

        std::cout << "hp1 != hp2 good " << std::endl;
    }

    hp1 -= 39;

    if (hp1 == hp2) {

        std::cout << "hp1 == hp2" << std::endl;

    } else {

        std::cout << "hp1 != hp2 good" << std::endl;
    }

    hp1 -= 1; 

    if (hp1 == hp2) {

        std::cout << "hp1 == hp2 good" << std::endl;

    } else {

        std::cout << "hp1 != hp2" << std::endl;
    }

    hp1 = hp2;

    if (hp1 == hp2) {

        std::cout << "hp1 == hp2 good" << std::endl;

    } else {

        std::cout << "hp1 != hp2" << std::endl;
    }

    hp2+=1;

    if (hp1 == hp2) {

        std::cout << "hp1 == hp2" << std::endl;

    } else {

        std::cout << "hp1 != hp2 good" << std::endl;
    }

    hp2 -=1;

    if (hp1 == hp2) {

        std::cout << "hp1 == hp2 good" << std::endl;

    } else {

        std::cout << "hp1 != hp2" << std::endl;
    }

    

    std::cout << " ----------------------- " << std::endl;
    std::cout << "hp1: " << hp1 << std::endl;
    std::cout << "hp2: " << hp2 << std::endl;

    for (int i = 1; i < ((hp1.get_max_hp() > hp2.get_max_hp() ? hp1.get_max_hp() : hp2.get_max_hp()) + 1); i++) {

        if (hp1 == i) {

            std::cout << "hp1 == i when i is " << i << " " << std::endl;

        } 

        if (hp2 == i) {

            std::cout << "hp2 == i when i is " << i << " " << std::endl;

        } 

    }


    hp1 = 39;
    hp2 = 76;

    std::cout << " ----------------------- " << std::endl;
    std::cout << "hp1: " << hp1 << std::endl;
    std::cout << "hp2: " << hp2 << std::endl;

    for (int i = 1; i < ((hp1.get_max_hp() > hp2.get_max_hp() ? hp1.get_max_hp() : hp2.get_max_hp()) + 1); i++) {

        if (hp1 == i) {

            std::cout << "hp1 == i when i is " << i << " " << std::endl;

        } 

        if (hp2 == i) {

            std::cout << "hp2 == i when i is " << i << " " << std::endl;

        } 

    }


    // checking order relations

    std::cout << " ----------------------- " << std::endl;

    std::cout << "hp1: " << hp1 << std::endl;
    std::cout << "hp2: " << hp2 << std::endl;

    if (hp1 <= hp2) {

        std::cout << "hp1 <= hp2 good" << std::endl;

    } else {

        std::cout << "hp1 > hp2" << std::endl;
    }

    if (hp1 < hp2) {

        std::cout << "hp1 < hp2 good" << std::endl;

    } else {

        std::cout << "hp1 >= hp2" << std::endl;
    }

    if (hp1 >= hp2) {

        std::cout << "hp1 >= hp2" << std::endl;

    } else {

        std::cout << "hp1 < hp2 good" << std::endl;
    }

    if (hp1 > hp2) {

        std::cout << "hp1 > hp2" << std::endl;

    } else {

        std::cout << "hp1 <= hp2 good" << std::endl;
    }

    hp1 = 76;

    std::cout << " ----------------------- " << std::endl;

    std::cout << "hp1: " << hp1 << std::endl;
    std::cout << "hp2: " << hp2 << std::endl;

    if (hp1 <= hp2) {

        std::cout << "hp1 <= hp2 good" << std::endl;

    } else {

        std::cout << "hp1 > hp2" << std::endl;
    }

    if (hp1 < hp2) {

        std::cout << "hp1 < hp2" << std::endl;

    } else {

        std::cout << "hp1 >= hp2 good" << std::endl;
    }

    if (hp1 >= hp2) {

        std::cout << "hp1 >= hp2 good" << std::endl;

    } else {

        std::cout << "hp1 < hp2" << std::endl;
    }

    if (hp1 > hp2) {

        std::cout << "hp1 > hp2" << std::endl;

    } else {

        std::cout << "hp1 <= hp2 good" << std::endl;
    }

    hp1 = 77;

    std::cout << " ----------------------- " << std::endl;

    std::cout << "hp1: " << hp1 << std::endl;
    std::cout << "hp2: " << hp2 << std::endl;

    if (hp1 <= hp2) {

        std::cout << "hp1 <= hp2" << std::endl;

    } else {

        std::cout << "hp1 > hp2 good" << std::endl;
    }

    if (hp1 < hp2) {

        std::cout << "hp1 < hp2" << std::endl;

    } else {

        std::cout << "hp1 >= hp2 good" << std::endl;
    }

    if (hp1 >= hp2) {

        std::cout << "hp1 >= hp2 good" << std::endl;

    } else {

        std::cout << "hp1 < hp2" << std::endl;
    }

    if (hp1 > hp2) {

        std::cout << "hp1 > hp2 good" << std::endl;

    } else {

        std::cout << "hp1 <= hp2" << std::endl;
    }

    std::cout << " ----------------------- " << std::endl;

    int good = 0;
    int test_number = 1;

    hp1 = 50;
    hp2 = 50;

    std::cout << "hp1: " << hp1 << std::endl;
    std::cout << "hp2: " << hp2 << std::endl;

    if (hp2 == hp1 && hp1 >= hp2 && hp2 <= hp1 && hp1.get_current_hp() == hp2.get_current_hp() && hp1.get_max_hp() == hp2.get_max_hp()){


        good += 1;

    }

    std::cout << good << "/" << test_number << " tests passed" << std::endl;



    return 0;
}